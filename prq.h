#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
//          0*
//        1*   2*
//       3* 4* 5* 6*
class prq{
    private:
        int a[100]={0};
        int p=0;
    public:
        void insert(int val){
            a[p]=val;
            int ind=p;
            while(ind!=0&&a[(ind-1)/2]<a[ind]){
                swap(a[(ind-1)/2],a[ind]);
                ind=(ind-1)/2;
            }
            p++;
        }    
        void print(){
            for(int i=0;i<p;i++){
                cout<<a[i]<<" ";
            }
        }
        void dis(){
            int tw=0;
            int c=1;
            bool f=1;
            for(int i=0;f;i=tw){
                cout<<"Level-"<<c<<" ";
                tw=tw*2+1;
                for(int j=i;j<tw;j++){
                    //cout<<p<<" "<<j<<" ";
                    if(j==p){
                        f=0;
                        break;
                    }
                    cout<<a[j]<<" ";
                }
                c++;
                cout<<"\n";
            }
        }
        int top(){
            return a[0];
        }
        int pop(){
            if(p==0){
                cout<<"NOT POSSIBLE\n";
                return 0;
            }
            int ret=a[0];
            swap(a[0],a[p-1]);
            a[p-1]=0;
            int ind=p-1;
            int b[16]={0};
            int pp=1;
            b[0]=p-1;
            while(ind!=0){
                ind=(ind-1)/2;
                b[pp]=ind;
                pp++;
            }
            pp--;
            ind=0;
            while(pp>=0){
                //cout<<ind<<" "<<a[ind+1]<<" "<<a[ind+2]<<" "<<a[ind]<<"\n";
                if(a[ind]<a[ind+1]||a[ind]<a[ind+2]){
                    swap(a[ind],a[b[pp]]);
                    pp--;
                }
                else break;
                if(a[ind]<a[ind+2]){
                    swap(a[ind],a[ind+2]);
                }
                else if(a[ind]<a[ind+1]){
                    swap(a[ind],a[ind+1]);
                }
                ind=b[pp+1];
            }
            p--;
            return ret;
        }   
};