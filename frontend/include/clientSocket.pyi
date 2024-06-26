import socket as sc
from socket import AddressFamily, SocketType
from typing import Literal

IP: str
PUERTO: int
TIPO_SC: AddressFamily
PROTO_SC: SocketType


class ClientSocket(sc.socket):
    def __init__(self) -> None:
        """
        Inicializa el socket del cliente
        """
    def enviar_mensaje(self, mensaje: str) -> None: ...
    def cerrar(self) -> None: ...
    def __del__(self) -> None: ...
