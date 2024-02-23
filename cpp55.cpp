#include<bits/stdc++.h>
using namespace std;

// stack can be used to reverse anything
void reverseString(string &s){
    int size=s.length();
    stack<char>st;
    for(int i=0; i<size; i++){
        st.push(s[i]);
    }
    for(int i=0; i<size; i++){
        s[i]=st.top();
        st.pop();
    }
}

void deleteMiddleElement(stack<int>&st){
    int size=st.size();
    int cnt=size/2;
    stack<int>st2;
    while(cnt--){
        st2.push(st.top());
        st.pop();
    }
    st.pop();
    cnt=size/2;
    while(cnt--){
        st.push(st2.top());
        st2.pop();
    }
}

void printStack(stack<int>st){
    int size=st.size();
    while(size--){
        cout<<st.top()<<' ';
        st.pop();
    }
        cout<<"\n\n";
}

void printStack2(stack<char>st){
    int size=st.size();
    while(size--){
        cout<<st.top()<<' ';
        st.pop();
    }
        cout<<"\n\n";
}

bool validParenthesis(string s){
    stack<char>st;
    int size= s.length();
    for(int i=0; i<size; i++){
        if((s[i]==')' || s[i]==']' || s[i]=='}') && st.empty()){
            cout<< "invalid parenthesis\n\n";
            return false;
        }

        if( (s[i]=='(') || (s[i]=='[') || (s[i]=='{')){
            st.push(s[i]);
        }
        else if((s[i]==')' && st.top()=='(') || 
                (s[i]==']' && st.top()=='[') || 
                (s[i]=='}' && st.top()=='{')){
            st.pop();
        }
        else{
            cout<< "invalid parenthesis\n\n";
            return false;
        }
    }

    if(st.empty()){
        cout<< "valid parenthesis\n\n";
        return true;
    }
    else{
        cout<< "invalid parenthesis\n\n";
        return false;
    }
}

void insertAtBottom(stack<int>&st, int d){
    stack<int>st2;
    while(st.size()!=0){
        st2.push(st.top());
        st.pop();
    }
    st.push(d);
    while(st2.size()!=0){
        st.push(st2.top());
        st2.pop();
    }
}

stack<int> reverseStackUsingRecursion(stack<int>&st, stack<int>&st2, int cnt){
    if(cnt==0)
        return st2;
    
    cnt--;
    reverseStackUsingRecursion(st, st2, cnt);
    st2.push(st.top());
    st.pop();
    return st2;
}

void sortInsert(stack<int>&st, int d){
    stack<int>st2;
    while(st.size()!=0 && st.top()>d){
        st2.push(st.top());
        st.pop();
    }
    st.push(d);
    while(st2.size()!=0){
        st.push(st2.top());
        st2.pop();
    }
}

void sortInsert2(stack<int>&st, int d){
    if(st.size()==0 || (st.size()!=0 && st.top()<d)){
        st.push(d);
        return;
    }
    
    int x=st.top();
    st.pop();
    sortInsert2(st, d);
    st.push(x);
}

void sortStack(stack<int>&st){
    if(st.size()==0){
        return;
    }

    int d=st.top();
    st.pop();
    sortStack(st);
    sortInsert2(st, d);
    return;
}

bool isBracket(char c){
    if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}'){
        return true;
    }
    else
        false;
}

bool isOpenBracket(char c){
    if(c=='(' || c=='[' || c=='{'){
        return true;
    }
    else
        false;
}

bool isCloseBracket(char c){
    if( c==')' || c==']' || c=='}'){
        return true;
    }
    else
        false;
}

bool isOperator(char c){
    if( c=='+' || c=='-' || c=='*' || c=='/' || c=='%'){
        return true;
    }
    else
        false;
}

char pairBracket(char c){
    if(c=='(' ){
        return ')';
    }
    else if(c=='[' ){
        return ']';
    }
    else if(c=='{' ){
        return '}';
    }
}

bool redundantBrackets(string s){
    int size=s.length();
    stack<char>st;
    for(int i=0; i<=size; i++){
        if(isOpenBracket(s[i]) || isOperator(s[i])){
            st.push(s[i]);
        }
        else if(isCloseBracket(s[i])){
            if(pairBracket(s[i])==st.top()){
                cout<<"redundant brackets\n\n";
                return true;
            }
            while(st.top()!=pairBracket(s[i])){
                st.pop();
            }
            st.pop();
        }
    }
    cout<<"no redundant brackets\n\n";
    return false;
}

bool redundantBrackets2(string &s){
    stack<char>st;
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        if(ch=='{' || ch=='[' || ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch=='}' || ch==']' || ch==')'){
            if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){\
                while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                st.pop();
                }
                st.pop();
            }
            else if(st.top()=='(' || st.top()=='{' || st.top()=='['){
                return true;
            }
        }
    }
    return false;
}

int minCostToMakeValidString(string s){
    int len=s.length();
    if(len&1)
        return -1;
    stack<int>st;
    for(int i=0; i<len; i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                st.push('}');
            }
            else if (st.top()=='{')
            {
                st.pop();
            }else{
                st.push('}');
            }
        }
    }

    int a=0, b=0;
    while(!st.empty()){
        if(st.top()=='{')
            a++;
        else
            b++;
        st.pop();
    }
    return ((a+1)/2 + (b+1)/2);
}

int main(){

    string s="Ujjwal23";
    // cout<<s<<'\n';

    reverseString(s);
    cout<<"reverseString\n";
    cout<<s<<'\n';

    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.push(50);
    printStack(st);

    deleteMiddleElement(st);
    cout<<"after deleteMiddleElement\n";
    printStack(st);

    string s2="{[}]}";
    validParenthesis(s2);

    // stack<int> st3;
    // cout<<st3.top()<<'\n';

    stack<int>st2;
    st2.push(10);
    st2.push(20);
    st2.push(30);
    printStack(st2);
    insertAtBottom(st2, 40);
    cout<<"after insertAtBottom\n";
    printStack(st2);

    stack<int>st3;
    st3.push(10);
    st3.push(20);
    st3.push(30);
    st3.push(40);
    printStack(st3);
    stack<int>st4;
    st4= reverseStackUsingRecursion(st3, st4, st3.size());
    cout<<"after reverseStackUsingRecursion\n";
    printStack(st4);

    stack<int>st5;
    st5.push(10);
    st5.push(40);
    st5.push(30);
    st5.push(20);
    printStack(st5);
    sortStack(st5);
    cout<<"after sortStack\n";
    printStack(st5);

    string s3="{}{(a+b)}";
    cout<<s3<<"\n\n";
    redundantBrackets(s3);

    string s4="{{{}";
    cout<<s4<<"\n\n";
    cout<< minCostToMakeValidString(s4) << "\n\n";



    
    



    return 0;
}