#include <NoDelay.h> // nodelay library to create delays

const int l_Pin = A0;    // Analog pin for LM35 temperature sensor   

const int tempThreshold = 30;  // Temperature threshold in degrees Celsius

noDelay ledBlinkDelay1(250); // to make a delay of 250ms
noDelay ledBlinkDelay2(500); // to make a delay of 500ms

// setup function is used to initailize input and output ports
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // built in lead pin(13) to set as output
  Serial.begin(9600);  // baud rate 9600 to make communication
}

void loop() {
  int iValue = analogRead(l_Pin);  // Read LM35 sensor value
  float voltage = (iValue / 1024.0) * 5.0;  // adc value converted to analog value
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
