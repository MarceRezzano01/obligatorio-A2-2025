#include <iostream>
using namespace std;

template <typename k, typename v>
struct keyValue{//estructura de la tabla
    k key;
    v value;
    keyValue(k key, v value){
        this->key = key;
        this->value = value;
    }
};



template <typename k, typename v>
class HashCerrado{
  private:
        keyValue<k, v> **table;//la tabla
        int n;//cant elementos
        int b;//tamaño de la tabla o cant buckets
        int (*hash)(k); //funcion de hash
        int (*SecondHash)(k);

         float factorDeCarga() {
            return (float)this->n/this->b;
        }

  public:
        HashCerrado(int _b,int (*unhasg)(k),int (*secHash)(k)){
            table = new keyValue<k,v>*[_b]();
            for(int i=0; i < _b; i++) {
                table[i] = nullptr;
            }
            b=_b;
            n=0;
            hash=unhasg;
            SecondHash=secHash;
        };


        /// Doble hashing: intento i =(H(k)+h2(k)x i) % _b
// h(k) fun hash y h2(k) otra funcion de hash

         void insert(k key, v value){    
            int pos = abs(this->hash(key))%this->b;
            bool insert=false;
            int intentos =0;
            while (!insert){
                if(table[pos]==nullptr){  
                    table[pos]=new keyValue<k,v>(key,value);
                    insert=true;
                  //  cout<< "Inserte "<< key<< endl;
                    n++;
                }else if(table[pos]->key == key){
                table[pos]->value=value;
                insert=true;
                }
             if (!insert) {
               intentos++; 
               int hagoSecH = abs(this->SecondHash(key)%this->b);
               //cout << "SegHas " << hagoSecH << endl;
               pos = (pos + (hagoSecH * intentos))%this->b;
               //cout << "PROXIMA POS A INSERT " << pos << endl;
            }
            }
         };
        
        int existe(k key){
        
        int pos = abs(this->hash(key))%this->b;
        int index = 0;
         while (b>index){
           if(table[pos] == nullptr) {
                    return 0;
           }else if (table[pos]->key==key){
                 return 1;
             }
             index++;
             int hagoSecH = abs(this->SecondHash(key)%this->b);
             pos = (pos + (hagoSecH * index))%this->b;
         }
         return 0;
        }           

};