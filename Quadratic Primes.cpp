https://projecteuler.net/problem=27
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define pb push_back

int quadratic(int n, int a, int b) {
    return n * n + a * n + b;
}

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
    int max_consecutive = 0;
    int best_a = 0, best_b = 0;
    
    vector<int> primes;
    For(i, 2, 1001)
        if (is_prime(i)) primes.pb(i);
    
    For(a, -999, 1000) {
        for (int b : primes) {
            int n = 0;
            while (true) {
                int value = quadratic(n, a, b);
                if (!is_prime(value)) break;
                n++;
            }
            
            if (n > max_consecutive) {
                max_consecutive = n;
                best_a = a;
                best_b = b;
            }
        }
    }
    
    cout << "a = " << best_a << ", b = " << best_b << ln;
    cout << "Primos consecutivos: " << max_consecutive << ln;
    cout << "Producto: " << best_a * best_b << ln;
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
