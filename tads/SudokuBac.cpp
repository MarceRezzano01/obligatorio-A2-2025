#include "ListImp.cpp"
#include <iostream>

using namespace std;

struct Sudoku{
    int filas;
    int columnas;
 
    Sudoku(int _filas, int _columnas) {
        filas = _filas;
        columnas = _columnas;
    }
};

class SudokuBac  {

    public:
    int filas;
    int columnas;
    int **sudoku;

    SudokuBac(int _filas, int _columnas) {
     filas = _filas;
     columnas = _columnas;
     sudoku = new int*[_filas];
     
     
     for (int i = 0; i < filas; ++i) {
      sudoku[i] = new int[columnas];
       for (int j = 0; j < columnas; ++j) {
          sudoku[i][j] = 0;
       }
     } 
    }

    void insert(int _fila, int _columna, int valor) {
        if (_fila >= 0 && _fila < filas && _columna >= 0 && _columna < columnas) {
            sudoku[_fila][_columna] = valor;
           // cout << "se inserto el valor " << valor << " en la fila " << _fila << " y columna " << _columna << endl;
        } else {
            cout << "se va el isert." << endl;
        }
    }

    bool numeroValido(int fila, int columna, int numEnJuego, int **sudoku, int filas, int columnas) {
        
        for (int i = 0; i < columnas; ++i) {
            if (sudoku[fila][i] == numEnJuego) {
                return false;
            }
        }
        
        for (int j = 0; j < filas; ++j) {
            if (sudoku[j][columna] == numEnJuego) {
                return false;
            }
        }

         int subGrillaF = filas / 3;
         int subGrillaC = columnas / 3;        
         int inicioF = fila - fila % subGrillaF;
         int inicioC = columna - columna % subGrillaC;

         for(int i = 0; i < subGrillaF; ++i) {
            for (int j = 0; j < subGrillaC; ++j) {
                if (sudoku[inicioF + i][inicioC + j] == numEnJuego) {
                    return false;
                }
            }   

          
        }
        return true;
    }
    
    bool resolverSudoku(int **&sudoku, int filas, int columnas, int valorMaximo) {
        for (int fila = 0; fila < filas; ++fila) {        
            for (int columna = 0; columna < columnas; ++columna) {

                if (sudoku[fila][columna] == 0) {
                    for (int numEnJuego = 1; numEnJuego <= valorMaximo; ++numEnJuego) {
                        if (numeroValido(fila, columna, numEnJuego, sudoku, filas, columnas)) {
                            sudoku[fila][columna] = numEnJuego;
                            if(resolverSudoku(sudoku, filas, columnas, valorMaximo)) {
                                return true; 
                            } 
                            sudoku[fila][columna] = 0; //desago movimiento
                        }
                    }
                    return false;
                }
            }
        }
        return true; // Sudoku solved
    }

       void imprimoResuleto(){
        int indexMaximo= max(filas, columnas);
        resolverSudoku(sudoku, filas, columnas, indexMaximo);
        for(int i = 0; i < filas; ++i) {
         
            for (int j = 0; j < columnas; ++j) {
                cout << sudoku[i][j];
                if (j < columnas - 1) {
                    cout << " ";
                }
            }

            cout << endl;
        }
    }
   
};
