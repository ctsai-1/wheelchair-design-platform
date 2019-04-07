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

# Instantiate a thing with its credential
my_thing = Thing(thing_id=THING_ID, token=THING_TOKEN)

# We can read the details of our thing,
# i.e. retrieving its information from the hub
my_thing.read()

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

# Read the next line from the serial port
# and update the property values
def serial_to_property_values():
    # Read one line
    line_bytes = ser.readline()
    # If the line is not empty
    if len(line_bytes) > 0:
        print("serial data found")
        line = line_bytes.decode('utf-8')
        # Split the string using commas as separator, we get a list of strings
        serialvalues = line.split(',')

        try:
            # Use the first element of the list as property id
            # property_serial_id = values.pop(0)
            # Get the property from the thing
            find_or_create("frame-orientation-3888",
                           PropertyType.THREE_DIMENSIONS).update_values([float(x) for x in serialvalues])

        except:
            print('Could not parse: ' + line)
    else:
        print("UNCAZZO")
# Finally, we call this method again
    serial_to_property_values()

serial_to_property_values()
