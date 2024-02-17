#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;
const int MAXLOGN = 19+1;

vector<int> depth(MAXN);
vector<vector<int>> adj(MAXN);
vector<vector<int>> jump(MAXN, vector<int>(MAXLOGN));

int n;

void dfs(int root, int parent) {
    for (int next : adj[root]) {
        if (next == parent) continue;
        jump[next][0] = root;
        depth[next] = depth[root] + 1;
        dfs(next, root);
    }
}

void preprocess() {
    for (int k = 1; k < MAXLOGN; k++) {
        for (int u = 0; u < n; u++) {
            jump[u][k] = jump[jump[u][k-1]][k-1];
        }
    }
}

int lift(int node, int k) {
    if (k <= 0) return node;
    int log = floor(log2(k));
    
    for (int i = 0; i <= log; i++) {
        if (k & (1 << i)) {
            node = jump[node][i];
        }
    }

    return node;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    x = lift(x, depth[x] - depth[y]);
    if (x == y) return x;

    int log = floor(log2(depth[x]));
    for (int k = log; k >= 0; k--) {
        if (jump[x][k] != jump[y][k]) {
            x = jump[x][k];
            y = jump[y][k];
        }
    }

    return jump[x][0];
}

int main() {
    // Costom Setup; Root=0
    n = 11;
    
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[3].push_back(5);
    adj[3].push_back(6);

    adj[4].push_back(7);
    adj[7].push_back(9);

    adj[5].push_back(8);
    adj[8].push_back(10);
    // ---
    
    jump[0][0] = 0;
    depth[0] = 0;
    dfs(0, 0);
    preprocess();
    
    cout << lca(10, 9) << endl;
    cout << lca(2, 5) << endl;
    cout << lca(8, 6) << endl;
    cout << lca(5, 6) << endl;

    return 0;
}