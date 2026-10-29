#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N 10
#define vi vector<ll>
#define nl cout<<"\n"

vi h(N,-1);

ll hashFunc(ll x){
    return x%N;
}

void insertKey(ll x){
    ll i=hashFunc(x);
    for(ll j=0;j<N;j++){
        ll k=(i+j)%N;
        if(h[k]==-1 || h[k]==-2){
            h[k]=x;
            return;
        }
    }
    cout<<"Full\n";
}

void searchKey(ll x){
    ll i=hashFunc(x);
    for(ll j=0;j<N;j++){
        ll k=(i+j)%N;
        if(h[k]==-1) break;
        if(h[k]==x){
            cout<<"Found\n";
            return;
        }
    }
    cout<<"Not Found\n";
}

void deleteKey(ll x){
    ll i=hashFunc(x);
    for(ll j=0;j<N;j++){
        ll k=(i+j)%N;
        if(h[k]==-1) break;
        if(h[k]==x){
            h[k]=-2;
            cout<<"Deleted\n";
            return;
        }
    }
    cout<<"Not Found\n";
}

void display(){
    for(ll i=0;i<N;i++){
        cout<<i<<" : ";
        if(h[i]==-1) cout<<"Empty";
        else if(h[i]==-2) cout<<"Deleted";
        else cout<<h[i];
        nl;
    }
}

void solve(){
    ll ch,x;
    do{
        cout<<"1.Insert 2.Search 3.Delete 4.Display 5.Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>x;
            insertKey(x);
        }
        else if(ch==2){
            cin>>x;
            searchKey(x);
        }
        else if(ch==3){
            cin>>x;
            deleteKey(x);
        }
        else if(ch==4) display();
    }while(ch!=5);
}

signed main(){
    solve();
    return 0;
}