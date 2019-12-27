
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

void setup() {
  Serial.begin(115200);
  Serial.println();

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

  Serial.println("Display setup");
  delay(100);
  display.init(115200);
  // first update should be full refresh
  helloWorld(display);
  delay(500);
  // partial refresh mode can be used to full screen,
  // effective if display panel hasFastPartialUpdate
  helloFullScreenPartialMode(display);
  delay(1000);
  helloArduino(display);
  delay(1000);
  helloEpaper(display);
//  delay(1000);
//  //helloValue(display, 123.9, 1);
//  //delay(1000);
//  showFont(display, "FreeMonoBold9pt7b", &FreeMonoBold9pt7b);

  display.powerOff();

  Serial.println("Display setup done");
}

void loop() {

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
    Serial.print(payload.message_id); Serial.print(", ");
    Serial.println();
  }

}

