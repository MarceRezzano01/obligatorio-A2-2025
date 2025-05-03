#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListAdy.cpp"


using namespace std;

int main()
{

    int n_reads;
   // cin >> n_reads;

  ListAdy *GrafitoDist = new ListAdy(4);
  GrafitoDist->aniadirArista(1,2,10);
  GrafitoDist->aniadirArista(1,3,5);
  GrafitoDist->aniadirArista(3,2,3);
  GrafitoDist->aniadirArista(2,4,1);
  GrafitoDist->aniadirArista(3,4,8);

  caminosXVert(1,GrafitoDist);

      
    // TODO
    return 0;
}