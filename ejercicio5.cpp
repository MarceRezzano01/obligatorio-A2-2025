#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListAdy.cpp"

using namespace std;

int main()
{

    int cvert;
    cin >> cvert;
    int caristas;
    cin >> caristas;

    
  ListAdy *miGrafito = new ListAdy(cvert);
   for (int i = 0; i < caristas; i++)
    {
        int og;
        int dst;

        cin >> og;
        cin >> dst;
        miGrafito->aniadirArista(og,dst);
    }

/*
  miGrafito->aniadirArista(1, 2);
  miGrafito->aniadirArista(2, 3);
  miGrafito->aniadirArista(3, 4);
  miGrafito->aniadirArista(4,2);
  */  
  
  bool result = hayCiclo(miGrafito);

cout << result;

  return 0;
}