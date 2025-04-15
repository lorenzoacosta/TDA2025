#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
// para la estructura de memorizacion combino vectores y un diccionario para optimizarlo en cuanto a tiempo y tambien memoria
int n, m;
vector<vector<int>> M;

bool funcion(int i, int j, int balance, vector<vector<int>> &M, vector<vector<unordered_map<int, bool>>> &dp) {
    // poda: si ya no se puede balancear en lo que queda de recorrido
    if (abs(balance) > (n + m - 1 - (i + j))) return false;

    // si me salgo del mapa
    if (i >= n || j >= m) return false;

    if (M[i][j] == 1) balance++;
    if (M[i][j] == -1) balance--;

    if (i == n - 1 && j == m - 1) return balance == 0;

    if (dp[i][j].count(balance)) return dp[i][j][balance];

    bool res = false;
    if (i + 1 < n) res = res || funcion(i + 1, j, balance, M, dp);
    if (j + 1 < m) res = res || funcion(i, j + 1, balance, M, dp);

    dp[i][j][balance] = res;
    return res;
}

int main() {
    int T;
    cin >> T;
    vector <string> respuestas;
    while (T--) {
        cin >> n >> m;
        M = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];

        vector<vector<unordered_map<int, bool>>> dp(n, vector<unordered_map<int, bool>>(m));

        bool res = funcion(0, 0, 0, M, dp);
        respuestas.push_back(res ? "YES" : "NO");
    }

    for (int i = 0; i < respuestas.size();  i++){
        cout << respuestas[i] << endl;
    }
}
