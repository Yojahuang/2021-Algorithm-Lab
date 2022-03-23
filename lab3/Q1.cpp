#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;


const int MAXN = 500505;

set<int> st;
set<pii> expir;
vector<int> G[MAXN];
int max_st, in[MAXN], n;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int ans, c;
    while (cin >> c >> max_st >> n) {
        ans = 0;
        for (int i = 1; i <= c; ++i) G[i].clear();
        st.clear(); expir.clear();

        for (int i = 0; i < n; ++i) {
            cin >> in[i];
            G[in[i]].push_back(i);
        }

        for (int i = 1; i <= c; ++i) G[i].push_back(n+1);
        for (int i = 1; i <= c; ++i) reverse(G[i].begin(), G[i].end());

        for (int i = 0; i < n; ++i) {
            if (st.find(in[i]) != st.end()) {
                int a, b;
                a = G[in[i]].back();
                b = in[i];

                // cerr << a << ' ' << i << ' ' << in[i] << '\n';
                assert(a == i);

                G[b].pop_back();
                expir.erase(expir.find(make_pair(a,b)));
                expir.insert(make_pair(G[b].back(), b));
            }
            else {
                ans++;
                if (st.size() < max_st) {
                    G[in[i]].pop_back();
                    expir.insert(make_pair(G[in[i]].back(), in[i]));
                    st.insert(in[i]);
                } else {
                    auto it = prev(expir.end());
                    int a, b;
                    a = it->first; b = it->second;
                    expir.erase(it);
                    st.erase(st.find(b));

                    G[in[i]].pop_back();
                    st.insert(in[i]);
                    expir.insert(make_pair(G[in[i]].back(), in[i]));
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
