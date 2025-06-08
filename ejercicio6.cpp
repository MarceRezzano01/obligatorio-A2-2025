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


/*
    EdificiosDac *edificios = new EdificiosDac(5);
    edificios->agregarEdificio(2,9,10);
    edificios->agregarEdificio(3,7,15);
    edificios->agregarEdificio(5,12,12);
    edificios->agregarEdificio(15,20,10);
    edificios->agregarEdificio(19,24,8);

  */
  
   edificios->PrintSiluestas();



    return 0;
}