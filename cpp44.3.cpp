#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;

    // constructor
    node(int d){
        this->data=d;
    }
};

void insertAfterValue(node *&tail, int value, int d){
    node*n1=new node(d);
    if(tail==NULL){
        tail=n1;
        tail->next=tail;
        return;
    }

    node*temp=tail;
    int cnt=0;
    while(temp->data!=value){
        temp=temp->next;
        if(temp==tail){
            cnt++;
        }
        if(cnt>1){
            return;
        }
    }

    n1->next=temp->next;
    temp->next = n1;
    if(temp==tail){
        tail=n1;
        return;
    }
}

void print(node*tail){
    if(tail==NULL){
        cout<<"empty list\n";
        return;
    }

    node*temp=tail->next;
    do{
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    while(temp!=tail->next);
    cout<<"\n\n";
}

int getLength(node*&tail){
    if(tail==NULL){
        return 0;
    }

    node*temp=tail;
    int len=1;
    while(temp->next!=tail){
        len++;
        temp=temp->next;
    }
    return len;
}

void deleteAtPosition(node*&tail, int pos){
    if(tail==NULL){
        cout<<"empty list\n";
        return;
    }

    if(getLength(tail)==1){
    // if(temp==temp2){     both work same      define both above them
        delete tail;
        tail=NULL;
        return;
    }

    node *temp=tail->next;
    node *temp2=tail;

    for(int i=1; i<pos; i++){
        temp2=temp;
        temp=temp->next;
    }

    if(temp==tail){
        tail=temp2;
    }

    temp2->next=temp->next;
    temp->next=NULL;
    delete temp;
}

int main(){
    /*  
    circular ll
       _ _    _ _    _ _
    ->|_|_|->|_|_|->|_|_|--
    |                     |
    -----------<-----------

    no need of head pointer, we can access all nodes just by tail pointer as tail->next and head points to same node

    head and tail are not logical in circular ll but we take it just to make it easy to understand and for reference

    circular doubly ll
         _ _ _       _ _ _       _ _ _
     => |_|_|_| <=> |_|_|_| <=> |_|_|_| <=
    ||                                   ||
      ====================================

    */

    node*n1=new node(10);
    n1->next=n1;
    node* tail=n1;
    cout<<"cll1->\n";
    print(tail);
    insertAfterValue(tail, 10, 20);
    print(tail);
    insertAfterValue(tail, 10, 30);
    print(tail);
    insertAfterValue(tail, 20, 40);
    print(tail);
    cout<< "tail is " <<tail->data<<"\n";
    cout<< "head is " <<tail->next->data<<"\n";
    cout<<"length of cll2 is "<<getLength(tail)<<"\n\n";

    node*tail2='\0';
    cout<<"cll2->\n";
    insertAfterValue(tail2, 10, 10);
    print(tail2);
    insertAfterValue(tail2, 10, 30);
    print(tail2);
    insertAfterValue(tail2, 20, 40);        //20 is not present
    print(tail2);
    cout<< "tail2 is " <<tail2->data<<"\n";
    cout<<"length of cll2 is "<<getLength(tail2)<<"\n\n";


    cout<<"cll1->\n";
    print(tail);
    deleteAtPosition(tail, 1);
    cout<<"cll1->\n";
    print(tail);
    deleteAtPosition(tail, 2);
    print(tail);
    deleteAtPosition(tail, 2);
    print(tail);
    cout<<"tail is " << tail->data<<'\n';












    return 0;
}