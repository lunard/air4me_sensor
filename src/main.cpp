#include <Arduino.h>
#include <M5StickCPlus.h>
#include "BLEManager/BLEManager.h"

BLEManager *ble;

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

  M5.Lcd.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("starting..");
  Serial.println("starting..");

  ble = new BLEManager();
  ble->begin("air4me", bleConnectionCallback);
  ble->start();

  ble->write("0"); // need to be discoverable
}

int counter = 0;
void loop()
{
  ble->write("Test value:" + String(counter));
  delay(1000);
  counter++;
}