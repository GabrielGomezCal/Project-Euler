#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define PQ priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define LOG2(x) (31 - __builtin_clz(x))
#define LOG2LL(x) (63 - __builtin_clzll(x))
#define nextpow2(x) 1 << (32 - __builtin_clz(x))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

const ll MOD = 10000000000LL;


ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (__int128)res * a % m;  
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll sum = 0;
    For(n, 1, 1001)
        sum = (sum + binpow(n, n, MOD)) % MOD;
    cout << sum << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
