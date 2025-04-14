#include <iostream>
#include <string>
using namespace std;

int posicionFinal;
string s1;
string s2;

double funcion(int indice, int posicion) {
    if (indice == s2.length()) {
        return posicion == posicionFinal ? 1.0 : 0.0;
    }
    if (s2[indice] == '+') return funcion(indice + 1, posicion + 1);
    if (s2[indice] == '-') return funcion(indice + 1, posicion - 1);
    if (s2[indice] == '?') {
        return 0.5 * funcion(indice + 1, posicion + 1) + 0.5 * funcion(indice + 1, posicion - 1);
    }
    return 0.0;
}

int main() {
    cin >> s1 >> s2;
    posicionFinal = 0;
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] == '+') posicionFinal++;
        if (s1[i] == '-') posicionFinal--;
    }
    cout.precision(12);
    cout << fixed << funcion(0, 0) << endl;
}
