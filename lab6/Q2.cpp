#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#define int ll

const ll INF = 1e15;
const int MAXN = 205;

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

int n, s, t, sum[MAXN][MAXN];
Dinic flow;


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    s = 0; t = n + 1;
    flow.init(n+1);


    for (int i = 1; i <= n; ++i) {
        int w; cin >> w;
        flow.addedge(s, i, w);
    }

    for (int i = 1; i <= n; ++i) {
        int w; cin >> w;
        flow.addedge(i, t, w);
    }

    memset(sum, 0, sizeof(sum));

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        sum[u][v] += w;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (sum[i][j]) {
                flow.addedge2(i, j, sum[i][j]);
            }
        }
    }

    cout << flow.maxflow(s, t) << '\n';
    return 0;
}
