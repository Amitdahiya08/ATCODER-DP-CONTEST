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

int dp[3001][3001][2];
int helper(vector<int>& arr,int i,int j,int turn){
    if(i>j)return 0;
    int& ans=dp[i][j][turn];
    if(ans!=-1)return ans;

    // check if it's taro's turn
    if(turn){
        int start=helper(arr,i+1,j,(turn+1)%2)+arr[i];
        int end=helper(arr,i,j-1,(turn+1)%2)+arr[j];
        return ans=max(start,end);
    }
    else{
        int start=helper(arr,i+1,j,(turn+1)%2);
        int end=helper(arr,i,j-1,(turn+1)%2);
        return ans=min(start,end);
    }
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    cin>>arr;
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    memset(dp,-1,sizeof(dp));
    // getting the taro score 
    int x=helper(arr,0,n-1,1);
    int y=sum-x;
    cout<<x-y<<"\n";
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