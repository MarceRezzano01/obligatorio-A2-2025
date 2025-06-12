#include "ListImp.cpp"
#include <iostream>
using namespace std;

struct Ejercicio{
    int tamArch;
    int cantLineasArch;
    int puntosEjer;
    Ejercicio(int _tArch, int _cantLineasArch, int _puntosEjer) {
        this->tamArch = _tArch;
        this->cantLineasArch = _cantLineasArch;
        this->puntosEjer = _puntosEjer;
    }
    
};

class UltimoMomentoTab {

    private:
        Ejercicio ** ejercicios;
        int cantArchivosAg = 0;
        int pesoMaximoEntrega;
        int cantMaximoLineas;
        int cantEjerciciosTot;
        int*** mochila; //Ejercicio x capacidad(lineas y peso)

        
        
public:

    UltimoMomentoTab(int cantEjercicios, int pesoMaximoEntrega ,int cantMaximoLineas) {
        this->pesoMaximoEntrega = pesoMaximoEntrega;
        this->cantMaximoLineas = cantMaximoLineas;
        this->cantEjerciciosTot = cantEjercicios;
        this->ejercicios = new Ejercicio*[cantEjerciciosTot + 1];

        this->mochila = new int **[this->pesoMaximoEntrega + 1];
         for (int i = 0 ; i <= pesoMaximoEntrega; i++){
            this->mochila[i] = new int* [this->cantEjerciciosTot + 1];
            for (int j = 0 ; j <= this->cantEjerciciosTot; j++){
             this->mochila[i][j] =  new int [this->cantMaximoLineas + 1];
             for (int k = 0; k <= this->cantMaximoLineas; k++)
             {
                this->mochila[i][j][k] = 0; // Inicializamos la mochila con 0
             }
             
               
            }
        }
    }


   void agregarEjercicio(int tArch, int cantLineasArch, int puntosEjer) {
        this->ejercicios[this->cantArchivosAg] = new Ejercicio(tArch, cantLineasArch, puntosEjer);
        this->cantArchivosAg++;  
    }

    void cargoMochila(){
        for(int i = 1 ; i <= this->pesoMaximoEntrega; i++)
        {
            for (int j = 1 ; j <= this->cantEjerciciosTot; j++)
            {
                for (int k = 1 ; k <= this->cantMaximoLineas; k++)
                {
                    if(k < this->ejercicios[j-1]->cantLineasArch || i < this->ejercicios[j-1]->tamArch){
                        this->mochila[i][j][k] = this->mochila[i][j-1][k];
                    }else{
                        this->mochila[i][j][k] = max(this->mochila[i][j-1][k],
                                                    this->ejercicios[j-1]->puntosEjer +
                                                    this->mochila[i - this->ejercicios[j-1]->tamArch][j-1][k - this->ejercicios[j-1]->cantLineasArch]);
                    }
                }
            }
        }      
    }
    
   int puntajeMax(){
    cargoMochila();
    return this->mochila[this->pesoMaximoEntrega][this->cantEjerciciosTot][this->cantMaximoLineas];
   } 


};