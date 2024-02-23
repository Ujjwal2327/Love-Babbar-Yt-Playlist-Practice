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

void insertAtHead(node * &head, int d){
    node * temp = new node(d);
    temp->next = head;
    head=temp;
}

void print(node * &head){
    node* temp = head;
    while(temp !=0){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout<<"\n\n";
}

void insertAtTail(node* &head, node*&tail, int d){
    node* n1=new node(d);
    if(head==0){
        head=n1;
        tail=n1;
        return;
    }
    node *temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=n1;
    tail=n1;
}

void reverse(node* &head, node*&tail){
    node* curr = head;
    node* currNext = curr->next;
    curr->next = NULL;
    tail=curr;
    while(currNext!=0){
    // while(currNext!='\0'){   // both, this and above lines are same
        node*currPrev=curr;
        curr=currNext;
        currNext=curr->next;
        curr->next = currPrev;
    }
    head=curr;
}

void reverse2(node* &head, node* curr, node*currPrev){
    if(head==NULL){
        return;
    }
    
    if(curr->next==NULL){
        curr->next = currPrev;
        head=curr;
        return;
    }

    node* currNext = curr->next;
    curr->next = currPrev;
    currPrev=curr;
    curr=currNext;
    reverse2(head, curr, currPrev);
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

node* reverse3(node* head, node* tail, node* curr, node*temp, node* tempnexthead){

    if(head==tail){
        return curr;
    }

    if(curr==tail){
        node*nexthead=curr;
        curr->next = temp;
        head=curr;
        return nexthead;
    }

    // cout<<curr->data<<' ';
    node* currNext = curr->next;
    if(curr==head){
        temp=curr;
        curr->next = tempnexthead;
    }
    else{
        currNext=curr->next;
        curr->next = temp;
        temp=curr;
    }
    curr=currNext;
    return reverse3(head, tail, curr, temp, tempnexthead);

}

void reverse4(node*&head, node *curr){
    if(curr==NULL){
        return;
    }
    if(curr->next==NULL){
        head=curr;
        return;
    }

    reverse4(head, curr->next);
    curr->next->next=curr;
    curr->next=NULL;
}

void kreverse( node* krtemptail, node* krhead, int k){
    krtemptail=krhead;
    node* krtempnexthead=0;
    if(getLength(krhead)>k){
        int i=k-1;
        while(i--){
            krtemptail = krtemptail->next;
        }
        krtempnexthead = reverse3(krhead, krtemptail, krhead, krhead, krtempnexthead);

    }
    else{
        krtemptail = getTail(krhead);
        krtempnexthead = reverse3(krhead, krtemptail, krhead, krhead, krtempnexthead);
        return;
    }
    krhead=krtemptail->next;
    kreverse(krtemptail, krhead, k);

}

node* getPrev(node* head, node* tail){
    node*temp = head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    return temp;
}

int getMid(node * head, node* tail){
    if(head==NULL){
        return INT_MIN;
    }

    if(head==tail){
        return tail->data;
    }
    while(head!=tail){
        if(head->next==tail){
            return tail->data;
        }

        head=head->next;
        tail=getPrev(head, tail);
    }
    return tail->data;
}

int getMid2(node * head){
    if(head==NULL){
        return INT_MIN;
    }

    int i=1;
    node*temp=head;
    while(head!=NULL){
        i++;
        head=head->next;
        if(i&1){
            temp=temp->next;
        }
    }
    return temp->data;
}

int getMid3(node * head){
    if(head==NULL){
        return INT_MIN;
    }

    int len = getLength(head);
    int i = len/2;
    while(i--){
        head=head->next;
    }
    return head->data;
    
}

int getMid4(node * head){
    if(head==NULL){
        return INT_MIN;
    }

    node*temp=head;
    while(head->next!=NULL){
        head=head->next;
        if(head->next!=NULL){
            head=head->next;
        }
        temp=temp->next;
    }
    return temp->data;
}

int main(){

    node*n1=new node(10);
    node*head1=n1;
    node*tail1=n1;
    insertAtTail(head1, tail1, 20);
    insertAtTail(head1, tail1, 30);
    insertAtTail(head1, tail1, 40);
    insertAtTail(head1, tail1, 50);
    print(head1);

    reverse(head1, tail1);
    print(head1);

    reverse2(head1, head1, NULL);
    print(head1);

    reverse4(head1, head1);
    print(head1);

    // kreverse(head1, head1, 2);
    // print(head1);

    cout << "mid is " << getMid(head1, tail1) << '\n';
    cout << "mid2 is " << getMid2(head1) << '\n';
    cout << "mid3 is " << getMid3(head1) << "\n";
    cout << "mid4 is " << getMid4(head1) << "\n\n";

    insertAtTail(head1, tail1, 60);
    cout << "mid is " << getMid(head1, tail1) << '\n';
    cout << "mid2 is " << getMid2(head1) << '\n';
    cout << "mid3 is " << getMid3(head1) << "\n";
    cout << "mid4 is " << getMid4(head1) << "\n\n";




    /*
    HOMEWORK
    reverse a doubly linked list
    */

    return 0;
}