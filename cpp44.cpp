#include<iostream>
using namespace std;
 
class node0{
    public:
    int data;
    node0 * next=0;      //initially points to Null
};

class node{
    public:
    int data;
    node * next=0;      //initially points to Null

    // constructor
    node(int d){
        // this.data=d;     //will give ERROR
        this->data=d;
        // this->next=0;    //same as below line
        this->next=NULL;
    }
};

void insertAtHead(node * &head, int d){
    node * temp = new node(d);    //creating a new node
    temp->next = head;          //pointing its next to the first node and head store the address of first node
    head=temp;               //point head pointer to this node to make it a first node
}

void print(node * head){
    while(head !=0){
        cout<<(*head).data<<' ';
        head=head->next;
    }
    cout<<"\n\n";
}

void print2(node * &head){
    node* temp = head;
    while(temp !=0){
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout<<"\n\n";
}

/*
void insertAtTail(node* &head, int d){
    node* n1=new node(d);
    if(head==0){
        head=n1;
        return;
    }
    node *temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=n1;
}
*/

void insertAtTail2(node * &tail, int d){
    node*temp=new node(d);
    tail->next=temp;
    // tail=tail->next;     both this and below line is correct
    tail=temp;
}

/*
void insertAtPosition(node * &head, int pos, int d ){
    node*n1=new node(d);
    node *temp=head;
    node *temp2=0;

    if(pos == 1){
        n1->next=head;
        head=n1;
    }

    int i=pos-1;
    while(i--){
        temp2=temp;
        temp=temp->next;
    }
    n1->next=temp;
    temp2->next=n1;
}
*/

void insertAtPosition2(node * &head, node * &tail, int pos, int d ){
    node*n1=new node(d);
    node *temp=head;

    if(pos == 1){
        n1->next=head;
        head=n1;
        return;
    }

    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }

    // just to update tail pointer
    if(temp->next==NULL){
        insertAtTail2(tail,d);
        return;
    }

    n1->next=temp->next;
    temp->next=n1;
}

void deleteAtPosition(node* &head, node* &tail, int pos){
    node* temp=head;

    // deletion at beginning
    if(pos==1){
        head=temp->next;
        delete temp;
        return;
    }

    node* temp2=temp;
    for(int i=1; i<pos; i++){
        temp2=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        tail=temp2;
    }
    temp2->next=temp->next;
    delete temp;    //free its HEAP memory
    // temp=NULL;   //workable in my code without it too
}

void deleteByValue(node* &head, node* &tail, int value){
    node* temp=head;

    // if value is present at first node
    if(temp->data==value){
        head=head->next;
        delete temp;
        return;
    }

    node* temp2=temp;
    while(temp->data!=value){
        temp2=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        tail=temp2;
    }
    temp2->next=temp->next;
    delete temp;

}

int main(){

    /*
    linked list ll
    non continuous  non contiguous
    store a same particular type of data
    linear ds which is made of collection of nodes
    node is a combination of data and &nextnode

    ll is dynamic (can be grow and shrink at run time)
    vector is also dynamic but in vector you make a whole new storage of double size and copy all the elements in it, but in ll, there is no memory wastage

    insertion and deletion is easy as compared to array as it does not include any shifting
    no need of continuous storage

    types of linked list
        singly ll
        doubly ll
        circular ll
        circular doubly ll

    Node-
    | data | pointer |
    | node data | & next node |
    */

    // making a node
    node0 * n0=new node0;
    cout<<"n0->data "<<n0->data<<'\n';      //gv
    cout<<"n0->next "<<n0->next<<'\n';      //0 as null pointer
    cout<<'\n';
    
    node * n=new node(10);
    cout<<"n->data "<<n->data<<'\n';      //gv
    cout<<"n->next "<<n->next<<'\n';      //0 as null pointer
    cout<<'\n';

    /*
    singly ll-
           _ _    _ _    _ _
    head->|_|_|->|_|_|->|_|_|->NULL (null pointer)

    head points to the address of first node in a linked list

    */

    node* n1= new node(10);
    cout<<"n->data "<<n->data<<'\n';
    cout<<"n->next "<<n->next<<'\n';
    node*head1 = n1;        //n1 is not a node, its a pointer so node*head1 = &n1 is wrong
    cout<<'\n';
    
    // insertion
    cout<<"INSERTION\n";
    cout<<"ll2\n";
    cout<<"print2\n";       // traverse in a linked list
    print2(head1);
    insertAtHead(head1,20);
    print2(head1);
    insertAtHead(head1,30);
    print2(head1);

    node*head2=0;
    insertAtHead(head2,10);
    cout<<"ll2\n";
    print2(head2);
    insertAtHead(head2,30);
    print2(head2);
    insertAtHead(head2,50);
    print2(head2);

    cout<<"ll1 is ";
    print2(head1);
    cout<<"ll2 is ";
    print2(head2);

    cout<<"ll3\n";
    node*n3=new node(10);
    node* head3=n3;
    // node* head3=0;
    print2(head3);
    insertAtTail2(head3, 10);
    print2(head3);
    insertAtTail2(head3, 20);
    print2(head3);
    insertAtTail2(head3, 30);
    print2(head3);

    cout<<"ll3 is ";
    print2(head3);

    node*n4=new node(10);
    node*head4=n4;
    node*tail4=n4;
    print2(head4);
    insertAtTail2(tail4, 20);
    print2(head4);
    insertAtTail2(tail4, 30);
    print2(head4);

    cout<<"ll4 is ";
    print2(head4);

    insertAtPosition2(head4, tail4, 3, 100);
    print2(head4);
    insertAtPosition2(head4, tail4, 1, 200);
    print2(head4);
    insertAtPosition2(head4, tail4, 6, 300);
    print2(head4);
    insertAtPosition2(head4, tail4, 3, 400);
    print2(head4);

    cout<<"ll4 is ";
    print2(head4);

    cout<<"head ->"<<head4->data<<'\n';
    cout<<"tail ->"<<tail4->data<<'\n';
    cout<<'\n';


    // deletion
    cout<<"DELETION\n";
    print2(head4);
    cout<<"deleteAtPosition\n";
    deleteAtPosition(head4, tail4, 1);
    print2(head4);
    deleteAtPosition(head4, tail4, 3);
    print2(head4);
    deleteAtPosition(head4, tail4, 5);
    print2(head4);
    // deleteAtPosition(head4, tail4, 5);   //it will stop the execution
    // print2(head4);

    cout<<"head ->"<<head4->data<<'\n';
    cout<<"tail ->"<<tail4->data<<'\n';
    cout<<'\n';

    cout<<"deleteByValue\n";
    deleteByValue(head4, tail4, 30);
    print2(head4);
    deleteByValue(head4, tail4, 400);
    print2(head4);
    deleteByValue(head4, tail4, 10);
    print2(head4);

    cout<<"head ->"<<head4->data<<'\n';
    cout<<"tail ->"<<tail4->data<<'\n';
    cout<<'\n';

    return 0;
}