#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListAdy.cpp"


using namespace std;

int main()
{

    int cvert;
    cin >> cvert;
    int caristas;
    cin >> caristas;

  ListAdy *GrafitoDist = new ListAdy(cvert);

    for (int i = 0; i < caristas; i++)
    {
        int og;
        int dst;
        int cost;

        cin >> og;
        cin >> dst;
        cin >> cost;
        GrafitoDist->aniadirArista(og,dst,cost);
    }

    int verticesAbuscarC;
    cin >> verticesAbuscarC;
     for (int i = 0; i < verticesAbuscarC; i++)
    {
      
        int initVert;
        cin >> initVert;
        caminosXVert(initVert,GrafitoDist);
    }
    return 0;
}