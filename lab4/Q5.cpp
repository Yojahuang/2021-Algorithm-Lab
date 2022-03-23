#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

const int MAXN = 2005;
const int MAXM = 505;

int n, m;
long long in[MAXN][MAXM], DP[MAXN][MAXM];
bool vis[MAXN][MAXM];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> in[i][j];
        }
    }

    for (int j = 0; j < m; ++j) DP[n-1][j] = in[n-1][j];

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            DP[i][j] = in[i][j] + DP[i+1][j];
            if (j - 1 >= 0) DP[i][j] = max(DP[i][j], in[i][j] + DP[i+1][j-1]);
            if (j + 1 <  m) DP[i][j] = max(DP[i][j], in[i][j] + DP[i+1][j+1]);
        }
    }

    for (int i = 0; i < m; ++i) cout << DP[0][i] << " \n"[i == m];
    return 0;
}
