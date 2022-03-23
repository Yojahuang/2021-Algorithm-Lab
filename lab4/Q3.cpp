#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

const ll mod = 1000000007;

vector<int> to[8];
ll DP[2][8], ans[10000001];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    to[0] = {0, 2, 4};
    to[1] = {0, 4};
    to[2] = {0};
    to[3] = {0};
    to[4] = {0, 2};
    to[5] = {0};
    to[6] = {0};
    to[7] = {0};

    for (int i = 0; i < 8; ++i) DP[1][i] = 1;
    ans[0] = ans[1] = 1;

    for (int now = 2; now <= 10000000; ++now) {
        for (int mask = 0; mask < 8; ++mask) {
            DP[now % 2][mask] = 0;
            for (auto it : to[mask]) {
                DP[now % 2][mask] += DP[(now-1) % 2][it];
                if (DP[now % 2][mask] >= mod) DP[now % 2][mask] -= mod;
            }
        }

        ans[now] = ans[now] + DP[(now-1) % 2][0] + DP[(now-1) % 2][2] + DP[(now-1) % 2][4];
        ans[now] *= 4ll;
        ans[now] -= 3;
        ans[now] %= mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int idx;
        cin >> idx;
        cout << ans[idx] << '\n';
    }
    return 0;
}
