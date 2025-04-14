#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int>> M;

bool funcion(int h, int c, int k, int i, int j) {
    if (i >= n || j >= m) return false;
    if (M[i][j] == 1) h++;
    if (M[i][j] == - 1) c++;
    k++;

//podas
    if (k > n + m - 1) return false;
    if (abs(h - c) > n + m - 1 - (i + j)) return false;


    //si termine de recorrer la matriz, compruebo las condiciones
    if (i == n - 1 && j == m - 1){
        if( h == c && k == n + m - 1){
            return true;
        }
    }

    return funcion(h, c, k, i + 1, j) || funcion(h, c, k, i, j + 1);
    
}

int main() {
    int T;
    cin >> T;
    vector <string> imprimir (T);

    while (T > 0){
        T--;
        cin >> n >> m;

        M = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> M[i][j];

            }
        }
        
        bool output = funcion(0,0,0,0,0);
        if (output) imprimir.push_back("YES");
        else imprimir.push_back("NO");
    }
    for (int i = 0; i < imprimir.size(); i++){
        cout << imprimir[i] << endl;
    }
    
    return 0;
}
