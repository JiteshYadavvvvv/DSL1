#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
#include "prq.h"

signed main(){
    prq a;
    int x=0;
    while(1){
        cout<<"||ENTER OPTION NUMBER||\n1.INSERT\n2.DELETE TOP ELEMENT\n3.GET TOP ELEMENT\n4.Display Level by Level\n5.EXIT";
        cin>>x;
        if(x==1){
            cout<<"Enter value\n";
            int t;
            cin>>t;
            a.insert(t);
        }
        else if(x==2){
            cout<<a.pop();
            cout<<endl;
        }
        else if(x==3){
            cout<<a.top();
            cout<<endl;
        }
        else if(x==4){
            a.dis();
        }
        else break;
        cout<<endl;
    }
}