#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> ans[19];

void build() {
    ans[0] = {1};
    for (int i = 1; i <= 18; ++i) {
        ans[i].clear();
        int s = 1 << (i - 1);
        for (auto x : ans[i-1]) {
            ans[i].push_back(x + s);
        }
        for (int j = ans[i-1].size() - 1; j >= 0; --j) ans[i].push_back(ans[i-1][j]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    build();
    int n;
    while (cin >> n) {
        for (auto x : ans[n]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
