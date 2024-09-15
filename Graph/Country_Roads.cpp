#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

struct edge {
    int to, wt;
};

void dfs(int cur, vector<bool> &vis, vector<int> &res, vector<vector<edge>>& adj, int cur_max) {
    vis[cur] = true;
    for (auto d : adj[cur]) {
        int node = d.to;
        int cost = max(cur_max, d.wt);
        if (cost < res[node]) {
            res[node] = cost;
            dfs(node, vis, res, adj, cost);
        }
    }
}

int main(){
    opt();
    int t;
    cin >> t;
    int case_num = 0;

    while (t--){
        case_num++;
        int n, m;
        cin >> n >> m;
        vector<vector<edge>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int start;
        cin >> start;
        vector<int> res(n, INT_MAX);
        vector<bool> vis(n, false);
        res[start] = 0;
        dfs(start, vis, res, adj, 0);

        cout << "Case " << case_num << ":" << endl;
        for (int i = 0; i < n; ++i) {
            if (res[i] == INT_MAX) {
                cout << "Impossible" << endl;
            } else {
                cout << res[i] << endl;
            }
        }
    }
    return 0;
}