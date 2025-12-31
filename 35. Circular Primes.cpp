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
const int MAXN = 1000000;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    return isPrime;
}

bool circularPrime(int n, const vector<bool>& isPrime) {
    int temp = n;
    int cnt = 0;
    int mult = 1;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit % 2 == 0 || digit == 5) {
            if (n > 10)
                return false;
        }
        cnt++;
        mult *= 10;
        temp /= 10;
    }
    mult /= 10;
    temp = n;
    For(i, 0, cnt) {
        if (!isPrime[temp])
            return false;
        int last = temp % 10;
        temp = temp / 10 + last * mult;
    }
    return true;
}

void solve() {
    vector<bool> isPrime = sieve(MAXN);

    int cnt = 0;
    For(i, 2, MAXN) {
        if (isPrime[i] && circularPrime(i, isPrime))
            cnt++;
    }
    cout << cnt << ln;
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
