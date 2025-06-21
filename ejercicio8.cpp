
#include <iostream>
using namespace std;

const int TAM_MAX = 1001;

//no se si hay otra dorma de contar largo
int largoStr(const char* s) {
    int l = 0;
    while (s[l] != '\0') l++;
    return l;
}

bool cumplePatron(const char* texto, const char* patron, bool** cumple) {
    int largoTexto = largoStr(texto);
    int largoPatron = largoStr(patron);

    // caso base: texto vacio - patron vacio
    cumple[0][0] = true;

    //inicializacion fila 1
    for (int posPatron = 1; posPatron <= largoPatron; posPatron++) {
        if (patron[posPatron - 1] == '*' && posPatron >= 2) {
            cumple[0][posPatron] = cumple[0][posPatron - 2];
        } else {
            cumple[0][posPatron] = false;
        }
    }
    //inicializacion columna 1 (no se si viene false por defecto, capaz no es necesaio)
    for (int posTexto = 1; posTexto <= largoTexto; posTexto++) {
        cumple[posTexto][0] = false;
    }
    //recorrida para completar el contenido de la matriz con true o false
    for (int posTexto = 1; posTexto <= largoTexto; posTexto++) {
        for (int posPatron = 1; posPatron <= largoPatron; posPatron++) {
            if (patron[posPatron - 1] == '*') {
                cumple[posTexto][posPatron] = cumple[posTexto][posPatron - 2];
                if (patron[posPatron - 2] == texto[posTexto - 1] || patron[posPatron - 2] == '.') {
                    cumple[posTexto][posPatron] = cumple[posTexto][posPatron] || cumple[posTexto - 1][posPatron];
                }
            } else {
                if (texto[posTexto - 1] == patron[posPatron - 1] || patron[posPatron - 1] == '.') {
                    cumple[posTexto][posPatron] = cumple[posTexto - 1][posPatron - 1];
                } else {
                    cumple[posTexto][posPatron] = false; 
                }
            }
        }
    }
    // el valor de cumple real, es a lo que llega, ultima fila con ultima columna
    return cumple[largoTexto][largoPatron];
}

int main() {
    char texto[TAM_MAX], patron[TAM_MAX];
    cin >> texto >> patron;

    int largoTexto = largoStr(texto);
    int largoPatron = largoStr(patron);
    //inicializacion de la matriz
    //agrego una mas de cada una para insertar el caso vacio "" "" 
    bool** cumple = new bool*[largoTexto + 1];
    for (int i = 0; i <= largoTexto; i++) {
        cumple[i] = new bool[largoPatron + 1];
    }
    // la funcion cumple patron genera el contenido 
    //con true o false segun si va cumpliendo o no el patron

    if (cumplePatron(texto, patron, cumple))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    for (int i = 0; i <= largoTexto; i++) {
        delete[] cumple[i];
    }
    delete[] cumple;

    return 0;
}
