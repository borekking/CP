#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;

vector<vector<int>> adj(MAXN);
vector<int> num(MAXN, -1);
vector<int> low(MAXN, -1);

int counter = 0;

void tarjan(int root, int parent) {
    num[root] = counter++;
    low[root] = num[root];

    for (int next : adj[root]) {
        if (next == parent) continue;

        if (num[next] == -1) { // Baumkante (root, next)
            tarjan(next, root);
            low[root] = min(low[root], low[next]);
            // Bridge (root, next)
            if (low[next] > num[root]) { 
                cout << "Bridge: (" << root << ", " << next << ")" << endl;
            }

            if (low[next] >= num[root]) {
                cout << "Articulation Point: " << root << endl;
            }
        } else { // Rueckwaertskante (root, next)
            low[root] = min(low[root], num[next]);
        }
    }
}

// --- Undirected Bridges and Articulation Points ---
// Bridges and Articulation Points 
// Root (0) is Articulation Point if it has more than 1 child
int main() {
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[3].push_back(6);
    adj[6].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[4].push_back(8);
    adj[8].push_back(4);
    adj[4].push_back(9);
    adj[9].push_back(4);

    adj[5].push_back(6);
    adj[6].push_back(5);

    adj[6].push_back(7);
    adj[7].push_back(6);

    adj[8].push_back(9);
    adj[9].push_back(8);

    tarjan(0, 0);

    return 0;
}