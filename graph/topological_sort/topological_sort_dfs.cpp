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

bool toposort() {
    for (int i = 0; i < n; i++) {
        if (finished[i]) continue;
        if (!dfs(i)) return false;
    }
    return true;
}

int main() {
    // This code was tested using https://cses.fi/problemset/result/8480428/

    /*
    if (!toposort()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    reverse(order.begin(), order.end());
    */
    return 0;
}