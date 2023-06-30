#include <iostream>
#include "testlib.h"

typedef long long LL;

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = 1e5, m = 1e6;
    int smin = atoi(argv[1]), smax = atoi(argv[2]);
    vector<int> a(n);
    for(auto &x : a) {
        x = rnd.next(smin, smax);
    }

    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i ++) {
        printf("%d%c", a[i], " \n"[i+1 == n]);
    }
    for(int i = 0; i < m; i ++) {
        int l = 1, r = n;
        printf("%d %d\n", l, r);
    }
}