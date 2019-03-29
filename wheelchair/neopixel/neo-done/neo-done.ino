#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_NeoPixel.h>
 
 
/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (10)
#define  PIN 6
Adafruit_BNO055 bno = Adafruit_BNO055();
 
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

int x;
int bright = 255;
unsigned long time;
 
void setup(void) {
  Serial.begin(9600);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");
 
  ring.begin();
 
  ring.show(); // Initialize all pixels to 'off'

  ring.setBrightness(bright); 
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
 
  delay(1000);
 
  bno.setExtCrystalUse(true);
 
  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
 
  ring.begin();
 
  ring.show(); // Initialize all pixels to 'off'

  ring.setBrightness(bright); 

}
 
/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void) {
    /* Get a new sensor event */
    sensors_event_t event;
    bno.getEvent(&event);
    x = event.orientation.x;
 
    /* Display the floating point data X*/
    Serial.print("\tX: ");
    Serial.println(x);
 
    if(abs(x) > 1 and abs(x) < 30){
      time = millis();      
       {
        ring.setPixelColor(1, 0, 0, 255);
      }
      ring.show();
    }
else{
     ring.clear();
}
      if(abs(x) > 31 and abs(x) < 60){
      time = millis();      
       {
        ring.setPixelColor(2, 0, 0, 255);
      }
      ring.show();

    }

      if(abs(x) > 61 and abs(x) < 90){
      time = millis();      
       {
        ring.setPixelColor(3, 0, 0, 255);
      }
      ring.show();

    }

      if(abs(x) > 91 and abs(x) < 120){
      time = millis();      
       {
        ring.setPixelColor(4, 0, 0, 255);
      }
      ring.show();

    }

      if(abs(x) > 121 and abs(x) < 150){
      time = millis();      
       {
        ring.setPixelColor(5, 0, 0, 255);
      }
      ring.show();

    }    

      if(abs(x) > 151 and abs(x) < 180){
      time = millis();      
       {
        ring.setPixelColor(6, 0, 0, 255);
      }
      ring.show();

    }    


      if(abs(x) > 181 and abs(x) < 210){
      time = millis();      
       {
        ring.setPixelColor(7, 0, 0, 255);
      }
      ring.show();

    }       

          if(abs(x) > 211 and abs(x) < 240){
      time = millis();      
       {
        ring.setPixelColor(8, 0, 0, 255);
      }
      ring.show();

    }  

    if(abs(x) > 241 and abs(x) < 270){
      time = millis();      
       {
        ring.setPixelColor(9, 0, 0, 255);
      }
      ring.show();

    }  

        if(abs(x) > 271 and abs(x) < 300){
      time = millis();      
       {
        ring.setPixelColor(10, 0, 0, 255);
      }
      ring.show();

    }  

        if(abs(x) > 301 and abs(x) < 330){
      time = millis();      
       {
        ring.setPixelColor(11, 0, 0, 255);
      }
      ring.show();

    }     

        if(abs(x) > 331 and abs(x) < 359){
      time = millis();      
       {
        ring.setPixelColor(12, 0, 0, 255);
      }
      ring.show();

    }      
else{
     ring.show();
}
 
  delay(BNO055_SAMPLERATE_DELAY_MS);
}
