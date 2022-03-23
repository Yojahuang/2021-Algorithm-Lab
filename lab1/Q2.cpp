#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long

const int MAXN = 5005;

int n, in[MAXN];

ll calc(int r, int val) {
    int ret = 0, s = 0, t = r;
    bool f = false;
    while (t > s) {
        while (in[s] + in[t] < val && s < t) s++;
        if (s >= t) break;
        if (in[s] + in[t] == val && !f) {
            ret++;
            if (in[s] == in[t]) f = true;
        }
        t--;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    while (cin >> n >> t) {
        for (int i = 0; i < n; ++i) cin >> in[i];
        sort(in, in + n);

        ll ans = 0;

        for (int i = n-1; i > 1; --i) {
            if (i != n - 1 && in[i] == in[i+1]) continue;
            ans += calc(i - 1, t - in[i]);
        }

        if (ans == 0) cout << "FeiDooDoo_Zuo_Wei_Men\n";
        else cout << ans << '\n';
    }
    return 0;
}
