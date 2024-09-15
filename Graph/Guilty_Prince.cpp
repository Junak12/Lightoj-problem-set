#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int cnt = 0;
int m, n;

void dfs (int i , int j, vector< vector<char> > &mat , vector< vector<bool> > &vis) {
    if (i < 0 || j < 0 || i >= n || j >= m) return; 
    if (vis[i][j] || mat[i][j] != '.') {
        return ;
    }
    cnt++;
    vis[i][j] = true;
    dfs(i, j + 1, mat , vis);
    dfs(i, j - 1, mat, vis);
    dfs(i + 1, j, mat, vis);
    dfs(i - 1, j, mat, vis);

} 

int main(){
    opt();
    int t;
    cin >> t;
    int tc = 0;

    while (t--){
        tc++;
        cin >> m >> n;
        vector< vector<char> > mat(n, vector<char>(m));
        int idx_1 = -1 , idx_2 = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] == '@') {
                    idx_1 = i;
                    idx_2 = j;
                }
            }
        }
        vector< vector<bool> > vis (n, vector<bool> (m , false));
        mat[idx_1][idx_2] = '.';
        dfs(idx_1, idx_2, mat, vis);
        cout << "Case " << tc <<": "<< cnt << endl;
        cnt = 0;
    }
    return 0;
}