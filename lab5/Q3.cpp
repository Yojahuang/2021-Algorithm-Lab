#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

vector<int> G[MAXN], rG[MAXN], stamp, sccG[MAXN];
int n, m;
int vis[MAXN], rnd;
int sccCnt, whichScc[MAXN], sccWeight[MAXN];
int DP[MAXN];
bool DP_vis[MAXN];

void dfs1(int id) {
    vis[id] = rnd;

    for (auto x : G[id]) {
        if (vis[x] == rnd) continue;
        dfs1(x);
    }
    stamp.push_back(id);
}

void dfs2(int id, int sccId) {
    vis[id] = rnd;
    whichScc[id] = sccId;
    sccWeight[sccId]++;

    for (auto x : rG[id]) {
        if (vis[x] == rnd) continue;
        dfs2(x, sccId);
    }
}

int dp(int idx) {
    if (DP_vis[idx]) return DP[idx];

    DP_vis[idx] = true;
    int result = sccWeight[idx];
    for (auto x : sccG[idx]) {
        result = max(result, dp(x) + sccWeight[idx]);
    }

    DP[idx] = result;
    return DP[idx];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    rnd = 0; memset(vis, 0, sizeof(vis));

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        G[i].clear(); rG[i].clear();
        sccG[i].clear(); sccWeight[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    stamp.clear();

    rnd++;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != rnd) {
            dfs1(i);
        }
    }

    rnd++; sccCnt = 0;
    while (!stamp.empty()) {
        int now = stamp.back(); stamp.pop_back();
        if (vis[now] == rnd) continue;
        dfs2(now, sccCnt);
        sccCnt++;
    }

    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        for (auto x : G[i]) {
            if (whichScc[i] == whichScc[x]) continue;
            sccG[whichScc[i]].push_back(whichScc[x]);
            tmp++;
        }
    }

    for (int i = 0; i < sccCnt; ++i) {
        sort(sccG[i].begin(), sccG[i].end());
        sccG[i].resize(unique(sccG[i].begin(), sccG[i].end()) - sccG[i].begin());
    }

    int ans = 0;
    for (int i = 0; i < sccCnt; ++i) ans = max(ans, dp(i));

    cout << ans << '\n';

}
