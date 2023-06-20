/*
 * @FilePath: \MAgIC-Fish\udp\udp.ino
 * @Date: 2023-03-20 20:31:31
 * @LastEditTime: 2023-03-21 19:38:46
 * @LastEditors: Xiaozhu Lin
 * @E-Mail: linxzh@shanghaitech.edu.cn
 * @Institution: MAgIC Lab, ShanghaiTech University, China
 */

#include <WiFi.h>
#include <AsyncUDP.h>

// WIFI related params
const char *ssid = "MAgIC_Fish_Project";
const char *password = "123456789";

// UDP related params
AsyncUDP udp;
unsigned int localUdpPort = 2333;
// 192.168.1.103

void setup()
{
    Serial.begin(115200);
    Serial.println();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (!WiFi.isConnected())
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());

    while (!udp.listen(localUdpPort));
    udp.onPacket(onPacketCallBack);

    pinMode(12, OUTPUT);
    digitalWrite(12, LOW);
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
}

void loop()
{
    Serial.println("I am alive!");
    delay(1000);
}

void onPacketCallBack(AsyncUDPPacket packet)
{
    digitalWrite(12, !digitalRead(12));
}