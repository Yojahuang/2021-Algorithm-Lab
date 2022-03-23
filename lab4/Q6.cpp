#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 35;
const int MAXC = 100005;

int n;
ll coins[MAXN], in[MAXN], DP[MAXN][MAXC];

void calc() {
    for (int i = 0; i < n; ++i) {
        DP[i][0] = 0;
        for (int j = 1; j <= 100000; ++j){
            DP[i][j] = 1e18;
            if (j - in[i] >= 0) DP[i][j] = min(DP[i][j], DP[i][j - in[i]] + 1);
            if (i > 0) DP[i][j] = min(DP[i][j], DP[i-1][j]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
            in[i] = coins[i];
        }

        sort(in, in + n);

        calc();

        int q; cin >> q;
        while (q--) {
            ll sum, sum2 = 0;
            cin >> sum;
            for (int i = 0; i < n; ++i) {
                ll cnt; cin >> cnt;
                sum2 += cnt * coins[i];
            }

            sum2 -= sum;
            cout << DP[n-1][sum2] << '\n';
        }
    }
    return 0;
}
