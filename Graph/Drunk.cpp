#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

map<string, vector<string>> adj;
map<string, bool> visited, recStack;

bool dfs(const string& u) {
    visited[u] = true;
    recStack[u] = true;
    for (auto d : adj[u]) {
        if (!visited[d]) {
            if (dfs(d)) {
                return true;
            }
        } else if (recStack[d]) {
            return true;
        }
    }
    recStack[u] = false;
    return false;
}

int main() {
    opt();
    
    int t;
    cin >> t;

    int case_num = 1;
    while (t--) {
        int m;
        cin >> m;

        adj.clear();
        visited.clear();
        recStack.clear();

        set<string> st;
        for (int i = 0; i < m; ++i) {
            string a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            st.insert(a);
            st.insert(b);
        }

        bool ok = false;
        for (auto d : st) {
            if (!visited[d]) {
                if (dfs(d)) {
                    ok = true;
                    break;
                }
            }
        }

        if (ok) {
            cout << "Case " << case_num << ": No" << endl;
        } 
        else {
            cout << "Case " << case_num << ": Yes" << endl;
        }

        case_num++;
    }

    return 0;
}
