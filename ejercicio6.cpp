#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/EdificiosDac.cpp"

using namespace std;

int main()
{
    //int cvert;
    //cin >> cvert;
    //int caristas;
    //cin >> caristas;


    EdificiosDac *edificios = new EdificiosDac(5);
    edificios->agregarEdificio(2, 9, 10);
    edificios->agregarEdificio(3,7,15);
    edificios->agregarEdificio(5, 12, 12);
    edificios->agregarEdificio(15, 20, 10);
    edificios->agregarEdificio(19, 24, 8);




    return 0;
}