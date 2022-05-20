# air4me sensor

The project uses a M5StickC Plus micro-controller with an SGP30 sensor connected on the I2C bus
The internal BLT is used to expose and write an GATT characteristic.
Each N seconds, the TVOC and eCO2 sensor values are written in the characteristic and notified to the connected client (the Flutter app).

# Data sheets

https://docs.rs-online.com/f0a5/A700000008182629.pdf
https://files.seeedstudio.com/wiki/Grove-VOC_and_eCO2_Gas_Sensor-SGP30/res/Sensirion_Gas_Sensors_SGP30_Datasheet_EN.pdf
