#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000001;

int n;
ll in[MAXN], k;

ll calc(ll l, ll r) {
    if (in[n-1] < l) return 0;
    if (in[0] > r) return 0;

    ll ans = 0;

    for (ll now = 1; now * l <= r; ++now) {
        ll st1 = lower_bound(in, in + n, now * l) - in;
        ll st2 = upper_bound(in, in + n, min(r, (now + 1ll) * l - 1)) - in;
        ans += (st2 - st1) * now;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) cin >> in[i];
        sort(in, in + n);
        int q;
        cin >> q;
        while (q--) {
            ll l, r;
            cin >> l >> r;
            r = min(r, k * l);
            cout << calc(l, r) << '\n';
        }
    }
    return 0;
}
