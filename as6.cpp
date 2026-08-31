#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
#include "sttack.h"
void bs(){
    cout<<"Enter Bracket Sequence";
    string s;
    cin>>s;
    int n=s.size();
    st<char> a;
    for(auto x: s){
        if(x=='('||x=='{'||x=='['){
            a.push(x);
        }
        else{
            if(x==')'){
                if('('==a.peek()){
                    a.pop();
                }
                else{
                    cout<<"Not Correct";
                    return ;
                }
            }
            else if(x==']'){
                if('['==a.peek()){
                    a.pop();
                }
                else{
                    cout<<"Not Correct";
                    return ;
                }
            }
            else if(x=='}'){
                if('{'==a.peek()){
                    a.pop();
                }
                else{
                    cout<<"Not Correct";
                    return ;
                }
            }
        }
    }
    if(a.size()>0){
        cout<<"Not Correct";
    }
    else cout<<"Correct ";
}
void con(){
    cout<<"Enter expression to convert to postfix";
    string s;
    cin>>s;
    st<char> b;
    int a[257]={0};
    a['+']=1;
    a['-']=1;
    a['*']=2;
    a['/']=2;
    a['%']=2;
    a['^']=3;
    a['(']=5;
    char ch[]={'+', '-', '*', '/', '%', '^', '(', ')'};
    for(auto x: s){
        bool f=0;
        for(auto xx: ch){
            if(x==xx){
                f=1;
                break;
            }
        }
        if(f){
            if(b.isEmpty())b.push(x);
            else{
                if(x==')'){
                    while(b.peek()!='('){
                        cout<<b.peek();
                        b.pop();
                    }
                    b.pop();
                    continue;
                }
                else if(x=='^'){
                    while(b.size()&&b.peek()!='('&&a[b.peek()]>a[x]){
                        cout<<b.peek();
                        b.pop();
                    }
                    b.push(x);
                    continue;
                }
                while(b.size()&&b.peek()!='('&&a[b.peek()]>=a[x]){
                    cout<<b.peek();
                    b.pop();
                }
                b.push(x);
            }
        }
        else{
            cout<<x;
        }
    }
    while(!b.isEmpty()){
        cout<<b.pop();
    }
}
void eval(){
    cout<<"Enter postfix expression to evaluate\n";
    string s;
    cin>>s;
    st<int> b;
    int a[257]={0};
    a['+']=1;
    a['-']=1;
    a['*']=2;
    a['/']=2;
    a['%']=2;
    a['^']=3;
    a['(']=5;
    char ch[]={'+', '-', '*', '/', '%', '^', '(', ')'};
    for(auto x: s){
        bool f=0;
        int j=-1;
        for(int i=0;i<8;i++){
            if(x==ch[i]){
                f=1;
                j=i;
                break;
            }
        }
        // for(auto y: b)cout<<y<<" ";
        //cout<<"\n";
        if(f){
            int bb=b.pop();
            int aa=b.pop();
            int c;
            //cout<<aa<<" "<<bb<<" "<<j<<"\n ";
            if(j==0){
                c=aa+bb;
            }
            else if(j==1){
                c=aa-bb;
            }
            else if(j==2){
                c=aa*bb;
            }
            else if(j==3){
                c=aa/bb;
            }
            else if(j==4){
                c=aa%bb;
            }
            else{
                c=pow(aa,bb);
            }
            b.push(c);
        }
        else{
            b.push(x-'0');
        }
    }
    cout<<b.pop();
}
void coi(){
    cout<<"Enter expression to convert to prefix";
    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    st<char> b;
    int a[257]={0};
    a['+']=1;
    a['-']=1;
    a['*']=2;
    a['/']=2;
    a['%']=2;
    a['^']=3;
    a[')']=5;
    string ans="";
    char ch[]={'+', '-', '*', '/', '%', '^', '(', ')'};
    for(auto x: s){
        bool f=0;
        for(auto xx: ch){
            if(x==xx){
                f=1;
                break;
            }
        }
        if(f){
            if(b.isEmpty())b.push(x);
            else{
                if(x=='('){
                    while(b.peek()!=')'){
                        ans+=b.pop();
                    }
                    b.pop();
                    continue;
                }
                else if(x=='^'){
                    while(b.size()&&b.peek()!=')'&&a[b.peek()]>a[x]){
                        ans+=b.pop();
                        
                    }
                    b.push(x);
                    continue;
                }
                while(b.size()&&b.peek()!=')'&&a[b.peek()]>=a[x]){
                    ans+=b.pop();
                }
                b.push(x);
            }
        }
        else{
            ans+=x;
        }
    }
    while(!b.isEmpty()){
        ans+=b.pop();
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
signed main(){
    while(1){
        cout<<"\n||||  ENTER OPTION  ||||\n1.Bracket Expression\n2.Convert Infix to Postfix\n3.Evaluate Postfix\n4.Infix to Prefix\n5.Exit";
        int x;
        cin>>x;
        if(x==1){
            bs();
        }
        else if(x==2){
            con();
        }
        else if(x==3){
            eval();
        }
        else if(x==4){
            coi();
        }
        else{
            break;
        }
    }
}      