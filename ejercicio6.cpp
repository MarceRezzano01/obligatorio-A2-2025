#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/EdificiosDac.cpp"

using namespace std;

int main()
{
    int n_reads;
    int m_exist;
    cin >> n_reads;

  EdificiosDac *edificios = new EdificiosDac(n_reads);
    for (int i = 0; i < n_reads; i++)
    {
        int inicio;
        int fin;
        int altura;

        cin >> inicio;
        cin >> fin;
        cin >> altura;
 
       edificios->agregarEdificio(inicio, fin, altura);
    } 
    
   edificios->PrintSiluestas();



    return 0;
}