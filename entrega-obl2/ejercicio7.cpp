#include <iostream>

using namespace std;


bool hayUnUnicoImpar(int cant[10]) {
    int impares = 0;
    for (int num = 0; num < 10; num++) {
        if (cant[num] % 2 != 0) impares++;
    }
    return impares <= 1;
}

int* armarPalindromoGreedy(int largo, int cant[]) {
    int* resultado = new int[largo];
    int der = 0;
    int izq = largo -1;
    int centro = (largo - 1) / 2;
    for (int posCant = 9; posCant >= 0; posCant--){
        if (cant[posCant] == 0){
            continue;
        }
        while (cant[posCant] >= 2 && der < izq) {
            resultado[der] = posCant;
            resultado[izq] = posCant;
            cant[posCant] -= 2;
            der++;
            izq--;
        }
        if (cant[posCant] == 1){
            resultado[centro] = posCant;
            cant[posCant]--;
        }
    }
    return resultado;
}




int main() {
    string N;
    cin >> N;
    int cant[10] = {0};
    // no se si hay otra forma de passarlo a int
    for (char c : N) {
        cant[c - '0']++;
    }
    if (!hayUnUnicoImpar(cant)) {
        cout << "No" << endl;
        return 0;
    }
    int largo = N.size();
    
    int* palindromo = armarPalindromoGreedy(largo, cant);

        for (int i = 0; i < largo; i++) {
            cout << palindromo[i];
        }
        cout << endl;
    
    return 0;
}

