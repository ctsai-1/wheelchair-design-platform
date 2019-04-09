# The EDU Wheelchair: a connected wheelchair for museum exhibition

by Dario Sapienza and Samira Miccolis
sdf

# project description:
The EDU wheelchair is a connected wheelchair specifically designed for museum context in order to enhance the experience of visiting a museum exhibition for everyone, both disabled people and not.
As guides do, the connected wheelchair will lead the visitors through the works of art by following different paths, according to visitors’ moods and the museum visitors’ preferences database.
Each wheelchair is equipped with heart rate sensor to detect the mood state of the visitor throughout the visiting experience and pressure sensors on the back of the chair to register when the visitor is bored or interested to the exhibition contents.
The data collected by the devices, will be used either by the museum to improve the overall visiting experience and by the internal processor to learn about user preferences and adjust the visiting flow.

# List of sensors:
-	GPS sensor (beacon for indoor use) tracks the position of the user in the space
-	Gyroscope knows the orientation of the wheelchair
-	(2) pressure sensor, placed on the back of the chair can recognize relaxed or interested posture
-	Heart rate sensor can detect the “emotional” reaction of a person to a work of art.
- Proximity sensor can detect when the wheelchair is too close to an obstacle, like an artiwork, preventing damages
- Clock sensor to register how much time a visitor spends in front of a specific artwork and in general inside the museum
#List of actuators:
- Neopixel leds can replace a display interface and simulate a smart compass based on the info from GPS sensor and Gyroscope
- Speaker to reproduce the guided tour according to the position of the wheelchair
- Buttons to call for help and to control the reproduction of the guided tour
# We are not sure if the sensors we identified are the ones needed for the implementation of our idea so we would like to discuss that with you before buying unnecessary components.

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


![IoT1 Exhibition](/docs/workshops/images/iot1_exhibition.jpg)
![IoT1 Exhibition](/docs/workshops/images/iot1_exhibition.jpg)

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

## Main Components

__**Disclaimer:**__ the design of this platform focuses on flexibility and
technology exploration rather than optimisation.

The main design includes a Raspberry Pi 3 and an Arduino Mega 2560 on the wheelchair frame.

The Arduino Mega is the micro-controller of the platform. Fixed on the main frame of the wheelchair,
it can collect data from sensors (e.g. force sensors, accelerometers), and trigger actions from actuators
(e.g. LEDs, vibration motors).

More on the Arduino Mega can be found [here](/docs/resources/arduino.md "Arduino resources").

Raspberry Pi is a small computer. It is also fixed to the main frame of the wheelchair,
where it can:
* interact with the Arduino Mega via USB to receive data and transmit commands;
* interact with the Internet to transmit commands and receive data;
* store data locally in files;
* run (machine learning) algorithms.

More on the Raspberry Pi can be found [here](/docs/resources/raspberrypi.md "Raspberry Pi resources").

These components fit together as shown on the following diagram. A large powerbank
powers the Raspberry Pi. The Arduino Mega communicates and receives power from the
Raspberry Pi via USB. A Feather (Arduino-like development board) on the wheel connects to
the Raspberry Pi via Bluetooth to sense and actuate from the wheel.

![Main Wheelchair components](/docs/workshops/images/wheechair-components.png)

## List of suggested components:

On the frame:

* 1 Raspberry Pi 3B;
* 1 SD card (Some come directly with NOOBS installed);
* 1 Arduino Mega;
* 1 Large power bank;
* 1 large breadboard;
* 1 USB cable A/micro (Powerbank to Raspberry Pi);
* 1 USB cable A/B (Raspberry Pi to Arduino Mega).

On the wheel:

* 1 Feather (Bluetooth enabled);
* 1 small power bank;
* 1 small breadboard;
* 1 USB cable A/B (power bank to Arduino Uno).


## Contact and Existing projects

* [The hiking wheelchair](https://github.com/cprecioso/wheelchair-design-platform)
* [The EDU wheelchair](https://github.com/ctsai-1/wheelchair-design-platform)
* [Weelchair tracking for basketball players](https://github.com/FabianIDE/wheelchair-design-platform)
* [Disco Wheelchair](https://github.com/MatthijsBrem/wheelchair-design-platform)
* [Wheelchair Madness 2222](https://github.com/pherkan/wheelchair-design-platform/tree/master/wheelchair)
* [Who is sitting?](https://github.com/Rosanfoppen/wheelchair-design-platform/tree/master/wheelchair)
* [Magic Wheelchair](https://github.com/Yuciena/wheelchair-design-platform)
* [Yoga Wheelchair](https://github.com/artgomad/wheelchair-design-platform)


Feel free to contact us at jacky@datacentricdesign.org. We welcome feedback, pull requests
or links to your project.
