#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 1e5 + 123;
vector<bool> vis(mx, false);
vector<int> dist(mx, 0);

struct edge {
    int to;
    int wt;
};
vector<vector<edge>> adj(mx);

void dfs(int u, int cur) {
    vis[u] = true;
    dist[u] = cur;
    for (auto edge : adj[u]) {
        if (!vis[edge.to]) {
            dfs(edge.to, cur + edge.wt);
        }
    }
}

int main() {
    opt();
    int t;
    cin >> t;
    int tc = 0;

    while(t--) {
        tc++;
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(0, 0);
        /*for (int i = 0; i < n; ++i) {
            cout << dist[i] << " ";
        }*/
        //cout << endl;
        int mx = 0;
        int node = -1;
        for (int i = 0; i < n; ++i) {
            if (dist[i] > mx) {
                mx = dist[i];
                node = i;
            }
        }
        fill(dist.begin(), dist.begin() + n, 0);
        fill(vis.begin(), vis.begin() + n, false);

        dfs(node, 0);
        /*for (int i = 0; i < n; ++i) {
            cout << dist[i] << " ";
        }*/
        int ans = *max_element(dist.begin(), dist.end());
        cout << "Case " << tc <<": " << ans << endl;
        //cout << endl;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        fill(dist.begin(), dist.begin() + n, 0);
        fill(vis.begin(), vis.begin() + n, false);
        //cout << endl;
    }
}
