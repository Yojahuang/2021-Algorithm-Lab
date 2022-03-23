#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<ll> problems;
ll w[7] = {1000, 500, 100, 50, 10, 5, 1}, cnt[7];

bool ok(ll v) {
    for (int i = 0; i < 7; ++i) {
        if (w[i] <= v && cnt[i] > 0) {
            ll p = min(cnt[i], v / w[i]);
            cnt[i] -= p;
            v -= p * w[i];
        }
    }

    if (v) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        problems.clear();

        ll sum, sum2, n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> sum; sum2 = 0;
            for (int j = 0; j < 7; ++j) {
                ll val; cin >> val;
                cnt[j] += val;
                sum2 += val * w[j];
            }
            if (sum2 - sum > 0) problems.push_back(sum2 - sum);
        }

        bool bad = false;
        for (auto x : problems) {
            if (!ok(x)) {
                bad = true;
                break;
            }
        }

        if (bad) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
