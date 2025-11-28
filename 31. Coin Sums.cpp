#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    int target = 200;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int &c : coins) {
        for (int x = c; x <= target; x++) {
            dp[x] += dp[x - c];
        }
    }
    cout << dp[target] << ln;
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
