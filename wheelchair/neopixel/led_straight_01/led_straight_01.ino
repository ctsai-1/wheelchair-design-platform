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
int counter;
//bool led_increase = true;
bool led_path = false;
bool led_way = false;
//int counter = 0;
int prevcommand = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50); //adjust brightness here
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
  if (command == '1' /*& =! prevcommand*/) {
    i++;
    counter++;
    led_path = true;
    prevcommand = command;
  } 
  
//  else {
//    led_path = false;
//  }

  if (led_path = true) {
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(10);
    if (i == 16) {
      i = 0;
    }
  }

  if (command == '0' /*& =! prevcommand*/) {
    led_path = false;
    strip.setPixelColor(i, 0, 0, 0);
    strip.clear();
    colorWipe(strip.Color(0, 255, 0), 60); // green
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 12; i < 16/*strip.numPixels()*/; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    strip.clear();
  }
}
