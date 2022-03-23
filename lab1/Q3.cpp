#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n, k, p[MAXN], c[MAXN];

bool check(double val) {
    int now = k;
    for (int i = 0; i < n; ++i) {
        double tmp = (double)c[i] / (double) (p[i] + 1);
        if (tmp < val) continue;
        tmp = (double) c[i] / val;
        int cnt = floor(tmp);
        now -= (cnt - p[i]);
        if (now < 0) break;
    }
    return now <= 0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) cin >> c[i] >> p[i];

        double l, r, m;
        l = 0; r = 1000000000.0;
        for (int i = 0; i < 52; ++i) {
            m = (l + r) / 2.0;
            if (check(m)) l = m;
            else r = m;
        }
        cout << fixed;
        cout << setprecision(6) << m << '\n';
    }
    return 0;
}
