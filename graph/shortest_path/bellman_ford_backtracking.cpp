#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> edge;

const int MAXN = 2e5+5;
const ll INF = 1e18;

vector<edge> edges;
vector<ll> dist(MAXN, INF);
vector<int> pars(MAXN, 0);

int n, m;

void bellman_ford(int root) {
    int from, to; ll d;
    dist[root] = 0;

    for (int v = 0; v < n-1; v++) {
        for (edge e : edges) {
            tie(from, to, d) = e;

            if (dist[from] == INF) continue;
            if (dist[from] + d >= dist[to]) continue;

            dist[to] = dist[from] + d;
            pars[to] = from;
        }
    }
}

bool negative_cylce() {
    int from, to; ll d;

    for (edge e : edges) {
        tie(from, to, d) = e;

        if (dist[from] == INF) continue;
        if (dist[from] + d >= dist[to]) continue;

        return true;
    }

    return false;
}

vector<int> path(int root, int end) {
    vector<int> path;
    int node = end;

    while (node != root) {
        path.push_back(node);
        node = pars[node];
    }
    path.push_back(root);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    n = 5;
    m = 7;

    edges.push_back({0, 1, 3});
    edges.push_back({0, 2, 4});
    edges.push_back({0, 3, 9});
    edges.push_back({0, 4, 4});

    edges.push_back({1, 2, 3});

    edges.push_back({2, 3, 4});
    edges.push_back({2, 4, 5});
    
    bellman_ford(0);

    for (int v = 0; v < n; v++) {
        cout << dist[v] << " ";
    }
    cout << endl; 

    cout << "(1, 4)" << endl;
    vector<int> p1 = path(0, 3);
    for (int x : p1) {
        cout << x << " ";
    }
    cout << endl;

    cout << "(1, 5)" << endl;
    vector<int> p2 = path(0, 4);
    for (int x : p2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}