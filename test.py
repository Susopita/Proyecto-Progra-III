import sys
import os

# Ruta a archivos fuente python
ruta_src = os.path.abspath(os.path.join(__file__, '..', 'frontend', 'src'))

sys.path.append(ruta_src)

from clientSocket import ClientSocket # type: ignore
from socket import AF_INET, SOCK_STREAM

IP = '127.0.0.1'
PUERTO = 8080
FAMILIA_SC = AF_INET # Dominio: IPv4 
TIPO_SC = SOCK_STREAM

clientemini = ClientSocket(IP,PUERTO,FAMILIA_SC,TIPO_SC)

with clientemini as xd:
    clientemini.confirmacion_backend()
    msj = ""
    clientemini.enviar_solicitud_busqueda(msj)