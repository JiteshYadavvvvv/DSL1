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
            temp->nxt->nxt=nullptr;
            return;
        }
        void rev(){
            Node *t1=head;
            if(sz==2){
                t1=t1->nxt;
                t1->nxt=head;
                head=t1;
                return;
            }
            Node *t2=t1->nxt;
            Node *t3=t2->nxt;
            for(int i=2;i<=sz-1;i++){
                t2->nxt=t1;
                
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
    a.rev();
    a.display();
}      