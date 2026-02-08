#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define PI acos(-1)
#define RAD(deg) ((deg) * PI / 180.0)
#define ln "\n"

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;


void solve() {
    ll total = 0;
    for (int num17 = 17; num17 < 1000; num17 += 17) {
        int d8 = num17 / 100;
        int d9 = (num17 / 10) % 10;
        int d10 = num17 % 10;

        if (d8 == d9 || d8 == d10 || d9 == d10)
            continue;

        for (int d7 = 0; d7 <= 9; d7++) {
            if (d7 == d8 || d7 == d9 || d7 == d10)
                continue;
            int num13 = d7 * 100 + d8 * 10 + d9;
            if (num13 % 13 != 0)
                continue;

            for (int d6 = 0; d6 <= 9; d6++) {
                if (d6 == d7 || d6 == d8 || d6 == d9 || d6 == d10)
                    continue;
                int num11 = d6 * 100 + d7 * 10 + d8;
                if (num11 % 11 != 0)
                    continue;

                for (int d5 = 0; d5 <= 9; d5++) {
                    if (d5 == d6 || d5 == d7 || d5 == d8 || d5 == d9 || d5 == d10)
                        continue;
                    int num7 = d5 * 100 + d6 * 10 + d7;
                    if (num7 % 7 != 0)
                        continue;

                    for (int d4 = 0; d4 <= 9; d4++) {
                        if (d4 == d5 || d4 == d6 || d4 == d7 || d4 == d8 || d4 == d9 || d4 == d10)
                            continue;
                        int num5 = d4 * 100 + d5 * 10 + d6;
                        if (num5 % 5 != 0)
                            continue;

                        for (int d3 = 0; d3 <= 9; d3++) {
                            if (d3 == d4|| d3 == d5 || d3 == d6 || d3 == d7 || d3 == d8 || d3 == d9 || d3 == d10)
                                continue;
                            int num3 = d3 * 100 + d4 * 10 + d5;
                            if (num3 % 3 != 0)
                                continue;

                            for (int d2 = 0; d2 <= 9; d2++) {
                                if (d2 == d3 || d2 == d4|| d2 == d5 || d2 == d6 || d2 == d7 || d2 == d8 || d2 == d9 || d2 == d10)
                                    continue;
                                int num2 = d2 * 100 + d3 * 10 + d4;
                                if (num2 % 2 != 0)
                                    continue;

                                for (int d1 = 0; d1 <= 9; d1++) {
                                    if (d1 == d2 || d1 == d3 || d1 == d4 || d1 == d5 || d1 == d6 || d1 == d7 || d1 == d8 || d1 == d9 || d1 == d10)
                                        continue;
                                    if (d1 == 0)
                                        continue;

                                    ll pandigital = 0;
                                    pandigital = pandigital * 10 + d1;
                                    pandigital = pandigital * 10 + d2;
                                    pandigital = pandigital * 10 + d3;
                                    pandigital = pandigital * 10 + d4;
                                    pandigital = pandigital * 10 + d5;
                                    pandigital = pandigital * 10 + d6;
                                    pandigital = pandigital * 10 + d7;
                                    pandigital = pandigital * 10 + d8;
                                    pandigital = pandigital * 10 + d9;
                                    pandigital = pandigital * 10 + d10;

                                    total += pandigital;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << total;
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
