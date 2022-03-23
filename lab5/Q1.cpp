#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;

set<int> G[MAXN];
vector<int> answer;
vector<pair<char, pair<int,int>>> operations;
int dis[MAXN], n, q, m;

int fa(int id) {
    if (dis[id] != id) dis[id] = fa(dis[id]);
    return dis[id];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[v].insert(u);
        G[u].insert(v);
    }

    for (int i = 0; i < q; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'U') {
            G[a].erase(b);
            G[b].erase(a);
        }
        operations.push_back(make_pair(c, make_pair(a,b)));
    }

    for (int i = 1; i <= n; ++i) dis[i] = i;

    for (int i = 1; i <= n; ++i) {
        for (auto x : G[i]) {
            dis[fa(i)] = fa(x);
        }
    }

    reverse(operations.begin(), operations.end());

    for (auto it : operations) {
        int a, b;
        a = it.second.first;
        b = it.second.second;

        if (it.first == 'U') {
            dis[fa(a)] = fa(b);
        } else {
            if (fa(a) ==fa(b)){
                answer.push_back(1);
            } else {
                answer.push_back(0);
            }
        }
    }

    reverse(answer.begin(), answer.end());

    string tmp[2] = {"NO\n", "YES\n"};
    for (auto it : answer) {
        cout << tmp[it];
    }
}
