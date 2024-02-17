#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, int> pi;

const int MAXN = 2e5+7;
const ll INF = 1e18;

vector<vector<pi>> adj(MAXN);

int n, m;

// O(m*log_2(n))
vector<ll> dijkstra(int root) {
    vector<ll> dist(n, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, root});

    int d, node;
    while (pq.size()) {
        tie(d, node) = pq.top();
        pq.pop();

        if (dist[node] <= d) continue;
        dist[node] = d;

        for (pi next : adj[node]) {
            int child = next.first;
            ll cost = next.second;
            pq.push({cost + d, child});
        }
    }

    return dist;
}

int main() { 
    // This code was tested using https://cses.fi/problemset/task/1671
    return 0;
}