#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/UltimoMomentoTab.cpp"

using namespace std;

int main()

{

    int n_archs;
    int max_lienas;
    int max_peso;
    cin >> n_archs;
    cin >> max_peso;
    cin >> max_lienas;
    UltimoMomentoTab *ultimoMomento = new UltimoMomentoTab(n_archs, max_peso, max_lienas);

    for (int i = 0; i < n_archs; i++)
    {
        int tam_arch;
        int cant_lineas_arch;
        int puntos_ejer;

        cin >> tam_arch;
        cin >> cant_lineas_arch;
        cin >> puntos_ejer;

        ultimoMomento->agregarEjercicio(tam_arch, cant_lineas_arch, puntos_ejer);
    }

           cout << ultimoMomento->puntajeMax() << endl;

           
/*
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

       cout << ultimoMomento->puntajeMax() << endl;
*/ 



  
    // TODO 
    return 0;
}