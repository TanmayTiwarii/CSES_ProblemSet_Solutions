#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    vector<vector<int>> dist(n+1, vector<int>(2, LLONG_MAX));

    dist[1][1] = 0; // coupon unused
    dist[1][0] = 0; // coupon used (not really used yet)

    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    pq.push({0, 1, 1}); // {cost, node, state}

    while(!pq.empty()){

        auto [cost,u,state] = pq.top();
        pq.pop();

        if(cost > dist[u][state]) continue;

        for(auto [v,w] : adj[u]){

            if(state == 1){

                // Travel without using coupon
                if(dist[u][1] + w < dist[v][1]){
                    dist[v][1] = dist[u][1] + w;
                    pq.push({dist[v][1], v, 1});
                }

                // Use coupon on this edge
                if(dist[u][1] + w/2 < dist[v][0]){
                    dist[v][0] = dist[u][1] + w/2;
                    pq.push({dist[v][0], v, 0});
                }

            } 
            else {

                // Coupon already used → normal travel only
                if(dist[u][0] + w < dist[v][0]){
                    dist[v][0] = dist[u][0] + w;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }

    cout << dist[n][0] << "\n";
}
