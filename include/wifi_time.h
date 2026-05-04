//
// Created by wppuq on 2026/5/4.
//

#ifndef INKPAPERREADER_WIFI_H
#define INKPAPERREADER_WIFI_H

#include "WiFi.h"
#include "secret.h"
#include "struct.h"

#define WIFI_CONNECTING_TIMEOUT 5

static uni_err_t init_wifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password);
    const unsigned long time_count = millis();
    unsigned long time_passed = 0;
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED || time_passed > WIFI_CONNECTING_TIMEOUT * 1000) {
        time_passed = millis() - time_count;
        Serial.print(".");
    }
    Serial.println();
    if (WiFi.status() == WL_CONNECTED) {
        state.wifi = true;
        Serial.println("Wifi Connected!");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        return SUCCESSFUL;
    }
    Serial.println("Fail to connect");
    return CAN_NOT_FOUND_WIFI;
}



#endif //INKPAPERREADER_WIFI_H
