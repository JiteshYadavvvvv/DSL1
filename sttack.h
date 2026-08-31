#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long

template <typename t> class st{
    private:
        t a[100]={0};
        int p=0;
    public:
        t* begin(){
            return &a[0];
        }
        t* end(){
            return &a[p];
        }
        void push(t val){
            a[p]=val;
            p++;
        }
        t pop(){
            p--;
            t b=a[p];
            a[p]=0;
            return b;
        }
        t peek(){
            return a[p-1];
        }
        t top(){
            return a[p-1];
        }
        t size(){
            return p;
        }
        bool isEmpty(){
            if(p==0)return 1;
            return 0;
        }
};