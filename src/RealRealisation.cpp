//
// Created by Ivan Bondaruk on 11/9/2023.
//

#define SENSOR_PIN 0 // Arduino pin

#include <Arduino.h>
#include "DallasTemperature.h"

double value; // variable to store temperature

OneWire oneWire(SENSOR_PIN); // Set up a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature.

void setup() {
    Serial.begin(9600);
    sensors.begin(); // Start up the library
}

void loop() {
    sensors.requestTemperatures(); // request temperature value from sensor
    value = sensors.getTempCByIndex(0); // Get temperature value by Celsius and put it in variable

    Serial.println(value); // Printing temperature value from variable to COM port

    if(value >= 45)
    {
        Serial.println("Too hot!");
    }
    else
    {
        Serial.println("Temperature is OK!");
    }

    delay(1000); // delay for 1 second. 1 sec = 1000ms.
}