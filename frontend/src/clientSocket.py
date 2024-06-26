import socket as sc

IP = '127.0.0.1'
PUERTO = 8080
TIPO_SC = sc.AF_INET
PROTO_SC = sc.SOCK_STREAM

class ClientSocket(sc.socket):
    def __init__(self):
        # Crear un socket TCP/IP
        super().__init__(TIPO_SC, PROTO_SC)
        self.connect((IP, PUERTO))

    def enviar_mensaje(self, mensaje):
        try:
            # Enviar el mensaje al servidor
            self.sendall(mensaje.encode())

            # Esperar la respuesta del servidor1
            response = self.recv(1024)
            print(f'Respuesta del servidor: {response.decode()}')
        
        except sc.error as e:
            # Cerrar la conexion y dar alerta de error
            print(f'Error: {e}')
            self.cerrar()
        except UnicodeEncodeError as e:
            # Capturar errores de codificación
            print(f'Error de codificación: {e}')
            self.cerrar()
        except Exception as e:
            # Capturar cualquier otro error
            print(f'Error inesperado: {e}')
            self.cerrar()

    def cerrar(self):
        # Cerrar la conexión
        self.close()

"""

c_socket = sc.socket(sc.AF_INET, sc.SOCK_STREAM)

server_socket = ('127.0.0.1', 8080)

c_socket.connect(server_socket)

try:
    mes = "Holi desde py :3"

    c_socket.sendall(mes.encode())

finally:
    c_socket.close()
"""