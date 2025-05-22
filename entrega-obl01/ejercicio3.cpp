#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"

using namespace std;


 int defaultCmp(int a, int b){
        return a-b;
    };


int main() {
    int n_reads;
    cin >> n_reads;

   
    MinHeap<int> *HeapDesOrd = new MinHeap<int>(n_reads,defaultCmp);


     for (int i = 0; i < n_reads; i++)
    {
        int numInsert;
        cin >> numInsert;
        HeapDesOrd->insertSinOrdenar(numInsert);
    }

    HeapDesOrd->heapify();

    for(int i = 0; i < n_reads; i++) {
        cout << HeapDesOrd->retornoYeliminoTope() << endl;
    }

    delete HeapDesOrd;
    return 0;
}