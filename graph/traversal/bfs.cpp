#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

// Adjacency List
vector<vector<int>> adj(N);

// Iterative using quque
void bfs(int root) {
    bool vis[N];
    queue<int> qu;
    qu.push(root);

    while (qu.size()) {
        int node = qu.front();
        qu.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        cout << node << " ";

        for (int next : adj[node]) {
            if (vis[next]) continue;
            qu.push(next);
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

    bfs(0);
    cout << endl;

    return 0;
}