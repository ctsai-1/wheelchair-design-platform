# The EDU Wheelchair:
### a connected wheelchair for museum exhibition

by Dario Sapienza and Samira Miccolis

# concept description:
The EDU-wheelchair is a connected wheelchair specifically designed for museum context in order to enhance the experience of visiting a museum exhibition for everyone, both disabled people and not. As guides do, the connected wheelchair will lead the visitors through the works of art by following different paths, according to visitors’ moods and the museum visitors’ preferences database.
Each wheelchair will be equipped with Bluetooth Low Energy to retrieve the position from beacons located in the museum. A pressure sensor on the back of the chair will register when the visitor is bored (lean back) or interested (lean forward) to the exhibition contents. The data collected by the devices will be used either by the museum to improve the overall visiting experience and by the internal processor to learn about user preferences and adjust the visiting flow.

## Main functions of the concept

* Triangulate the position of the wheelchair through BLE connection (beacons) installed inside the museum.

 ![Triangulate the position](/wheelchair/images/triangulateposition.png)

* Guide the visitors with a smart compass and give information via audio.

 ![Triangulate the position](/wheelchair/images/smartcompass.png)

* Detect the reaction of the users in front of an artwork by detecting the posture on the wheelchair.

 ![Triangulate the position](/wheelchair/images/pressuresensor.png)

## List of sensors for the concept:
 __**Sensors**__
* __**BNO055 9axis Abs**__ - Gets the orientation of the wheelchair and the rotations of the left wheel.
* __**Force sensing resistor (FSR)**__ - Monitor the reaction of user in front of the artwork by sensing the force applied on the back of the wheelchair.

 __**Actuators**__
* __**Speakers**__ - Plays an audio tour according to the position of the user in the exhibition.
* __**Neopixel ring x 16**__ - Indicates the distance traveled by the users and shows the direction that they need to follow.

 __**Other**__
* __**Feather BLE board**__ - Receives the bluetooth low frequency signals from the beacons placed in the museum.




Wheelchair Design Platform is a repository that contains some resources to help
designers and developers speak the same language, and work together towards
addressing relevant challenges for wheelchair users. It is a collection of
workshop materials, code examples and also a compilation of resources to foster
a prospering research and design community around wheelchair users.


![EDUchair1](/wheelchair/images/EDUchair1.jpg)

## Workshops

* [Getting started](/docs/workshops/GettingStarted.md)
* [Workshop 1: Building an Internet-Connected Wheelchair](/docs/workshops/Workshop1.md)
* [Workshop 2: Integrating and Visualising Sensor-Based Data](/docs/workshops/Workshop2.md)
* [Workshop 3: Developing Algorithms and Controlling Actuators](/docs/workshops/Workshop3.md)
* [Workshop 4: Developing and Conducting a Data Collection Campaign](/docs/workshops/Workshop4.md)
* [Workshop 5: Implementing a Machine Learning Pipeline](/docs/workshops/Workshop5.md)
* [Workshop 6: Developing a Product Analytics Dashboard](/docs/workshops/Workshop6.md)

## Resources

* This platform uses two programming languages, Python on computers and C on
micro-controllers. While descriptions and examples of code should help you
get started, you can find some additional resources
[here](/docs/resources/software.md "Python and C resources").

* Documentation of your project is key,
[here are some tips and examples](/docs/resources/documentation.md "Documentation tips and examples").

* [Git manipulation such as Pull Request](/docs/resources/git.md "Git manipulation").

## Prototype description

The working prototype is an iterative step towards the final concept.
Several experimentations were conducted as preparation to work with more complex components such as beacons. The BNO055 9 axis absolute sensor has been used to perform a rough motion traking of the wheelchair within a preset path.
The first attempt included using the 9 axis absolute sensor, placed on the frame of the wheelchair, to detect the linear acceleration of the wheelchair while moving. This data, together with the length of the movement allows to calculate the distance travelled. This could have been used in the context of a pre-set path to set a threeshold as trigger for the actuators.
However, the instability of the acceleration values made the outcome calcultion unrealiable.
Therefore, the sensor was connected to a Feather BLE board and moved to the right wheel. The presence of the feather allows the use of the sensor to detects rotations without the cables constraints and to send the data via BLE to the Rasperry. Being more reliable, this data can be used to display the motion on a neopixel ring placed on the armrest of the wheelchair.

## Main Components

The main design includes a Raspberry Pi 3, an Arduino Mega 2560 on the wheelchair frame and a Feather BLE board (bluetooth enabled) on the right wheel.

The Arduino Mega is the micro-controller of the platform. Fixed on the main frame of the wheelchair,
it gets data from the Raspberry Pi via serial connection and triggers a Neopixel ring x 16.

The Raspberry Pi, attached to the main frame, is used as microprocessor. In this project the functions of the Raspberry are:

* interact with the Feather BLE board through bluetooth connection and subscribes to the GATT caracteristic of rotation;
* interact with the Arduino Mega via USB to transmit commands;
* interact with the Internet to transmit commands and receive data;
* store data locally in files;

These is described in the following diagram:

![System architecture](/wheelchair/images/systemarchitecture.png)

## Main Components setup



## Prototype components

On the frame:

* 1 Raspberry Pi 3B;
* 1 SD card;
* 1 Arduino Mega;
* 1 Large power bank;
* 1 USB cable A/micro (Powerbank to Raspberry Pi);
* 1 USB cable A/B (Raspberry Pi to Arduino Mega).

On the wheel:

* 1 Feather (Bluetooth enabled);
* 1 small power bank;
* 1 small breadboard;
* 1 USB cable A/B (power bank to Arduino Uno).

On the armrest:

* 1 Neopixel ring x 16;


 __**Cloud server**__
the project is based on a cloud server, where the data collected are uploaded and stored. For this purpose the data centric design Hub prototype from Tu Delft has been used.
## Main Components setup
This project is based on the contents and dependencies provided with the GitHub repository of the Wheelchair Design Platform:
<a href="https://github.com/datacentricdesign/wheelchair-design-platform" target="_blank">https://github.com/datacentricdesign/wheelchair-design-platform</a>

In this case a fork of the repository has been used to experiment with changes without affecting the original project. A description of how to fork a repository can be found here: <a href="https://help.github.com/articles/fork-a-repo/" target="_blank">(GitHub Help)</a>

Inside the forked repository a new project have been created and cloned to have a local copy on our computers.

The text editor (IDE) used for the project was <a href="https://atom.io/" target="_blank">(Atom)</a>.
Use git commands to open to open the codes in your text editor and to manage it while working.

  #### Cloud server    
  The project is based on a cloud server, where the data collected are uploaded and stored. For this purpose the data centric design Hub prototype from Tu Delft has been used.


1. creates an account, by signing up to this link [DCD hub](https://dwd.tudelft.nl/auth/signin?login_challenge=c84123b9885e483daef1bb1d8c2f8186) with your e-mail address, name and password.
2. click on my thing button to create your THING and give it name. This will generate a thing id and an access token for your thing.
3. Copy and save this information, as they will enble the communication between the hub and the raspberry.

#### Raspberry Pi

1. at the root of your project folder, create a .env file and paste the following lines

       THING_ID = paste here the copied thing ID
       THING_TOKEN = paste here the copied thing token

2. as the code  

extract the SD card fromn the rasperry and create a .env file at the root of boot,

#### Arduino Mega
1. connect the Arduino Mega to the computer via serial

2. open the Arduino IDE

3. install the following libraries:

    Wire.h, Adafruit_Sensor.h, Adafruit_BNO055.h, utility/imumaths.h, Adafruit_NeoPixel.h

4. in the Arduino IDE, go in the top menu 'Tools > Boards', and select 'Arduino/Genuino Mega or Mega 2560'
5. check that the right serial port is selected in 'Tools > Port'

6. flash the Arduino code [(led_straight_01)](/wheelchair\final code\led_straight_01) to the Arduino Mega board





## Contact and Existing projects

* [The hiking wheelchair](https://github.com/cprecioso/wheelchair-design-platform)
* [The EDU wheelchair](https://github.com/ctsai-1/wheelchair-design-platform)
* [Weelchair tracking for basketball players](https://github.com/FabianIDE/wheelchair-design-platform)
* [Disco Wheelchair](https://github.com/MatthijsBrem/wheelchair-design-platform)
* [Wheelchair Madness 2222](https://github.com/pherkan/wheelchair-design-platform/tree/master/wheelchair)
* [Who is sitting?](https://github.com/Rosanfoppen/wheelchair-design-platform/tree/master/wheelchair)
* [Magic Wheelchair](https://github.com/Yuciena/wheelchair-design-platform)
* [Yoga Wheelchair](https://github.com/artgomad/wheelchair-design-platform)
