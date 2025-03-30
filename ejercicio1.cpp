#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HashAbierto.cpp"
#include "tads/ListImp.cpp"

using namespace std;


int hash3(string k){
    int h = 0;
  for (int i = 0; i < k.length(); i++)
    h = 31 * h + int(k[i]);
  return h;

}

int main()
{
    int n_reads;
    cin >> n_reads;
    

 //HashAbierto<string, string> *mihash = new HashAbierto <string,string>(10,hash3);
 //mihash->insert("pepe@pepe","pepe@pepe");
//mihash->insert("pepe@pepe","pepe@pepe");
//mihash->insert("pepe@pepe1","pepe@pepe1");
//cout << mihash->unicos();

HashAbierto<string, string> *mihash = new HashAbierto <string,string>(n_reads,hash3);
for (int i = 0; i < n_reads; i++)
    {
        string mail;
        cin >> mail;
        mihash->insert(mail,mail);
    } 

   cout << "unicoss " << mihash->unicos();
   return 0;
}