#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;

vector<set<int>> adj(MAXN);
vector<int> in(MAXN, 0), out(MAXN, 0);
vector<int> path;

int n, m;
int cnt = 0;

void hierholzer() {
    stack<int> sta;
    sta.push(0);

    while (sta.size()) {
        int top = sta.top();

        if (adj[top].size() == 0) {
            sta.pop();
            path.push_back(top);
            continue;
        }

        int next = *adj[top].begin();
        sta.push(next);
        adj[top].erase(next);
        adj[next].erase(top);
        cnt++; // Count Edges
    }
}

int main() {
    // This code was tested using https://cses.fi/problemset/task/1691
    cin >> n >> m;
    int x, y;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x); // Directed?
    }

    for (int i = 0; i < n; i++) {
        out[i] = adj[i].size(); 

        // Directed?
        /*
        for (int v : adj[i]) {
            in[v] += 1;
        }
        */
    }

    bool ans = true;
    // Undirected
    // - tour: All even
    for (int i = 0; i < n; i++) {
        if (out[i] % 2 != 0) {
            ans = false;
            break;
        }
    }
    // - path: All even + 2*odd
    // Directed
    // - tour: in = out for all nodes
    // - path: in = out for all nodes + 1*Extra Out and 1*Extra In
    
    if (!ans) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    hierholzer();

    if (cnt != m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i]+1 << " ";
    }
    cout << endl;
    return 0;
}