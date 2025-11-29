#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define pb push_back

bool isPandigital(const string& s) {
    if (s.length() != 9) return false;
    for (char c = '1'; c <= '9'; c++) {
        if (count(all(s), c) != 1)
            return false;
    }
    return true;
}

void solve() {
    set<int> products;

    for (int a = 1; a<= 9; a++) {
        for (int b = 1234; b <= 9876; b++) {
            int p = a * b;
            if (p < 1000 || p > 9999)
                continue;
            string s = to_string(a) + to_string(b) + to_string(p);
            if (isPandigital(s))
                products.insert(p);
        }
    }

    for (int a = 12; a <= 98; a++) {
        for (int b = 123; b <= 987; b++) {
            int p = a * b;
            if (p < 1000 || p > 9999) continue;
            string s = to_string(a) + to_string(b) + to_string(p);
            if (isPandigital(s))
                products.insert(p);
        }
    }

    int sum = 0;
    for (int x : products)
        sum += x;

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
