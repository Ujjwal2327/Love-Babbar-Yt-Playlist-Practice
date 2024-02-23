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

bool detectLoop1(node* head){
    if(head==NULL){
        return false;
    }

    map<node*, bool>visited; 
    node* temp=head;
    // at starting, values of all key are 0(int) or false/0(bool)
    while(temp->next!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

node* startLoopNode1(node*head){
    if(head==NULL){
        return NULL;
    }

    map<node*, bool>visited; 
    node* temp=head;
    while(temp->next!=NULL){
        if(visited[temp]==true){
            return temp;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    
    return NULL;
}

void deleteLoop1(node*head){
    if(head==NULL){
        return;
    }

    if(detectLoop1(head)){
        node*startNode=startLoopNode1(head);
        node*temp=startNode;
        while(temp->next!=startNode){
            temp=temp->next;
        }
        temp->next=NULL;
    }

}

bool detectLoop2(node*head){
    if(head==NULL){
        return false;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

node* detectLoop2_2(node*head){
    if(head==NULL){
        return NULL;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return fast;
        }
    }
    return NULL;
}

node* startLoopNode2(node*head){
    if(detectLoop2){
        node*temp=detectLoop2_2(head);
        node*temp2=head;
        while(temp!=temp2){
            temp=temp->next;
            temp2=temp2->next;
        }
        return temp;
    }
    return NULL;
}

void deleteLoop2(node*head){
    if(head==NULL){
        return;
    }

    if(detectLoop2){
        node*startNode=startLoopNode2(head);
        node*temp=startNode;
        while(temp->next!=startNode){
            temp=temp->next;
        }
        temp->next=NULL;
    }

}


int main(){

    node*head=NULL;
    node*tail=NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    tail->next=head->next->next;
    // print(head);

    // Method 1     Using Map

    // if(detectLoop1(head)){
    //     cout<<"loop is present\n";
    // }
    // else{
    //     cout<<"loop is absent\n";
    // }

    // node*startingNode1 = startLoopNode1(head);
    // if(startingNode1 == NULL){
    //     cout<<"loop is absent\n";
    // }
    // else{
    //     cout<<"loop is present at "<<startingNode1->data<<"\n";
    // }

    // deleteLoop1(head);
    // if(detectLoop1(head)){
    //     cout<<"loop is present\n";
    // }
    // else{
    //     cout<<"loop is absent\n";
    // }


    // Method 2     Using Floyd's Cycle Detection Algorithm
    
    if(detectLoop1(head)){
        cout<<"loop is present\n";
    }
    else{
        cout<<"loop is absent\n";
    }

    node*startingNode2 = startLoopNode2(head);
    if(startingNode2 == NULL){
        cout<<"loop is absent\n";
    }
    else{
        cout<<"loop is present at "<<startingNode2->data<<"\n";
    }

    deleteLoop2(head);
    if(detectLoop2(head)){
        cout<<"loop is present\n";
    }
    else{
        cout<<"loop is absent\n";
    }

    return 0;
}