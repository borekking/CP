#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> edge;
typedef pair<int, ll> pil;

const int MAXN = 1e5+5;

vector<edge> edges;
vector<int> union_find(MAXN);
vector<vector<pil>> adj(MAXN);

ll sum = 0; 
int n, m;

// Union Find
void init() {
    for (int i = 0; i < MAXN; i++) {
        union_find[i] = i;
    }
}

int find(int a) {    
    if (union_find[a] != a) {
        union_find[a] = find(union_find[a]);
    }
    return union_find[a];
}

void my_union(int a, int b) {
    union_find[a] = b;
}

// Kruskal
bool kruskal() {
    int a, b; ll c;
    int ra, rb;
    int cnt = 0;

    sort(edges.begin(), edges.end(), [](edge p, edge q) {
        return get<2>(p) < get<2>(q);
    });

    for (edge e : edges) {
        tie(a, b, c) = e;
        ra = find(a);
        rb = find(b);

        if (ra != rb) {
            my_union(ra, rb);
            sum += c;
            cnt++;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
    }

    return cnt == n-1;
}

int main() {
    // https://cses.fi/problemset/task/1675
    
    init();

    kruskal();

    return 0;
}