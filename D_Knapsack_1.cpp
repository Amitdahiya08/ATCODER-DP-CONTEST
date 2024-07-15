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

int dp[100001][101];
int helper(vector<int>& weights, vector<int>& value,int limit,int i){
    if(i==weights.size() || limit==0)return 0;
    int& ans=dp[limit][i];
    if(ans!=-1)return ans;

    int take=0,notTake=0;
    if( limit - weights[i] >=0)take=helper(weights,value,limit-weights[i] , i+1)+value[i];
    notTake=helper(weights,value,limit,i+1);
    return ans=max(take,notTake);
}
void solve(){
    int n,k;
    cin>>n>>k;
    vi w(n),val(n);
    for(int i=0;i<n;i++)cin>>w[i]>>val[i];

    memset(dp,-1,sizeof(dp));
    int ans=helper(w,val,k,0);
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