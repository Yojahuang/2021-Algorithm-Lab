#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n;

vector<int> getLIS(const vector<int>& in) {
    vector<int> w, result;
    w.clear(); result.clear();

    for (auto x : in) {
        if (w.empty() || w.back() < x) {
            w.push_back(x);
            result.push_back(w.size());
        } else {
            int idx = lower_bound(w.begin(), w.end(), x) - w.begin();
            w[idx] = x;
            result.push_back(idx);
        }
    }

    return result;
}

int get_ans(vector<int>& in) {
    vector<int> a, b;

    a = getLIS(in);
    reverse(in.begin(), in.end());
    b = getLIS(in);
    reverse(in.begin(), in.end());

    int result = a[0] + b[n-1] - 1;
    for (int i = 0; i < n; ++i) {
        result = max(result, a[i] + b[n-1-i] - 1);
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> in;
    while (cin >> n) {
        in.clear();
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            in.push_back(v);
        }

        int ans = get_ans(in);
        for (int i = 0; i < n; ++i) in[i] *= -1;

        ans = max(ans, get_ans(in));
        cout << ans << '\n';
    }
    return 0;
}
