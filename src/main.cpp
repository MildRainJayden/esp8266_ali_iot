#include <Arduino.h>

#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht;

#include <ESP8266WiFi.h>

static WiFiClient espClient;
#include <ArduinoJson.h>

#include "AliyunIoTSDK.h"
AliyunIoTSDK iot;

#define PRODUCT_KEY "h68r06vqp9I"
#define DEVICE_NAME "device1"
#define DEVICE_SECRET "b295a9097368fdcd33570f403cfda328"
#define REGION_ID "cn-shanghai"

// #define WIFI_SSID "Jayden's iPhone"
// #define WIFI_PASSWD "61nxvx47gs30Y"

#define WIFI_SSID "Wakanda2.4"
#define WIFI_PASSWD "WYJczTYChj29110"




void powerCallback(JsonVariant p);

void wifiInit(const char *ssid, const char *passphrase)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passphrase);
    WiFi.setAutoConnect (true);
    WiFi.setAutoReconnect (true);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("WiFi not Connect");
    }
    Serial.println("Connected to AP");
}

void setup()
{
    Serial.begin(115200);

    wifiInit(WIFI_SSID, WIFI_PASSWD);
    dht.setup(2, DHTesp::DHT11); // Connect DHT sensor to D4
    AliyunIoTSDK::begin(espClient, PRODUCT_KEY, DEVICE_NAME, DEVICE_SECRET, REGION_ID);

    // 绑定属性回调
    AliyunIoTSDK::bindData("PowerSwitch", powerCallback);
}

unsigned long lastMsMain = 0;
void loop()
{
    AliyunIoTSDK::loop();
    if (millis() - lastMsMain >= 2000)
    {
        lastMsMain = millis();
        // 发送事件到阿里云平台
        AliyunIoTSDK::sendEvent("xxx"); 
        // 发送模型属性到阿里云平台
        delay(dht.getMinimumSamplingPeriod());
        float humidity = dht.getHumidity();
        float temperature = dht.getTemperature();

        AliyunIoTSDK::send("Humidity", humidity);

        AliyunIoTSDK::send("temperature", temperature);
    }
}


void powerCallback(JsonVariant p)
{
    int PowerSwitch = p["PowerSwitch"];
    if (PowerSwitch == 1)
    {
        //
    }
    else
    {
        //
    }
}
