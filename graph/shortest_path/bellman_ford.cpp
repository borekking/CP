#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> ti;

const int MAXN = 2500+7; // Depends on bounds
const ll INF = 1e18;

vector<ti> edges;

int n, m;

// O(m*n)
vector<ll> bellman_ford(int root) {
    vector<ll> dist(n, INF);
    dist[root] = 0;
    
    for (int k = 1; k <= n-1; k++) {
        for (ti t : edges) {
            int from = get<0>(t), to = get<1>(t);
            ll c = get<2>(t);
            if (dist[from] == INF) continue;
            dist[to] = min(dist[to], dist[from] + c);
        }
    }

    return dist;
}

bool negative_cycle(vector<ll> &dist) {
    vector<ll> new_dist = dist;

    for (ti p : edges) {
        int from = get<0>(p), to = get<1>(p);
        ll c = get<2>(p);
        if (dist[from] == INF) continue; // Not even reachable
        // There is a negative cycle in the graph!
        if (dist[from] + c < dist[to]) return true;
    }

    return false;
}

int main() {
    // This code was testet using https://cses.fi/problemset/result/8478895/
    return 0;
}