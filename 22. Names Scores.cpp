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

int alphaValue(const string& s) {
    int sum = 0;
    for (char c : s)
        if (isalpha(c))
            sum += toupper(c) - 'A' + 1;
    return sum;
}

void solve() {
    ifstream file("names.txt");
    if (!file) {
        cerr<<"No se pudo abrir " << ln;
        return;
    }
    string line;
    vector<string> names;

    getline(file, line);

    stringstream ss(line);
    string name;
    while (getline(ss, name, ',')) {
        if (name.front() == '"' && name.back() == '"')
            name = name.substr(1, name.size() - 2);
        names.pb(name);
    }

    sort(all(names));

    ll total = 0;
    For(i, 0, names.size()) {
        int val = alphaValue(names[i]);
        total += val *(i + 1);
    }

    cout << total << ln;
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
