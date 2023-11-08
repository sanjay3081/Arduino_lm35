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
  int iValue = analogRead(l_Pin);  /* Read LM35 sensor value. 
  The input value which we get from sensor is connected to analog reader.
  A0 pin will not directly give analog value. We get adc value from A0 pin*/
  float voltage = (iValue / 1024.0) * 5.0;  // in arduino, we are using 10 bit adc and 5V as board voltage.
  float temperatureC = (voltage - 0.5) * 100.0;  /* as the temp value for 0.5V is 0C so we are subtracting.
  and we are multipying it with 1000 to convert V to mV and as 1C temperature changes for 10mv so we divide it. */

  if (temperatureC < tempThreshold) { //if input temperature is less than 30C this condition will run
    if (ledBlinkDelay1.update()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle onboard LED
    }
  } else { // it is always assigned that the input temperature is always greater than 30C
    if (ledBlinkDelay2.update()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // Toggle onboard LED
    }
  }
}
