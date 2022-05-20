#include "SensorManager.h"

boolean SensorManager::begin()
{
    sgp = new Adafruit_SGP30();
    return sgp->begin();
}

void SensorManager::getMeasure()
{
    if (!sgp->IAQmeasure())
    {
        Serial.println("Measurement failed");
        measure.eCO2 = -1;
        measure.TVOC = -1;
    }
    else
    {
        measure.eCO2 = sgp->eCO2;
        measure.TVOC = sgp->TVOC;
    }
}
