// In this example, the vibration motor is increasing speed up to max speed, then
// decreases to half speed before starting increasing  again

// Lets make our vibration example, using PWM!

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_NeoPixel.h>
#define BNO055_SAMPLERATE_DELAY_MS (10)
#define  PIN 6
Adafruit_BNO055 bno = Adafruit_BNO055();

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

// int i = 127;       // Our counter for PWM, we declare it globally,
// So it lasts for the duration of the entire program.
// It starts in 127 since the vibration motor starts
// working from around 2 volts (so we start at 2.5v)
int i;
//bool led_increase = true;
bool led_enabled = false;
//int counter = 0;
int prevcommand = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

/*void led_pattern() {
  if (led_increase) {
    i += 10; // incrementing the power of the vibration motor
  } else {
    i -= 10;
  }

  if ( i > 255) {
    increase = false;
  } else if ( i < 127) {
    increase = true;
  }
  }*/

void loop() {
  char command = Serial.read();
  if (command == '1' & =! prevcommand) {
    i++;
    led_enabled = true;
    prevcommand = command;
  } else {
    Serial.println(".....");
    led_enabled = false;
  }

  if (led_enabled = true) {
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(10);
    led_enabled = false;

  }
  delay(50);
}
