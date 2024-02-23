#include<bits/stdc++.h>
using namespace std;

// stack implementation using array
class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size=size;    // here right size is the variable size that is closest to it   i.e. variable of constructor
        arr=new int[size];
        top=-1;
    }

    void push(int element){
        if(size-1-top>0){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow\n";
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow\n";
        }
    }

    int peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"empty stack\n";
            return -1;
        }
    }

    bool empty(){
        if(top>=0)
            return 0;
        else
            return 1;
    }
    
};

class node{
    public:
    int data;
    node*next=NULL;

    node(int d){
        this->data=d;
    }
};

void insertAtTail(node*&head, node*&tail, int d){
    node*n1=new node(d);
    if(head==NULL){
        head=n1;
        tail=n1;
        return;
    }
    tail->next=n1;
    tail=n1;
}

void deleteAtTail(node*&head, node* &tail){
    if(head==NULL){
        cout<<"stack underflow\n";
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        tail=NULL;
        return;
    }
    node* prev=head;
    while(prev->next->next!=NULL){
        prev=prev->next;
    }
    node*temp=prev->next;
    prev->next=NULL;
    tail=prev;
    delete temp;

}

// stack implementation using linked list
// other approach-> give size/2 space to both stacks but in this way, space is not optimally utilised
class Stack2{
    public:
    node*top=NULL;
    node*head=NULL;
    node*tail=NULL;

    void push(int d){
        insertAtTail(head, tail, d);
    }

    void pop(){
        deleteAtTail(head, tail);
    }

    int peek(){
        if(head==NULL){
            cout<<"empty stack\n";
            return -1;
        }
        return tail->data;
    }

    bool empty(){
        if(head==NULL)
            return true;
        else
            return false;
    }
};

class Stack2_2{
    public:
    node*head;
    node*tail;

    Stack(){
        head=NULL;
        tail=NULL;
    }

    void push(int d){
        node*n1=new node (d);
        if(head==NULL){
            head=n1;
        }
        else{
            tail->next=n1;
        }
        tail=n1;
    }

    void pop(){
        if(head==NULL){
            cout<<"stack underflow\n";
        }
        else{
            if(head->next==NULL){
                head=NULL;
                tail=NULL;
                return;
            }
            node*curr=head;
            node*currprev=curr;
            while(curr->next!=NULL){
                currprev=curr;
                curr=curr->next;
            }
            currprev->next=NULL;
            delete curr;
            tail=currprev;
        }
    }

    int peak(){
        if(head==NULL){
            cout<<"empty stack\t";
            return -1;
        }
        else{
            return tail->data;
        }
    }

    bool empty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

// 2 stacks implementation using single array
class Stack3{
    public:
    int size;
    int *arr;
    int top1;
    int top2;

    Stack3(int size){
        arr = new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    void push1(int d){
        if(top1==top2-1){
            cout<<"stack overflow\n";
            return;
        }
        top1++;
        arr[top1]=d;
    }

    void pop1(){
        if(top1==-1){
            cout<<"stack1 underflow\n";
            return;
        }
        top1--;
    }

    int peek1(){
        if(top1==-1){
            cout<<"empty stack1\n";
            return -1;
        }
        return arr[top1];
    }

    bool empty1(){
        if(top1==-1)
            return true;
        else
            return false;
    }
    
    void push2(int d){
        if(top1==top2-1){
            cout<<"stack overflow\n";
            return;
        }
        top2--;
        arr[top2]=d;
    }

    void pop2(){
        if(top2==size){
            cout<<"stack2 underflow\n";
            return;
        }
        top2++;
    }

    int peek2(){
        if(top2==size){
            cout<<"empty stack2\n";
            return -1;
        }
        return arr[top2];
    }

    bool empty2(){
        if(top2==size)
            return true;
        else
            return false;
    }  
};

int main(){

    /*
    stack- LIFO-> Last In First Out

    Operations in Stack
    push-> insert at top of the stack
    pull-> remove from top of the stack
    peek-> returns the top element of the stack
    empty-> returns bool value  check whether a stack is empty or not
    
    creating a stack
    stack<datatype>stackName;
    stack<int>s;

    inbuilt functions
    s.push(value);
    s.pop();
    s.top();    // peek
    s.empty();
    s.size();

    */

    // creation of stack using STL
    stack<int>s;
    s.push(10);
    s.push(20);
    cout << "s.peak()-> " << s.top() << '\n';
    cout << "s.empty()-> " << s.empty() << '\n';
    cout << "s.size()-> " << s.size() << "\n\n";

    s.pop();
    cout << "s.peak()-> " << s.top() << '\n';
    cout << "s.empty()-> " << s.empty() << '\n';
    cout << "s.size()-> " << s.size() << "\n\n";

    s.pop();
    // cout << "s.peak()-> " << s.peek() << '\n';      //why is it not working
    cout << "s.empty()-> " << s.empty() << '\n';
    cout << "s.size()-> " << s.size() << "\n\n";
    cout<<'\n';

    // array implementation of stack
    cout<<"array implementation of stack\n";
    Stack s2(2);
    s2.push(10);
    cout << "s2.peak()-> " << s2.peek() << '\n';
    cout << "s2.empty()-> " << s2.empty() << '\n';
    s2.push(20);
    cout << "s2.peak()-> " << s2.peek() << '\n';
    cout << "s2.empty()-> " << s2.empty() << '\n';
    s2.push(30);
    cout << "s2.peak()-> " << s2.peek() << '\n';
    cout << "s2.empty()-> " << s2.empty() << '\n';
    s2.pop();
    s2.pop();
    cout << "s2.peak()-> " << s2.peek() << '\n';
    cout << "s2.empty()-> " << s2.empty() << '\n';
    cout<<'\n';

    // linkedlist implementation of stack
    cout<<"linked list implementation of stack\n";
    Stack2 s3;
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.push(10);
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.push(20);
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.push(30);
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.pop();
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.pop();
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    s3.pop();
    cout << "s3.peak()-> " << s3.peek() << '\n';
    cout << "s3.empty()-> " << s3.empty() << '\n';
    cout<<'\n';

    // 2 stacks implementation using single array
    cout<<"2 stacks implementation using single array\n";
    Stack3 s4(5);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push1(10);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push2(20);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push1(30);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push2(40);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push1(50);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push2(60);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.push1(70);
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop1();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop2();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop1();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop2();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop1();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop2();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    s4.pop1();
    cout << "s4.peak1()-> " << s4.peek1() << '\n';
    cout << "s4.empty1()-> " << s4.empty1() << '\n';
    cout << "s4.peak2()-> " << s4.peek2() << '\n';
    cout << "s4.empty2()-> " << s4.empty2() << "\n\n";
    cout<<'\n';

    return 0;
}