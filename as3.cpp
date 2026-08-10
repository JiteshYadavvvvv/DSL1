#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
pair<vvi,pair<int,int>> in(){
    int n,m;
    cout<<"Size of Matrix in order of rows and columns\n";
    cin>>n>>m;
    vvi a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            if(x)a.push_back({i,j,x});
        }
    }
    return {a,{n,m}};
}
void display(vvi &a, int n, int m){
    int nn=a.size();
    int k=0;
    cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(k<nn){
                if(a[k][0]==i&&a[k][1]==j){
                    cout<<a[k][2]<<" ";
                    k++;
                }
                else{
                    cout<<0<<" ";
                }
            }
            else{
                cout<<0<<" ";
            }

        }
        cout<<"\n";
    }
}
void tr(vvi &a, int n, int m){
    for(auto &x: a){
        swap(x[0],x[1]);
    }
    sort(a.begin(), a.end());
    
}
void ad(vvi &a,int n,int m){
    auto v=in();
    vvi b=v.first;
    if(v.second.second!=m||v.second.first!=n){
        cout<<"Not possible";
        return;
    }
    int u=0;
    int nn=a.size();
    int mm=b.size();
    int d=0;
    vvi c;
    while(u<nn||d<mm){
        if(u<nn&&d==mm){
            c.push_back(a[u]);
            u++;
        }
        else if(d<mm&&u==nn){
            c.push_back(b[d]);
            d++;
        }
        else if(a[u][0]<b[d][0]){
            c.push_back(a[u]);
            u++;
        }
        else if(a[u][0]>b[d][0]){
            c.push_back(b[d]);
            d++;
        }
        else{
            if(a[u][1]<b[d][1]){
                c.push_back(a[u]);
                u++;
            }
            else if(a[u][1]>b[d][1]){
                c.push_back(b[d]);
                d++;
            }
            else{
                a[u][2]+=b[d][2];
                c.push_back(a[u]);
                u++;
                d++;
            }
        }
    }
}
int main(){
    auto v=in();
    vvi a=v.first;
    int n=v.second.first;
    int m=v.second.second;
    cout<<"Enter number in accordance of task\n 1.Transpose of Matrix\n 2.Addition of Matrix\n";
    int t;
    cin>>t;
    if(t==1){
        tr(a,n,m);
        display(a,m,n);
    }
    else{
        ad(a,n,m);
        display(a,n,m);
    }
}