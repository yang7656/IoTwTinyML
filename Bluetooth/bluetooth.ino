// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_Sensor.h>

// This #include statement was automatically added by the Particle IDE.
#include <DHT.h>

// This #include statement was automatically added by the Particle IDE.
#include <DiagnosticsHelperRK.h>

SYSTEM_THREAD(ENABLED);

const unsigned long UPDATE_INTERVAL = 2000;
unsigned long lastUpdate = 0;
double currentLightLevel;
int temp;
int humidity;

#define DHTPIN 2     // DHT22连接的数字引脚
#define DHTTYPE DHT22   // DHT22型号
DHT dht(DHTPIN, DHTTYPE);

// Private battery and power service UUID
const BleUuid serviceUuid("5c1b9a0d-b5be-4a40-8f7a-66b36d0a5176"); // CHANGE ME

BleCharacteristic uptimeCharacteristic("uptime", BleCharacteristicProperty::NOTIFY, BleUuid("fdcf4a3f-3fed-4ed2-84e6-04bbb9ae04d4"), serviceUuid);
BleCharacteristic signalStrengthCharacteristic("strength", BleCharacteristicProperty::NOTIFY, BleUuid("cc97c20c-5822-4800-ade5-1f661d2133ee"), serviceUuid);
BleCharacteristic freeMemoryCharacteristic("freeMemory", BleCharacteristicProperty::NOTIFY, BleUuid("d2b26bf3-9792-42fc-9e8a-41f6107df04c"), serviceUuid);

void configureBLE()
{
    BLE.addCharacteristic(uptimeCharacteristic);
    BLE.addCharacteristic(signalStrengthCharacteristic);
    BLE.addCharacteristic(freeMemoryCharacteristic);
    
    BleAdvertisingData advData;
    
    // Advertise our private service only
    advData.appendServiceUUID(serviceUuid);
    
    // Continuously advertise when not connected
    BLE.advertise(&advData);
}

void setup() {
    dht.begin();
    configureBLE();
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - lastUpdate >= UPDATE_INTERVAL)
    {
        lastUpdate = millis();
    
        temp = (int)dht.readTemperature();
        humidity = (int)dht.readHumidity();
        
        Serial.printlnf("Temp: %f", temp);
        Serial.printlnf("Humidity: %f", humidity);
        
        double lightAnalogVal = analogRead(A0);
        currentLightLevel = map(lightAnalogVal, 0.0, 4095.0, 0.0, 100.0);
        
        if (currentLightLevel > 50)
        {
            Particle.publish("light-meter/level", String(currentLightLevel), PRIVATE);
        }
    }
    
    if (BLE.connected())
    {
        uint8_t uptime = (uint8_t)DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_UPTIME);
        uptimeCharacteristic.setValue(uptime);
        
        uint8_t signalStrength = (uint8_t)(DiagnosticsHelper::getValue(DIAG_ID_NETWORK_SIGNAL_STRENGTH) >> 8);
        signalStrengthCharacteristic.setValue(signalStrength);
        
        int32_t usedRAM = DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_USED_RAM);
        int32_t totalRAM = DiagnosticsHelper::getValue(DIAG_ID_SYSTEM_TOTAL_RAM);
        int32_t freeMem = (totalRAM - usedRAM);
        freeMemoryCharacteristic.setValue(freeMem);
    }
}