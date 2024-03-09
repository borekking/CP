#include <bits/stdc++.h>

using namespace std;

struct Node {
    char c;
    bool done;
    struct Node *nodes[26];
};

struct Node *create(char c) {
    struct Node *node = new Node;
    node->c = c;
    node->done = false;
    for (int i = 0; i < 26; i++) {
        node->nodes[i] = NULL;
    }
}

void insert(struct Node *root, string &str) {
    struct Node *node = root;
    int n = str.size();
    
    for (int i = 0; i < n; i++) {
        int index = str.at(i) - 'a';
        if (!node->nodes[index]) {
            node->nodes[index] = create(str.at(i));
        }
        node = node->nodes[index];
    }

    node->done = true;
}

bool contains(struct Node *root, string &str) {
    struct Node *node = root;
    int n = str.size();
    
    for (int i = 0; i < n; i++) {
        int index = str.at(i) - 'a';
        if (!node->nodes[index]) {
            return false;
        }
        node = node->nodes[index];
    }

    return node->done;
}


// --- Trie Data Structure for a-z strings ---
int main() {
    return 0;
}