#include "ListImp.cpp"
#include <iostream>
using namespace std;

struct Edificio{
    int posInicio;
    int posFin;
    int altura;
    Edificio(int inicio, int fin, int alt){
        this->posInicio = inicio;
        this->posFin = fin;
        this->altura = alt;
    } 
};

struct Pares{
    int inicio;
    int altura;
    Pares(int _inicio, int _altura){
        this->inicio = _inicio;
        this->altura = _altura;
    }

       bool operator==(const Pares &other) const
    {
        if (this->inicio == other.inicio && this->altura == other.altura)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};


class EdificiosDac {

 private:
        Edificio ** SiuetasEdificios;
        int n =0;
        int initDac;
        int endDac;
        int cantEdif;
        ListImp<Pares> *siluetasPegadas;

  public:

    EdificiosDac(int _cantEdificios) {
            this->SiuetasEdificios = new Edificio*[_cantEdificios]();
            for (int i = 0; i < _cantEdificios; i++) {
                this->SiuetasEdificios[i] = nullptr;
            }
            this->siluetasPegadas = new ListImp<Pares>[_cantEdificios];
        
            this->cantEdif = _cantEdificios;
        };

    void PrintSiluestas() {
        cout << "entando con edif = "<< cantEdif << endl;
     
         ListImp<Pares> * ret = obtenerSilueta(SiuetasEdificios, 0, cantEdif);
        for (int i = 0; i < ret->getSize(); i++) {
            cout << "Inicio: " << ret->get(i).inicio << ", Altura: " << ret->get(i).altura << endl; 
        }
    }


    ListImp<Pares> * obtenerSilueta( Edificio ** SiuetasEdificios, int inicio, int fin) {
       // cout << "entro a obtener silueta con fin en: " << fin << endl;
        if (fin == inicio){
             cout << "entro a obtener silueta en CB " << endl;
             ListImp<Pares> *cb= new ListImp<Pares>[this->cantEdif];
              cb->insert(Pares(SiuetasEdificios[fin]->posInicio, SiuetasEdificios[fin]->altura));
           return this->siluetasPegadas;
        } 

        int mid = inicio + fin / 2;
       //  cout << "miatad: "<< mid<< endl;
         ListImp<Pares> * siluetaIzq = obtenerSilueta(SiuetasEdificios, inicio, mid);
        cout << "Fin silueta izq " << endl;
         ListImp<Pares> * SiluestaDer = obtenerSilueta(SiuetasEdificios, mid + 1, fin);
          cout << "Fin silueta der " << endl;

        return mergeSiluetas(siluetaIzq, SiluestaDer);
       // return obtenerSilueta (SiuetasEdificios, 0, cantEdif - 1);
       
      }

    ListImp<Pares>* mergeSiluetas( ListImp<Pares>* left,  ListImp<Pares>*  right) {
         cout << "entro a MERGE de Siluetas"<< endl;

         
        ListImp<Pares> *merged= new ListImp<Pares>[this->cantEdif];
        int h1 = 0, h2 = 0, i = 0, j = 0;

        while (i < left->getSize() && j < right->getSize()) {
            if (left->get(i).inicio < right->get(j).inicio) {
                int x = left->get(i).inicio;
                h1 = left->get(i).altura;
                int maxH = max(h1, h2);
                merged->insert(Pares(x, maxH));
                i++;
            } else if (left->get(i).inicio  > right->get(j).inicio) {
                int x = right->get(j).inicio;
                h2 = right->get(j).altura;
                int maxH = max(h1, h2);
                merged->insert(Pares(x, maxH));
                j++;
            } else {
                int x = left->get(i).inicio;
                h1 =  left->get(i).altura;
                h2 = right->get(j).altura;
                int maxH = max(h1, h2);
                merged->insert(Pares(x, maxH));
                i++;
                j++;
            }
        }

        while (i < left->getSize()) {
            merged->insert(Pares(left->get(i).inicio, left->get(i).altura));
            i++;
        }

        while (j < right->getSize()) {
             merged->insert(Pares( right->get(j).inicio,  right->get(j).altura));
            j++;
        }

        return merged;
    }


   
    void agregarEdificio(int inicio, int fin, int altura) {
        this->SiuetasEdificios[this->n] =  new Edificio(inicio, fin, altura);
        this->n++;
        
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    

};