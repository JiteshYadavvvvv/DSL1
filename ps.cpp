#include<bits/stdc++.h>
using namespace std;
void bs(int a[], int n, int k){
    sort(a, a+n);
    int c=0;
    int l=0,r=n-1;
    while(l<=r){
        c++;
        int mid=(r-l)/2+l;
        if(a[mid]>k){
            r=mid-1;
        }
        else if(a[mid]<k){
            l=mid+1;
        }
        else{
            cout<<"Position is "<<mid+1<<endl;
            cout<<"operations performed "<<c<<endl;
            return;
        }
    }
    cout<<-1;
}
void ls(int a[], int n, int k){
    int c=0;
    for(int i=0;i<n;i++){
        c++;
        if(a[i]==k){
            cout<<"Position is "<<i+1<<endl;
            cout<<"operations performed "<<c<<endl;
            return;
        }
    }
    cout<<-1;
}
int main(){
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    //cout<<"Enter elements\n";
    for(int i=0;i<n;i++){
        int t=rand();
        a[i]=t;
    }
    //cout<<a[12];
    int x;
    cout<<"Enter\n 1.Binary Search \n 2.Linear Search\n";
    cin>>x;
    int k;
    cout<<"Enter element you want to find";
    cin>>k;
    if((x-1))ls(a,n,k);
    else bs(a,n,k);
}
