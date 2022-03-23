#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll a, b, q, k;

ll fastpower(ll x, ll y) {
    if (y == 0) return 1;
    else {
        if (y & 1) return x * fastpower(x, y - 1) % mod;
        else return fastpower((x * x) % mod, y / 2) % mod;
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> a >> b >> q) {
        k = b / (a - 1);
        k = ((k % mod) + mod) % mod;
        while (q--) {
            ll val; cin >> val;
            if (val == 1) cout << "1\n";
            else {
                ll ans = k * fastpower(a,  val - 1) % mod;
                ans = ((ans + fastpower(a, val - 1)) % mod) - k;
                ans = ((ans % mod) + mod) % mod;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
