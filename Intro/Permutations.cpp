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
    int n,i;
    cin>>n;
    if(n==1)
    cout<<1;
    else if(n==2||n==3)
    cout<<"NO SOLUTION"<<endl;
    else if(n==4)
    cout<<"2 4 1 3"<<endl;
    else{
    int a[n],b=1;
    fo(0,n){
        if(b>n)
        b=2;
        a[i]=b;
        b+=2;
    }
    fo(0,n)
    cout<<a[i]<<" ";}
    return 0;
}
