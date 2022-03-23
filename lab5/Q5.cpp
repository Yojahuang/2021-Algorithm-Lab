#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 300005;

vector<int> G[MAXN];
int result[2][MAXN];
int n, m, s, vis[MAXN], rnd;

void getDistance(int st, int idx) {
    queue<pii> qu;

    while (!qu.empty()) qu.pop();
    rnd++;

    result[idx][st] = 0;
    qu.push(make_pair(0, st));
    vis[st] = rnd;

    while (!qu.empty()) {
        pii now = qu.front(); qu.pop();

        for (auto it : G[now.second]) {
            if (vis[it] == rnd) continue;
            result[idx][it] = now.first + 1;
            qu.push(make_pair(result[idx][it], it));
            vis[it] = rnd;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    rnd = 1;
    memset(vis, 0, sizeof(vis));

    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        for (int i = 1; i <= n + 1; ++i) G[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        int cnt;
        cin >> cnt;
        while (cnt--) {
            int tmp; cin >> tmp;
            G[tmp].emplace_back(n+1);
            G[n+1].emplace_back(tmp);
        }

        getDistance(n+1, 0);
        getDistance(s, 1);

        bool ok = false;

        cin >> cnt;
        while (cnt--){
            int tmp; cin >> tmp;
            if (result[1][tmp] < result[0][tmp] - 1) ok = true;
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
