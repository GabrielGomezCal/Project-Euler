#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define PI acos(-1)
#define RAD(deg) ((deg) * PI / 180.0)
#define ln "\n"

const ll INF = 1e18;
const double eps = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

bool isPerfectSq(ll x) {
    ll r = sqrtl(x);
    return r * r == x;
}

bool isPentagonal(ll x) {
    ll disc = 1 + 24 * x;
    if (!isPerfectSq(disc)) return false;
    ll r = sqrtl(disc);
    return (1 + r) % 6 == 0;
}

void solve() {
    ll n = 144;
    while (true) {
        ll h = n * (2 * n - 1);// all triangular are pentagonal
    
        if (isPentagonal(h)) { //we only need to check this
            cout << h << ln;
            break;
        }
        n++;
    }
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
