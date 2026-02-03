#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define ln "\n"
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 100005;

int wordVal(string s) {
    int sum = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z')
            sum += (c - 'A' + 1);
        else if (c >= 'a' && c <= 'z')
            sum += ( c - 'a' + 1);
    }
    return sum;
}

bool isTriangular(int num) {
    int n = (int)((-1 + sqrt(1 + 8 * num)) / 2);
    return n * (n + 1) / 2 == num;
}

void solve() {
    //The txt is given
    ifstream text("text.txt");
    if (!text.is_open()) {
        cout << "The file can´t be openned" << ln;
        return;
    }
    string line;
    getline(text, line);

    vector<string> words;
    string cur = "";
    bool ok = false;

    for (char c : line) {
        if (c == '"') {
            if (ok) {
                if (!cur.empty()) {
                    words.push_back(cur);
                    cur = "";
                }
            }
            ok = !ok;
        }else if (ok) {
            cur += c;
        }
    }
    text.close();

    int cnt = 0;
    for (const string& w : words) {
        int val = wordVal(w);
        if (isTriangular(val))
            cnt++;
    }
    cout << "Number of triangle words: " << cnt << ln;
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
