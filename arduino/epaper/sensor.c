
//#include <string.h>

#include "sensor.h"

static Sensor_t sensors[SENSOR_NUM] = {0};

/**
 * Compares mac addresses.
 *
 * returns zero if they are “equal”
 * see https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html
 *
 */
static int8_t compareMacs(uint8_t a[6], uint8_t b[6]) {
  for (int i = 0; i < 6; i++) {
    if (a[i] != b[i]) {
      return 1;
    }
  }
  return 0;
}

static int8_t sensorNum(PAYLOAD_sensor_t *payload) {
  for (uint8_t i = 0; i < SENSOR_NUM; i++) {
    if (compareMacs(sensors[i].payload.mac, payload->mac) == 0) {
      return i;
    }
  }

  // Not seen before.
  for (uint8_t i = 0; i < SENSOR_NUM; i++) {
    if (sensors[i].payload.mac[0] == 0) {
      return i;
    }
  }

  return -1;
}

static uint8_t batteryLevel(uint16_t batt) {
  if (batt > 3700) {
    return 3;
  }
  if (batt > 3600) {
    return 2;
  }
  if (batt > 3400) {
    return 1;
  }
  return 0;
}

static uint8_t waterLevel(uint16_t val) {
  if (val == 1023) {
    // No sensor connected.
    return 0;
  }
  if (val > 1000) {
    return 1;
  }
  if (val > 800) {
    return 2;
  }
  if (val > 500) {
    return 3;
  }
  if (val > 300) {
    return 4;
  }

  return 5;
}

Sensor_t SensorGet(PAYLOAD_sensor_t *payload) {
  int8_t num = sensorNum(payload);
  
  if (num == -1) {
    num = 0; // Override the first one for now.
  }

  sensors[num].previous = sensors[num].payload;
  //memcpy ( &sensors[num].previous, &sensors[num].payload, sizeof(PAYLOAD_sensor_t) );
  //memcpy ( &sensors[num].payload, payload, sizeof(PAYLOAD_sensor_t) );
  sensors[num].payload = *payload;
  sensors[num].num = num;
  if (sensors[num].payload.message_id != sensors[num].previous.message_id) {
    sensors[num].last = millis();
  }

  SensorIcons_t icons = {0};
  icons.flower = num;
  icons.batt = batteryLevel(payload->batt);
  
  // The first adc value is the battery, so ignore it.
  for (int i = 1; i < SENSOR_LEVELS + 1; i++) {
    icons.level[i - 1] = waterLevel(payload->adc[i]);
  }
  sensors[num].icons = icons;

  return sensors[num];
}
