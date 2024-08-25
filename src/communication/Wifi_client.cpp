#include <Arduino.h>
#include <string.h>
#include <communication/Wifi_client.hpp>

#include <configs/Configs.hpp>

#include <WiFi.h>

Wifi_client::Wifi_client()
{
    Serial.println("Wifi_client : constructor");
}

boolean Wifi_client::connect()
{
    Serial.print("Wifi_client : connect to ");
    Serial.println(CODECRAFT_WIFI_SSID.c_str());
    WiFi.begin(CODECRAFT_WIFI_SSID.c_str(), CODECRAFT_WIFI_PASSWORD.c_str());

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("WiFi connected with IP :");
    Serial.println(WiFi.localIP());

    return true;
}

boolean Wifi_client::isConnected(){
    return WiFi.isConnected();
}
