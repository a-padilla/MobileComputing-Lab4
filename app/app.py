import socket
import time


HOST = "10.20.0.197"
PORT = 6668

'''
read_button: 
    Returns if the button is currently being pressed.
    Inputs - None
    Output - int

read_button: 
    Returns if tilt sensor is inverted or not.
    Inputs - None
    Output - int (1 - Upright | 2 - Inverted)

pulse_buzzer:
    Pulses the buzzer for a certain amount of time described by input
    Input - time to buzz in ms
    Output - None

pulse_led:
    Pulses the led for a certain amount of time described by input
    Input - time to light led in ms
    Output - None

This script uses sockets to send requests to the Atlas. Each socket request includes various info
such as the tweet type, thing ID, space Id, and service name etc.... We then receive the data and
are able to print it out.
'''

# ================ Read Button ======================
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s: 
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"read_button","Service Inputs":"()"}')
    data = s.recv(1024)

print(f"\n Button reads: {data!r} \n") 

# Sleep to give time to press the button
print('You have 5 seconds before next request, press the button')
time.sleep(5)

# Read Button - again, but this time pressed
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s: 
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"read_button","Service Inputs":"()"}')
    data = s.recv(1024)

print(f"\n Button reads: {data!r} \n \n") 

# Sleep to give time for presentation
print('Done showing button service, switch to tilting service')
time.sleep(3)

# ================ Read Tilt Sensor when upright=================
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"read_tilt","Service Inputs":"()"}')
    data = s.recv(1024)

print(f"\n Tilt Orientation is {data!r} \n. Expected 1 for upright")

# Sleep to give time to change orientation
print('You have 5 seconds before next request, press the button')
time.sleep(5)

# ================ Read Tilt Sensor when inverted=================
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"read_tilt","Service Inputs":"()"}')
    data = s.recv(1024)

print(f"\n Tilt Orientation is {data!r} \n. Expected 0 for inverted.")

# Sleep to give time for presentation
print('Done showing tilting service, show pulsing services')
time.sleep(3)

# =================== Pulse Buzzer for 1 second ===================
# Returned data doesn't really matter, but we still print it out to show that we get a response back from the atlas device
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"pulse_buzzer","Service Inputs":"(1000)"}')
    data = s.recv(1024)

print(f"\n Received {data!r} \n")

# Sleep to give time between pulses
print('Sleeping to separate the buzzer pulses')
time.sleep(3)

# =================== Pulse Buzzer for 5 second ===================
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"pulse_buzzer","Service Inputs":"(5000)"}')
    data = s.recv(1024)

print(f"\n Received {data!r} \n")
print('Now pulsing LED')

# =================== Pulse LED for 1 second ===================
# Returned data doesn't really matter, but we still print it out to show that we get a response back from the atlas device
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"pulse_led","Service Inputs":"(1000)"}')
    data = s.recv(1024)

print(f"\n Received {data!r} \n")

# Sleep to give time between pulses
print('Pause to separate LED Pulses')
time.sleep(3)

# =================== Pulse LED for 5 second ===================
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"pulse_led","Service Inputs":"(5000)"}')
    data = s.recv(1024)

print(f"\n Received {data!r} \n")