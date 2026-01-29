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

int findDigit(int n) {
    int digits = 1;
    ll cnt = 9;
    int start = 1;

    while (n > digits * cnt) {
        n -= digits * cnt;
        digits++;
        cnt *= 10;
        start *= 10;
    }

    int number = start + (n - 1) / digits;
    int digit_pos = digits - 1 - ((n - 1) % digits);
    For(i, 0, digit_pos)
        number /= 10;
    return number % 10;
}

void solve() {
    int res = 1;

    For(power, 0, 7) {
        int pos = (int) pow(10, power);
        int digit = findDigit(pos);
        res *= digit;
    }
    cout << res << ln;
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
