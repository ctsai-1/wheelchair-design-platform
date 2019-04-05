#!/usr/bin/env python3

# In this example, we connect to a GATT service 'rotation' on the wheel, sending
# the rotation count over time. When we reach the recommended number of rotation,
# we send a command to the Arduino to turn on the vibration motors.

# Import required library
import pygatt  # To access BLE GATT support
import signal  # To catch the Ctrl+C and end the program properly
import os  # To access environment variables
from dotenv import load_dotenv  # To load environment variables from .env file
import serial
import time
import math

# DCD Hub
from dcd.entities.thing import Thing
from dcd.entities.property import PropertyType

# The thing ID and access token
load_dotenv()
THING_ID = os.environ['THING_ID']
THING_TOKEN = os.environ['THING_TOKEN']
BLUETOOTH_DEVICE_MAC = os.environ['BLUETOOTH_DEVICE_MAC']

# UUID of the GATT characteristic to subscribe
GATT_CHARACTERISTIC_ROTATION = "02118733-4455-6677-8899-AABBCCDDEEFF"
# Many devices, e.g. Fitbit, use random addressing, this is required to connect.
ADDRESS_TYPE = pygatt.BLEAddressType.random

# Recommended number of rotation
#ROTVAL = 2
prev_val = 0
# Did we already vib
#vib = False

# Start reading the serial port
ser = serial.Serial(
    port = os.environ['SERIAL'],
    baudrate = 9600,
    timeout = 2)


def find_or_create(property_name, property):
    """Search a property by name, create it if not found, then return it."""
    if my_thing.find_property_by_name(property_name) is None:
        my_thing.create_property(name=property_name,
                                 property=property)
    return my_thing.find_property_by_name(property_name)


def handle_rotation_data(handle, value_bytes):
    """
    handle -- integer, characteristic read handle the data was received on
    value_bytes -- bytearray, the data returned in the notification
    """
    print("Received data: %s (handle %d)" % (str(value_bytes), handle))
    #rotation_values = [0, 0]
    rotation_values = [float(x) for x in value_bytes.decode('utf-8').split(",")]
    print("float data collected")
    find_or_create("Left Wheel Rotation",
                   PropertyType.TWO_DIMENSIONS).update_values(rotation_values)
    print("values sent to the hub")
    print(rotation_values[0])
    #print(rotation_values[1])

    rotation_values0 = math.floor(rotation_values[0])
    print(rotation_values0)


    global prev_val
    print(prev_val)
    if (prev_val == (rotation_values0 - 1)):
        print("1 ON ")
        ser.write('1'.encode())
    else:
        print("0 OFF ")
        #ser.write('0'.encode())
    prev_val = rotation_values0
    print(prev_val)
#        global vib
#        print("not vib yet %s" % str(vib))
#        vib = True
#        print("after nudge %s" % str(vib))


def keyboard_interrupt_handler(signal_num):
    """Make sure we close our program properly"""
    print("Exiting...".format(signal_num))
    left_wheel.unsubscribe(GATT_CHARACTERISTIC_ROTATION)
    exit(0)


# Instantiate a thing with its credential, then read its properties from the DCD Hub
my_thing = Thing(thing_id=THING_ID, token=THING_TOKEN)
my_thing.read()

# Start a BLE adapter
bleAdapter = pygatt.GATTToolBackend()
bleAdapter.start()

# Use the BLE adapter to connect to our device
left_wheel = bleAdapter.connect(BLUETOOTH_DEVICE_MAC, address_type=ADDRESS_TYPE)

# Subscribe to the GATT services
left_wheel.subscribe(GATT_CHARACTERISTIC_ROTATION, callback=handle_rotation_data)

# Register our Keyboard handler to exit
signal.signal(signal.SIGINT, keyboard_interrupt_handler)


# Read the next line from the serial port
# and update the property values
def serial_to_property_values():
    # Read one line
    line_bytes = ser.readline()
    # If the line is not empty
    if len(line_bytes) > 0:
        # Convert the bytes into string
        line = line_bytes.decode('utf-8')
        # Split the string using commas as separator, we get a list of strings
        values = line.split(',')
        # Use the first element of the list as property id
        property_id = values.pop(0)
        # Get the property from the thing
        prop = my_thing.properties[property_id]
        # If we find the property, we update the values (rest of the list)
        if prop is not None:
            prop.update_values([float(x) for x in values])
        # Otherwise, we show a warning
        else:
            print('Warning: unknown property ' + property_id)
    # Finally, we call this method again
    serial_to_property_values()


serial_to_property_values()
