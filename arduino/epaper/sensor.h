#ifndef SENSOR_H
#define SENSOR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "payload.h"

#define SENSOR_NUM 4
#define SENSOR_LEVELS 6 // number of water levels

/* How to show the payload icons */
typedef struct {
  int8_t flower;
  uint8_t batt;
  uint8_t level[SENSOR_LEVELS];
} SensorIcons_t;

/* The sensor struct. */
typedef struct {
  PAYLOAD_sensor_t payload;
  PAYLOAD_sensor_t previous;
  unsigned long last;
  int8_t num;
  SensorIcons_t icons;
} Sensor_t;


Sensor_t SensorGet(PAYLOAD_sensor_t *payload);

#ifdef __cplusplus
}
#endif
#endif

