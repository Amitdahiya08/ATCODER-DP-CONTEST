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

int dp[22][(int)1<<22];
int mod=(int)1e9+7;
int helper(vector<vector<int>>& arr,int men,int women){
    if(men==0){
        return 1;
    }
    int& ans=dp[men][women];
    if(ans!=-1)return ans;
    // now current men has n ways to select any women
    ans=0;
    for(int i=0;i<arr.size();i++){
        // if it is available
        if(1 & (women>>i)){
            // mark it unavailable for next men
            if(arr[men-1][i])ans= (ans+ helper(arr,men-1, women^(1<<i)))%mod;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>arr[i][j];
    }
    memset(dp,-1,sizeof(dp));
    // we know that there are n man and n woman , since n is 21 , if we go by backtracking method it will be TLE 
    //  and 21 gives use vibes of using bitmask 
    // here we use bitmask to represent available women for ith man 
    // all n men are available and all women are available
    int ans=helper(arr,n,(1<<n)-1);
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