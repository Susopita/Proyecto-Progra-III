import socket as sc
from socket import AddressFamily, SocketType

IP = '127.0.0.1'
PUERTO = 8080
TIPO_SC = sc.AF_INET
PROTO_SC = sc.SOCK_STREAM

class ClientSocket(sc.socket):
    def __init__(self):
        super().__init__(TIPO_SC, PROTO_SC)
        self.connect((IP, PUERTO))

    def enviar_mensaje(self, mensaje):
        try:
            self.sendall(mensaje.encode())
            response = self.recv(1024)
            print(f'Respuesta del servidor: {response.decode()}')
        except sc.error as e:
            print(f'Error: {e}')
            self.cerrar()
        except UnicodeEncodeError as e:
            print(f'Error de codificación: {e}')
            self.cerrar()
        except Exception as e:
            print(f'Error inesperado: {e}')
            self.cerrar()

    def cerrar(self):
        self.close()

# Decorator
class ClientSocketDecorator:
    def __init__(self, client_socket):
        self._client_socket = client_socket

    def enviar_mensaje(self, mensaje):
        mensaje_comprimido = self._comprimir(mensaje)
        self._client_socket.enviar_mensaje(mensaje_comprimido)

    def cerrar(self):
        self._client_socket.cerrar()

    def _comprimir(self, mensaje):
        return mensaje.replace(" ", "")

# Uso del decorator
if __name__ == "__main__":
    client_socket = ClientSocket()
    decorator = ClientSocketDecorator(client_socket)
    decorator.enviar_mensaje("Mensaje de prueba con compresión")
