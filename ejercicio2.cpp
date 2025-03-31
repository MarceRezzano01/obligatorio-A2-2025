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


//TODO: BORRAR SI TODO SIGUE OK
int sencondHash(string palabra, int buckets)
{
    int pos = 0;
    for (int i = 0; i <= 20; i++)
    {
        if (palabra[i] != '\0')
        {
            pos += palabra[i] * 32 ^ i;
        }
        else
            return pos % buckets;
    }
    return pos % buckets;
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


  

/*    
HashCerrado<string,int> *mihash = new HashCerrado<string,int>(3,hash3,sencondHash);
mihash->insert("pepe",0);
mihash->insert("pepe1",1);
mihash->insert("pepe2",2);

  cout << mihash->existe("pepe1") << endl;
  cout << mihash->existe("pepe4") << endl;

*/

    return 0;
}