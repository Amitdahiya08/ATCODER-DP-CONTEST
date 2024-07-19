#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#endif

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

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

int dp[100001];

// every player trying to end the the chances on him means odd number of chances starting from him
// can also by played in bool terms instead of even and odd 
int helper(vector<int>& arr, int k) {
    int& ans = dp[k];
    if (ans != -1) return ans;

    ans = 0;  // Assume losing position
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= k) {
            // number of times stones are taken after this chance
            int next=helper(arr,k-arr[i]);
            // if even number of chances are played after it means we win by picking it
            if(next%2==0){
                ans=next+1;
                break;
            }
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    cin >> arr;
    memset(dp,-1,sizeof(dp));
    int ans = helper(arr, k);
    if (ans%2) cout << "First" << "\n";
    else cout << "Second" << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
    return 0;
}
