import socket



HOST = "10.20.0.197"
PORT = 6668

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b'{"Tweet Type":"Service call","Thing ID":"G1_thing","Space ID":"G1_smart_space","Service Name":"pulse_led","Service Inputs":"(1000)"}')
    data = s.recv(1024)

print(f"Received {data!r}")