#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

vector<vector<int>> adj(MAXN);

vector<int> depth(MAXN, 0);
vector<int> height(MAXN, 0);
vector<int> sizes(MAXN, 0);
vector<int> parent(MAXN, 0);

void dfs(int root, int par) {
    sizes[root] = 1;
    parent[root] = par;

    for (int next : adj[root]) {
        if (next == par) continue;

        depth[next] = depth[root] + 1;

        dfs(next, root);

        sizes[root] += sizes[next];
        height[root] = max(height[root], 1 + height[next]);
    }
}

int main() {
    // Input

    // Solve
    // Notes:
    //  1) depth[0] := 0
    //  2) height[leaf] := 0
    //  3) sizes[leaf] := 1 (always include self)
    //  4) parent[0] = 0
    // dfs(0, 0);

    // Output

    // -- Example --
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

    int root = 0;
    depth[root] = 0;
    dfs(root, root);

    for (int i = 0; i < 11; i++) {
        cout << i << ": h=" << height[i] << " d=" << depth[i] << "; s=" << sizes[i] << "; p=" << parent[i] << "\n";
    }
    
    cout << flush;
    return 0;
}