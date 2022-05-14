#ifndef __BLE_MANAGER_H__
#define __BLE_MANAGER_H__

#include <Arduino.h>
#include <M5StickCPlus.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#define SERVICE_UUID "06538008-d393-11ec-9d64-0242ac120002"
#define CHARACTERISTIC_UUID "105fce30-d393-11ec-9d64-0242ac120002"

typedef void(connectionCallback)(boolean bleConnected);

class BLEManager
{
public:
    void begin(String btDeviceName, connectionCallback *callback);
    void start();
    void write(String message);

private:
    BLEServer *pServer = NULL;
    BLEService *pService = NULL;
    BLECharacteristic *pCharacteristic = NULL;
};

#endif