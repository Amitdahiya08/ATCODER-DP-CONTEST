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

int dp[401][401];
int maxm = 1e18L+5;
int helper(vector<int>& arr,int l,int r){
    if(l==r)return 0;
    int& ans=dp[l][r];
    if(ans!=-1)return ans;

    int sum=0;
    // wall after merging L and R , so total cost for merging L and R completely is ..
    for(int i=l;i<=r;i++)sum+=arr[i];
    // now we can merge range of l and r in many ways 
    ans=maxm;
    for(int i=l;i<=r-1;i++){
        // merging l to i and i+1 to r + cost of merging both 
        ans=min(ans,helper(arr,l,i)+helper(arr,i+1,r)+sum);
    } 
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    cin>>arr;
    // here dp[i][j] is cost of merging range of L and R 
    // dp[0][n-1] has cost of merging them all
    memset(dp,-1,sizeof(dp));
    int ans=helper(arr,0,n-1);
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