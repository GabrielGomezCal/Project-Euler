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
const ll INF = 1e18;
const int MAXN = 1000000;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int  i = 2; i * i <= n; i++) {
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return is_prime;
}

bool ltrunc(int n, const vector<bool>& is_prime) {
    while (n > 0) {
        if (!is_prime[n])
            return false;
        n/=10;
    }
    return true;
}

bool rtrunc(int n, const vector<bool>& is_prime) {
    int mod = 10;
    while (mod <= n) {
        if (!is_prime[n % mod])
            return false;
        mod *= 10;
    }
    return true;
}

void solve() {
    vector<bool> is_prime = sieve(MAXN);
    vector<int> trunc_primes;

    for (int i = 11; i  <= MAXN && trunc_primes.size() < 11; i += 2) {
        if (is_prime[i]) {
            if (ltrunc(i, is_prime) && rtrunc(i, is_prime))
                trunc_primes.pb(i);
        }
    }
    ll sum = 0;
    cout << "Trunc primes: "<< ln;
    for (int p : trunc_primes) {
        cout << p << " ";
        sum += p;
    }
    cout << ln << "Sum: "<<ln;
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
