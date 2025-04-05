#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"


using namespace std;



int main()
{
    int n_reads;
   // cin >> n_reads;


    MinHeap<int> *miHeap = new MinHeap<int>(4);
    miHeap->insert(12);
    miHeap->insert(10);
    miHeap->insert(4);
    miHeap->insert(6);



     for (int i = 0; i < 4; i++)
    {
        cout << miHeap->retornoYeliminoTope()<<endl;
    } 


/* 
for (int i = 0; i < n_reads; i++)
    {
        string mail;
        cin >> mail;
        mihash->insert(mail,mail);
    } 

   cout << "unicoss " << mihash->unicos();

   */
   return 0;
}