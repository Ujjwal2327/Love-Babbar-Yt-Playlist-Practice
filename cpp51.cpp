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

int add2LL(node*head1, node*head2){
    int value1=0;
    int value2=0;

    while(head1!=NULL){
        value1=value1*10+head1->data;
        head1=head1->next;
    }
    while(head2!=NULL){
        value2=value2*10+head2->data;
        head2=head2->next;
    }
    return value1+value2;
}

node* add2LL2(node*head1, node*head2){
    head1=reverse(head1);
    head2=reverse(head2);
    node*head=NULL;
    node*tail=NULL;
    int carry=0;
    int value=0;
    int digit=0;
    int value1 = 0;
    int value2 = 0;
    while(head1!=NULL || head2!=NULL || carry!=0){
        value1=0;
        if(head1!=NULL){
            value1 = head1->data;
        }
        value2=0;
        if(head2!=NULL){
            value2 = head2->data;
        }
        value = value1 + value2 + carry;
        carry=value/10;
        digit=value%10;
        insertAtTail(head, tail, digit);
        if(head1!=NULL)
            head1=head1->next;
        if(head2!=NULL)
            head2=head2->next;
    }

    head = reverse(head);
    return head;

}

int main(){

    node*head1=NULL;
    node*tail1=NULL;
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    print(head1);

    node*head2=NULL;
    node*tail2=NULL;
    insertAtTail(head2, tail2, 9);
    insertAtTail(head2, tail2, 9);
    insertAtTail(head2, tail2, 9);
    insertAtTail(head2, tail2, 9);
    print(head2);

    cout<<add2LL(head1, head2)<<"\n\n";

    node*ans=add2LL2(head1, head2);
    print(ans);

    return 0;
}