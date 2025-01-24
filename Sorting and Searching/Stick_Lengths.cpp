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
    int i,n;
    cin>>n;
    int a[n];
    fo(0,n)
    cin>>a[i];
    sort(a,a+n);
    int x=a[n/2];
    int ans=0;
    fo(0,n)
    ans+=(abs(a[i]-x));
    cout<<ans<<endl;
}
