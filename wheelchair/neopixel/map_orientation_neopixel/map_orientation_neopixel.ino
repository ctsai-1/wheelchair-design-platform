#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_NeoPixel.h>
#define BNO055_SAMPLERATE_DELAY_MS (10)
#define  PIN 6
Adafruit_BNO055 bno = Adafruit_BNO055();

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
int x;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
  delay(1000);
  bno.setExtCrystalUse(true);
  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
}

void loop(void) {
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);
  x = event.orientation.x;

  /* Display the floating point data X*/
  Serial.print("\tX: ");
  Serial.println(x);
  uint16_t i = map (x, 0, 361, 0, 16);
  strip.setPixelColor(i, 0, 0, 255);
  strip.show();
  delay(10);

  uint16_t j = map (x, 361, 0, 16, 0);
  strip.setPixelColor(j, 0, 0, 255);
  strip.clear();
  delay(10);

  delay(BNO055_SAMPLERATE_DELAY_MS);
}
