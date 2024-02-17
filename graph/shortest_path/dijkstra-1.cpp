#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
typedef tuple<ll, int, int> trip;

const int MAXN = 2e5+5;
const ll INF = 1e18;

vector<vector<pil>> adj(MAXN);
vector<ll> dist(MAXN, INF);
vector<int> pars(MAXN, 0);

int n;

void dijkstra(int root) {
    priority_queue<trip, vector<trip>, greater<trip>> pq;
    pq.push({0, root, root});
    ll d; int top, parent;
    int next; ll dist_next;

    while (pq.size()) {
        tie(d, top, parent) = pq.top();
        pq.pop();

        if (dist[top] <= d) continue;
        dist[top] = d;
        pars[top] = parent;

        for (auto p : adj[top]) {
            tie(next, dist_next) = p;
            if (dist[next] <= dist_next + d) continue;

            pq.push({dist_next + d, next, top});
        }
    }
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
    int n = 5;
    adj[0].push_back({1, 3});
    adj[0].push_back({2, 4});
    adj[0].push_back({3, 9});
    adj[0].push_back({4, 4});

    adj[1].push_back({2, 3});

    adj[2].push_back({3, 4});
    adj[2].push_back({4, 5});
    
    dijkstra(0);

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
