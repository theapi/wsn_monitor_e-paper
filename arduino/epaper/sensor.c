
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

  return sensors[num];
}

