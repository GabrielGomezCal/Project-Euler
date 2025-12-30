#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define ln "\n"
#define pb push_back
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAXN = 20000;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void solve() {
    ll total = 0;
    For(num, 10, 3000000) {
        ll sum = 0;
        int n = num;

        while (n > 0) {
            sum += fact[n % 10];
            n /= 10;
        }
        if (sum == num) {
            cout << "Found: " << num << ln;
            total += num;
        }
    }
    cout << total << ln;
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
