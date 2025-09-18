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




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int> (m+1,INT_MAX));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    // return dp[n][m];
    return 0;
}
