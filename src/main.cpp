#include <Arduino.h>
#include <M5StickCPlus.h>
#include "UIManager/UIManager.h"
#include "BLEManager/BLEManager.h"
#include "SensorManager/SensorManager.h"

UIManager *ui;
BLEManager *ble;
SensorManager *sensor;

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

int counter = 0;
void loop()
{
  sensor->getMeasure();
  Serial.println("Measure: TVOC=" + String(sensor->measure.TVOC) + ", eCO2=" + String(sensor->measure.eCO2));
  ble->write(String(sensor->measure.TVOC) + "##" + String(sensor->measure.eCO2));
  delay(1500);
  counter++;
}