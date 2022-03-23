#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

const ll INF = 1e15;
const int MAXN = 505;

ll DP[MAXN][MAXN];
int n, m, q;

void initialize() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            DP[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i) DP[i][i] = 0;
}

void getDP() {
    for (int m = 0; m < n; ++m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                DP[i][j] = min(DP[i][j], DP[i][m] + DP[m][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    initialize();

    for (int i = 0; i < m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        DP[u][v] = min(DP[u][v], w);
    }
    getDP();
    cin >> q;

    while (q--) {
        int u, v; cin >> u >> v;
        if (DP[u][v] == INF) cout << "-1\n";
        else cout << DP[u][v] << '\n';
    }
}
