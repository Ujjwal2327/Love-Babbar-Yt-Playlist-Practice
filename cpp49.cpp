#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;

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
    node*n1=new node(d);
    if(head==NULL){
        head=n1;
        tail=n1;
        return;
    }

    tail->next=n1;
    tail=n1;
}

void insertAtTail2(node*&tail, node*&newtail){
    tail->next=newtail;
    tail=newtail;
}

// Method 1     By replacing data
void sort012sM1(node*&head){
    int cnt[3]={0};
    node*temp=head;
    while(temp!=NULL){
        cnt[temp->data]++;
        temp=temp->next;
    }

    temp=head;
    while(cnt[0]--){
        temp->data=0;
        temp=temp->next;
    }
    while(cnt[1]--){
        temp->data=1;
        temp=temp->next;
    }
    while(cnt[2]--){
        temp->data=2;
        temp=temp->next;
    }
}

// Method 2     By not replacing data, but replacing links
void sort012sM2(node*&head){
    node*head0=new node(-1);
    node*head1=new node(-1);
    node*head2=new node(-1);
    node*tail0=head0;
    node*tail1=head1;
    node*tail2=head2;

    node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            insertAtTail2(tail0, temp);
        }
        else if(temp->data==1){
            insertAtTail2(tail1, temp);
        }
        else{
            insertAtTail2(tail2, temp);
        }
        temp=temp->next;
    }

    if(head1->next!=NULL){
        tail0->next=head1->next;
        tail1->next=head2->next;
    }
    else{
        tail0->next=head2->next;
    }
    tail2->next=NULL;

    head=head0->next;

    delete head0;
    delete head1;
    delete head2;
}

node* merge2SortedLL(node*head1, node*head2){
    node*temp1=head1;
    node*temp2=head2;
    node*n1=new node(INT_MIN);
    node*head=n1;
    node*tail=n1;
    while(temp1!=NULL && temp2!=NULL){
        int value1=temp1->data;
        int value2=temp2->data;
        if(value1<value2){
            insertAtTail2(tail, temp1);
            temp1=temp1->next;
        }
        else{
            insertAtTail2(tail, temp2);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        insertAtTail2(tail, temp1);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insertAtTail2(tail, temp2);
        temp2=temp2->next;
    }
    head=head->next;
    delete n1;
    return head;
}

node* merge2SortedLL2(node*head1, node*head2){
    node*temp1prev=head1;
    node*temp1=head1->next;
    node*temp2=head2;
    node*temp2next=head2->next;

    while(temp1!=NULL && temp2!=NULL){
        temp2next=temp2->next;
        int currValue=temp2->data;
        int smallValue=temp1prev->data;
        int bigValue=temp1->data;
        if(currValue>=smallValue && currValue<=bigValue){
            temp1prev->next=temp2;
            temp2->next=temp1;
            temp1prev=temp1prev->next;
            temp2=temp2next;
        }
        // if(currValue<smallValue)     //for this condition we apply condition in main function at line no. 246
        else{
            temp1prev=temp1prev->next;
            temp1=temp1->next;
        }
    }
    if(temp2!=NULL){        //also valid if head1->next==NULL   one node in ll1
        temp1prev->next=temp2;
    }
    return head1;
}

int main(){

    cout<<"ll1-> ";
    node*n1=new node(1);
    node*head1=n1;
    node*tail1=n1;
    insertAtTail(head1, tail1, 0);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 0);
    print(head1);
    sort012sM1(head1);
    print(head1);
    
    cout<<"ll2-> ";
    node*n2=new node(1);
    node*head2=n2;
    node*tail2=n2;
    insertAtTail(head2, tail2, 0);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 0);
    print(head2);
    sort012sM2(head2);
    print(head2);


    node*n3=new node(2);
    node*head3=n3;
    node*tail3=n3;
    insertAtTail(head3, tail3, 4);
    insertAtTail(head3, tail3, 6);
    insertAtTail(head3, tail3, 8);
    
    node*n4=new node(0);
    node*head4=n4;
    node*tail4=n4;
    insertAtTail(head4, tail4, 1);
    insertAtTail(head4, tail4, 3);
    insertAtTail(head4, tail4, 5);
    insertAtTail(head4, tail4, 7);

    cout<<"ll3-> ";
    print(head3);
    cout<<"ll4-> ";
    print(head4);
    node*mergeHead = merge2SortedLL(head3, head4);
    cout<<"merge sorted ll-> ";
    print(mergeHead);
    cout<<"ll3-> ";
    print(head3);
    cout<<"ll4-> ";
    print(head4);


    node*n5=new node(2);
    node*head5=n5;
    node*tail5=n5;
    insertAtTail(head5, tail5, 4);
    insertAtTail(head5, tail5, 6);
    insertAtTail(head5, tail5, 8);
    
    node*n6=new node(0);
    node*head6=n6;
    node*tail6=n6;
    insertAtTail(head6, tail6, 1);
    insertAtTail(head6, tail6, 3);
    insertAtTail(head6, tail6, 5);
    insertAtTail(head6, tail6, 7);

    cout<<"ll5-> ";
    print(head5);
    cout<<"ll6-> ";
    print(head6);

    node*mergeHead2 = NULL;
    // requirement-> none of these ll should be NULL
        // if one is NULL, the the other ll is the required ans
    if(head5->data > head6->data){
        mergeHead2 = merge2SortedLL2(head6, head5);
    }
    else{
        mergeHead2 = merge2SortedLL2(head5, head6);
    }
    cout<<"merge sorted ll2-> ";
    print(mergeHead2);

    return 0;

}