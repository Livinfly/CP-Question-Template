#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, m, t;
    cin >> n >> m;
    vector<int> a(n), lg2(n+1);
    for(int i = 0, t = 1; t <= n; t *= 2, i ++) {
		lg2[t] = i;
	}
	for(int i = 1; i <= n; i ++) {
		if(!lg2[i]) lg2[i] = lg2[i-1];
	}
	t = lg2[n];
    vector<vector<int>> f(n, vector<int>(t+1));
    vector<vector<int>> g(n, vector<int>(t+1));
    for(auto &x : a) cin >> x;
    for(int i = 0; i < n; i ++) {
    	f[i][0] = g[i][0] = a[i];
    }
    for(int i = 1; i <= t; i ++) {
    	int len = 1<<i-1;
    	for(int j = 0; j+len < n; j ++) {
    		f[j][i] = max(f[j][i-1], f[j+len][i-1]);
    		g[j][i] = min(g[j][i-1], g[j+len][i-1]);
    	}
    }
    // cerr << n << ' ' << m << ' ' << t << '\n';
    auto Query = [&](int l, int r, int op) {
    	int k = lg2[r-l+1];
    	return (op ? max(f[l][k], f[r-(1<<k)+1][k]) 
    			   : min(g[l][k], g[r-(1<<k)+1][k]));
    };
    while(m --) {
    	int l, r;
    	cin >> l >> r;
    	l --, r --;

    	int mx = Query(l, r, 1), mn = Query(l, r, 0);
    	cout << mx << ' ' << mn << '\n';
    	// cout << mx-mn << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("PrimeChoice_13.in", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}