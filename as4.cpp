#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
int ps(vi &v, int l, int r){
    int j=l-1;
    for(int i=l;i<r;i++){
        if(v[i]<v[r]){
            j++;
            swap(v[i],v[j]);
        }
    }
    swap(v[j+1],v[r]);
    return j+1;
}
void qs(vi &v, int l, int r){
    if(l>=r)return;
    int p=ps(v,l,r);
    //cout<<p;
    qs(v,l,p-1);
    qs(v,p+1,r);
}
void mer(vi &v, int l, int r, int m){
    vi a,b;
    for(int i=l;i<=m;i++){
        a.push_back(v[i]);
    }
    for(int i=m+1;i<=r;i++){
        b.push_back(v[i]);
    }
    int n=a.size();
    int nn=b.size();
    int k=l;
    int i=0,j=0;
    while(i<n||j<nn){
        if(i==n){
            v[k]=b[j];
            j++;
        }
        else if(j==nn){
            v[k]=a[i];
            i++;
        }
        else if(a[i]>b[j]){
            v[k]=b[j];
            j++;
        }
        else{
            v[k]=a[i];
            i++;
        }
        k++;
    }
    //for(int i=l;i<=r;i++)cout<<v[i]<<" ";
   // cout<<"\n";
}
void ms(vi &v,int l, int r){
    if(l>=r)return;
    ms(v, l, (l+r)/2);
    ms(v,(l+r)/2+1,r);
    mer(v,l,r,(l+r)/2);
}
signed main(){
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<"Enter accordingly\n 1.Quick Sort\n 2.Merge Sort\n";
    int x;
    cin>>x;
    if(x==1)qs(v,0,n-1);
    else ms(v,0,n-1);
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
}            
