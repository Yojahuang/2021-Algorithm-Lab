#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

ll in[1000005], weight[1000005], cost[1000005], DP[2][1000005];
pair<pii,ll> c[1000005];
int n, m, s;

int get(int v) {
    return v % 2;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) cin >> in[i];
    sort(in, in + n);

    for (int i = 0; i < m; ++i) {
        cin >> c[i].first.first >> c[i].first.second >> cost[i];
        c[i].second = i;
    }
    sort(c, c + m);

    ll ans = 0;

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while (in[i] > c[cur].first.second && cur < m) cur++;
        if (cur == m) ans++;
        else {
            if (c[cur].first.first <= in[i] && in[i] <= c[cur].first.second) {
                weight[c[cur].second]++;
            } else {
                ans++;
            }
        }
    }

    memset(DP, 0, sizeof(DP));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= s; ++j) {
            DP[get(i)][j] = DP[get(i+1)][j];
            if (j >= cost[i]) DP[get(i)][j] = max(DP[get(i+1)][j - cost[i]] + weight[i], DP[get(i)][j]);
        }
    }

    cout << ans + DP[get(m-1)][s] << '\n';
    return 0;
}
