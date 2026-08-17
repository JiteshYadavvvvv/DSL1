#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
class Node{
    private:
        int data;
        Node* nxt=nullptr;
    public :
        Node(int val){
            data=val;
        }
    friend class Linked_List;
};
class Linked_List{
    public: 
        int sz=0;
        Node* head=nullptr;
        Linked_List();
        Linked_List(Node* a){
            head=a;
            sz++;
        }
        void display(){
            Node *t=head;
            for(int i=1;i<=sz;i++){
                cout<<t->data<<" ";
                t=t->nxt;
            }
        }
        void searchbyval(int val){
            Node* temp=head;
            if(temp->data==val){
                cout<<1<<"\n";
            }
            for(int i=2;i<=sz;i++){
                temp=temp->nxt;
                if(temp->data==val){
                    cout<<i<<"\n";
                }
            }
        }
        void searchbypos(int pos){
            Node *temp=head;
            if(pos==1){
                cout<<temp->data;
            }
            for(int i=2;i<=pos;i++){
                temp=temp->nxt;
            }
            cout<<temp->data<<"\n";
        }
        void insert(int pos, Node *a){
            Node* temp=head;
            this->sz++;
            if(pos==1){
                a->nxt=head;
                head=a;
                return;
            }
            for(int i=2;i<=pos-1;i++){
                temp=temp->nxt;
            }
            a->nxt=temp->nxt;
            temp->nxt=a;
        }
        void insert(int pos, int val){
            Node* temp=head;
            this->sz++;
            Node *a=new Node(val);
            if(pos==1){
                a->nxt=head;
                head=a;
                return;
            }
            for(int i=2;i<=pos-1;i++){
                temp=temp->nxt;
            }
            a->nxt=temp->nxt;
            temp->nxt=a;
        }
        void delbyval(int val){
            Node* temp=head;
            if(temp->data==val){
                head=temp->nxt;
                temp->nxt=nullptr;
                sz--;
                return;
            }
            for(int i=2;i<=sz-1;i++){
                temp=temp->nxt;
                if(temp->nxt->data==val){
                    temp->nxt=temp->nxt->nxt;
                    temp->nxt->nxt=nullptr;
                    sz--;
                    return;
                }
            }
            cout<<"Not found\n";
        }
        void delbypos(int pos){
            Node* temp=head;
            if(pos==1){
                head=temp->nxt;
                temp->nxt=nullptr;
                sz--;
                return;
            }
            for(int i=2;i<=pos-1;i++){
                temp=temp->nxt;
            }
            sz--;
            temp->nxt=temp->nxt->nxt;
            return;
        }
        void rev(){
            if(sz==1)return;
            Node *t1=head;
            if(sz==2){
                t1=t1->nxt;
                t1->nxt=head;
                head=t1;
                return;
            }
            Node *t2=t1->nxt;
            for(int i=1;i<=sz-1;i++){
                Node *t3=t2->nxt;
                t2->nxt=t1;
                t1=t2;
                t2=t3;
            }
            head=t1;
        }
        void sort(){
            for(int i=1;i<=sz-1;i++){
                Node* temp=head;
                for(int j=1;j<=sz-i;j++){
                    if(temp->data > temp->nxt->data){
                        swap(temp->data,temp->nxt->data);
                    }
                    temp=temp->nxt;
                }
            }
        }
};
signed main(){
    cout<<"Enter size of Linked List\n";
    int n;
    cin>>n;
    cout<<"Enter Elements\n";
    int x;
    cin>>x;
    Node* t=new Node(x);
    Linked_List a(t);
    for(int i=2;i<=n;i++){
        cin>>x;
        a.insert(i,x);
    }
    x=1;
    while(x>0){
        cout<<"\nDOUBLY LINKED LIST OPERATION\n";
        cout<<"1.Display\n";
        cout<<"2.Search by value\n";
        cout<<"3.Search by position\n";
        cout<<"4.Insert value at given position\n";
        cout<<"5.Delete by position\n";
        cout<<"6.Delete by value\n";
        cout<<"7.Reverse Linked List\n";
        cout<<"8.Sort Linked List\n";
        cin>>x;
        if(x==1){
            a.display();
        }
        else if(x==2){
            cout<<"Enter value\n";
            int tt;
            cin>>tt;
            a.searchbyval(tt);
        }
        else if(x==3){
            cout<<"Enter position\n";
            int tt;
            cin>>tt;
            a.searchbypos(tt);
        }
        else if(x==4){
            cout<<"Enter value and position respectively\n";
            int tt,ttt;
            cin>>tt>>ttt;
            a.insert(ttt,tt);
        }
        else if(x==5){
            cout<<"Enter position\n";
            int tt;
            cin>>tt;
            a.delbypos(tt);
        }
        else if(x==6){
            cout<<"Enter value\n";
            int tt;
            cin>>tt;
            a.delbyval(tt);
        }
        else if(x==7){
            a.rev();
        }
        else if(x==8){
            a.sort();
        }
    }
}      