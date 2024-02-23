#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        next=NULL;
    }
};

void print(node * &head){
    node* temp = head;
    while(temp !=0){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout<<"\n\n";
}

void insertAtTail(node * &tail, int d){
    node*temp=new node(d);
    tail->next=temp;
    // tail=tail->next;     both this and below line is correct
    tail=temp;
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

// void kreverse(node* &head, int k){

// //     node*afterhead=head;
// //     node*temp2=head;
// //     int i=k-1;
// //     while(i--){
// //         afterhead=afterhead->next;
// //     }
// //     node*currhead=head;
// //     node*prevtail=0;
// //     node* currtail=currhead;

// //     while(getLength(currhead)>k){

// //         // getting current tail
// //         i=k-1;
// //         currtail=currhead;
// //         while(i--){
// //             currtail = currtail->next;
// //         }

// //         node*tempprev=currhead;
// //         node*temp=currhead;
// //         node*tempnext=temp->next;
// //         temp->next=prevtail;
// //         temp->next=prevtail;
// //         i=k-1;
// //         while(i--){
// //             temp=tempnext;
// //             prevtail=temp;
// //             tempnext=temp->next;
// //             // currhead=tempnext;
// //             temp->next=tempprev;
// //             tempprev=temp;
// //         }
// //         temp2=tempnext;
// //         i=k-1;
// //         if(getLength(temp2)>k){
// //             while(i--){
// //                 temp2=temp2->next;
// //             }
// //         }
// //         else{
// //             while(temp->next!=NULL){
// //                 temp2=temp2->next;
// //             }
// //         }
// //         currhead->next=temp2;
// //         currhead=tempnext;
// //     }

// //     int leftlen=getLength(currhead);
// //     // getting current tail
// //     currtail=currhead;
// //     while(currtail->next!=NULL){
// //         currtail = currtail->next;
// //     }

// //     node* tempprev=currhead;
// //     node* temp=currhead;
// //     node* tempnext=temp->next;
// //     temp->next=prevtail;
// //     i=leftlen-1;
// //     while(i--){
// //         temp=tempnext;
// //         prevtail=temp;
// //         tempnext=temp->next;
// //         // currhead=tempnext;
// //         temp->next=tempprev;
// //         tempprev=temp;
// //     }
// //     currhead->next=tempnext;
// //     cout<<"value is "<<head->data<<'\n';
// //     head=afterhead;
// // }

void kreverse(node*&head, int k, node*curr, node*currListPrev, node*currListNext){
    node*currPrev=currListPrev;
    node*currNext=curr->next;
    currPrev->next=curr;
    currPrev=curr;
    curr=currNext;
    currNext=curr->next;
    while(curr->next=currListNext){
        // cout<<curr->data<<' ';
        curr->next=currPrev;
        currPrev=curr;
        curr=currNext;
        currNext=curr->next;
    }
    curr->next=currPrev;
    currPrev=curr;
    curr=currNext;
    if(currListNext==NULL){
        return;
    }
    currListPrev=currPrev;

    for(int i=0; i<k; i++){
        if(currListNext!=NULL){
            currListNext=currListNext->next;
        }
    }

    kreverse(head, k, curr, currListPrev, currListNext);
}

int main(){

    node*n1=new node(10);
    node*head1=n1;
    node*tail1=n1;
    insertAtTail(tail1, 20);
    insertAtTail(tail1, 30);
    insertAtTail(tail1, 40);
    // insertAtTail(tail1, 50);
    print(head1);
    
    cout << "head->data is " << head1->data << '\n';
    cout << "tail->data is " << tail1->data << "\n\n";

    // kreverse(head1, 3);
    // print(head1);
    int k;
    cin>>k;
    node*currListNext=head1;
    for(int i=0; i<k; i++){
        currListNext=currListNext->next;
    }
    cout<<"currListNext is "<<currListNext->data<<'\n';
    kreverse(head1, k, head1, head1, currListNext);
    print(head1);


    return 0;
}