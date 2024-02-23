#include<iostream>
using namespace std;

class node{
    public:
    node*prev=NULL;
    int data;
    node*next=NULL;

    // constructor
    node(int d){
        this->data=d;
    }
};

print(node* &head){
    node* temp=head;
    // while(temp!=NULL){       //both work same
    while(temp!=0){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<"\n\n";
}

int getLength(node* &head){
    node*temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

node* getTail(node* &head){
    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    return tail;
}

void insertAtHead(node* & head, int d){     //&a, & a are same in case of reference operator
    node*n1=new node(d);

    if(head==NULL){
        head=n1;
        return;
    }

    head->prev=n1;
    n1->next=head;
    head=n1;
}

void insertAtTail(node* &tail, int d){
    node*temp=new node(d);
    if(tail==NULL){
        tail=temp;
        return;
    }

    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(node* &head, node* &tail, int pos, int d){
    node*n1=new node(d);
    node* temp=head;
    if(pos==1){
        insertAtHead(head, d);
        return;
    }

    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    n1->next=temp->next;
    (temp->next)->prev=n1;      //temp->next->prev and (temp->next)->prev are same
    temp->next=n1;
    n1->prev=temp;

}

void deleteAtPosition(node* &head, node * & tail, int pos){     //will not work if the length of ll is 1
    node* temp=head;
    if(pos==1){
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        tail=temp->prev;
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;

}

void deleteByValue(node* &head, node * & tail, int value){     //will not work if the length of ll is 1
    node* temp=head;
    if(value==head->data){
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    while(temp->data!=value){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"value not found\n";
        return;
    }
    if(temp->next==NULL){
        tail=temp->prev;
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;

}

int main(){
    /*
    doubly linked list
             _ _ _       _ _ _       _ _ _
    NULL <- |_|_|_| <=> |_|_|_| <=> |_|_|_| ->NULL

    | previous pointer | data | next pointer |
    previous pointer-> storing the address of previous node
    data-> stores the particular type of data
    next pointer-> storing the address of next node
    */

    node* n1=new node(10);
    node* head1= n1;
    node*tail1=n1;
    cout<<"ll1 is ";
    print(head1);
    cout<<"length of ll1 is "<<getLength(head1)<<"\n\n";
    
    cout<<"INSERTION\n";
    cout<<"ll1->\n";
    insertAtHead(head1, 20);
    print(head1);
    insertAtHead(head1, 30);
    print(head1);
    insertAtHead(head1, 40);
    print(head1);
    cout<<"head is "<<head1->data<<'\n';
    cout<<"tail is "<<tail1->data<<"\n\n";


    insertAtTail(tail1, 50);
    print(head1);
    insertAtTail(tail1, 60);
    print(head1);
    insertAtTail(tail1, 70);
    print(head1);
    cout<<"head is "<<head1->data<<'\n';
    cout<<"tail is "<<tail1->data<<"\n\n";

    node* tail1_2=getTail(head1);
    cout<<"tail (by function) is "<<tail1_2->data<<"\n\n";

    insertAtPosition(head1, tail1, 3, 80);
    print(head1);
    insertAtPosition(head1, tail1, 1, 90);
    print(head1);
    insertAtPosition(head1, tail1, 10, 100);
    print(head1);
    cout<<"head is "<<head1->data<<'\n';
    cout<<"tail is "<<tail1->data<<"\n";
    cout<<"length of ll1 is "<<getLength(head1)<<"\n\n";


    cout<<"ll2 is ";
    node* head2=NULL;
    node* tail2=NULL;
    insertAtHead(head2,20);
    print(head2);
    tail2=getTail(head2);
    cout<<"head is "<<head2->data<<'\n';
    cout<<"tail is "<<tail2->data<<"\n\n";
    cout<<"length of ll2 is "<<getLength(head2)<<"\n\n";


    cout<<"ll3 is ";
    node* head3=NULL;
    node* tail3=NULL;
    insertAtTail(tail3,30);
    head3=tail3;
    print(head3);
    cout<<"head is "<<head3->data<<'\n';
    cout<<"tail is "<<tail3->data<<'\n';
    cout<<"length of ll3 is "<<getLength(head3)<<"\n\n";



    cout<<"DELETION\n";
    cout<<"ll1 is ";
    print(head1);
    cout<<"deleteAtPosition\n";
    deleteAtPosition(head1, tail1, 3);
    print(head1);
    deleteAtPosition(head1, tail1, 1);
    print(head1);
    deleteAtPosition(head1, tail1, 8);
    print(head1);
    cout<<"head is "<<head1->data<<'\n';
    cout<<"tail is "<<tail1->data<<"\n";
    cout<<"length of ll1 is "<<getLength(head1)<<"\n\n";

    cout<<"deleteByValue\n";
    deleteByValue(head1, tail1, 10);
    print(head1);
    deleteByValue(head1, tail1, 70);
    print(head1);
    deleteByValue(head1, tail1, 40);
    print(head1);
    // deleteByValue(head1, tail1, 100);
    // print(head1);
    cout<<"head is "<<head1->data<<'\n';
    cout<<"tail is "<<tail1->data<<"\n";
    cout<<"length of ll1 is "<<getLength(head1)<<"\n\n";

    return 0;
}