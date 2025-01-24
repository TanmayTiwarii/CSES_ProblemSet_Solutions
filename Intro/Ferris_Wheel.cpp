#include <bits/stdc++.h>
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int int long long
using namespace std;



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,i,j;
    cin>>n>>x;
    int a[n];
    fo(0,n)
    cin>>a[i];
    sort(a,a+n);
    int ans=0;
    int start=0;
    int end=n-1;
    while(start<=end){
        if(a[end]+a[start]>x){
            end--;
            ans++;
        }
        else{
            ans++;
            start++;
            end--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
