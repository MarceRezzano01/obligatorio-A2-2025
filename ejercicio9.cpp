#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/UltimoMomentoTab.cpp"

using namespace std;

int main()
{
    UltimoMomentoTab *ultimoMomento = new UltimoMomentoTab(10, 50, 1000);
    ultimoMomento->agregarEjercicio(16,665,1);
    ultimoMomento->agregarEjercicio(6,501,8);
    ultimoMomento->agregarEjercicio(25,904,7);
    ultimoMomento->agregarEjercicio(18,591,5);
    ultimoMomento->agregarEjercicio(7,683, 6);
    ultimoMomento->agregarEjercicio(22,88,1);
    ultimoMomento->agregarEjercicio(24,497,9);
    ultimoMomento->agregarEjercicio(22,565,7);
    ultimoMomento->agregarEjercicio(31,414,9);
    ultimoMomento->agregarEjercicio(49,389,2);
    
//SALIDA -> 17
   cout << ultimoMomento->puntajeMax() << endl;
  
    // TODO 
    return 0;
}