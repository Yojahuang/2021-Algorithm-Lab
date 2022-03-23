#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long

const int MAXN = 1000005;

struct Student {
    string name;
    int house, score[4];
}in[MAXN];

string cmp[4], housename[4] = {"GRYFFINDOR", "HUFFLEPUFF", "RAVENCLAW", "SLYTHERIN"};
vector<Student> G[4];
map<char, int> table;
int n;

bool cmpFunction(Student &lhs, Student &rhs) {
    int house = lhs.house;
    for (int i = 0; i < 4; ++i) {
        int now = table[cmp[house][i]];
        if (lhs.score[now] !=  rhs.score[now]) return lhs.score[now] > rhs.score[now];
    }
    return lhs.name < rhs.name;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    table['G'] = 0;
    table['H'] = 1;
    table['R'] = 2;
    table['S'] = 3;
    while (cin >> n) {
        for (int i = 0; i < 4; ++i) cin >> cmp[i];
        for (int i = 0; i < 4; ++i) G[i].clear();

        for (int i = 0; i < n; ++i)
            cin >> in[i].name >> in[i].score[0] >> in[i].score[1] >> in[i].score[2] >> in[i].score[3];

        for (int i = 0; i < n; ++i) {
            int val = max({in[i].score[0], in[i].score[1], in[i].score[2], in[i].score[3]});
            if(in[i].score[0] == val) G[0].push_back(in[i]);
            else if(in[i].score[1] == val) G[1].push_back(in[i]);
            else if(in[i].score[2] == val) G[2].push_back(in[i]);
            else if(in[i].score[3] == val) G[3].push_back(in[i]);
        }

        for (int i = 0; i < 4; ++i) {
            cout << housename[i] << ":";
            if (G[i].size()) {
                cout << "\n";
                for (int j = 0; j < G[i].size(); ++j) G[i][j].house = i;
                sort(G[i].begin(), G[i].end(), cmpFunction);
                for (auto x: G[i]) cout << x.name << '\n';
            } else {
                cout << " NO NEW STUDENTS\n";
            }
        }
    }
    return 0;
}
