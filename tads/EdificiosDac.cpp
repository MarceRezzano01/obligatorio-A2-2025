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
    int fin;
    int altura;
    Pares(int _inicio, int _altura ){
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
        int insertIndex = 0;
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
    //LLAMO AL DAC
      ListImp<Pares> * ret = obtenerSilueta(SiuetasEdificios, 0, cantEdif - 1);
    //PRINTEO SILUETAS
       for (int i = 0; i < ret->getSize(); i++) {
            cout << ret->get(i).inicio << " " << ret->get(i).altura << endl; 
        }
    }


    ListImp<Pares> * obtenerSilueta( Edificio ** SiuetasEdificios, int inicio, int fin) {
        if (fin == inicio){
          //  cout << "entro a obtener silueta en CB " << endl;
             ListImp<Pares> *cb= new ListImp<Pares>[this->cantEdif];
             cb->insert(Pares(SiuetasEdificios[inicio]->posInicio, SiuetasEdificios[inicio]->altura));
             cb->insert(Pares(SiuetasEdificios[inicio]->posFin, 0));
             return cb;
        } 

        int mid =  (inicio + fin) / 2;
         ListImp<Pares> * siluetaIzq = obtenerSilueta(SiuetasEdificios, inicio, mid);
         ListImp<Pares> * SiluestaDer = obtenerSilueta(SiuetasEdificios, mid + 1, fin);

        //return muestroSiluetas(siluetaIzq, SiluestaDer);
        return mergeSiluetas(siluetaIzq, SiluestaDer);
      
       
      }

    ListImp<Pares>* mergeSiluetas( ListImp<Pares>* left,  ListImp<Pares>*  right) {
        ListImp<Pares> *merged= new ListImp<Pares>[this->cantEdif];
        int h1 = 0, h2 = 0, i = 0, j = 0;

        while (i < left->getSize() && j < right->getSize()) {
            if (left->get(i).inicio < right->get(j).inicio ) {
                int x = left->get(i).inicio;
                h1 = left->get(i).altura;
                int maxH = max(h1, h2);
                agregoSilueta(merged, x, maxH);
                i++;
            } else if (left->get(i).inicio  > right->get(j).inicio) {
                int x = right->get(j).inicio;
                h2 = right->get(j).altura;
                int maxH = max(h1, h2);
                agregoSilueta(merged, x, maxH);
                j++;
            } else {
                int x = left->get(i).inicio;
                h1 =  left->get(i).altura;
                h2 = right->get(j).altura;
                int maxH = max(h1, h2);
                agregoSilueta(merged, x, maxH);
                i++;
                j++;
            }
        }

        while (i < left->getSize()) {
            agregoSilueta(merged, left->get(i).inicio, left->get(i).altura);
            i++;
        }

        while (j < right->getSize()) {
             agregoSilueta(merged,right->get(j).inicio,  right->get(j).altura);
             j++;
        }

        return merged;
    }


    void agregoSilueta( ListImp<Pares> *merged, int x, int h) {
      int lastElemt =merged->getSize() - 1;
        if (!merged->isEmpty() && merged->get(lastElemt).altura == h  ) return;
        if (!merged->isEmpty() && merged->get(lastElemt).inicio == x) {
        Pares pairAnterior = merged->get(lastElemt);
        merged->removeAt(lastElemt);
        merged->insert (Pares(pairAnterior.inicio,h));
        } else {
            merged->insert(Pares(x, h));
    
        }
    }

   
    void agregarEdificio(int inicio, int fin, int altura) {
        this->SiuetasEdificios[this->n] =  new Edificio(inicio, fin, altura);
        this->n++;
        
    }

    void printEdif(){
        for (int i = 0; i < this->n; i++) {
            cout << "Edificio " << i << ": Inicio: " << SiuetasEdificios[i]->posInicio 
                 << ", Fin: " << SiuetasEdificios[i]->posFin 
                 << ", Altura: " << SiuetasEdificios[i]->altura << endl;
        }
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

     ListImp<Pares>* muestroSiluetas( ListImp<Pares>* left,  ListImp<Pares>*  right) {
        cout << "Izquierda: " << endl;
          for (int i = 0; i < left->getSize(); i++) {
            cout << left->get(i).inicio << " " << left->get(i).altura << endl; 
        }
         cout << "Der: " << endl;
          for (int i = 0; i < right->getSize(); i++) {
            cout << right->get(i).inicio << " " << right->get(i).altura << endl; 
        }
        return left;

     }

};