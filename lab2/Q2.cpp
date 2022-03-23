#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n;

map<string,ll> get_ans(int &idx) {
    map<string,ll> result, tmp;
    string cur;
    while (idx < n && s[idx] != ')') {
        // cerr << idx << ' ' << s[idx] << '\n';
        if (s[idx] == '(') {
            idx++;
            tmp = get_ans(idx);
            ll val = 0;
            // get multiple
            while (idx < n && '0' <= s[idx] && s[idx] <= '9') {
                val *= 10;
                val += s[idx] - '0';
                idx++;
            }
            // merge tmp and result
            if (val == 0) val = 1;
            for (auto x : tmp) result[x.first] += val * x.second;
        } else if ('A' <= s[idx] && s[idx] <= 'Z') {
            cur = ""; cur.push_back(s[idx]); idx++;

            while ('a' <= s[idx] && s[idx] <= 'z') {
                cur.push_back(s[idx]);
                idx++;
            }

            if ('0' <= s[idx] && s[idx] <= '9') {
                ll val = 0;
                // get multiple
                while (idx < n && '0' <= s[idx] && s[idx] <= '9') {
                    val *= 10;
                    val += s[idx] - '0';
                    idx++;
                }
                result[cur] += val;
            } else {
                result[cur]++;
            }
        }
    }

    if (idx < n && s[idx] == ')') idx++;
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> s) {
        n = s.size();
        int id = 0;
        map<string,ll> ans = get_ans(id);
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            string tmp = "";
            tmp.push_back(i + 'A');
            if (ans[tmp]) cnt++;
        }

        cout << cnt << '\n';
        for (int i = 0; i < 26; ++i) {
            string tmp = "";
            tmp.push_back(i + 'A');
            if (ans[tmp]) cout << tmp << ":" << ans[tmp] << '\n';
        }

        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                string tmp = "";
                tmp.push_back('A' + i);
                tmp.push_back('a' + j);
                if (ans[tmp]) cnt++;
            }
        }

        cout << cnt << '\n';
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                string tmp = "";
                tmp.push_back('A' + i);
                tmp.push_back('a' + j);
                if (ans[tmp]) cout << tmp << ":" << ans[tmp] << '\n';
            }
        }
    }
    return 0;
}
