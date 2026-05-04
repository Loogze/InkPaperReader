#include <Arduino.h>

#include "init.h"
#include "render.h"
#include "struct.h"
#include "senser.h"
#include "wifi_time.h"

void setup() {
    const unsigned long tick_start_init = millis();
    init_GPIO();
    init_senser();
    init_wifi();

    Serial.printf("Taking %lu\n",millis() - tick_start_init);
}

void loop() {


}