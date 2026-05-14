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

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
const int MAXN = 200000 + 5;

VI count(int n = 1e9) {
    VI primeCount(1e9 + 1, 0);

    For(i, 2, 1e9 + 1) {
        if (primeCount[i] == 0) {
            for (int j = i; j <= 1e9; j += i)
                primeCount[j]++;
        }
    }
    return primeCount;
}

void solve() {
    VI primeCount = count();
    For(n, 646, 1e9 - 3) {
        if (primeCount[n] == 4 &&
            primeCount[n + 1] == 4 &&
            primeCount[n + 2] == 4 &&
            primeCount[n + 3] == 4) {
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
