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
    
  ListAdy *GrafitoTopo = new ListAdy(cvert);
   for (int i = 0; i < caristas; i++)
    {
        int og;
        int dst;

        cin >> og;
        cin >> dst;
        GrafitoTopo->aniadirArista(og,dst);
    }
  
bool result = hayCiclo(GrafitoTopo);
cout << result;

  return 0;
}