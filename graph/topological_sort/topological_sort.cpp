#include <bits/stdc++.h>

using namespace std;

int MAXN = 2e5+7;

vector<vector<int>> adj(MAXN);

vector<bool> started(MAXN);
vector<bool> finished(MAXN);
vector<int> order;

int n, m;

bool dfs(int root) {
    started[root] = 1;

    for (int next : adj[root]) {
        if (!started[next]) {
            dfs(next);
        }
        if (started[next] && !finished[next]) return false;
    }

    order.push_back(root);
    finished[root] = 1;
    return true;
}

bool toposort0() {
    for (int i = 0; i < n; i++) {
        if (finished[i]) continue;
        if (!dfs(i)) return false;
    }
    return true;
}

vector<int> toposort1() {
    vector<int> in(n, 0);
    vector<int> nodes;
    queue<int> qu;

    for (int i = 0; i < n; i++) {
        for (int next : adj[i]) {
            in[next]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            qu.push(i);
        }
    }
    
    while (qu.size()) {
        int node = qu.front();
        qu.pop();
        nodes.push_back(node);

        for (int next : adj[node]) {
            if (--in[next] == 0) {
                qu.push(next);
            }
        }
    }

    return nodes;
}

int main() {
    // This code was tested using https://cses.fi/problemset/result/8480428/
    
    /*
    vector<int> nodes = toposort1();
    if (nodes.size() != n) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
    }
    */

    /*
    if (!toposort0()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    reverse(order.begin(), order.end());
    */
    return 0;
}