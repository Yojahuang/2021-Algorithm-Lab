#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;
const ll mod = 1000000007;

int BIT[MAXN], n;

inline int lowbit(int id) {
    return id & (-id);
}

int query(int id) {
    int sum = 0;
    while (id) {
        sum += BIT[id];
        id -= lowbit(id);
    }
    return sum;
}

void modify(int id, int x) {
    while (id <= n) {
        BIT[id] += x;
        id += lowbit(id);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) BIT[i] = 0;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            v = min(v, n);
            modify(v+1, -1);
            modify(1, 1);
        }

        ll ans = 1;
        for (int i = n; i >= 1; --i) {
            ll tmp = query(i);
            modify(1, -1);
            ans *= tmp;
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
