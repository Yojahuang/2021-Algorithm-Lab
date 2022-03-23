#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 200005;

int n, rt;
pii in[MAXN];
ll p, cnt;
priority_queue<int> G;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int cur;
    while (cin >> n >> p >> cur >> rt) {
        while (!G.empty()) G.pop();
        cnt = 0;

        for (int i = 0; i < n; ++i) cin >> in[i].first >> in[i].second;
        sort(in, in + n);

        int idx = 0;
        while (in[idx].first <= cur && idx < n) {
            G.push(in[idx].second);
            idx++;
        }

        bool bad = false;
        while (cur < rt) {
            if (G.size() == 0 || G.top() < cur) {
                bad = true;
                break;
            }

            int val = G.top();
            G.pop();
            cur = val;
            cnt++;

            while (in[idx].first <= cur && idx < n) {
                G.push(in[idx].second);
                idx++;
            }
        }

        if (bad) cout << "0\n";
        else cout << p * cnt << '\n';
    }
    return 0;
}
