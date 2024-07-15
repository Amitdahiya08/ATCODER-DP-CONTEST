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

int dp[100001][3][3][3];
int vacation(vector<int>& a,vector<int>& b,vector<int>& c,int i,int x,int y,int z){
    if(i==a.size())return 0;
    int& ans=dp[i][x][y][z];
    if(ans!=-1)return ans;

    int A=0,B=0,C=0;
    if(x!=0)A=vacation(a,b,c,i+1,0,1,1)+a[i];
    if(y!=0)B=vacation(a,b,c,i+1,1,0,1)+b[i];
    if(z!=0)C=vacation(a,b,c,i+1,1,1,0)+c[i];
    return ans=max(A,max(B,C));
}
void solve(){
    int n;
    cin>>n;
    vi a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    // 2 to represent no one has been taken
    cout<<vacation(a,b,c,0,2,2,2)<<"\n";
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