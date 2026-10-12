#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpi vector<vector<pair<int,int>>>
#define vppi vector<pair<int,pair<int,int>>>
#define fe first
#define se second
#include "prq.h"
vector<int> p;
vector<int> sz;
void make(int x){
    p[x]=x;
    sz[x]=1;
}
int find(int x){
    if(p[x]==x)return x;
    int v=find(p[x]);
    p[x]=v;
    return v;
}
void un(int x, int y){
    int a=find(x);
    int b=find(y);    [[[[]]]]
    if(sz[a]>=sz[b]){
        p[b]=p[a];
        sz[a]+=sz[b];
    }
    else{
        p[a]=p[b];
        sz[b]+=sz[a];
    }
}
void disg(vvi g){
    int root=1;
    queue<int> q;
    vector<int> lev(g.size(),0);
    lev[1]=1;
    vector<vector<int>> l(g.size());
    vector<int> vis(g.size(),0);
    q.push(1);
    vis[1]=1;
    while(q.size()){
        int a=q.front();
        q.pop();
        l[lev[a]].push_back(a);
        for(auto x: g[a]){
            if(vis[x])continue;
            vis[x]=1;
            lev[x]=lev[a]+1;
            q.push(x);
        }
    }
    for(int i=1;i<l.size();i++){
        cout<<"LEVEL "<<i<<": ";
        for(auto x: l[i])cout<<x<<" ";
        cout<<"\n";
    }
}
void kruskal(vppi g, int n){
    sort(g.begin(),g.end());
    vvi gg(n+1);
    for(int i=1;i<=n;i++){
        make(i);
    }
    for(int i=0;i<g.size();i++){
        if(find(g[i].se.fe)!=find(g[i].se.se)){
            un(g[i].se.se,g[i].se.fe);
            gg[g[i].se.fe].push_back(g[i].se.se);
            gg[g[i].se.se].push_back(g[i].se.fe);
        }
    }
    disg(gg);
}
void prims(vvpi gg, int n){
    set<pair<int,pair<int,int>>> s;
    vector<int> vis(n+1,0);
    vvi g(n+1);
    vis[1]=1;
    for(auto x: gg[1]){
        s.insert({x.se,{1,x.fe}});
    }
    int c=1;
    while(s.size()){
        pair<int,pair<int,int>> p=*s.begin();
        cout<<c<<"\n";
        for(auto x: s){
            cout<<x.fe<<" "<<x.se.fe<<" "<<x.se.se<<"\n";
        }
        c++;
        s.erase(s.begin());
        if(vis[p.se.se])continue;
        vis[p.se.se]=1;
        g[p.se.fe].push_back(p.se.se);
        g[p.se.se].push_back(p.se.fe);
        for(auto x: gg[p.se.se]){
            s.insert({x.se,{p.se.se,x.fe}});
        }
    }
    disg(g);
}
pair<vppi,vvpi> gm(){
    cout<<"ENTER GRAPH NUMBER OF NODES, NUMBER OF EDGES AND THEN THE EDGES\n";
    int n,m;
    cin>>n>>m;
    p=vector<int>(n+1);
    sz=vector<int>(n+1,0);
    pair<vppi,vvpi> pg;
    pg.se=vvpi(n+1);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        pg.fe.push_back({z,{x,y}});
        pg.se[x].push_back({y,z});
        pg.se[y].push_back({x,z});
    }
    return pg;
}

signed main(){
    pair<vppi,vvpi> g=gm();
    cout<<"Enter \n1.Kruskal\n2.Prims\n";
    int x;
    cin>>x;
    if(!x)kruskal(g.fe,g.se.size()-1);
    else prims(g.se,g.se.size()-1);
}