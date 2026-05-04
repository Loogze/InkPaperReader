//
// Created by Loogze on 2026/5/4.
//

#ifndef INKPAPERREADER_SENSER_H
#define INKPAPERREADER_SENSER_H

#include "struct.h"

#include <Wire.h>
#include <AHT20.h>
#include <Adafruit_BMP280.h>
#include <Ticker.h>

typedef struct aht20_struct {
    float temperature;
    float humidity;
}aht20_data_s;

aht20_data_s aht20_data;

typedef struct bmp280_struct {
    float temperature;
    float pressure;
    float altitude;
}bmp280_struct;

bmp280_struct bmp280_data;


AHT20 aht20;

Adafruit_BMP280 bmp;

Ticker senser_aht20_ticker;

Ticker senser_bmp280_ticker;

inline void aht20_interrupt() {
    aht20_data = {
        .temperature = aht20.getTemperature(),
        .humidity = aht20.getHumidity(),
    };
}

inline void bmp280_interrupt() {
    bmp280_data = {
        .temperature = bmp.readTemperature(),
        .pressure = bmp.readPressure(),
        .altitude = bmp.readAltitude(1013.25)
    };
}

static uni_err_t init_senser() {
    Wire.begin();
    state.aht20 = aht20.begin();
    if (state.aht20 == FAIL) {
        Serial.println("Fail to start AHT20");
        return FAIL_INIT_AHT20_SENSER;
    }
    senser_aht20_ticker.attach_ms(500,aht20_interrupt);

    state.bmp280 = bmp.begin();
    if (state.bmp280 == FAIL) {
        Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
        Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
        return FAIL_INIT_BMP280_SENSER;
    }
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                 Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                 Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                 Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                 Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
    senser_bmp280_ticker.attach_ms(500,bmp280_interrupt);
    return SUCCESSFUL;

}



#endif //INKPAPERREADER_SENSER_H
