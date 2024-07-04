#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

const int TIPO = AF_INET;
const int PROTO = SOCK_STREAM;
const int PUERTO = 8080;

int server = socket(AF_INET, SOCK_STREAM, 0);

class ServerSocket
{
    int server;
    int clientSocket;

public:
    ServerSocket();
    ~ServerSocket();
    void start();
    void stop();
    void send(const char *msg);
    void receive(char *msg, int size);
};