#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123; 
vector<int> adj[mx];
vector<bool> vis(mx, false);
vector<char> col(mx, 'u');

void dfs(int u, char c, int &cnt1, int &cnt2) {
    vis[u] = true;
    col[u] = c;
    if (c == 'w') {
        cnt1++;
    } else if (c == 'b') {
        cnt2++;
    }
    for (auto d : adj[u]) {
        if (!vis[d]) {
            if (c == 'w') {
                dfs(d , 'b', cnt1, cnt2);
            }
            else if (c == 'b') {
                dfs(d, 'w', cnt1, cnt2);
            }
        }
    }
}

int main() {
    opt();
    int t;
    cin >> t;
    int tc = 0;

    while (t--) {
        tc++;
        // Reset for each test case
        for (int i = 0; i < mx; ++i) {
            adj[i].clear();
            vis[i] = false;
            col[i] = 'u';
        }

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ll max_count = 0;
        for (int i = 1; i < mx; ++i) {
            if (!vis[i] && !adj[i].empty()) {
                int cnt1 = 0, cnt2 = 0;
                dfs(i, 'w', cnt1, cnt2);
                max_count += max(cnt1, cnt2);
            }
        }

        cout << "Case " << tc << ": " << max_count << endl;
    }

    return 0;
}
