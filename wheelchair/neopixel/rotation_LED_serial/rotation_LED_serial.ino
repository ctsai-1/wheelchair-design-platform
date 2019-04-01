// In this example, the vibration motor is increasing speed up to max speed, then
// decreases to half speed before starting increasing  again

// Lets make our vibration example, using PWM!
// Careful, here we have to use a pin that can be used for pwm.
#include <Adafruit_NeoPixel.h>
 
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
int i = 127;       // Our counter for PWM, we declare it globally,
// So it lasts for the duration of the entire program.
// It starts in 127 since the vibration motor starts
// working from around 2 volts (so we start at 2.5v)

bool increase = true;
bool vibration_enabled = false;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void vibration_pattern() {
  if (increase) {
    i += 1; // incrementing the power of the vibration motor
  } else {
    i -= 1;
  }

  if ( i > 16) {
    increase = false;
  } else if ( i < 1) {
    increase = true;
  }
}

void loop() {
  char command = Serial.read();
  if (command == '1') {
    Serial.println("Turning on Vibration...");
    vibration_enabled = true;
  } else if (command == '0') {
    Serial.println("Turning off Vibration...");
    vibration_enabled = false;
    strip.setPixelColor(i, 0, 0, 0);
    strip.show(); //maybe strip.clear 
    
    //analogWrite(VIB_PIN, 0);//replace with led off 
  }
  if (vibration_enabled) {
    vibration_pattern();
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    //analogWrite(VIB_PIN, i);//replace with led on 
  }
  delay(50);
}
