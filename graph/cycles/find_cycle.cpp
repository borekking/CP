#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;

vector<vector<int>> adj(MAXN);
stack<int> sta;
vector<bool> vis(MAXN, 0);
int n, m;

bool dfs(int root, int parent) {
    sta.push(root);

    if (vis[root]) return true;
    vis[root] = true;

    for (int next : adj[root]) {
        if (next == parent) continue;
        if (dfs(next, root)) return true;
    }

    sta.pop();
    return false;
}

int main() {
    // This code was tested using https://cses.fi/problemset/result/8489054/
    bool pos = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (dfs(i, i)) {
            pos = 1;
            break;
        }
    }

    if (!pos) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    // Otherwise the result is contained in the last interval of the stack: u ... u <-
    return 0;
}