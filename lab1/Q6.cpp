#include<bits/stdc++.h>
using namespace std;

using ll = long long;

multiset<int> G;
ll n, l, k;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> l >> k) {
        G.clear();
        
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            G.insert(v);
        }

        while (!G.empty()) {
            cnt++;
            ll a = *prev(G.end()), b;
            G.erase(G.find(a));
            b = l - a;
            if (G.empty()) break;
            if (*(G.begin()) > b) continue;

            auto it = prev(G.upper_bound(b));
            b = *it;
            G.erase(G.find(b));
        }

        cout << (ll)cnt * 2ll * k << '\n';
    }
    return 0;
}
