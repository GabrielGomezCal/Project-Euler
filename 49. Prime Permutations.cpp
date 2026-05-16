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

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

string order(int n) {
    string s = to_string(n);
    sort(all(s));
    return s;
}

void solve() {
    vector<bool> is_prime = sieve(10000);
    VI primes;
    For(i, 1000, 10000) {
        if (is_prime[i])
            primes.push_back(i);
    }

    map<string, VI > groups;
    for (int p: primes) {
        string s = order(p);
        groups[s].push_back(p);
    }

    for (auto &[s, nums]: groups) {
        if (nums.size() < 3)
            continue;

        For(i, 0, nums.size()) {
            For(j, i + 1, nums.size()) {
                For(k, j + 1, nums.size()) {
                    if (nums[j] - nums[i] == nums[k] - nums[j]) {
                        if (nums[i] != 1487) {
                            cout << "Sequence: " << nums[i] << " " << nums[j] << " " << nums[k] << ln;
                            return;
                        }
                    }
                }
            }
        }
    }

    int n = primes.size();
    For(i, 0, n) {
        For(j, i + 1, n) {
            For(k, j + 1, n) {
                if (primes[j] - primes[i] == primes[k] - primes[j]) {
                    if (primes[i] != 1487) {
                        cout << "Sequence: " << primes[i] << " " << primes[j] << " " << primes[k] << ln;
                        return;
                    }
                }
            }
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
