AVISOS: Utilizar, por lo menos, 2 patrones de diseño diferentes. 

# Avances de Investigacion
: Esto fue creado para poner toda la teoria o informacion referente al proyecto para que los demas lo puedan ver. 

## Frontend

### Libreria Arcade


## Metodos de fusion de frontend y backend

***Sockets***
¿Cómo funcionan los sockets? La comunicación a través de sockets sigue un modelo cliente-servidor1:

Creación: Se crea un socket en el servidor que escucha en un puerto específico y un socket en el cliente que sabe a qué dirección y puerto conectarse.
Conexión inicial: El cliente inicia una solicitud de conexión al servidor. Si el servidor acepta, se establece una conexión.
Transferencia de datos: Los datos pueden ser enviados y recibidos en ambas direcciones a través de los sockets.
Cierre de la conexión: Una vez finalizada la comunicación, ambos lados pueden cerrar la conexión para liberar recursos.

Ejemplo de como se podria implementar un socket en la comunicacion servidor, cliente: 

- C++
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    int client_fd = accept(server_fd, (struct sockaddr *)NULL, NULL);
    // Aquí manejarías la comunicación con el cliente
    close(client_fd);
    close(server_fd);
    return 0;
}

- Python
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 8080))
# Aquí enviarías y recibirías datos del servidor
s.close()

***ctype*** 

ctypes es una biblioteca en Python que te permite cargar y utilizar funciones de bibliotecas dinámicas como las .dll.

Como implementar ctypes:

- Python 
1) Cargar la biblioteca .dll
import ctypes
# Reemplaza 'mydll.dll' con el nombre de tu archivo .dll
my_dll = ctypes.CDLL('ruta/a/mydll.dll')

2) Definir prototipos de funciones:
Especifica los tipos de argumentos y el tipo de retorno de las funciones de la .dll que deseas utilizar.

Por ejemplo, si tienes una función int mi_funcion(int), definirías el prototipo así:

- Python
mi_funcion = my_dll.mi_funcion
mi_funcion.argtypes = [ctypes.c_int]
mi_funcion.restype = ctypes.c_int

3) Llamar a las funciones:
Ahora puedes llamar a las funciones de la .dll como si fueran funciones de Python.
Por ejemplo: resultado = mi_funcion(5)

Es importante que las funciones en tu código C++ estén marcadas para exportación para que puedan ser utilizadas por otras aplicaciones o bibliotecas. En Visual Studio, esto se hace con la macro __declspec(dllexport).

---

Convertir código C++ en una biblioteca .dll: Para convertir tu código C++ en una biblioteca .dll, debes seguir dos pasos principales1:

1) Compilar los archivos de código fuente a archivos objeto:

Utiliza un compilador como GCC o MSVC para compilar tus archivos .cpp.
Por ejemplo, con GCC, usarías el comando gcc -c source.cpp para obtener source.o.

2) Vincular los archivos objeto a una biblioteca .dll:

Luego, vinculas los archivos objeto para crear la .dll.
Con GCC, el comando sería gcc -shared -o mydll.dll source.o.

Si estás utilizando Visual Studio, puedes crear un proyecto de biblioteca DLL y agregar tus archivos de código fuente. Visual Studio se encargará de la compilación y vinculación para generar la .dll 


## Backend

### Algoritmo de busqueda de titulos

- Objetivo: Se tienen la idea que el algoritmo de busqueda  debe leer una frase completa hasta el un salto de linea y que ordene de mayor a menor los titulos que mas se asemejan a la frase ingresada. 


# Bibliografia

