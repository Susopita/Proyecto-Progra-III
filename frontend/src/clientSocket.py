from inspect import Traceback
import socket as sc
from socket import AddressFamily, SocketKind
from typing import Self
import mensajes_pb2
import struct
import time

class ClientSocket():
    def __init__(self, IP: str, PUERTO: int, FAMILY_SC: AddressFamily=AddressFamily.AF_INET, TIPO_SC: SocketKind=SocketKind.SOCK_STREAM):
        self.client_socket: sc.socket
        self.address = IP
        self.port = PUERTO
        self.domain_sc = FAMILY_SC
        self.tipo_sc = TIPO_SC
        print('Conexión creada')


    def __enter__(self) -> Self:
        self.client_socket = sc.socket(self.domain_sc, self.tipo_sc)
        self.client_socket.connect((self.address, self.port))
        print('Conexión establecida')
        return self


    def __exit__(self, exc_type, exc_value, traceback):

        print(f"Cerrando la conexión a {self.address}:{self.port}")

        if self.client_socket:
            try:    
                self.client_socket.close()
                print("Socket cerrado con éxito")

            except Exception as e:
                print(f"Se produjo una excepción al cerrar el socket: {e}")
                self._log_exception(e)
                self._cleanup_resources()
                self._retry_close()

        # Manejo de excepciones en el bloque with
        if exc_type:
            print(f"Se produjo una excepción: {exc_value}")
            print(traceback)
            return False


    def _log_exception(self, exception):
        with open('client_socket_errors.log', 'a') as log_file:
            log_file.write(f"Error al cerrar el socket: {exception}\n")


    def _cleanup_resources(self):
        # Realizar cualquier limpieza adicional necesaria aquí
        print("Limpiando recursos adicionales")


    def _retry_close(self):
        try:
            print("Reintentando cerrar el socket . . .")
            time.sleep(1)  # Esperar brevemente antes de reintentar
            self.client_socket.close()
            print("Socket cerrado con éxito")
        except Exception as e:
            print(f"Fallo al reintentar cerrar el socket: {e}")


    def _protocolo_enviar_mensaje(self, mensaje_serializado):
        try:
            msj_size = len(mensaje_serializado)
            packed_length = struct.pack('!I', msj_size)
            self.client_socket.sendall(packed_length + mensaje_serializado)
            return True
        except Exception as e:
            print("Error al enviar mensaje: {e}")
            return False


    def _protocolo_recibir_mensaje(self):
        packed_length = self.client_socket.recv(4)
        if not packed_length:
            return None
        message_length = struct.unpack('!I', packed_length)[0]
        serialized_message = b''
        while len(serialized_message) < message_length:
            chunk = self.client_socket.recv(message_length - len(serialized_message))
            if not chunk:
                return None
            serialized_message += chunk

        return serialized_message


    def enviar_solicitud_busqueda(self, buscar):
        solicitud = mensajes_pb2.Busqueda(texto=buscar)
        return self._protocolo_enviar_mensaje(solicitud.SerializeToString())

    def confirmacion_backend(self):
        confirmacion_bytes = self._protocolo_recibir_mensaje()
        confirmacion = mensajes_pb2.conexion()
        confirmacion.ParseFromString(confirmacion_bytes)
        return confirmacion.estado
    
    def enviar_estado(self, estado):
        estado = mensajes_pb2.conexion(estado=estado)
        return self._protocolo_enviar_mensaje(estado.SerializeToString())
    
    def recibir_resultados_busqueda(self):
        try:
            resultado = self._protocolo_recibir_mensaje()
            resultado_busqueda = mensajes_pb2.Resultado_Busqueda()
            resultado_busqueda.ParseFromString(resultado)
            if resultado_busqueda:   
                resultado_list = []
                for pelicula in resultado_busqueda.peliculas:
                    pelicula_dict = {
                        'titulo': pelicula.titulo,
                        'tag': pelicula.tag,
                        'sinopsis': pelicula.sinopsis
                    }
                    resultado_list.append(pelicula_dict)
                return resultado_list
        except Exception as e:
            print("Error al recibir resultados: {e}")
            raise e

