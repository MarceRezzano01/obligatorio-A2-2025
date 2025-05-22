#include "ListImp.cpp"
#include <iostream>
using namespace std;

template <typename k, typename v>
struct keyValue
{
    k key;
    v value;
    keyValue(k key, v value)
    {
        this->key = key;
        this->value = value;
    }

    bool operator==(const keyValue<k, v> &other) const
    {
        if (this->key == other.key && this->value == other.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
};

template <typename k, typename v>
class HashAbierto
{
private:
    ListImp<keyValue<k, v> > *table; 
    int n;                          
    int b;                          
    int (*hash)(k);                 
    int repetidos;
    
    float factorDeCarga()
    {
        return (float)this->n / this->b;
    }

public:
    HashAbierto(int _b, int (*unhasg)(k))
    {
        table = new ListImp<keyValue<k, v> >[_b];
        b = _b;
        n = 0;
        hash = unhasg;
    };

    void insert(k key, v value)
    {
        int pos = abs(this->hash(key)) % this->b;
       
       if(table[pos].existe(keyValue<k, v>(key, value))){
         repetidos++;
       }else{
        table[pos].insert(keyValue<k, v>(key, value));
       }

    };

    int unicos (){
        return b- repetidos;        
    };
};