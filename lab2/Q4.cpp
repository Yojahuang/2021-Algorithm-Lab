#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;
using ll = long long;

#define int ll

int n;
ll w[MAXN];

ll getCost(vector<ll>& in) {
    int m = (in.size() - 1) / 2;
    ll val = in[m], ans = 0;
    for (auto x : in) ans += abs(x - val);
    return ans;
}

ll merge_sort(int l, int r) {
    if (l == r) return 0;
    int m = (l + r) >> 1;

    ll ansl = merge_sort(l, m);
    ll ansr = merge_sort(m+1, r);

    // merge
    vector<ll> a, b;
    int cur = r;
    for (int i = l; i <= m; ++i) a.push_back(w[i]);
    for (int i = m+1; i <= r; ++i) b.push_back(w[i]);

    ll costl, costr;
    costl = getCost(a);
    costr = getCost(b);

    while (cur >= l) {
        if (a.empty()) {
            w[cur] = b.back(); b.pop_back();
        }
        else if (b.empty()) {
            w[cur] = a.back(); a.pop_back();
        } else {
            if (a.back() > b.back()) {
                w[cur] = a.back(); a.pop_back();
            } else {
                w[cur] = b.back(); b.pop_back();
            }
        }
        cur--;
    }

    if (r - l < 2) return 0;
    return min(ansl + costr, ansr + costl);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> w[i];
        cout << merge_sort(0, n - 1) << '\n';
    }
    return 0;
}
