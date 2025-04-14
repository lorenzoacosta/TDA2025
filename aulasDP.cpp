#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//para hacerlo mas eficiente uso una estructura de 3 dimensiones con vectores para memorizacion. Me basta con los parametros i, j, que determinan la posicion y de los
//cuales se deducen los pasos minimos que se requieren para llegar a dicha posicion, y la variable balance, que representa la diferencia entre aulas frias y calientes
//en dicha posicion

using namespace std;
int n, m;
vector<vector<int>> M;
int offset; //utilizo un offset para manejar indices negativos en dp

bool funcion(int i, int j, int balance, const vector<vector<int>> &M, vector<vector<vector<int>>> &dp){
    if (abs(balance) > n + m - 1 - (i + j)) return false;
    
    if (i >= n || j >= m) return false;
    if (M[i][j] == 1) balance++;
    if (M[i][j] == -1) balance--;

    if (i == n - 1 && j == m - 1) return balance == 0;
    

    if (dp[i][j][balance + offset] != -1) return dp[i][j][balance + offset];

    bool res = funcion(i + 1, j, balance, M, dp) || funcion(i, j + 1, balance, M, dp);
    dp[i][j][balance + offset] = res ? 1 : 0;
    return res;
}

int main(){
    int T;
    cin >> T;
    vector<string> respuestas;

    while (T > 0){
        T--;
        cin >> n >> m;
        M = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> M[i][j];
            }
        }
        offset = m + n - 1;
        int dimensionBalance = 2 * offset + 1;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(dimensionBalance, -1)));

        bool res = funcion(0, 0, 0, M, dp);
        if (res) respuestas.push_back("YES");
        else respuestas.push_back("NO");
    }

    for (int i = 0; i < respuestas.size(); i++){
        cout << respuestas[i] << endl;
    }
}
