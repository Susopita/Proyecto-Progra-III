#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main()
{
    int sockC = socket(AF_INET, SOCK_STREAM, 0);
    if (sockC == -1)
    {
        perror("Error al crear el socket");
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    serverAddr.sin_port = htons(8080);

    if (connect(sockC, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        perror("Error en la conexion");
        close(sockC);
        return 1;
    }

    const char *mes = "Holi :3";
    send(sockC, mes, strlen(mes), 0);

    close(sockC);
    return 0;
}