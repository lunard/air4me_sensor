#include <Arduino.h>
#include <M5StickCPlus.h>
#include "UIManager/UIManager.h"
#include "BLEManager/BLEManager.h"
#include "SensorManager/SensorManager.h"

UIManager *ui;
BLEManager *ble;
SensorManager *sensor;
float BTL_MESSAGE_FREQUENCY = 0.5; // Hz
float MEASURE_FREQUENCY = 2;       // Hz

static void bleConnectionCallback(boolean bleConnected)
{
  if (bleConnected)
  {
    Serial.println("BLE connected");
  }
  else
  {
    Serial.println("BLE disconnected");
  }
}

void setup()
{
  M5.begin();

  ui = new UIManager();
  ui->begin();

  ble = new BLEManager();
  ble->begin("air4me", bleConnectionCallback);
  ble->start();
  ui->setStatusbar("BLE started..");
  ble->write("0"); // need to be discoverable

  delay(500);

  sensor = new SensorManager();
  if (!sensor->begin())
  {
    ui->setStatusbar("Sensor SGP30 NOT found", true);
  }
  else
  {
    ui->setStatusbar("Sensor SGP30 found");
  }
}

float elapsedTime = 0;
float delayTime = (1000 / MEASURE_FREQUENCY);
void loop()
{
  sensor->getMeasure();
  Serial.println("Measure: TVOC=" + String(sensor->measure.TVOC) + ", eCO2=" + String(sensor->measure.eCO2));

  ui->updateUI(sensor->measure.TVOC, sensor->measure.eCO2);

  delay(delayTime);
  elapsedTime += delayTime;

  if ((1000 / elapsedTime) == BTL_MESSAGE_FREQUENCY)
  {
    ble->write(String(sensor->measure.TVOC) + "##" + String(sensor->measure.eCO2));
    Serial.println("Sent data via BLT");
    elapsedTime = 0;
  }
}