#include <iostream>
#include "backend/include/mensajes.pb.h"

using namespace std;

int main()
{
    mensaje::Busqueda input;
    input.set_texto("");
    cout << input.texto() << endl;
    string inputs;
    input.SerializeToString(&inputs);
    input.ParseFromString(inputs);
    cout << input.texto() << endl;
    return 0;
}
