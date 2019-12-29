#ifndef SENSOR_H
#define SENSOR_H
#ifdef __cplusplus
extern "C" {
#endif

#include "payload.h"

#define SENSOR_NUM 4

/* The sensor struct. */
typedef struct {
  PAYLOAD_sensor_t payload;
  PAYLOAD_sensor_t previous;
  int8_t num;
} Sensor_t;


Sensor_t SensorGet(PAYLOAD_sensor_t *payload);

#ifdef __cplusplus
}
#endif
#endif

