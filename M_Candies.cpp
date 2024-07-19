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

int mod=(int)1e9+7;
void solve(){
    int n,k;
    cin>>n>>k;
    vi arr(n);
    cin>>arr;
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    // giving 0 number of candies to 0 child is 1 
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        vector<int>pref(k+1,0);
        pref[0]=dp[i-1][0];
        for(int j=1;j<=k;j++){
            pref[j]=(pref[j-1]+dp[i-1][j])%mod;
        }
        for(int j=0;j<=k;j++){
            int ans=0;
            /*for(int x=0;x<=j;x++){
                if(x<=arr[i-1]){
                    // here this dp[i-1][j-x] , means allocating x candies to ith child and j-x to rest i-1 children
                    // where x goes from 0 to arr[i] , and ans value goes from dp[i-1][j] to dp[i-1][j-arr[i-1]]
                    ans+= dp[i-1][j-x];
                    // so basically for value of dp[i][j] we need sum of prev row i-1 values sum from 0 to j-arr[i-1]
                }
            } */
            // ways to distribute candies to ith child form 0 to arr[i-1] candies
            // edge case -> during %mod , pref[j] value can go smaller than pref[j-arr[i]-1] so add mod (std technique for modulus)
            if(j > arr[i-1]) ans=(pref[j]+mod - pref[(j-1)-arr[i-1]])%mod;
            else ans=pref[j];
            dp[i][j]=ans%mod;
        }
    }
    int ans=dp[n][k];
    cout<<ans<<"\n";
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;

    while(t--)
     solve();
    return 0;
}