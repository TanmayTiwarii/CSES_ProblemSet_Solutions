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

int func(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
    if(i==s1.size()){
        return dp[i][j]=max(0LL,(int)s2.size()-j);
    }
    if(j==s2.size()){
        return dp[i][j]=max(0LL,(int)s1.size()-i);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=func(s1,s2,i+1,j+1,dp);
    }
    int ans=0;
    ans=func(s1,s2,i+1,j+1,dp)+1;
    ans=min(ans,func(s1,s2,i+1,j,dp)+1);
    ans=min(ans,func(s1,s2,i,j+1,dp)+1);
    return dp[i][j]=ans;

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    cout<<func(s1,s2,0,0,dp)<<endl;
    return 0;
}
