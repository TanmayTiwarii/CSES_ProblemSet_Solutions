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


int func(vector<int> &a,int i,int j,int ans1,int ans2,int f){
    if(i>j){
        if(f==1){
            return ans1;
        }else{
            return ans2;
        }
    }
    if(f==1){
        return max(func(a,i+1,j,ans1+a[i],ans2,0),func(a,i,j-1,ans1+a[j],ans2,0));
    }
    else{
        return max(func(a,i+1,j,ans1,ans2+a[i],1),func(a,i,j-1,ans1,ans2+a[j],1));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,m;
    cin>>n;
    vector<int> a(n);
    fo(0,n){
        cin>>a[i];
    }
    cout<<func(a,0,n-1,0,0,1)<<endl;
    return 0;
}
