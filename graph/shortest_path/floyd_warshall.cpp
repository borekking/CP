#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pi;

const int MAXN = 200+3;
const ll INF = 1e18;

vector<vector<pi>> adj(MAXN);

// O(n^3)
vector<vector<int>> floyd_warshall() {
    vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));

    for (int u = 0; u < MAXN; u++) {
        dist[u][u] = 0;
        for (pi next : adj[u]) {
            dist[u][next.first] = next.second;
        }
    }

    for (int w = 0; w < MAXN; w++) {
        for (int u = 0; u < MAXN; u++) {
            for (int v = 0; v < MAXN; v++) {
                dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
            }
        }
    }
}

int main() {
    return 0;
}