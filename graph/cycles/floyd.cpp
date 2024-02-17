#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+5;

vector<int> succ(MAXN, 0);

int floyd(int start, int end) {
    int a = start, b = end;

    do {
        a = succ[b];
        b = succ[succ[b]];
    } while (a != b);

    a = start;
    
    while (a != b) {
        a = succ[a];
        b = succ[b];
    } 

    return a;
}

int main() {
    return 0;
}