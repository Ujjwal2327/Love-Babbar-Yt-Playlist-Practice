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
        cout<<head->data<<' ';
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

int getLength(node*head){
    int len=0;

    node*curr=head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    return len;
}

bool isVectorPallindrome(vector<int>v, int n){
    for(int i=0, j=n-1; i<j; i++, j--){
        if(v[i]!=v[j]){
            cout<<"not a pallindrome\n\n";
            return false;
        }
    }
    cout<<"pallindrome\n\n";
    return true;
}

bool isPallindrome(node*head){
    if(head==NULL){
        return 1;
    }
    int len=getLength(head);
    // vector<int, len>v;       //why it gives ERROR
    vector<int>v;

    node*curr=head;
    while(curr!=NULL){
        v.push_back(curr->data);
        curr=curr->next;
    }
    return isVectorPallindrome(v,len);
}

node* reverse(node*head){
    if(head==NULL){
        return head;
    }
    node*curr=head;
    node*currprev=NULL;
    while(curr!=NULL){
        node* currnext=curr->next;
        curr->next=currprev;
        currprev=curr;
        curr=currnext;
    }
    return currprev;
}

bool isPallindrome2(node*head){
    node*reverseHead= reverse(head);
    node*temp1=head;
    node*temp2=reverseHead;
    while(temp1!=NULL){
        if(temp1->data!=temp2->data){
            cout<<"not a pallindrome\n\n";
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"pallindrome\n\n";
    return true;
}

int getMid(node *head){
    // can also be done using getLength function
    if(head==NULL)
        return 0;
    
    node*fast=head;
    int i=1;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            i++;
        }
    }
    return i;
}

node* getMid2(node *head){
    // can also be done using getLength function
    if(head==NULL)
        return 0;
    
    node*fast=head;
    node*slow=head;

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
    }
    return slow;
}

bool isPallindrome3(node*head){
    if(head==NULL || head->next==NULL){
        cout<<"pallindrome\n\n";
        return true;
    }
    
    node*mid = getMid2(head);
    node*curr=head;
    while(curr->next!=mid){
        curr=curr->next;
    }

    node*temp2=reverse(mid);
    curr->next=temp2;
    mid=curr->next;     //why mid is changing?
    node*temp1=head;
    while(temp1!=mid){
        if(temp1->data!=temp2->data){
            cout<<"not a pallindrome\n\n";
            temp2=reverse(mid);
            curr->next=temp2;
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"pallindrome\n\n";
    temp2=reverse(mid);
    curr->next=temp2;
    return true;
}

int main(){

    node*head=NULL;
    node*tail=NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 10);
    print(head);

    isPallindrome(head);
    // isPallindrome2(head);    //change the ll
    isPallindrome3(head);
    print(head);

    return 0;
}