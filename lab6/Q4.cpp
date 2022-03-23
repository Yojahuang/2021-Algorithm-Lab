#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

const ll INF = 1e15;
const int MAXN = 100005;

class edge {
public:
    ll u, v, w;
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {
    }
};

int n, m;
int vis[MAXN], rnd;
vector<edge> edges;

vector<ll> getDistance(int st, vector<vector<pll>>& G) {
    vector<ll> result;
    for (int i = 0; i <= n; ++i) result.push_back(INF);
    result[st] = 0;
    rnd++;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(result[st], st));

    while (!pq.empty()) {
        pll now = pq.top(); pq.pop();
        if (vis[now.second] == rnd) continue;
        vis[now.second] = rnd;
        for (auto x : G[now.second]) {
            if (result[x.first] > result[now.second] + x.second) {
                result[x.first] = result[now.second] + x.second;
                pq.push(make_pair(result[x.first], x.first));
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<vector<pll>> G, rG;

    memset(vis, 0, sizeof(vis)); rnd = 0;

    cin >> n >> m;

    G.clear(); G.resize(n + 5);
    rG.clear(); rG.resize(n + 5);

    for (int i = 0; i < m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        rG[v].push_back(make_pair(u, w));
        edges.push_back(edge(u, v, w));
    }

    vector<ll> dis_1, dis_n;
    dis_1 = getDistance(1, G);
    dis_n = getDistance(n, rG);

    for (auto e : edges) {
        ll tmp = dis_1[e.u] + dis_n[e.v];
        if (tmp > dis_1[n]) {
            cout << "-1\n";
        } else {
            tmp += e.w;
            cout << tmp - dis_1[n] << '\n';
        }
    }
}
