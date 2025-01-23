#include <bits/stdc++.h>
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int int long long
using namespace std;


int func(vector<int> &v,int sum){
    int dp[sum+1],mod=1e9+7;
    for(int i=0;i<sum+1;i++)
    dp[i]=0;
    dp[0]=1;
    for(int i=0;i<sum+1;i++){
        for(int j=0;j<v.size();j++){
            if(i+v[j]<=sum)
            dp[i+v[j]]=(dp[i+v[j]]+dp[i])%mod;
        }
    }
    return dp[sum];
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,target;
    cin>>n>>target;
    vector<int> v(n);
    fo(0,n)
    cin>>v[i];
    cout<<func(v,target)<<endl;
    return 0; 
}
