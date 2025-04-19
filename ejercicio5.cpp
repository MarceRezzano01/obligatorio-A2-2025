#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListAdy.cpp"

using namespace std;

int main()
{
  ListAdy *miGrafito = new ListAdy(5);
  miGrafito->aniadirArista(1, 2);
  miGrafito->aniadirArista(2, 3);
  miGrafito->aniadirArista(3, 4);
  miGrafito->aniadirArista(4,2);
    
  bool result = hayCiclo(miGrafito);

cout << "Hay ciclo: " << result;

  return 0;
}