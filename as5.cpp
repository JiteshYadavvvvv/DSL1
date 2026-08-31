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
            nxt=nullptr;
        }
    friend class Linked_List;
};
class Linked_List{
    private:
        Node *head=nullptr;
        int sz=0;
    public: 
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
            if(sz==0){
                cout<<"Not possible\n";
                return;
            }
            Node* temp=head;
            if(temp->data==val){
                cout<<1<<"\n";
                return;
            }
            for(int i=2;i<=sz;i++){
                temp=temp->nxt;
                if(temp->data==val){
                    cout<<i<<"\n";
                    return;
                }
            }
            cout<<"Not Found\n";
        }
        void searchbypos(int pos){
            Node *temp=head;
            if(pos==1){
                cout<<temp->data;
                return;
            }
            if(pos>sz||pos<1||head==nullptr){
                cout<<"Not possible\n";
                return;
            }
            for(int i=2;i<=pos;i++){
                temp=temp->nxt;
            }
            cout<<temp->data<<"\n";
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
            if(pos>sz||sz==0){
                cout<<"Not possible\n";
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
            Node* tt=head;
            if(temp->data==val){
                head=temp->nxt;
                delete temp;
                sz--;
                
                return;
            }
            for(int i=2;i<=sz-1;i++){
                temp=temp->nxt;
                if(temp->nxt->data==val){
                    tt=temp->nxt;
                    temp->nxt=temp->nxt->nxt;
                    delete tt;
                    sz--;
                    
                    return;
                }
            }
            cout<<"Not found\n";
        }
        void delbypos(int pos){
            Node* temp=head;
            Node *tt=head;
            if(pos==1){
                head=temp->nxt;
                temp->nxt=nullptr;
                sz--;
                
                return;
            }
            if(pos>sz||pos<1||head==nullptr){
                cout<<"Not possible\n";
                return;
            }
            for(int i=2;i<=pos-1;i++){
                temp=temp->nxt;
            }
            tt=temp->nxt;
            temp->nxt=temp->nxt->nxt;
            delete tt;
            sz--;
        }
        void rev(){
            if(sz==1)return;
            Node *t1=head;
            if(sz==2){
                t1=t1->nxt;
                head->nxt=nullptr;
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
                Node* prev=nullptr;
                Node* temp=head;
                for(int j=1;j<=sz-i;j++){
                    Node* next=temp->nxt;
                    if(temp->data > temp->nxt->data){
                        if(prev==nullptr){
                            head=next;
                        }
                        else{
                            prev->nxt=next;
                        }
                        temp->nxt=next->nxt;
                        next->nxt=temp;
                        prev=next;
                    }
                    else{
                        prev=temp;
                        temp=temp->nxt;
                    }
                    
                }
            }
        }
        Linked_List operator+(Linked_List b){
            Node *temp=this->head;
            while(temp->nxt!=nullptr){
                temp=temp->nxt;
            }
            temp->nxt=b.head;
            Linked_List c(this->head);
            c.sz=this->sz+b.sz;
            return c;
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
        cout<<"\nLINKED LIST OPERATION\n";
        cout<<"1.Display\n";
        cout<<"2.Search by value\n";
        cout<<"3.Search by position\n";
        cout<<"4.Insert value at given position\n";
        cout<<"5.Delete by position\n";
        cout<<"6.Delete by value\n";
        cout<<"7.Reverse Linked List\n";
        cout<<"8.Sort Linked List\n";
        cout<<"9.Concatenate a second Linked List\n";
        cout<<"Press 0 for Exit\n";
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
        else if(x==9){
            int sz2;
            cout<<"Enter size of second linked list\n";
            cin>>sz2;
            if(sz2==0){
                continue;
            }
            cout<<"Enter elements of second linked list\n";
            int y;
            cin>>y;
            Node *yy =new Node(y);
            Linked_List b(yy);
            for(int i=2;i<=sz2;i++){
                cin>>y;
                b.insert(i,y);
            }
            a=a+b;
            a.display();
        }
    }
}      