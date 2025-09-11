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

void dfs(vector<vector<int>> &adj,int u,vector<int> &vis){
    for(auto v:adj[u]){
        if(!vis[v]){
            vis[v]=1;
            dfs(adj,v,vis);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    fo(0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    vector<int> cities;
    fo(1,n+1){
        if(!vis[i]){
            cities.push_back(i);
            vis[i]=1;
            dfs(adj,i,vis);
        }
    }
    cout<<cities.size()-1<<endl;
    fo(1,cities.size()){
        cout<<cities[i-1]<<" "<<cities[i]<<endl;
    }
    return 0;
}
