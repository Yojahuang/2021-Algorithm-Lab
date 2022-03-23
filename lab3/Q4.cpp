#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct node {
    node *l, *r;
    long long w;
    string s;

    node () {
        l = r = nullptr;
        w = 0;
        s = "";
    }

    node(ll _w, string _s) {
        w = _w;
        s = _s;
        l = r = nullptr;
    }
};

const int MAXN = 500005;


struct CMP {
    bool operator()(const node* lhs, const node* rhs) const {
        return lhs->w > rhs->w || (lhs->w == rhs->w && lhs->s > rhs->s);
    }
};

string in[MAXN];
map<string,int> cnt;
map<string,int> cost;

priority_queue<node*, vector<node*>, CMP> pq;

int calc(int v) {
    int res = 0;
    while ( (1ll << (res + 1)) <= v) res++;

    return res;
}

void dfs(int dep, node* now) {
    if (now->l == nullptr && now->r == nullptr) {
        cost[now->s] = dep;
        return;
    }
    if (now->l) dfs(dep+1, now->l);
    if (now->r) dfs(dep+1, now->r);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (!pq.empty()) pq.pop();
    cnt.clear();

    int t; cin >> t;
    getline(cin, in[0]);
    for (int i = 0; i < t; ++i) {
        in[i] = "";
        getline(cin, in[i]);
    }

    {
        stringstream ss; string s;
        for (int i = 0; i < t; ++i) {
            ss.clear(); ss.str("");
            ss.str(in[i]);
            while (ss >> s) {
                cnt[s] = cnt[s] + 1;
            }
        }
    }

    for (auto it : cnt) pq.push(new node(it.second, it.first));

    node *root = nullptr;
    while (!pq.empty()) {
        node *a = pq.top(); pq.pop();
        if (pq.empty()) {
            root = a;
            break;
        } else {
            node *b = pq.top(); pq.pop();
            node *c = new node(a->w + b->w, min(a->s, b->s));
            c->l = a;
            c->r = b;
            pq.push(c);
        }
    }

    dfs(0, root);

    {
        stringstream ss; string tmp;
        vector<string> s;
        for (int i = 0; i < t; ++i) {
            s.clear();
            ss.clear(); ss.str("");
            ss.str(in[i]);

            while (ss >> tmp) {
                s.push_back(tmp);
            }

            int sum1, sum2;
            sum1 = sum2 = 0;
            for (auto x : s) sum1 += cost[x];

            sum2 = s.size() * ceil(log2(cost.size()));

            cout << fixed << setprecision(10) << (double)sum1 / (double)sum2 << '\n';
        }
    }


    return 0;
}
