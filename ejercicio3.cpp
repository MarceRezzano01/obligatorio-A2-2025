#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"

using namespace std;

int main() {
    int n_reads;
    cin >> n_reads;


    MinHeap<int> *miHeap = new MinHeap<int>(n_reads);


     for (int i = 0; i < n_reads; i++)
    {
        int numInsert;
        cin >> numInsert;
        miHeap->insertSinOrdenar(numInsert);
    }

    miHeap->heapify();

    for(int i = 0; i < n_reads; i++) {
        cout << miHeap->retornoYeliminoTope() << endl;
    }

    delete miHeap;
    return 0;
}