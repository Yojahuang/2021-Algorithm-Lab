#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 100005;

#define int ll

int n, m, c, f, s, dis[MAXN];
vector< pair<int,pii> > edges;

int fa(int id) {
    if (dis[id] != id) dis[id] = fa(dis[id]);
    return dis[id];
}

int get_mst_cost() {
    int result = 0;

    for (int i = 0; i < n; ++i) dis[i] = i;
    sort(edges.begin(), edges.end());

    for (auto it : edges) {
        int a = it.second.first, b = it.second.second;
        if (fa(a) == fa(b)) continue;
        dis[fa(a)] = fa(b);
        result += it.first;
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> c >> f >> s;
        edges.clear();

        for (int i = 0; i < m; ++i) {
            int u, v; char w;
            cin >> u >> v >> w;
            if (w == 'S') edges.push_back(make_pair(0, make_pair(u, v)));
            else edges.push_back(make_pair(1, make_pair(u, v)));
        }

        int cnt1, cnt2;
        cnt1 = n - 1; cnt2 = 0;

        if (s != f) {
            while (s * cnt1 + f * cnt2 < c && cnt1 >= 0) {
                cnt1--;
                cnt2++;
            }

            if (s * cnt1 + f * cnt2 != c) {
                cout << "No\n";
                continue;
            }

            int v = get_mst_cost();

            for (auto &it : edges) it.first ^= 1;

            int w = get_mst_cost();

            for (auto &it : edges) it.first = 1;

            if (v > cnt2 || w > cnt1 || get_mst_cost() != n - 1) cout << "No\n";
            else cout << "Yes\n";
        } else {
            for (auto &it : edges) it.first = 1;
            if (c / s != n - 1 || c % s || get_mst_cost() != n - 1) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}
