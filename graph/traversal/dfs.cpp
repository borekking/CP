#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

// Adjacency List
vector<vector<int>> adj(N);
vector<bool> vis(N, 0);

// Recursive
void dfs(int root) {
    vis[root] = 1;
    cout << root << " ";
    for (int next : adj[root]) {
        if (vis[next]) continue;
        dfs(next);
    }
}

// Iterative using stack
void dfs1(int root) {
    bool visited[N];
    stack<int> sta;
    sta.push(root);

    while (sta.size()) {
        int node = sta.top();
        sta.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        cout << node << " ";

        for (int next : adj[node]) {
            if (visited[next]) continue;
            sta.push(node);
        }
    }
}

int main() {
    // Costom Setup; Root=0
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

    dfs(0);
    cout << endl;

    dfs1(0);
    cout << endl;

    return 0;
}