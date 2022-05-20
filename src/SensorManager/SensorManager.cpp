#include "SensorManager.h"

boolean SensorManager::begin()
{
    sgp = new Adafruit_SGP30();
    return sgp->begin();
}