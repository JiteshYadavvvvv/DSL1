#include<bits/stdc++.h>
using namespace std;
void bubs(int a[], int n){
    int c=0;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0&&a[j]<a[j-1]){
            c++;
            swap(a[j],a[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Operations performed "<<c;
}
void sels(int a[], int n){
    int c=0;
    for(int i=0;i<n;i++){
        int mi=i;
        for(int j=i;j<n;j++){
            if(a[mi]>a[j]){
                mi=j;
            }
        }
        swap(a[mi],a[i]);
        c++;
        cout<<"Pass number "<<c<<"\n";
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
    	cout<<endl;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Operations performed "<<c;
}
void ins(int a[], int n){
    int c=0;
    for(int i=1;i<n;i++){
        int t=a[i];
        int j=i-1;
        while(j>=0&&a[j]>t){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
    cout<<"Operations performed "<<c;
}
int main(){
    int n;
    cout<<"Enter number of elements";
    cin>>n;
    int a[n];
    cout<<"Enter elements";
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"Enter\n 1.Selection Sort\n 2.Insertion sort\n 3.Bubble Sort";
    int x;
    cin>>x;
    if(x==1)sels(a,n);
    else if(x==2)ins(a,n);
    else bubs(a,n);
}
