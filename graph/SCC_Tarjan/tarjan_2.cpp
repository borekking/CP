#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;

vector<vector<int>> adj(MAXN);
vector<int> num(MAXN, -1);
vector<int> low(MAXN, -1);
stack<int> sta;
vector<bool> in(MAXN, 0);
vector<vector<int>> components;

int counter = 0;
int n;

// SCC on undirected graphs
void tarjan(int root) {
    num[root] = counter++;
    low[root] = num[root];
    sta.push(root);
    in[root] = 1;

    for (int next : adj[root]) {
        if (num[next] == -1) {
            tarjan(next);
        }
        if (in[next]) {
            low[root] = min(low[root], low[next]);
        }
    }

    if (num[root] == low[root]) {
        vector<int> c;
        int node;
        do {
            node = sta.top();
            sta.pop();
            c.push_back(node);
            in[node] = 0;
        } while (node != root);

        components.push_back(c);
    }
}

int main() {
    n = 10;
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[2].push_back(0);

    adj[1].push_back(2);

    adj[3].push_back(4);
    adj[6].push_back(3);

    adj[4].push_back(5);
    adj[4].push_back(8);
    adj[9].push_back(4);

    adj[5].push_back(6);

    adj[6].push_back(7);

    adj[8].push_back(9);

    for (int i = 0; i < n; i++) {
        if (num[i] == -1) tarjan(i);
    }

    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i+1 << ":" << endl;
        for (int x : components[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}