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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 200005;

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    //los otros se descartan por propiedas de divisivilidad,
    //por que la suma de sus digitos es congruente a 0 mod 3
    string digits = "7654321";

    do {
        int num = stoi(digits);
        if (is_prime(num)) {
            cout << num << ln;
            return;
        }
    }while (prev_permutation(all(digits)));
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
