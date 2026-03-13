#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

bool is_goldbach(int n, const vector<bool> &is_prime) {
    for (int k = 1; 2 * k * k < n; k++) {
        int p = n - 2 * k * k;
        if (p > 0 && is_prime[p])
            return true;
    }
    return false;
}

void solve() {
    auto is_prime = sieve(1e6);
    for (int n = 9; ; n+= 2) {
        if (is_prime[n])
            continue;
        if (!is_goldbach(n, is_prime)) {
            cout << n << ln;
            break;
        }
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
