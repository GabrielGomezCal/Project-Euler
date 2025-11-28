#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for(int  i = a; i < b; i++)

bool valid(int n) {
    int num = 0;
    int m = n;
    while (m) {
        int cur = m % 10;
        m/=10;
        num += pow(cur, 5);
    }
    return num == n;
}

void solve() {
    int limit = 6 * pow(9, 5);
    int ans = 0;
    For(n, 2, limit) {
        if (valid(n))
            ans += n;
    }
    cout << ans << ln;
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
