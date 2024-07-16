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

int LCS(string&s ,string& t,int i,int j,vector<vector<int>>& dp){
    if(i==0 ||j==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int take=0,notTake=0;
    if(s[i-1]==t[j-1])take=LCS(s,t,i-1,j-1,dp)+1;
    notTake=max(LCS(s,t,i-1,j,dp),LCS(s,t,i,j-1,dp));
    return dp[i][j]=max(take,notTake);
}
void solve(){
    string s,t;
    cin>>s;
    cin>>t;
    // first fill the dp for length of LCS 
    int n=s.size(),m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    LCS(s,t,n,m,dp);
    // now we have our dp array filled 
    string ans="";
    int i=n,j=m;
    // now our LCS value is stored at dp[m][n]
    // so moving backwards from m,n to 0,0 using stored values of dp
    while(i>0 && j>0){
        // if they are equal we know that next value will be at i-1,j-1 
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--,j--;
        }
        // if not check which one to reduce i or j ( use dp stored values for that)
        else {
            if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;
        }
    }
    // ans is stored in reverse order so straight it 
    reverse(ans.begin(),ans.end());
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