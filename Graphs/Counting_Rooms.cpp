#include <bits/stdc++.h>
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int int long long
using namespace std;



int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(g[i][j]=='.' && !vis[i][j]){
                q.push({i,j});
                vis[i][j]=true;
            }
            else{
                continue;
            }
            while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]=='.' && vis[nr][nc]==false){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
