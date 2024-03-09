#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int si;

vector<ll> tree;

void init(vector<ll> &vec) {
    si = 2 << __lg(n);
    tree.resize(2*si, 0); // 0 should be the neutral element for the +-operation

    for (int i = 0; i < n; i++) {
        tree[i+si] = vec[i];
    }

    for (int i = si-1; i >= 1; i--) {
        tree[i] = tree[2*i] + tree[2*i+1]; // + might be some other operator like min, max, *
    }
}

// Set value of a[index] = value;
// On the path from the node of a[index] to the root:
//    Update all nodes
void update(int index, ll value) {
    int node = (index+si);
    tree[node] = value;

    for (node /= 2; node >= 1; node /= 2) {
        tree[node] = tree[2*node] + tree[2*node+1]; // + might be some other operator like min, max, *
    }
}

// Find the sum (depending on the +-operation) of the array in range [ql, qr),
// which are contained as leafes in the subtree of node
ll query(int ql, int qr, int left, int right, int node) {
    // [left, right) is completely inside of [ql, qr)
    if (ql <= left && qr >= right) {
        return tree[node];
    }

    // [left, right) is completely outside of [ql, qr)
    if (right <= ql || left >= qr) {
        return 0; // 0 should be the neutral element for the +-operation
    }

    // Otherwise (Part of [left, right) is inside of [ql, qr)): 
    // Recusively call the childs
    int mid = left + (right - left) / 2;
    return query(ql, qr, left, mid, 2*node) + query(ql, qr, mid, right, 2*node+1); // + might be some other operator like min, max, *
}

// --- Segment Tree using using +-operation ---
//  1. update(i, x): set a[i] = x
//  2. query(l, r): find sum of a[l...r-1]
// Note: + might be any associative operator
int main() {
    return 0;
}