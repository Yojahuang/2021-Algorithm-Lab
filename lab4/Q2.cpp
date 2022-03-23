#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 102;
const ll INF = 1e18;

int n;
ll in[MAXN], prefix[MAXN], DP[MAXN][MAXN];
bool vis[MAXN][MAXN];

ll dp(int l, int r) {
    if (l == r) return 0;
    if (l + 2 == r) return in[l] * in[r] - in[l+1];
    if (vis[l][r]) return DP[l][r];

    vis[l][r] = true;
    DP[l][r] = -INF;

    for (int m1 = l+1; m1 < r; m1 += 2) {
        for (int m2 = m1; m2 < r; m2 += 2) {
            ll a, b, c;
            a = prefix[m1-1] - prefix[l-1];
            b = prefix[m2] - prefix[m1-1];
            c = prefix[r] - prefix[m2];
            DP[l][r] = max(DP[l][r], dp(l, m1-1) + dp(m1, m2) + dp(m2+1, r) + a * c - b);
        }
    }
    return DP[l][r];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> in[i];
            prefix[i] = prefix[i-1] + in[i];
        }

        memset(vis, 0, sizeof(vis));
        cout << dp(1, n) << '\n';
    }
    return 0;
}
