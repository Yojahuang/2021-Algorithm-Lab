#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct Furniture {
    long long weight, cnt[2];

    bool operator<(const Furniture &rhs) const {
        double x, y;

        if (cnt[0] + cnt[1] == 0) x = weight;
        else x = ((double)weight / (double)(cnt[0] + cnt[1] + 1ll)) * (double)(cnt[1] + 1ll) - ((double)weight / (double)(cnt[0] + cnt[1])) * (double)(cnt[1]);

        if (rhs.cnt[0] + rhs.cnt[1] == 0) y = rhs.weight;
        else y = ((double)rhs.weight / (double)(rhs.cnt[0] + rhs.cnt[1] + 1ll)) * (double)(rhs.cnt[1] + 1ll) - ((double)rhs.weight / (double)(rhs.cnt[0] + rhs.cnt[1])) * (double)(rhs.cnt[1]) ;

        return x < y;
    }
};

priority_queue<Furniture> G;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        while (!G.empty()) G.pop();

        for (int i = 0; i < n; ++i) {
            Furniture tmp;
            long long a, b;
            cin >> a >> b;
            tmp.weight = a;
            tmp.cnt[0] = b;
            tmp.cnt[1] = 0;
            G.push(tmp);
        }

        while (m--) {
            Furniture tmp = G.top(); G.pop();
            tmp.cnt[1]++;
            G.push(tmp);
        }

        double ans = 0;
        while (!G.empty()) {
            Furniture x = G.top(); G.pop();
            if (x.cnt[0] + x.cnt[1] == 0ll) continue;
            double tmp = (double)x.weight / (double)(x.cnt[0] + x.cnt[1]) * (double)(x.cnt[1]);
            ans += tmp;
        }
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}
