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

void removeDuplicatesFromSortedLL(node*head){
    if(head==NULL){
        return;
    }

    node*curr=head->next;
    node*currprev=head;
    while(curr!=NULL){
        if(curr->data==currprev->data){
            currprev->next=curr->next;
            curr=currprev->next;
        }
        else{
            currprev=curr;
            curr=curr->next;
        }
    }
}

void removeDuplicatesFromSortedLL2(node*head){
    if(head==NULL){
        return;
    }

    node*curr=head->next;
    while(curr->next!=NULL){
        if(curr->next->data!=curr->data){
            curr=curr->next;
        }
        else{
            node*nodeToDelete=curr->next;
            node*currnextnext=curr->next->next;
            delete nodeToDelete;
            // delete curr->next;   // are both ablove and this line are same?
            curr->next=currnextnext;
        }
    }
}

void removeDuplicates(node*head){   //can be unsorted
    if(head==NULL){
        return;
    }

    map<int, bool>visited;
    node*curr=head;
    node*currprev=head;
    while(curr!=NULL){
        if(visited[curr->data]==false){
            visited[curr->data]=true;
            currprev=curr;
            curr=curr->next;
        }
        else{
            currprev->next=curr->next;
            delete curr;
            curr=currprev->next;
        }
    }
}

void removeDuplicates2(node*head){   //can be unsorted
    if(head==NULL){
        return;
    }
    node*curr=head;
    while(curr!=NULL){
        node*temp=curr;
        while(temp->next!=NULL){
            if(temp->next->data==curr->data){
                node*nodeToDelete=temp->next;
                temp->next=temp->next->next;
                delete nodeToDelete;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
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

node* startLoopNode(node*head){
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

void deleteLoop(node*head){
    if(head==NULL){
        return;
    }

    if(detectLoop1(head)){
        node*startNode=startLoopNode(head);
        node*temp=startNode;
        while(temp->next!=startNode){
            temp=temp->next;
        }
        temp->next=NULL;
    }

}

pair<node*, node*> splitCLL(node*head){
    deleteLoop(head);
    int len=getLength(head);
    cout<<"len is "<<len<<'\n';
    int first, second;
    if(len&1)
        first=len/2+1;
    else
        first=len/2;
    second=len/2;

    node*currhead1=NULL;
    node*currhead2=NULL;
    node*currtail1=NULL;
    node*currtail2=NULL;
    node*temp1=head;

    while(first--){
        insertAtTail(currhead1, currtail1, temp1->data);
        temp1=temp1->next;
    }

    while(second--){
        insertAtTail(currhead2, currtail2, temp1->data);
        temp1=temp1->next;
    }
    pair<node*, node*>halves;
    halves.first=currhead1;
    halves.second=currhead2;

    return halves;
}

int main(){

    node*head=NULL;
    node*tail=NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    cout<<"ll->\n";
    print(head);
    cout<<"removeDuplicatesFromSortedLL\n";
    removeDuplicatesFromSortedLL(head);
    print(head);

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 40);
    cout<<"ll->\n";
    print(head);
    cout<<"removeDuplicatesFromSortedLL2\n";
    removeDuplicatesFromSortedLL2(head);
    print(head);

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 10);
    cout<<"ll->\n";
    print(head);
    cout<<"removeDuplicates\n";
    removeDuplicates(head);
    print(head);
    
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 5);
    cout<<"ll->\n";
    print(head);
    cout<<"removeDuplicates2\n";
    removeDuplicates2(head);
    print(head);

    head->next->next->next->next->next=head->next;
    // 10->20->30->40->20->30->40 and so on
    pair<node*, node*>ans = splitCLL(head);
    print(ans.first);
    print(ans.second);

    return 0;
}