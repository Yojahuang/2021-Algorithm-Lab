#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

#define int long long

const int MAXN = 1000505;

vector<int> input, G;
int BIT[MAXN], n;

int lowbit(int id) {
    return id & (-id);
}

void modify(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += lowbit(idx);
    }
}

int get_Kth(int rk) {
    int st = 0, cur = 0;
    while ((1ll << (st + 1)) <= n) {
        st++;
    }

    for (; st >= 0; st--) {
        int base = (1ll) << st;
        if (cur + base > n) continue;
        if (BIT[cur + base] < rk) {
            cur += base;
            rk -= BIT[cur];
        }
    }
    return cur + 1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    memset(BIT, 0, sizeof(BIT));
    G.clear(); input.clear();

    int tmp;
    while (cin >> tmp && tmp) input.push_back(tmp);

    G = input;

    sort(G.begin(), G.end());
    G.resize(unique(G.begin(), G.end()) - G.begin());

    n = 500005;

    for (int i = 0; i < input.size(); ++i) {
        int val = lower_bound(G.begin(), G.end(), input[i]) - G.begin() + 1;
        input[i] = val;
    }

    int sz = 0;
    for (auto i : input) {
        sz++;
        modify(i, 1);

        if (sz == 1) {
            cout << "0\n";
            continue;
        }
        else {
            int st = sz % 4, s, f, half_sz;
            half_sz = sz / 2;

            if (st == 0) {
                int dx = half_sz / 2;
                int dx2 = dx + 1;
                s = G[get_Kth(dx) - 1] + G[get_Kth(dx2) - 1];
                f = G[get_Kth((sz - half_sz) + dx) - 1] + G[get_Kth((sz - half_sz) + dx2) - 1];
            } else if (st == 1) {
                int dx = (1 + half_sz) / 2;
                int dx2 = dx + 1;
                s = G[get_Kth(dx) - 1] + G[get_Kth(dx2) - 1];
                f = G[get_Kth(sz - half_sz + dx) - 1] + G[get_Kth(sz - half_sz + dx2) - 1];
            } else if (st == 2) {
                s = G[get_Kth((1 + half_sz) / 2) - 1] * 2;
                f = G[get_Kth((sz + 1 + half_sz) / 2) - 1] * 2;
            } else {
                s = G[get_Kth((1 + half_sz) / 2) - 1] * 2;
                f = G[get_Kth((sz - half_sz) + (1 + half_sz) / 2) - 1] * 2;
            }

            f -= s;

            if (f & 1) {
                cout << f / 2ll << ".5\n";
            } else {
                cout  << f / 2ll << '\n';
            }
         }
    }
    return 0;
}
