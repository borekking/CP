#include <bits/stdc++.h>

using namespace std;

int MAXN = 2e5+7;

vector<vector<int>> adj(MAXN);

int n, m;

vector<int> toposort() {
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
    vector<int> nodes = toposort();
    if (nodes.size() != n) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
    }
    */
    return 0;
}