#ifndef __SENSOR_MANAGER_H__
#define __SENSOR_MANAGER_H__

#include <Arduino.h>
#include <M5StickCPlus.h>
#include "Adafruit_SGP30.h"

class Measure
{
public:
    float TVOC;
    float eCO2;
};

class SensorManager
{
public:
    boolean begin();
    void getMeasure();
    Measure measure;

private:
    Adafruit_SGP30 *sgp;
};

#endif