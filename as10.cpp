#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pair<int,int>>>
#define vppi vector<pair<int,pair<int,int>>>
#define fe first
#define se second
#include "prq.h"
vector<bool> vis;
vi dij(vvpi g, int n, int v){
    set<pair<int,int>> s;
    vi ans(n+1,1e9);
    ans[v]=0;
    s.insert({0,v});
    while(s.size()){
        pair<int,int> p=*s.begin();
        if(vis[p.se]){
            s.erase(s.begin());
            continue;
        }
        vis[p.se]=1;
        for(auto x: g[p.se]){
            //cout<<p.fe+x.se;
            if(ans[x.fe]<=p.fe+x.se)continue;
            ans[x.fe]=p.fe+x.se;
            s.insert({p.fe+x.se,x.fe});
        }
        s.erase(s.begin());
    }
    return ans;
}
signed main(){
    cout<<"ENTER VERTICES, EDGES AND GRAPH RESPECTIVELY\n";
    int n,m;
    cin>>n>>m;
    vvpi g(n+1);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    vis=vector<bool>(n+1,0);
    cout<<"ENTER STARTING VERTEX\n";
    int tt; 
    cin>>tt;
    vi ans=dij(g,n,tt);
    for(int i=1;i<ans.size();i++){
        cout<<"Distance from Node "<<i<<" is "<<ans[i]<<"\n";
    }
}