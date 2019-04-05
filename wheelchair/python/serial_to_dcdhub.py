# This example shows how to establish a connection
# with the DCD HUB using the credentials of a thing,
# and start reading the serial port to transfer the data.

# This is a typical case for a Python transferring data
# from an Arduino-like device.

# Import required library
from dotenv import load_dotenv
import os
import serial

from dcd.entities.thing import Thing
from dcd.entities.property import PropertyType

# The thing ID and access token
load_dotenv()
THING_ID = os.environ['THING_ID']
THING_TOKEN = os.environ['THING_TOKEN']

DATA_PROP_NAME = "frame_orientation-ab9e"

# Instantiate a thing with its credential
my_thing = Thing(thing_id=THING_ID, token=THING_TOKEN)

# We can read the details of our thing,
# i.e. retrieving its information from the hub
my_thing.read()

prop_data = my_thing.find_or_create_property(DATA_PROP_NAME, PropertyType.THREE_DIMENSIONS)


ser = serial.Serial(
    port = os.environ['SERIAL'],
    baudrate = 9600,
    timeout = 2)

# Read the next line from the serial port
# and update the property values
def serial_to_property_values():
    # Read one line
    line_bytes = ser.readline()
    # If the line is not empty
    if len(line_bytes) > 0:
        # Convert the bytes into string
        try:
            line = line_bytes.decode('utf-8')
        except UnicodeDecodeError:
            line = "0,0,0,0,0,0,0,0,0,0,0,0"
        # Split the string using commas as separator, we get a list of strings
        str_values = line.split(',')
        # Remove the first id
        str_values.pop(0)
        # Transform the array of string values into float values (numbers)
        values = [float(x) for x in str_values]

        # Update values of data and label properties (send them to the DCD Hub)
        # With the same timestamp, so we can easily connect label and raw data later

        prop_data.update_values(values)


    # Finally, we call this method again
    serial_to_property_values()

serial_to_property_values()
