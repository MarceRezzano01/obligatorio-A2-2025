#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HashCerrado.cpp"


using namespace std;


int hash3(string k){
    int h = 0;
    for (int i = 0; i < k.length(); i++)
    h = 31 * h + int(k[i]);
    return h;

}

int secondaryHashString(string key) {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 17 + c);
    }
    return 7 - (hash % 7);
}


int main()
{
    int n_reads;
    int m_exist;
    cin >> n_reads;
    HashCerrado<string,string> *mihash = new HashCerrado<string,string>(n_reads * 2,hash3,secondaryHashString);


  for (int i = 0; i < n_reads; i++)
    {
        string palabraInsert;
        cin >> palabraInsert;
        mihash->insert(palabraInsert,palabraInsert);
    } 

     cin >> m_exist;

     for (int i = 0; i < m_exist; i++)
    {
        string palabraSearch;
        cin >> palabraSearch;
        cout << mihash->existe(palabraSearch) <<endl;
    } 

    return 0;
}