#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#define int ll

const int MAXN = 200005;
const ll mod = 1000000007;

vector<pll> G[MAXN];
int m, dis[MAXN];
ll sz[MAXN], ans, n;
vector< pair<ll,pll> > edges;

int fa(int id) {
    if (dis[id] != id) dis[id] = fa(dis[id]);
    return dis[id];
}

void dfs(int id, int fa) {
    sz[id] = 1;
    for (auto x : G[id]) {
        if (x.first == fa) continue;
        dfs(x.first, id);
        sz[id] += sz[x.first];

        ll tmp = (x.second * sz[x.first]) % mod;
        tmp = tmp * (n - sz[x.first]); tmp %= mod;
        tmp *= 2ll; tmp %= mod;

        ans += tmp; ans %= mod;
    }

    sz[id] %= mod;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) sz[i] = 0;
    for (int i = 1; i <= n; ++i) dis[i] = i;
    edges.clear();

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    ll ans1;
    ans1 = 0;
    for (auto it : edges) {
        int a, b;
        a = it.second.first;
        b = it.second.second;
        if (fa(a) == fa(b)) continue;

        dis[fa(a)] = fa(b);
        ans1 += it.first;
        ans1 %= mod;
        G[a].push_back(make_pair(b, it.first));
        G[b].push_back(make_pair(a, it.first));
        cnt++;
    }

    ans1 *= 2;
    ans1 %= mod;

    if (cnt != n - 1) {
        cout << "-1\n";
        return 0;
    }

    cout << ans1 << ' ';
    ans = 0;
    dfs(1, 1);
    cout << ans << '\n';
}
