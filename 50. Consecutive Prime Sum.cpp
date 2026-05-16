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

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

void solve() {
    int n = 1e6;
    vector<bool> is_prime = sieve(n);

    vector<int> primes;
    For(i, 2, n) {
        if (is_prime[i])
            primes.push_back(i);
    }

    int max_len = 0;
    int best_prime = 0;

    For(i, 0, primes.size()) {
        ll sum = 0;
        For(j, i, primes.size()) {
            sum += primes[j];

            if (sum >= n)
                break;

            if (is_prime[sum]) {
                int len = j - i + 1;
                if (len > max_len) {
                    max_len = len;
                    best_prime = sum;
                }
            }
        }
    }
    cout << "Prime: " << best_prime << ln;
    cout << "Length: " << max_len << ln;
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
