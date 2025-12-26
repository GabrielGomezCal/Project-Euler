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

void solve() {
    int num_p = 1, den_p = 1;
    For(num, 10, 99) {
        For(den, num + 1, 100) {
            int a = num / 10;
            int b = num % 10;
            int c = den / 10;
            int d = den % 10;

            if (b == 0 && d == 0)
                continue;

            double original = (double)num / den;
            if (a == c && d != 0) {
                if (original == (double) b / d) {
                    cout << num << "/" << den << "=" << b << "/" << d << ln;
                    num_p *= num;
                    den_p *= den;
                }
            }
            if (a == d && c != 0) {
                if (original == (double)b / c) {
                    cout << num << "/" << den << "=" << b << "/" << c << ln;
                    num_p *= num;
                    den_p *= den;
                }
            }

            if (b == c && d != 0) {
                if (original == (double)a / d) {
                    cout << num << "/" << den << "=" << a << "/" << d << ln;
                    num_p *= num;
                    den_p *= den;
                }
            }

            if (b == d && c != 0) {
                if (original == (double)a / c) {
                    cout << num << "/" << den << "=" << a << "/" << c << ln;
                    num_p *= num;
                    den_p *= den;
                }
            }
        }
    }

    int g = gcd(num_p, den_p);
    num_p /= g;
    den_p /= g;

    cout << "Product: " << num_p << "/" << den_p << ln;
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
