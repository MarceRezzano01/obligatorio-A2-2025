//#include "ColaFifo.cpp"
#include <climits>
#include <iostream>
#include "ColaFifo.cpp"

using namespace std;

struct Arista {
  int origen;
  int destino;
  int peso;
  Arista() {}
  Arista(int _origen, int _destino, int _peso = 1) {
    origen = _origen;
    destino = _destino;
    peso = _peso;
  }
};

template<typename T>
struct Nodo{
   T dato;
   Nodo<T> *sig;
   Nodo( T _dato, Nodo<T> *_sig){
    dato = _dato;
    sig = _sig;
   } 
   Nodo(T _dato) {
    dato = _dato;
    sig = nullptr;
  }
};

class ListAdy {

    private:

        int cantV;
        int A;
        Nodo <Arista> **grafo;


    public:

     ListAdy(int _V){
        cantV = _V;
        A=0;
        grafo = new Nodo<Arista>*[cantV+1]();
        for (int i = 0; i <= cantV; i++)
        {
            grafo[i]=nullptr;
        }
    }

     Nodo<Arista> *adyacentesA(int origen) {
        Nodo<Arista> *aux = grafo[origen];
        Nodo<Arista> *aristasClone = nullptr;
        while (aux != nullptr) {
            aristasClone = new Nodo<Arista>(aux->dato, aristasClone);
            aux = aux->sig;
        }
     return aristasClone;
  }

   void aniadirArista(int origen, int destino, int peso = 1) {
    assert(origen >= 1 && origen <= cantV);
    assert(destino >= 1 && destino <= cantV);
    Arista arista(origen, destino, peso);
    Nodo<Arista> *nuevoNodo = new Nodo<Arista>(arista, grafo[origen]);
    grafo[origen] = nuevoNodo;
    A++;
  }
   
   int getV() { return cantV; }

  int getA() { return A; }
};

  int processNodes(int InitNode, int nodesVisiteds,ListAdy *grafo,  int *gradoDeEntrada) {
     Nodo<Arista> *ady = grafo->adyacentesA(InitNode);
     while (ady != nullptr) {
              int destino = ady->dato.destino;
              gradoDeEntrada[destino]--;
              if (gradoDeEntrada[destino] == 0) {
                nodesVisiteds++;
                cout << "caaaant sumo uno y tot es : "<< nodesVisiteds << endl; 
                    processNodes(destino, nodesVisiteds,grafo,gradoDeEntrada);
      }
      ady = ady->sig;
    }   
     return nodesVisiteds;
    }

 bool hayCiclo(ListAdy *grafo) {
    int V = grafo->getV();
    int extraNodes=0;
    int *gradoDeEntrada = new int[V + 1]();  

    // Calcular el grado de entrada de cada nodo
    for (int v = 1; v < V + 1; v++) {
        Nodo<Arista> *ady = grafo->adyacentesA(v);
        while (ady != nullptr) {
        int destino = ady->dato.destino;
        gradoDeEntrada[destino]++;
        ady = ady->sig;
        }
    }
    QueueImp<int> *cola = new QueueImp<int>();
     for (int v = 1; v < V + 1; v++) {
      if (gradoDeEntrada[v] == 0) {
         cola->enqueue(v);
       //  extraNodes++;
        // extraNodes = processNodes(v,extraNodes,grafo,gradoDeEntrada);   
    }
  }

  while (!cola->isEmpty()) {
    int v = cola->dequeue();
    extraNodes++;
   // cout << v << endl;
    Nodo<Arista> *ady = grafo->adyacentesA(v);
    while (ady != nullptr) {
      int destino = ady->dato.destino;
      gradoDeEntrada[destino]--;
      if (gradoDeEntrada[destino] == 0) {
         cola->enqueue(destino);
      }
      ady = ady->sig;
    }
  }
    //cout << "cant TOtal vert: "<< V << endl; 

    //cout << "cant de nodos process: "<< extraNodes << endl; 
    return extraNodes != V;
}


