#include <iostream>
using namespace std;

template <typename T>
class MinHeap {
    private:
        T *arr;
        int sig;
        int cap;
      //  bool (*cmpfunc) (T a, T b);

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
      //  cmpfunc = (T a, T b) { return a - b < 0; }; 
        
    }
 /* 
    MinHeap (int _cap, bool _cmpfunc(T a, T b)){
        arr = new T[_cap];
        sig=1;
        cap=_cap;
        cmpfunc = _cmpfunc;
        
    }      
*/
     T retornoYeliminoTope(){
     assert(!estavacio());
     T elemTope = arr[1];
     arr[1]= arr[sig-1];
     sig--;
     hundir(1);
     return elemTope;
     }

    void insertSinOrdenar(T element){
        assert(!estalleno());
        arr[sig]=element;
        sig++;
    }

    void heapify() {
        for(int i = sig/2; i >= 1; i--) {
            hundir(i);
        }
    }
};
