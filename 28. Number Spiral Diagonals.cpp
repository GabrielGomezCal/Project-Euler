//https://projecteuler.net/problem=28
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define pb push_back
const int MOD = 1e9 + 7;

void solve() {
    vector<int> nums;
    nums.pb(1);
    int cur = 0;
    int bit = 1;
    bool ok = true;
    while (*nums.rbegin() < 1001 * 1001) {
        int b = bit << 1;
        For(i, 0, 4) {
            cur = nums[nums.size() - 1] + b;
            if (cur > 1001 * 1001) {
                ok = false;
                break;
            }
            nums.pb(cur);
        }
        if (!ok)
            break;
        bit++;
    }

    ll ans = 0;
    for (auto &x : nums)
        ans += x;
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
