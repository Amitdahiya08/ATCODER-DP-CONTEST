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

int mod=1e9+7;
int dp[1001][1001];
int dfs(vector<vector<char>>& grid,int i,int j){
    if(i==grid.size() || j==grid[0].size() || grid[i][j]=='#')return 0;
    if(i==grid.size()-1 && j==grid[0].size()-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    // now just move to bottom or left only 
    int ans=0;
    if(i+1 < grid.size())ans+=dfs(grid,i+1,j);
    if(j+1 < grid[0].size())ans+=dfs(grid,i,j+1);
    return dp[i][j]=ans%mod;
}
void solve(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>grid(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)cin>>grid[i][j];
    }
    memset(dp,-1,sizeof(dp));
    int ans=dfs(grid,0,0);
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