#include<bits/stdc++.h>
using namespace std;

// queue using array
class Queue{
    public:
    int*arr;
    int s;
    int front;
    int rear;

    // if size is not given
    Queue(){
        s=10000;
        arr = new int[10000];
        front=-1;
        rear=-1;
    }

    Queue(int size){
        s=size;
        arr = new int[size];
        front=-1;
        rear=-1;
    }

    void push(int data){
        if(front ==-1 && rear==-1){
            front=0;
            rear=0;
            arr[rear]=data;
            return;
        }
        if(rear==s-1){
            cout<<"queue overflow\n";
            return;
        }
        rear++;
        arr[rear]=data;
    }

    void pop(){
        if(front==-1){
            cout<<"stack underflow\n";
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        front++;
    }

    bool empty(){
        if(rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int size(){
        if(rear==-1){
            return 0;
        }
        else{
            return rear-front+1;
        }
    }

    int Front(){
        // if(this->size()==0)      //both this and below line are same
        if(size()==0)
            return -1;
        return arr[front];
    }
    
    int back(){
        if(this->size()==0)
            return -1;
        return arr[rear];
    }
};

class node{
    public:
    int data;
    node*next;

    node(int d){
        data=d;
        next=NULL;
    }
};

// queue using linkedlist
class Queue2{
    public:
    node*front;
    node*rear;
    int s;

    Queue2(){
        front=NULL;
        rear=NULL;
        s=0;
    }

    void push(int data){
        s++;
        node*n1 = new node(data);

        if(rear==NULL){
            rear=front=n1;
        }
        else{
            rear->next=n1;
            rear=rear->next;
        }
    }

    void pop(){
        if(front==NULL){
            cout<<"queue underflow\n";
            return;
        }
        s--;
        if(front==rear){
            delete front;
            front=rear=NULL;
            return;
        }
        node*temp=front;
        front=front->next;
        delete temp;
    }

    bool empty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    int size(){
        return s;
    }

    int Front(){
        if(front==NULL){
            cout << "empty queue\n";
            return -1; 
        }
        else{
            return front->data;
        }
    }
    
    int back(){
        if(rear==NULL){
            cout << "empty queue\n";
            return -1; 
        }
        else{
            return rear->data;
        }
    }

};

// circular queue using array
class Queue3{
    public:
    int*arr;
    int s;
    int front;
    int rear;

    // if size is not given
    Queue3(){
        s=10000;
        arr = new int[10000];
        front=-1;
        rear=-1;
    }

    Queue3(int size){
        s=size;
        arr = new int[size];
        front=-1;
        rear=-1;
    }

    void push(int data){
        if(front ==-1 && rear==-1){
            front=0;
            rear=0;
            arr[rear]=data;
            return;
        }
        if(rear==s-1){
            if(front>0){
                rear=0;
                arr[rear]=data;
            }
            else{
                cout<<"queue overflow\n";
            }
            return;
        }
        if(front!=rear+1){
            rear++;
            arr[rear]=data;
        }
        else{
            cout<<"queue overflow\n";
        }
    }

    void pop(){
        if(front==-1){
            cout<<"stack underflow\n";
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        // if(front==s-1 && rear<front){
        if(front==s-1 ){    //both above and this line will act as same as rear cant be > front if front==s-1, and equal condition has been check earlier
            front=0;
            return;
        }
        front++;
    }

    bool empty(){
        if(rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int size(){
        if(rear==-1){
            return 0;
        }
        else{
            if(rear>=front)
                return rear-front+1;
            else
                return s-(front-rear-1);
        }
    }

    int Front(){
        // if(this->size()==0)      //both this and below line are same
        if(size()==0)
            return -1;
        return arr[front];
    }
    
    int back(){
        if(this->size()==0)
            return -1;
        return arr[rear];
    }
};

// doubly ended queue using array
class Queue4{
    public:
    int*arr;
    int s;
    int front;
    int rear;

    // if size is not given
    Queue4(){
        s=10000;
        arr = new int[10000];
        front=-1;
        rear=-1;
    }

    Queue4(int size){
        s=size;
        arr = new int[size];
        front=-1;
        rear=-1;
    }

    void push_back(int data){
        if(front ==-1 && rear==-1){
            front=rear=0;
            arr[rear]=data;
            return;
        }
        if(rear==s-1){
            if(front==0){
                cout<<"queue overflow\n";
            }
            else{
                rear=0;
                arr[rear]=data;
            }
            return;
        }
        rear++;
        arr[rear]=data;
    }

    void push_front(int data){
        if(front ==-1 && rear==-1){
            front=rear=0;
            arr[front]=data;
            return;
        }
        if(front==0){
            if(rear==s-1){
                cout<<"queue overflow\n";
            }
            else{
                front=s-1;
                arr[front]=data;
            }
            return;
        }
        front--;
        arr[front]=data;
    }

    void pop_front(){
        if(front==-1){
            cout<<"stack underflow\n";
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        if(front==s-1){
            front=0;
            return;
        }
        front++;
    }
    
    void pop_back(){
        if(rear==-1){
            cout<<"stack underflow\n";
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        if(rear==0){
            rear=s-1;
            return;
        }
        rear--;
    }

    bool empty(){
        if(rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int size(){
        if(rear==-1){
            return 0;
        }
        else{
            if(front>rear){
                return s-(front-rear-1);
            }
            else{
                return rear-front+1;
            }
        }
    }

    int Front(){
        // if(this->size()==0)      //both this and below line are same
        if(size()==0)
            return -1;
        return arr[front];
    }
    
    int back(){
        if(this->size()==0)
            return -1;
        return arr[rear];
    }
};


int main(){

    /*
    queue- FIFO- First In First Out
    front- for pop / dequeue
    rear- for push / enqueue

    queue using STL
    queue<datatype>name;
    queue<int>q;
    q.push(value);
    q.pop();
    q.size();
    q.empty();
    q.front();
    q.back();

    circular queue

    input restricted queue
        can pop (pop_front, pop_back) from both side, but push only from rear

    output restricted queue
        can push (push_front, push_back) from both side, but pop only from front
    
    doubly ended queue  dequeue
        can push (push_front, push_back) and pop (pop_front, pop_back) from both sides
        also it act as circular queue

    application of queues
        cpu / process scheduling in Operating System
    

    */

    // queue using STL
    cout<<"queue using STL\n";
    queue<int>q;
    q.push(5);
    cout << "q.front() -> "<<q.front()  << '\n';
    cout << "q.back() -> "<<q.back()  << '\n';
    cout << "q.size() -> "<<q.size()  << '\n';
    cout << "q.empty() -> "<<q.empty()  << "\n\n";
    q.push(10);
    cout << "q.front() -> "<<q.front()  << '\n';
    cout << "q.back() -> "<<q.back()  << '\n';
    cout << "q.size() -> "<<q.size()  << '\n';
    cout << "q.empty() -> "<<q.empty()  << "\n\n";
    q.push(15);
    cout << "q.front() -> "<<q.front()  << '\n';
    cout << "q.back() -> "<<q.back()  << '\n';
    cout << "q.size() -> "<<q.size()  << '\n';
    cout << "q.empty() -> "<<q.empty()  << "\n\n";
    q.pop();
    cout << "q.front() -> "<<q.front()  << '\n';
    cout << "q.back() -> "<<q.back()  << '\n';
    cout << "q.size() -> "<<q.size()  << '\n';
    cout << "q.empty() -> "<<q.empty()  << "\n\n\n";

    // queue implementation using array
    cout<<"queue implementation using array\n";
    Queue q2(1);
    q2.push(5);
    cout << "q2.Front() -> "<<q2.Front()  << '\n';
    cout << "q2.back() -> "<<q2.back()  << '\n';
    cout << "q2.size() -> "<<q2.size()  << '\n';
    cout << "q2.empty() -> "<<q2.empty()  << "\n\n";
    q2.push(10);
    cout << "q2.Front() -> "<<q2.Front()  << '\n';
    cout << "q2.back() -> "<<q2.back()  << '\n';
    cout << "q2.size() -> "<<q2.size()  << '\n';
    cout << "q2.empty() -> "<<q2.empty()  << "\n\n";
    q2.push(15);
    cout << "q2.Front() -> "<<q2.Front()  << '\n';
    cout << "q2.back() -> "<<q2.back()  << '\n';
    cout << "q2.size() -> "<<q2.size()  << '\n';
    cout << "q2.empty() -> "<<q2.empty()  << "\n\n";
    q2.pop();
    cout << "q2.Front() -> "<<q2.Front()  << '\n';
    cout << "q2.back() -> "<<q2.back()  << '\n';
    cout << "q2.size() -> "<<q2.size()  << '\n';
    cout << "q2.empty() -> "<<q2.empty()  << "\n\n";
    q2.pop();
    cout << "q2.Front() -> "<<q2.Front()  << '\n';
    cout << "q2.back() -> "<<q2.back()  << '\n';
    cout << "q2.size() -> "<<q2.size()  << '\n';
    cout << "q2.empty() -> "<<q2.empty()  << "\n\n";

    Queue q3;
    cout << "q3.Front() -> "<<q3.Front()  << '\n';
    cout << "q3.back() -> "<<q3.back()  << '\n';
    cout << "q3.size() -> "<<q3.size()  << '\n';
    cout << "q3.empty() -> "<<q3.empty()  << "\n\n\n";


    // queue implementation using linkedlist
    cout<<"queue implementation using linkedlist\n";
    Queue2 q4;
    q4.push(5);
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n";
    q4.push(10);
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n";
    q4.push(15);
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n";
    q4.pop();
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n";
    q4.pop();
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n";
    q4.pop();
    cout << "q4.Front() -> "<<q4.Front()  << '\n';
    cout << "q4.back() -> "<<q4.back()  << '\n';
    cout << "q4.size() -> "<<q4.size()  << '\n';
    cout << "q4.empty() -> "<<q4.empty()  << "\n\n\n";
   
    // circular queue implementation using array
    cout<<"circular queue implementation using array\n";
    Queue3 q5(3);
    q5.push(5);
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.push(10);
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.push(15);
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.pop();
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.push(20);
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.pop();
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.pop();
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.push(25);
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.pop();
    q5.pop();
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n";
    q5.pop();
    cout << "q5.Front() -> "<<q5.Front()  << '\n';
    cout << "q5.back() -> "<<q5.back()  << '\n';
    cout << "q5.size() -> "<<q5.size()  << '\n';
    cout << "q5.empty() -> "<<q5.empty()  << "\n\n\n";
   
    // doubly ended queue using STL
    deque<int>dq;
    dq.push_front(5);
    cout << "dq.Front() -> "<<dq.front()  << '\n';
    cout << "dq.back() -> "<<dq.back()  << '\n';
    cout << "dq.size() -> "<<dq.size()  << '\n';
    cout << "dq.empty() -> "<<dq.empty()  << "\n\n";
    dq.push_back(10);
    cout << "dq.Front() -> "<<dq.front()  << '\n';
    cout << "dq.back() -> "<<dq.back()  << '\n';
    cout << "dq.size() -> "<<dq.size()  << '\n';
    cout << "dq.empty() -> "<<dq.empty()  << "\n\n";
    dq.pop_back();
    cout << "dq.Front() -> "<<dq.front()  << '\n';
    cout << "dq.back() -> "<<dq.back()  << '\n';
    cout << "dq.size() -> "<<dq.size()  << '\n';
    cout << "dq.empty() -> "<<dq.empty()  << "\n\n\n";
    
    // doubly ended queue implementation using array
    cout<<"doubly ended queue implementation using array\n";
    Queue4 dq2(3);
    dq2.push_front(5);
    cout << "dq2.Front() -> "<<dq2.Front()  << '\n';
    cout << "dq2.back() -> "<<dq2.back()  << '\n';
    cout << "dq2.size() -> "<<dq2.size()  << '\n';
    cout << "dq2.empty() -> "<<dq2.empty()  << "\n\n";
    dq2.push_back(10);
    cout << "dq2.Front() -> "<<dq2.Front()  << '\n';
    cout << "dq2.back() -> "<<dq2.back()  << '\n';
    cout << "dq2.size() -> "<<dq2.size()  << '\n';
    cout << "dq2.empty() -> "<<dq2.empty()  << "\n\n";
    dq2.pop_back();
    cout << "dq2.Front() -> "<<dq2.Front()  << '\n';
    cout << "dq2.back() -> "<<dq2.back()  << '\n';
    cout << "dq2.size() -> "<<dq2.size()  << '\n';
    cout << "dq2.empty() -> "<<dq2.empty()  << "\n\n\n";
    

    // overflow condition
    // condition for 1st element
    // cyclic condition
    // l common conditions      else wala part




    return 0;
}