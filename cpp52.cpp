#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next=NULL;

    node(int d){
        this->data=d;
    }
};

void print(node*head){
    if(head==NULL){
        return;
    }

    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
    cout<<"\n\n";
}

void insertAtTail(node*&head, node*&tail, int d){
    node*n1= new node(d);
    if(head==NULL){
        head=n1;
        tail=n1;
        return;
    }

    node*curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=n1;
    tail=n1;
}

node*reverse(node*head){
    if(head==NULL){
        return head;
    }

    node*curr=head;
    node*currprev=NULL;
    node*currnext=NULL;

    while(curr!=NULL){
        currnext=curr->next;
        curr->next=currprev;
        currprev=curr;
        curr=currnext;
    }
    return currprev;
}

node* cloneALL(node*head){
    node*head1=NULL;
    node*head2=NULL;
}

int main(){

    node*head1=NULL;
    node*tail1=NULL;
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    print(head1);

    node*head2=NULL;
    node*tail2=NULL;
    cout<<add2LL(head1, head2)<<"\n\n";



    return 0;
}