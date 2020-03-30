
#define ENABLE_GxEPD2_GFX 1

#include <Arduino.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "bitmaps.h"

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "config.h"
#include "payload.h"
#include "sensor.h"

enum State {
  ST_SETUP,
  ST_PAYLOAD_RECEIVED,
};
State state = ST_SETUP;


WiFiUDP Udp;
// Multicast declarations
IPAddress ipMulti(239, 0, 0, 58);
unsigned int portMulti = 12345;      // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
const byte DEBUG_LED = 16;
unsigned long empty_check = 0;
unsigned long screen_reset = 0;

GxEPD2_BW<GxEPD2_290, GxEPD2_290::HEIGHT> display(GxEPD2_290(/*CS=D8*/ 5, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4));
// Display is 296x128

void showConnected() {
  const char msg[] = "Connected";

  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(msg, 0, 0, &tbx, &tby, &tbw, &tbh);
  Serial.printf("tbx: %d, tby: %d, tbw: %d, tbh: %d,\n", tbx, tby, tbw, tbh);
  uint16_t x = 5;
  uint16_t y = 5;
  display.setPartialWindow(x, y, tbw, tbh);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y + tbh);
    display.print(msg);
  }
  while (display.nextPage());
}

void showStartUp() {
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    // 296x128
    display.drawInvertedBitmap(0, 0, us_bw, 296, 128, GxEPD_BLACK);
  }
  while (display.nextPage());
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  display.init(115200);
  //display.init(0);
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.clearScreen();

  showStartUp();
  display.powerOff();

  WiFi.persistent(false);
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    delay(1000);
    ESP.restart();
  }

  Serial.println(WiFi.localIP().toString());

  Udp.beginMulticast(WiFi.localIP(), ipMulti, portMulti);
  Serial.printf("Now listening to IP %s, UDP port %d\n", ipMulti.toString().c_str(), portMulti);
  // showConnected();
  // display.powerOff();

  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON

}



void hideSensor(Sensor_t *sensor) {
  uint8_t x_start = 10;
  uint8_t y_start = 10;
  uint8_t y_space = 30;

  Serial.printf("Hide %lu \n", sensor->last);

  display.firstPage();
  do {
    uint8_t x = x_start;
    uint8_t y = y_start + y_space * sensor->num;

    display.setPartialWindow(x, y, 230, 25);
    display.fillScreen(GxEPD_WHITE);
  }
  while (display.nextPage());
}

void showSensor(Sensor_t *sensor) {
  uint8_t x_start = 10;
  uint8_t y_start = 10;
  uint8_t x_space = 30;
  uint8_t y_space = 30;

  const unsigned char* flowers[] =
  {
    flower0, flower1, flower2, flower3
  };

  const unsigned char* batteries[] =
  {
    battery0, battery1, battery2, battery3
  };

  const unsigned char* levels[] =
  {
    level_nc, level0, level1, level2, level3, level4
  };

  display.firstPage();
  do {
    uint8_t x = x_start;
    uint8_t y = y_start + y_space * sensor->num;

    display.setPartialWindow(x, y, 230, 25);
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(x, y, flowers[sensor->icons.flower], 25, 25, GxEPD_BLACK);
    display.drawInvertedBitmap(x + x_space, y, batteries[sensor->icons.batt], 13, 25, GxEPD_BLACK);

    // Show the water levels.
    for (int i = 0; i < SENSOR_LEVELS; i++) {
      display.drawInvertedBitmap(x + x_space * (2 + i), y, levels[sensor->icons.level[i]], 25, 25, GxEPD_BLACK);
    }
  }
  while (display.nextPage());
}

void loop() {

  // Check for udp data.
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // receive incoming UDP packets
    //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);

    Sensor_t sensor = SensorPopulate((uint8_t*) incomingPacket, len);
    Serial.printf("Sensor: num %d, prev: %d, msg_id %d, last %lu\n",
      sensor.num, sensor.previous.message_id, sensor.payload.message_id, sensor.last);

    if (state == ST_SETUP) {
      state = ST_PAYLOAD_RECEIVED;
      if (sensor.payload.message_id != 0) {
        display.clearScreen();
        display.powerOff();
      }
    }

    if (state == ST_PAYLOAD_RECEIVED) {
      if (sensor.payload.message_id != sensor.previous.message_id) {
        showSensor(&sensor);
        display.powerOff();
      }
    }
  }

  unsigned long now = millis();
  if (now - screen_reset >= 60000 * 60) {
    // Ensure the screen does not get burn in.
    screen_reset = now;
    display.clearScreen();
    display.powerOff();
    // Show the sensors again
    for (uint8_t i = 0; i < SENSOR_NUM; i++) {
      Sensor_t sensor = SensorGetByNumber(i);
      if (sensor.visible == 1) {
        showSensor(&sensor);
        display.powerOff();
      }
    }
  }

  if (now - empty_check >= 2000) {
    empty_check = now;
    for (uint8_t i = 0; i < SENSOR_NUM; i++) {
      Sensor_t sensor = SensorGetByNumber(i);
      if (sensor.visible == 1 && now - sensor.last > (sensor.payload.delay + 2) * 1000UL) {
        //Serial.printf("HIDING: num %d, delay %d, last %d, visible %d\n", sensor.num, sensor.payload.delay, sensor.last, sensor.visible);
        SensorSetVisible(i, 0);
        hideSensor(&sensor);
        display.powerOff();
      }
    }
  }

}

