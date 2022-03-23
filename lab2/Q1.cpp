#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2000005;
const ll mod = 1000000007;

ll input[MAXN], c[MAXN];
bool vis[MAXN];
int degree[MAXN], to[MAXN], n;
queue<int> qu;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    memset(vis, 0, sizeof(vis));
    memset(degree, 0, sizeof(degree));
    for (int i = 1; i <= n; ++i) input[i] = 1;
    while (!qu.empty()) qu.pop();

    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 2; i <= n; ++i) {
        cin >> to[i];
        degree[to[i]]++;
    }

    for (int i = 1; i <= n; ++i) if (degree[i] == 0) qu.push(i);

    while (!qu.empty()) {
        int now = qu.front(); qu.pop();
        if (now == 1) break;
        if (!vis[to[now]]) {
            vis[to[now]] = true;
            input[to[now]] = 0;
        }
        input[to[now]] += (input[now] * c[now]) % mod;
        input[to[now]] %= mod;
        degree[to[now]]--;
        if (degree[to[now]] == 0) {
            qu.push(to[now]);
        }
    }

    ll ans = (input[1] * c[1]) % mod;
    cout << ans << '\n';
    return 0;
}
