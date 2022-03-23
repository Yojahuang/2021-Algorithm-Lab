#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100005;

int n, in[MAXN], lhs, midpoint;

int LBS(int l, int r, int val) {
    if (l > r) return -1;
    int m = (l + r) >> 1;
    if (in[m] == val) return m;
    else if (in[m] > val) {
        return LBS(l, m-1, val);
    } else {
        return LBS(m+1, r, val);
    }
}

int RBS(int l, int r, int val) {
    if (l > r) return -1;
    int m = (l + r) >> 1;
    if (in[m] == val) return m;
    else if (in[m] < val) {
        return RBS(l, m-1, val);
    } else {
        return RBS(m+1, r, val);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    while (cin >> n >> q) {
        for (int i = 0; i < n; ++i) cin >> in[i];
        lhs = in[0];
        for (int i = 0; i < n - 1; ++i) {
            if (in[i] > in[i+1]) {
                midpoint = i;
                break;
            }
        }

        while (q--) {
            int val;
            cin >> val;
            if (val >= lhs) {
                cout << LBS(0, midpoint, val) << '\n';
            } else {
                cout << RBS(midpoint + 1, n - 1, val) << '\n';
            }
        }
    }
    return 0;
}
