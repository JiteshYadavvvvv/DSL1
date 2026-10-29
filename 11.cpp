#include <bits/stdc++.h>
using namespace std;

#define ll int
#define N 10
#define st string
#define pi pair<ll,st>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define nl cout<<"\n"

vvpi h(N);

ll hashFunc(ll x){
    return x%N;
}

void insertKey(ll isbn,st title){
    ll i=hashFunc(isbn);
    for(auto &p:h[i]){
        if(p.first==isbn){
            p.second=title;
            return;
        }
    }
    h[i].push_back({isbn,title});
}

void searchKey(ll isbn){
    ll i=hashFunc(isbn);
    for(auto p:h[i]){
        if(p.first==isbn){
            cout<<p.second<<"\n";
            return;
        }
    }
    cout<<"Not Found\n";
}

void deleteKey(ll isbn){
    ll i=hashFunc(isbn);
    for(ll j=0;j<(ll)h[i].size();j++){
        if(h[i][j].first==isbn){
            h[i].erase(h[i].begin()+j);
            cout<<"Deleted\n";
            return;
        }
    }
    cout<<"Not Found\n";
}

void display(){
    for(ll i=0;i<N;i++){
        cout<<i<<" : ";
        for(auto p:h[i]){
            cout<<"("<<p.first<<","<<p.second<<") ";
        }
        nl;
    }
}

void solve(){
    ll ch,isbn;
    st title;
    do{
        cout<<"1.Insert 2.Search 3.Delete 4.Display 5.Exit\n";
        cin>>ch;
        if(ch==1){
            cin>>isbn;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,title);
            insertKey(isbn,title);
        }
        else if(ch==2){
            cin>>isbn;
            searchKey(isbn);
        }
        else if(ch==3){
            cin>>isbn;
            deleteKey(isbn);
        }
        else if(ch==4) display();
    }while(ch!=5);
}

signed main(){
    solve();
    return 0;
}