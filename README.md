# The EDU Wheelchair:
### a connected wheelchair for museum exhibition

by Dario Sapienza and Samira Miccolis

<<<<<<< HEAD
>>>>>>> e


=======
>>>>>>> 1cbc10dfd580e111c1d1570eb2ad658a91eaeda8
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

#orientation sensor experiment (picture in slack)
We started from reviewing workshop 2 and tried to connect the sensor and the raspberry via Bluetooth. We encountered many problems in connecting the devices, and we reinstalled the raspberry requirements after pulling the updated version of material from GitHub. We finally managed to run the code on raspberry and we felt more confident on the understanding of the lines needed to talk with raspberry, to achieve that and to navigate through the folders.
Furthermore, we were able to send our values to the server and visualize them in grafana.
We explored all the Arduino examples given for the orientation sensor and after, visualizing the sensor behaviour in the serial plotter, we chose which one was more appropriate for the function we needed:  identifying the direction of the wheelchair on 1 axis.
On grafana we found out that the curves in the graphs show the different orientation of the wheelchair. From the starting position, if the user turns left the sensor will register an increase in the value. While if the user turns right there is a decrease in the value.
The peaks of the curves represent a completed rotation.


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
<<<<<<< HEAD
=======
## Prototype description
>>>>>>> bf5e165161bda46a56d2f938d117f31a89c47a7b

The working prototype is an iterative step towards the final concept.
To reach the complexity of working with advanced components, like the beacons, earlier experimentation were conducted.
The IMU 9 axixs absolute sensor was used to perform motion traking of the wheelchair within a preset path. In a first attempt the linear acceleration detected by the sensor placed on the wheelchair’s frame was used to calculate the distance.
Due to the instability of the outcome value, the sensor was moved to the right wheel and connected to a feather. This allows to detects rotations and send them via BLE to the Rasperry on the frame. Being more reliable, the data collected in this way can be used to display the motion on a neopixel placed on the armsert of the wheelchair.

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

On the frame:

* 1 Neopixel ring x 16;

# Wiring
