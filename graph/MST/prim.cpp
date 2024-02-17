#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
typedef tuple<ll, int, int> tli;

const int MAXN = 1e5+5;
const ll INF = 1e18;

vector<vector<pil>> adj(MAXN);
vector<vector<pil>> res(MAXN);

ll sum = 0;
int n;

bool prim(int root) {
    ll d; int top, parent;
    int next; ll next_dist;
    int cnt = 0;

    vector<ll> dist(n, INF);
    priority_queue<tli, vector<tli>, greater<tli>> pq;
    dist[root] = 0;
    pq.push({0, root, root});

    while (pq.size()) {
        tie(d, top, parent) = pq.top();
        pq.pop();

        if (dist[top] == -1) continue;
        dist[top] = -1;
        sum += d;
        cnt++;
        res[parent].push_back({top, d});
        res[top].push_back({parent, d});

        for (pil p : adj[top]) {
            tie(next, next_dist) = p;
            if (dist[next] <= next_dist) continue;

            dist[next] = next_dist;
            pq.push({next_dist, next, top});
        }
    }

    return cnt == n; // n because of (0, root, root)
}

int main() {
    // https://cses.fi/problemset/task/1675
    return 0;
}