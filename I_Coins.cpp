#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ndl cout<<"\n";
#define spc <<" "<<
#define pb push_back
#define vi vector<int>
#define vpi vector<pii>
#define pii pair<int, int>
#define all(v)  v.begin(),v.end()
#define mii map<int, int>
#define bits __builtin_popcount
#define gcd __gcd
#define in insert

template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }

vector<vector<double>> dp;

double helper(vector<double>& arr, int i, int heads) {
    int n = arr.size();
    if (i == n) {
        return heads > n / 2 ? 1 : 0;
    }
    double& ans = dp[i][heads];
    if (ans != -1) return ans;
    ans = 0;
    ans += arr[i] * helper(arr, i + 1, heads + 1);
    ans += (1 - arr[i]) * helper(arr, i + 1, heads);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<double> arr(n);
    cin >> arr;
    dp.assign(n + 1, vector<double>(n + 1, -1));
    double ans = helper(arr, 0, 0);
    cout << setprecision(10) << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
