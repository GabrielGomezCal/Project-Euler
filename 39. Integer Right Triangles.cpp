#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define ln "\n"
#define pb push_back
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int MAX = 200005;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, b % a);
}

void solve() {
    vector<int> cnt(1001, 0);

    for (int m = 2; m * m <= 1000; m++) {
        for (int n = 1; n < m; n++) {
            if ((m - n) % 2 == 1 && gcd(m, n) == 1) {
                //triple pitagorico primitivo
                ll a = 1LL * m * m - 1LL * n * n;
                ll b = 2LL * m * n;
                ll c = 1LL * m * m + 1LL * n * n;

                ll perim = a + b + c;

                if (perim > 1000)
                    break;

                for (int k = 1; k * perim <= 1000; k++)
                    cnt[k * perim]++;
            }
        }
    }
    int maxi = 0;
    int best = -1;
    For(p, 1, 1001) {
        if (cnt[p] > maxi) {
            maxi = cnt[p];
            best = p;
        }
    }
    cout << best << ln;
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
