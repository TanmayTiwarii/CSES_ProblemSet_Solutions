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


vector<int> a;
vector<int> seg;

int build(int root,int low,int high,vector<int> &nums){
    if(low==high){
        return seg[root]=nums[low];
    }
    int mid = (low+high)/2;
    seg[2*root+1] = build(2*root+1,low,mid,nums);
    seg[2*root+2] = build(2*root+2,mid+1,high,nums);
    seg[root] = seg[2*root+2] + seg[2*root+1];
    return seg[root];
}

int sum(int root,int left,int right, int low,int high){
    if(low>right || left>high){
        return 0;
    }
    if(low>=left && high<=right){
        return seg[root];
    }
    else{
        int mid=(low+high)/2;
        return sum(root*2+1,left,right,low,mid)+sum(root*2+2,left,right,mid+1,high);
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,i,j;
    cin>>n>>q;
    a.resize(n);
    seg.resize(4*n);
    fo(0,n){
        cin>>a[i];
    }
    build(0,0,a.size()-1,a);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum(0,l-1,r-1,0,n-1)<<endl;
    }
    return 0;
}
