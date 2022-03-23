#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;

int w[MAXN], in[MAXN], post[MAXN], pos[MAXN], ans, n;

void calc(int in_l, int in_r, int post_l, int post_r, int ancestor_w) {
    if(in_l > in_r || post_l > post_r) return;
    int val = w[post[post_r]];
    if (val > ancestor_w) ans++;

    int in_m = pos[post[post_r]], l_sz = in_m - in_l;
    calc(in_l, in_m - 1, post_l, post_l + l_sz - 1, val);
    calc(in_m + 1, in_r, post_l + l_sz, post_r - 1, val);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n) {
        ans = 0;
        for (int i = 1; i <= n; ++i) cin >> w[i];
        for (int i = 1; i <= n; ++i) cin >> in[i];
        for (int i = 1; i <= n; ++i) cin >> post[i];
        for (int i = 1; i <= n; ++i) pos[in[i]] = i;
        calc(1, n, 1, n, 1000000001);
        cout << ans << '\n';
    }
    return 0;
}
