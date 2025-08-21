#include <bits/stdc++.h>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define int long long
using namespace std;

int dr[] = {1,-1,0,0};  
int dc[] = {0,0,1,-1};
char dir[] = {'D','U','R','L'};  

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m, '?')); 

    queue<pair<int,int>> q;

    pair<int,int> start, dest;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                dis[i][j]=0;
                q.push({i,j});
                start = {i,j};
            }
            if(g[i][j]=='B'){
                dest = {i,j};
            }
        }
    }

    while(!q.empty()){
        int r=q.front().first; int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m 
               && (g[nr][nc]=='.' || g[nr][nc]=='B') 
               && dis[r][c]+1<dis[nr][nc]){
                dis[nr][nc]=dis[r][c]+1;
                parent[nr][nc] = {r,c};
                move[nr][nc] = dir[k];
                q.push({nr,nc});
            }
        }
    }

    if(dis[dest.first][dest.second]==INT_MAX){
        no;
        return 0;
    } else {
        yes;
        cout<<dis[dest.first][dest.second]<<"\n";
        string path="";
        pair<int,int> cur=dest;
        while(cur!=start){
            path.push_back(move[cur.first][cur.second]);
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
        cout<<path<<"\n";
    }

    return 0;
}
