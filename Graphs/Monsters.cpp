#include <bits/stdc++.h>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fo(a,b) for(i=a;i<b;i++)
#define foj(a,b) for(j=a;j<b;j++)
#define int long long
using namespace std;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
char pathC[] = {'D','U','R','L'};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    pair<int,int> origin;
    vector<pair<int,int>> monsters;

    fo(0,n){
        foj(0,m){
            cin>>grid[i][j];
            if(grid[i][j]=='A') origin={i,j};
            if(grid[i][j]=='M') monsters.push_back({i,j});
        }
    }

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    vector<vector<int>> distM(n,vector<int>(m,1e9));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    queue<pair<int,int>> q;
    for(auto it: monsters){
        distM[it.first][it.second]=0;
        q.push(it);
    }
    while(!q.empty()){
        auto [r,c] = q.front(); q.pop();
        for(int d=0;d<4;d++){
            int nr=r+dr[d], nc=c+dc[d];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='.' && distM[r][c]+1<distM[nr][nc]){
                distM[nr][nc]=distM[r][c]+1;
                q.push({nr,nc});
            }
        }
    }

    queue<pair<int,int>> qa;
    dist[origin.first][origin.second]=0;
    qa.push(origin);

    while(!qa.empty()){
        auto [r,c]=qa.front(); qa.pop();
        if(r==0 || c==0 || r==n-1 || c==m-1){
            yes;
            cout<<dist[r][c]<<endl;
            string ans="";
            pair<int,int> cur={r,c};
            while(cur!=origin){
                auto [pr,pc]=parent[cur.first][cur.second];
                for(int d=0;d<4;d++){
                    if(pr+dr[d]==cur.first && pc+dc[d]==cur.second){
                        ans.push_back(pathC[d]);
                    }
                }
                cur=parent[cur.first][cur.second];
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
            return 0;
        }

        for(int d=0;d<4;d++){
            int nr=r+dr[d], nc=c+dc[d];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='.' && dist[r][c]+1<dist[nr][nc]){
                if(dist[r][c]+1 < distM[nr][nc]){ 
                    dist[nr][nc]=dist[r][c]+1;
                    parent[nr][nc]={r,c};
                    qa.push({nr,nc});
                }
            }
        }
    }

    no;
    return 0;
}
