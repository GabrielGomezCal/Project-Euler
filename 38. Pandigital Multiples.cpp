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

bool isPandigital(const string& s) {
    if (s.size() != 9)
        return false;

    set<char> digits(all(s));
    if (digits.size() != 9)
        return false;

    for (char c : s) {
        if (c < '1' || c > '9')
            return false;
    }
    return true;
}

void solve() {
    ll largest = 0;
    string largest_str;

    For(n, 1000, 10000) {
        string s = to_string(n) + to_string(n * 2);
        if (isPandigital(s)) {
            ll  num = stoll(s);
            if (num > largest) {
                largest = num;
                largest_str = s;
            }
        }
    }

    For(n, 100, 333) {
        string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
        if (isPandigital(s)) {
            ll  num = stoll(s);
            if (num > largest) {
                largest = num;
                largest_str = s;
            }
        }
    }

    For(n, 1, 10) {
        string s;
        For(k, 1, 10) {
            s += to_string(n * k);
            if (s.length() > 9)
                break;
            if (s.length() == 9 && isPandigital(s)) {
                ll num = stoll(s);
                if (num > largest) {
                    largest = num;
                    largest_str = s;
                }
                break;
            }
        }
    }

    cout << "mayor pandigital: " << largest << ln;
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
