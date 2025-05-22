#include <climits>
#include <iostream>
#include "Heap.cpp"

using namespace std;

struct Arista {
  int origen;
  int destino;
  int costo;
  Arista() {}
  Arista(int _origen, int _destino, int _costo = 1) {
    origen = _origen;
    destino = _destino;
    costo = _costo;
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
  

   Nodo<Arista> *adyacentesDe(int origen){
       Nodo<Arista> * aux = grafo[origen];
       Nodo<Arista> * clon = nullptr;
       while (aux !=nullptr)
       {
        Arista a = aux->dato;
        clon =new Nodo<Arista>(a,clon);
        aux=aux->sig;
       }
        return clon;
    };
       

   void aniadirArista(int origen, int destino, int costo = 1) {
    assert(origen >= 1 && origen <= cantV);
    assert(destino >= 1 && destino <= cantV);
    Arista arista(origen, destino, costo);
    Nodo<Arista> *nodo = new Nodo<Arista>(arista, grafo[origen]);
    grafo[origen] = nodo;
    A++;
  }
   
  int getV() { return cantV; }

  int getA() { return A; }
};

 bool hayCiclo(ListAdy *grafo) {
    int V = grafo->getV();
    int nodosTopo=0;
    int *gradoDeEntrada = new int[V + 1]();  

    
    for (int v = 1; v < V + 1; v++) {
        Nodo<Arista> *ady = grafo->adyacentesDe(v);
        while (ady != nullptr) {
        int destino = ady->dato.destino;
        gradoDeEntrada[destino]++;
        ady = ady->sig;
        }
    }
      for (int v = 1; v < V + 1; v++) {
       if (gradoDeEntrada[v] == 0) {
        nodosTopo++;
        Nodo<Arista> *ady = grafo->adyacentesDe(v);
        while (ady != nullptr) {
              int destino = ady->dato.destino;
              gradoDeEntrada[destino]--;
              ady = ady->sig;
        }          
      }
    }
    return nodosTopo != V;

}

struct cam {
  int vert;
  int costo;
  cam() {}
  cam(int _vert, int _costo) {
    vert = _vert;
    costo = _costo;
  }
};

int cmpCamino(cam c1, cam c2) {
  return c1.costo - c2.costo;
}

void caminosXVert(int vertInit, ListAdy *grafo) {
  int V = grafo->getV();
   MinHeap<cam> *HeapDist = new MinHeap<cam> (V * V, cmpCamino);
   int *dist = new int[V + 1]();
   bool *vst = new bool[V + 1]();

  cam caminoInit(vertInit, 0);
   HeapDist->insertar(caminoInit);
   for (int i = 1; i < V + 1; i++) {
     vst[i] = false;
     dist[i] = INT_MAX;
   }
   dist[vertInit] = 0;

   while (!HeapDist->estavacio()) {
     cam aProcesar = HeapDist->retornoYeliminoTope();
     if (!vst[aProcesar.vert]) {
         vst[aProcesar.vert] = true;
         Nodo<Arista> *ady = grafo->adyacentesDe(aProcesar.vert);
         while (ady != nullptr) {
          int destino= ady->dato.destino; 
          int costoAristaD = ady->dato.costo;
       
          if (!vst[destino] && dist[destino] > costoAristaD + dist[aProcesar.vert]) {
            dist[destino] = costoAristaD + dist[aProcesar.vert];
            HeapDist->insertar( cam (destino, dist[destino]));
         }
         ady = ady->sig;
      }
     }
   }
   for (int i = 1; i < V + 1; i++) {
     if (i == vertInit ||!vst[i]) {
         cout << -1 << endl;
     }else{
        cout << dist[i] << endl;
     }
   
   }
}


