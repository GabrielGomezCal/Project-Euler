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

bool isPent(ll n) {
    ll disc = 1 + 24 * n;
    ll sqrtDisc = sqrt(disc);

    if (sqrtDisc * sqrtDisc != disc)
        return false;

    if ((1 + sqrtDisc) % 6 != 0)
        return false;

    return true;
}

void solve() {
    vector<ll> pent;
    ll limit = 10000;

    For(n,1, limit) {
        ll p = n * (3 * n - 1) / 2;
        pent.push_back(p);
    }

    ll minDiff = INF;

    For(j, 0, pent.size()) {
        For(k, j + 1, pent.size()) {
            ll Pj = pent[j];
            ll Pk = pent[k];

            ll sum = Pj + Pk;
            ll diff = Pk - Pj;

            if (isPent(sum) && isPent(diff))
                if (diff < minDiff)
                    minDiff = diff;
        }
    }

    cout << minDiff << ln;
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
