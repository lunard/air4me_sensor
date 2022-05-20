#include "BLEManager.h"

class MyServerCallbacks : public BLEServerCallbacks
{

public:
    connectionCallback *cb;

    MyServerCallbacks(connectionCallback *callback)
    {
        cb = callback;
    }

    void onConnect(BLEServer *pServer)
    {
        cb(true);
    };

    void onDisconnect(BLEServer *pServer)
    {
        cb(false);
    }
};

class MyCallbacks : public BLECharacteristicCallbacks
{
    void onRead(BLECharacteristic *pCharacteristic)
    {
        Serial.println("onRead");
    }

    void onWrite(BLECharacteristic *pCharacteristic)
    {

        std::string value = pCharacteristic->getValue();
        Serial.println("BLE read: " + String(value.c_str()));
    }
};

void BLEManager::begin(String btDeviceName, connectionCallback *callback)
{
    BLEDevice::init(btDeviceName.c_str());

    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks(callback));

    pService = pServer->createService(SERVICE_UUID);

    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY |
            BLECharacteristic::PROPERTY_INDICATE);

    BLEDescriptor *pDescriptor = new BLE2902(); // Client Characteristic Configuration
    pDescriptor->setValue("air4me - air quality");
    pCharacteristic->setNotifyProperty(true);
    pCharacteristic->setCallbacks(new MyCallbacks());
    pCharacteristic->addDescriptor(pDescriptor);
}

void BLEManager::start()
{
    pService->start();
    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}

void BLEManager::write(String message)
{
    pCharacteristic->setValue(message.c_str());
    pCharacteristic->notify();
}