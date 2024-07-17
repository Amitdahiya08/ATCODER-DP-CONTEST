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

vector<vector<vector<double>>>dp;
int n;
// Mathematical proof of it is 
//  E(c1,c2,c3) = (1 + p1*e1 + p2*e2 + p3*e3 ) / (1 - p0)
// no. of operation until  the experiment terminates is equal to = 1 + chance of picking c1 + chances of c2 + chances c3 / not picking empty
// Why Use This Formula?
// The formula is used to calculate the expected number of operations until the experiment terminates. 
// The term E(c1,c2,c3) accounts for the expected additional operations based on the probabilities of picking each outcome when the experiment doesn't terminate immediately.
double helper(int c1,int c2,int c3){
    if(c1==0 && c2==0 && c3==0 )return 0;
    double& ans= dp[c1][c2][c3];
    if(ans!=-1)return ans;
    ans=1;
    
    if(c1)ans+= ( (double)c1/n ) * helper(c1-1,c2,c3);
    if(c2)ans+= ( (double)c2/n ) * helper(c1+1,c2-1,c3);
    if(c3)ans+= ( (double)c3/n ) * helper(c1,c2+1,c3-1);

    double p0= 1. * (n-c1-c2-c3)/n;
    ans/= 1. - p0;

    return ans;
}
void solve(){
    cin>>n;
    vi a(4);
    // since only 3 values exist 1 2 3 , we will just store each counts
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    dp.assign(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1)));
    double ans = helper(a[1],a[2],a[3]);
    cout<<setprecision(10)<<ans<<"\n";


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