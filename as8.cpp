#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pair<int,int>>>
#define vppi vector<pair<int,pair<int,int>>>
#define fe first
#define se second
#include "prq.h"
vi ans;
vector<bool> vis;
void dfs(int v, int c, vector<vector<bool>> gg){
    for(int i=1;i<gg.size();i++){
        if(!gg[v][i])continue;
        if(vis[i])continue;
        ans.push_back(i);
        vis[i]=1;
        dfs(i,v,gg);
    }
}
void bfs(int v, vvi g){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        for(auto x: g[q.front()]){
            if(vis[x])continue;
            vis[x]=1;
            ans.push_back(x);
            q.push(x);
        }
        q.pop();
    }
}
signed main(){
    cout<<"ENTER VERTICES, EDGES AND GRAPH RESPECTIVELY\n";
    int n,m;
    cin>>n>>m;
    vvi g(n+1);
    vector<vector<bool>> gg(n+1,vector<bool>(n+1));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        gg[x][y]=1;
        gg[y][x]=1;
    }
    vis=vector<bool>(n+1,0);
    cout<<"ENTER TRAVERSAL METHOD\n1.DFS\n2.BFS";
    int tt;
    cin>>tt;
    vis[1]=1;
    ans.push_back(1);
    if(tt==1)dfs(1,0,gg);
    else bfs(1,g);
    for(auto x: ans)cout<<x<<" ";
}