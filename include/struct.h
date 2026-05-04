//
// Created by wppuq on 2026/4/3.
//

#ifndef INKPAPERREADER_STRUCT_H
#define INKPAPERREADER_STRUCT_H

typedef unsigned char pin_t;

struct pin_I2c {
    pin_t SDA ;
    pin_t SCA ;
}pin_I2c;

struct pin_SPI {
    pin_t WD = 0;
};

pin_t board_Statis_LED = 0;

enum uni_err_t {
    SUCCESSFUL,
    UNKNOWN_ERR,
    FAIL_INIT_WIFI,
    FAIL_INIT_TF_STORAGE,
    FAIL_INIT_AHT20_SENSER,
    FAIL_INIT_BMP280_SENSER,
    FAIL_INIT_SPI_CONNECTION,
    FAIL_CONNECT_WIFI,
    DRAW_FAIL,
    CAN_NOT_FOUND_WIFI,
    CAN_NOT_CONNECT_NETWORK,
};

typedef enum uni_err_t uni_err_t;


typedef struct statis_run {
    bool aht20;
    bool bmp280;
    bool wifi;
    bool network;
    bool tf_storage;
    bool spi;
    bool i2c;
}statis_run;

#define FAIL 0
#define SUCCESS 1

static statis_run state;


#endif //INKPAPERREADER_STRUCT_H
