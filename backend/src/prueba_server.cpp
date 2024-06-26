#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

int main()
{
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == -1)
    {
        cerr << "Error al crear socket" << endl;
        return 1;
    }
    // tyy
    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    if (bind(server, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        cerr << "Error al enlazar el socket al puerto" << endl;
        close(server);
        return 1;
    }

    if (listen(server, 1) == -1)
    {
        cerr << "Error al escuchar conexiones entrantes" << endl;
        perror("Error con perror");
        close(server);
        return 1;
    }

    cout << "Servidor escuchando en el puerto 8080..." << endl;

    int clientSocket = accept(server, nullptr, nullptr);

    if (clientSocket == -1)
    {
        cerr << "Error al aceptar la conexion entrante" << endl;
        close(server);
        return 1;
    }

    cout << "Cliente conectado" << endl;

    int bufer = 20;
    char buffer[bufer];

    int valread = recv(clientSocket, buffer, bufer, 0);

    if (valread == -1)
    {
        cerr << "Error al recibir mensaje" << endl;
        close(clientSocket);
        close(server);
        return 1;
    }

    cout << "Mensaje recibido: " << buffer << endl;

    close(clientSocket);
    close(server);
    return 0;
}