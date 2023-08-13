# README

# esp8266连接阿里云物联网平台

![](https://img.shields.io/badge/star-welcome!-red)
![](https://img.shields.io/badge/%20welcome_to_pull_your_requests!-8A2BE2)

采用platformio进行开发，使用arduino框架，esp8266+dht11，进行温湿度上传报告阿里云物联网平台。

## 硬件部分

以esp8266为主要控制器，dht11为温湿度采集器，将dht11收集到的温湿度信息传给esp8266，esp8266在链接WiFi后，上报给阿里云IOT平台。

![esp8266引脚图](README%20429caba87ef6437f8b7dc8374ee5b969/Untitled.png)

esp8266引脚图

## 软件部分

- 使用platformio，利用Arduino框架开发

![platformio](README%20429caba87ef6437f8b7dc8374ee5b969/Untitled%201.png)

platformio

- 将从dht11采集到的温湿度数据采集后，封装为JSON格式，通过加密后传给阿里云IOT平台

![dht11温湿度采集模块](README%20429caba87ef6437f8b7dc8374ee5b969/Untitled%202.png)

dht11温湿度采集模块

### lib-deps

Crypto·········································Arduino的加密库

ArduinoJson································Arduino的Json格式库

arduino-aliyun-iot-sdk-0.4·········Arduino的阿里云iot开发包

PubSubClient-2.7.0·····················MQTT协议订阅分发机制库，用于client上报消息

## 运行结果

在vscode的platformio进行编译后烧录，查看运行结果，可以发现，成功上传温湿度数据。

![本地运行结果](README%20429caba87ef6437f8b7dc8374ee5b969/Untitled%203.png)

本地运行结果

登录阿里云IOT平台，将设备绑定后，烧录运行，可以发现，数据已经可以正常上传到平台，数据显示正常。

![阿里云iot平台运行结果](README%20429caba87ef6437f8b7dc8374ee5b969/Untitled%204.png)

阿里云iot平台运行结果
