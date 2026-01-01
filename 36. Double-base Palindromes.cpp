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

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        r--;
        l++;
    }
    return true;
}

string decimalToBinary(int n) {
    if (n == 0) return "0";

    string binary = "";
    bool start = false;

    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            binary += '1';
            start = true;
        } else if (start)
            binary += '0';
    }
    return binary;
}

void solve() {
    ll sum = 0;
    For(n, 0, MAXN) {
        string num = to_string(n);
        bool ok1 = isPalindrome(num);
        num = decimalToBinary(n);
        bool ok2 = isPalindrome(num);
        if (ok1 and ok2)
            sum += n;
    }
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
