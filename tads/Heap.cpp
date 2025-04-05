#include <iostream>
using namespace std;

template <typename T>
class MinHeap {
    private:
        T *arr;
        int sig;
        int cap;

        int padre(int pos){
            return pos/2;
        }

        int hIzq(int pos){
            return pos*2;
        }
        int hDer(int pos){
            return (pos*2)+1;
        }
        void swap(int pos1, int pos2){
            T aux = arr[pos1];
            arr[pos1]=arr[pos2];
            arr[pos2]=aux;
        }
        void flotar (int pos){
            if(pos>1){//no estamos en la raiz
               T padreEl = arr [padre(pos)];
               T element = arr[pos];
               if (padreEl - element>0){
                    swap(pos,padre(pos));
                    flotar(padre(pos));
               }
            }
        }

        void hundir (int pos){
            int posHizq= hIzq(pos);
            int posHDer=hDer(pos);
            if(posHizq<sig){
                int posMenorHijo=posHizq;
                if (posHDer<sig && arr[posHizq] - arr[posHDer] >0){
                    posMenorHijo=posHDer;
                }

                if (arr[pos] - arr[posMenorHijo] > 0) {
                    swap(pos, posMenorHijo);
                    hundir(posMenorHijo);
                }
            }
        }

       

        bool estalleno(){
        return this->sig > this->cap;
        }
        bool estavacio(){
        return this->sig ==1;
        }

    public:
    MinHeap (int _cap){
        arr = new T[_cap];
        sig=1;
        cap=_cap;
        
    }    
     void insert (T element){
        assert(!estalleno());
        arr[sig]=element;
        //cout << "inserte " << arr[sig] << endl;
        sig++;
        flotar(sig-1);
     }

     T tope(){
        assert(!estavacio());
        return arr[1];

     } 

     void removerTope(){
     assert(!estavacio());
     arr[1]= arr[sig-1]; //swap(1,sig-1)
     sig--;
     hundir(1);
     }

     T retornoYeliminoTope(){
     assert(!estavacio());
     T elemTope = arr[1];
     arr[1]= arr[sig-1]; //swap(1,sig-1)
     sig--;
     hundir(1);
     return elemTope;
     }
};
