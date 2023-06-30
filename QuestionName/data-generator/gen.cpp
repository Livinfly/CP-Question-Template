#include <iostream>
#include "testlib.h"

typedef long long LL;

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]), m = atoi(argv[2]);
    int smin = atoi(argv[3]), smax = atoi(argv[4]);
    vector<int> a(n);
    for(auto &x : a) {
        x = rnd.next(smin, smax);
    }

    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i ++) {
        printf("%d%c", a[i], " \n"[i+1 == n]);
    }
    for(int i = 0; i < m; i ++) {
        int l = rnd.next(1, n), r = rnd.next(1, n);
        if(l > r) swap(l, r);
        printf("%d %d\n", l, r);
    }
}