#include <NoDelay.h> // nidelay library to make a delay

const int l_Pin = A0;    // Analog pin for LM35 temperature sensor   

const int tempThreshold = 30;  // Temperature threshold in degrees Celsius

noDelay ledBlinkDelay1(250); // to make a delay of 250ms
noDelay ledBlinkDelay2(500); // to make a delay of 500ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(l_Pin);  // Read LM35 sensor value
  float voltage = (rawValue / 1024.0) * 5.0;  // adc value converted to analog value
  float temperatureC = (voltage - 0.5) * 100.0;  // Convert to temperature in °C 

  if (temperatureC < tempThreshold) {
    if (ledBlinkDelay1.update()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle onboard LED
    }
  } else {
    if (ledBlinkDelay2.update()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle onboard LED
    }
  }
}
