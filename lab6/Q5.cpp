#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#define int ll

const int MAXN = 1005;
const int INF = 1e15;

class Edge {
public:
    int from, to, w;
    Edge(int _from, int _to, int _w) {
        to = _to;
        from = _from;
        w = _w;
    }

    const bool operator <(const Edge &rhs) const {
        return w > rhs.w;
    }
};

int n, e, dis[MAXN];
vector<Edge> edges;

bool relax(int val) {
    bool result = false;
    for (int i = 0; i < e; ++i) {
        if (edges[i].w <= val) break;
        if (dis[edges[i].to] > dis[edges[i].from] + edges[i].w) {
            result = true;
            dis[edges[i].to] = dis[edges[i].from] + edges[i].w;
        }
    }

    return result;
}

bool check(ll val) {
    for (int i = 0; i < n; ++i) dis[i] = INF;
    dis[0] = 0;

    for (int i = 1; i < n; ++i) {
        if (!relax(val)) return true;
    }


    if (relax(val)) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int l = 1, r = 0, m;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
        l = min(l, w);
    }

    sort(edges.begin(), edges.end());

    if (check(l-1)) {
        cout << "GO AHEAD\n";
        return 0;
    }

    while (l <= r) {
        m = (l + r) >> 1;
        if (check(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    bool bad = true;

    for (auto it : edges) {
        if (it.w < 0 && it.w > l) {
            bad = false;
        }
    }

    if (bad) cout << "NO WAY BACK\n";
    else cout << l << '\n';

    return 0;
}
