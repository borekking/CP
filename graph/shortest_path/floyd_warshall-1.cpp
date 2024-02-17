#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> edge;

const int MAXN = 200+2;
const ll INF = 1e18;

vector<edge> edges;
vector<vector<ll>> dist(MAXN, vector<ll>(MAXN, INF));
vector<vector<int>> pars(MAXN, vector<int>(MAXN, -1));
int n;

void floyd_warshall() {
    int a, b; ll c;
    for (edge e : edges) {
        tie(a, b, c) = e;
        dist[a][b] = c;
        pars[a][b] = a;
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        pars[i][i] = i;
    }

    for (int w = 0; w < n; w++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u][w] + dist[w][v] < dist[u][v]) {
                    dist[u][v] = dist[u][w] + dist[w][v];
                    pars[u][v] = w;
                }
            }
        }
    }
}

vector<int> path(int root, int end) {
    if (pars[root][end] == -1) return {};
    vector<int> path;
    int node = end;

    while (node != root) {
        path.push_back(node);
        node = pars[root][node];
    }
    path.push_back(root);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    n = 5;

    edges.push_back({0, 1, 3});
    edges.push_back({0, 2, 4});
    edges.push_back({0, 3, 9});
    edges.push_back({0, 4, 4});

    edges.push_back({1, 2, 3});

    edges.push_back({2, 3, 4});
    edges.push_back({2, 4, 5});
    
    floyd_warshall();

    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            cout << dist[v][u] << " ";
        }
        cout << endl;
    }

    cout << "(2, 4)" << endl;
    vector<int> p1 = path(1, 3);
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