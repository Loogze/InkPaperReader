
#ifndef INKPAPERREADER_INIT_H
#define INKPAPERREADER_INIT_H

#include "struct.h"

const unsigned int Serial_band = 115200 ;

static uni_err_t init_GPIO() {
    pinMode(board_Statis_LED,OUTPUT);
    pinMode();
    return SUCCESSFUL;
}

static uni_err_t init_serial() {
    Serial.begin(Serial_band);
    Serial.println("Hello world,Serial success init");
    return SUCCESSFUL;
}

#endif //INKPAPERREADER_INIT_H
