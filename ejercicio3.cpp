#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"


using namespace std;



int main()
{
    int n_reads;
    cin >> n_reads;


    MinHeap<int> *miHeap = new MinHeap<int>(n_reads);
   // miHeap->insert(12);
   // miHeap->insert(10);
   // miHeap->insert(4);
   // miHeap->insert(6);



     for (int i = 0; i < n_reads; i++)
    {
        int numInsert;
        cin >> numInsert;
        miHeap->insert(numInsert);
    } 


    for (int i = 0; i < n_reads; i++)
    {
        cout << miHeap->retornoYeliminoTope()<<endl;
    } 


   return 0;
}