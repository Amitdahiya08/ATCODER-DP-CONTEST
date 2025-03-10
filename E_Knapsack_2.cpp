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

// since here limit can go upto 1e9 we cant create a matrix this large 
// reversing the question , we will fix a value of V and call the function (i,V) which return min limit
// since vi<=1000 and N = 100 max value of sum of V can go upto 1e5 
int dp[(int)1e5+1][101];
int helper(vector<int>& v, vector<int>& w,int i,int values){
    if(i==v.size()){
        if(values==0)return 0;
        else return INT_MAX;
    }
    if(values==0)return 0;
    int& ans=dp[values][i];
    if(ans!=-1)return ans;

    int take=INT_MAX,notTake=INT_MAX;
    if(v[i]<=values)take=helper(v,w,i+1,values-v[i])+w[i];
    notTake=helper(v,w,i+1,values);
    return ans=min(take,notTake);
}

void solve(){
    int n,limit;
    cin>>n>>limit;
    vi w(n),v(n);
    for(int i=0;i<n;i++)cin>>w[i]>>v[i];
    memset(dp, -1, sizeof(dp));
    int low=1,high=(int)1e5;
    int ans=0;
    // checking all the values from high to low , BS dont work here 
    while(high){
        if(helper(v,w,0,high)<=limit){
            ans=high;
            break;
        }
        high--;
    }
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