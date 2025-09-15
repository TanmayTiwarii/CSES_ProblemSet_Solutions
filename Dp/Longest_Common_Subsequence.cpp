#include <bits/stdc++.h>
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int int long long
using namespace std;




//Frequently used Functions
string DecToBi(int n) {
 string bin = ""; while (n>0) { bin += to_string(n%2); n=n/2; } for (int i = 0; i < bin.size() / 2; i++) { swap(bin[i], bin[bin.size() - i - 1]); } return bin;
 }
int BiToDec(string str) {
 int dec_num = 0; int power = 0 ; int n = str.length() ; for(int i = n-1 ; i>=0 ; i--){ if(str[i] == '1'){ dec_num += (1<<power) ; } power++ ; } return dec_num; 
 }
bool isPrime(int n) {
 if (n <= 1) return false; for (int i = 2; i <= n / 2; i++) if (n % i == 0) return false; return true; 
 }
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
return (a.second < b.second);
}
//***************************************************************************************************************************************************


int func(vector<int> &a,vector<int> &b,int i,int j,vector<vector<int>> &dp){
    if(i==a.size() || j==b.size()){
        return 0LL;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(a[i]==b[j]){
        ans=max(ans,func(a,b,i+1,j+1,dp)+1);
    }
    ans=max(ans,func(a,b,i,j+1,dp));
    ans=max(ans,func(a,b,i+1,j,dp));
    return dp[i][j]=ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin>>n>>m;
    vector<int> a(n),b(m);
    fo(0,n){
        cin>>a[i];
    }
    fo(0,m){
        cin>>b[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=func(a,b,0,0,dp);
    cout<<ans<<endl;
    i=0,j=0;
    vector<int> lcs;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            lcs.push_back(a[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j]>=dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }
    for(auto it:lcs){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
