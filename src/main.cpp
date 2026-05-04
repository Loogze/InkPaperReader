#include <Arduino.h>

#include "init.h"
#include "render.h"
#include "struct.h"
#include "senser.h"

void setup() {
    const unsigned long tick_start_init = millis();
    init_GPIO();
    init_senser();
    Serial.printf("Taking %lu",millis() - tick_start_init);
}

void loop() {


}