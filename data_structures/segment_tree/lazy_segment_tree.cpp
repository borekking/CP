#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> tree;
vector<ll> lazy;

int n;
int si;

void init(vector<ll> &vec) {
    si = 2 << __lg(n);
    tree.resize(2*si, 0); // Init with neutral element of +-operation
    lazy.resize(2*si, 1); // Init with neutral element of *-operation

    for (int i = 0; i < n; i++) {
        tree[si + i] = vec[i];
    }

    for (int i = si-1; i >= 1; i++) {
        tree[i] = tree[2*i] + tree[2*i+1]; // +-operation
    }
}

// Apply *-operation for some node
void apply1(int node, ll value) {
    tree[node] *= value;
    lazy[node] *= value; // Need to change values for childs!
}

// Push down *-operation updates on given node
void push(int node) {
    apply1(2*node, lazy[node]);
    apply1(2*node+1, lazy[node]);
    lazy[node] = 1; // Neutral element for *-operation
}

void apply(int ql, int qr, int left, int right, ll value, int node) {
    // [left, right) lies completely inside of [ql, qr)
    if (ql <= left && qr >= right) {
        apply1(node, value);
        return;
    }

    // [left, right) lies completely outside of [ql, qr)
    if (right <= ql || left >= qr) {
        return;
    }

    // Otherwise (Part of [left, right) lies inside if [ql, qr))
    push(node);
    int mid = left + (right - left) / 2;
    apply(ql, qr, left, mid, value, 2*node);
    apply(ql, qr, mid, right, value, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int ql, int qr, int left, int right, int node) {
    // [left, right) lies completely inside of [ql, qr)
    if (ql <= left && qr >= right) {
        return tree[node];
    }

    // [left, right) lies completely outside of [ql, qr)
    if (right <= ql || left >= qr) {
        return 0; // Neutral element of +-operation
    }

    // Otherwise (Part of [left, right) lies inside if [ql, qr))
    push(node);
    int mid = left + (right - left) / 2;
    return query(ql, qr, left, mid, 2*node) + query(ql, qr, mid, right, 2*node+1);
}

int main() {
    return 0;
}
