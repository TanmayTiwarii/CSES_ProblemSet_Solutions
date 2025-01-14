#include <bits/stdc++.h>
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int int long long
using namespace std;

int func(int n,vector<int> &dp){

    int i;
    if(n==0)
    return dp[n] = 0;
    if(dp[n]!=-1)
    return dp[n];
    int temp=n,ans=INT_MAX;
    while(temp!=0){
        if(temp%10==0){
            temp/=10;
            continue;
        }
        ans=min(ans,func(n-temp%10,dp)+1);
        temp=temp/10;
    }
    return dp[n]=ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<func(n,dp);
    return 0;
}