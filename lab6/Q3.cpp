#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#define int ll

const ll INF = 1e15;
const int MAXN = 10500;

class Edge {
public:
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};


class Dinic {
private:
    vector<Edge> G[MAXN];
    int s, t, ptr[MAXN], level[MAXN];

public:
    void init(int sz) {
        for (int i = 0; i <= sz; ++i) G[i].clear();
    }

    void addedge(int from, int to, int cap) {
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, 0, G[from].size()-1));
    }

    void addedge2(int from, int to, int cap) {
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, cap, G[from].size()-1));
    }

    bool bfs() {
        memset(ptr, 0, sizeof(ptr));
        memset(level, -1, sizeof(level));

        queue<int> qu;
        level[s] = 0; qu.push(s);

        while (!qu.empty()) {
            int now = qu.front(); qu.pop();
            for (auto nowE : G[now]) {
                if (level[nowE.to] == -1 && nowE.cap > 0) {
                    level[nowE.to] = level[now] + 1;
                    qu.push(nowE.to);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int now, int f) {
        if (now == t || f == 0) return f;
        for (int &i = ptr[now]; i < G[now].size(); ++ptr[now]) {
            Edge &x = G[now][ptr[now]];
            if (x.cap > 0 && level[x.to] > level[now]) {
                int tmp = dfs(x.to, min(f, x.cap));
                if (tmp > 0) {
                    x.cap -= tmp;
                    G[x.to][x.rev].cap += tmp;
                    return tmp;
                }
            }
        }
        level[now] = -1;
        return -1;
    }

    int maxflow(int _s, int _t) {
        this -> s = _s;
        this -> t = _t;

        int result = 0;
        while (1) {
            if (!bfs()) break;
            int tmp = 0;
            do {
                result += tmp;
                tmp = dfs(s, INF);
            } while (tmp > 0);
        }
        return result;
    }
};

Dinic flow;
int f, n, m;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> f >> n >> m;

    int s = 0, t = (f + n + m + 1) * 2;

    for (int i = 1; i <= f; ++i) {
        int w; cin >> w;
        flow.addedge(s, i, w);
    }

    for (int i = f + 1; i <= f + n; ++i) {
        int w; cin >> w;
        flow.addedge(i * 2, i * 2 + 1, w);
    }

    for (int i = f + n + 1; i <= f + n + m; ++i) {
        int w; cin >> w;
        flow.addedge(i * 2, i * 2 + 1, w);
        flow.addedge(i * 2 + 1, t, INF);
    }

    int c; cin >> c;
    for (int i = 0; i < c; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        v += f;
        flow.addedge(u, v * 2, w);
    }

    cin >> c;
    for (int i = 0; i < c; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u += f;
        v += f + n;
        flow.addedge(u * 2 + 1, v * 2, w);
    }

    int k; cin >> k;

    cout << min(k, flow.maxflow(s, t)) << '\n';
    return 0;
}
