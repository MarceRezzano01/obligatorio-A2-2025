#include <cassert>
#include <string>
#include <limits>
#include "tads/SudokuBac.cpp"
#include <iostream>

using namespace std;

int main()
{

    int filas;
    int columnas;
    cin >> filas;
    cin >> columnas;

    SudokuBac *sudoku = new SudokuBac(filas, columnas);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int valor;
            cin >> valor;
            sudoku->insert(i, j, valor);
        }
    }

    sudoku->imprimoResuleto();

    // TODO
    return 0;
}