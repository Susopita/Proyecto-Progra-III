import socket

c_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket = ('127.0.0.1', 8080)

c_socket.connect(server_socket)

try:
    mes = "Holi desde py :3"

    c_socket.sendall(mes.encode())

finally:
    c_socket.close()