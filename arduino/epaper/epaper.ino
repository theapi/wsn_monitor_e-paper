
#define ENABLE_GxEPD2_GFX 1

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "TextDisplay.h"

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "config.h"
#include "payload.h"

WiFiUDP Udp;
// Multicast declarations
IPAddress ipMulti(239, 0, 0, 58);
unsigned int portMulti = 12345;      // local port to listen on
char incomingPacket[255];  // buffer for incoming packets

const byte DEBUG_LED = 16;

PAYLOAD_sensor_t payload = {};

GxEPD2_BW<GxEPD2_290, GxEPD2_290::HEIGHT> display(GxEPD2_290(/*CS=D8*/ 5, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4));
// Display is 296x128

void setup() {
  Serial.begin(115200);
  Serial.println();

  display.init(115200);
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);

  // first update should be full refresh
  //display.clearScreen();
  showBoot(display);
  display.powerOff();

  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    delay(5000);
    ESP.restart();
  }

  Serial.println(WiFi.localIP().toString());

  Udp.beginMulticast(WiFi.localIP(), ipMulti, portMulti);
  Serial.printf("Now listening to IP %s, UDP port %d\n", ipMulti.toString().c_str(), portMulti);
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON

  showConnected(display);
  display.powerOff();


}

void showBoot(GxEPD2_GFX& display) {
  const char text[] = "WSN Monitor";
  display.setFullWindow();
  int16_t tbx, tby; uint16_t tbw, tbh; // boundary box window
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center bounding box by transposition of origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(text);
  }
  while (display.nextPage());
}

void showConnected(GxEPD2_GFX& display) {
  char buf[64];
  uint16_t x = 0;
  uint16_t y = 20;

  display.setPartialWindow(0, 0, display.width(), 40);
  sprintf(buf, "IP %s,\nUDP port %d", ipMulti.toString().c_str(), portMulti);
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(buf);
  }
  while (display.nextPage());
}

void showPayload(GxEPD2_GFX& display) {
  char buf[64];
  uint16_t x = 0;
  uint16_t y = 120;

  display.setPartialWindow(0, 100, display.width(), 24);
  sprintf(buf, "Msg %d", payload.message_id);
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(buf);
  }
  while (display.nextPage());
}

void loop() {
  static uint8_t msg_id = 0;
  // Check for udp data. 
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)  {
      incomingPacket[len] = 0;
    }
    PAYLOAD_unserialize(&payload, (uint8_t*) incomingPacket);
    if (payload.message_id != msg_id) {
      msg_id = payload.message_id;
      showPayload(display);
      display.powerOff();
      Serial.print(payload.message_id); Serial.print(", ");
      Serial.println();
    }
    
  }

}

