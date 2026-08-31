#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   ll n,y;
   cin>>n>>y;
   vector<ll> v(n);
   map<int,int> m;
   set<int> s;
   //a1%k+a2%k+a3%k+a4%k
   for(auto &x: v){
    cin>>x;
    s.insert(x);
    for(int i=2;i*i<=x;i++){
        if(x%i!=0)continue;
        if(i*i!=x)m[x/i]++;
        m[i]++;
    }
   }
   for(int i=2;i<=2e5;i++){

   }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
