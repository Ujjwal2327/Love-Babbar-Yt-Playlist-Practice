#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left=NULL;
    node*right=NULL;

    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void buildTree(node*&root){
    int data;
    cin>>data;
    if(data==-1){
        return;
    }
    root=new node(data);
    buildTree(root->left);
    buildTree(root->right);
}

void printLevelOrderTraversal(node*root){
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp){
            cout<<temp->data<<' ';
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                cout<<'\n';
            }
        }
    }
    cout<<"\n\n";
}

void insertInBST(node*&root, int d){      //avg time complexity- O(h)      worst time complexity- O(n)
    if(root==NULL){
        root=new node(d);
        return;
    }
    if(d == root->data)
        return;
    else if(d>root->data)
        insertInBST(root->right, d);
    else
        insertInBST(root->left, d);
}

void createBST(node* &root){
    int data;
    cout<<"enter data for BST\n";
    cin>>data;

    while(data!=-1){
        insertInBST(root, data);
        cin>>data;
    }
}

void BSTtoLL(node*root, vector<int>&ll){
    if(root==NULL)
        return;
    BSTtoLL(root->left, ll);
    ll.push_back(root->data);
    BSTtoLL(root->right, ll);
}

vector<int> merege2SortedLL(vector<int>ll1, vector<int>ll2){
    int i=0, j=0;
    vector<int>ans;

    while(i<ll1.size() && j<ll2.size()){
        if(ll1[i]<ll2[j])
            ans.push_back(ll1[i++]);
        else
            ans.push_back(ll2[j++]);
    }

    while(i<ll1.size())
        ans.push_back(ll1[i++]);

    while(j<ll2.size())
        ans.push_back(ll2[j++]);

    return ans;
}

node* LLtoBST(vector<int>ll, int s, int e){
    if(s>e)
        return NULL;
    
    int mid = s+(e-s)/2;
    node*root = new node(ll[mid]);
    root->left = LLtoBST(ll, s, mid-1);
    root->right = LLtoBST(ll, mid+1, e);
    return root;
}

node* merge2BST(node*root1, node*root2){
    vector<int>ll1;
    BSTtoLL(root1, ll1);
    vector<int>ll2;
    BSTtoLL(root2, ll2);

    vector<int>ll = merege2SortedLL(ll1, ll2);
    return LLtoBST(ll, 0, ll.size()-1);
}

void BSTtoLL2(node*root, node*&llcurr){
    if(root==NULL)
        return;
    
    BSTtoLL2(root->left, llcurr);
    llcurr->right = new node(root->data);
    llcurr = llcurr->right;
    BSTtoLL2(root->right, llcurr);
}

vector<node*> merge2SortedLL2(node*head1, node* head2){
    vector<node*>ans;
    if(head1==NULL && head2==NULL){
        return ans;
    }

    if(head2==NULL){
        while(head1!=NULL){
            ans.push_back(head1);
            head1=head1->right;
        }
        return ans;
    }

    if(head1==NULL){
        while(head2!=NULL){
            ans.push_back(head2);
            head2=head2->right;
        }
        return ans;
    }

    node*head = NULL;
    if(head1->data < head2->data)
        head = head1;
    else
        head = head2;

    node*curr = new node(INT_MIN);
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            curr->right = head1;
            curr = curr->right;
            head1 = head1->right;
        }
        else{
            curr->right = head2;
            curr = curr->right;
            head2 = head2->right;
        }
    }
    while(head1!=NULL){
        curr->right = head1;
        curr = curr->right;
        head1 = head1->right;
    }
    while(head2!=NULL){
        curr->right = head2;
        curr = curr->right;
        head2 = head2->right;
    }

    while(head!=NULL){
        ans.push_back(head);
        head=head->right;
    }

    return ans;
}

node* LLtoBST2(vector<node*>ll, int s, int e){
    if(s>e)
        return NULL;
    
    int mid = s+(e-s)/2;
    node*root = new node(ll[mid]->data);
    root->left = LLtoBST2(ll, s, mid-1);
    root->right = LLtoBST2(ll, mid+1, e);
    return root;
}

node* merge2BST2(node*root1, node*root2){
    node*llcurr1=new node(INT_MIN);
    node*llhead1=llcurr1;
    BSTtoLL2(root1, llcurr1);
    llhead1 = llhead1->right;

    node*llcurr2=new node(INT_MIN);
    node*llhead2=llcurr2;
    BSTtoLL2(root2, llcurr2);
    llhead2 = llhead2->right;

    vector<node*>ans = merge2SortedLL2(llhead1, llhead2);
    return LLtoBST2(ans, 0, ans.size()-1);    
}

int main(){

    /*  inputs
    20 10 30 15 40 25 5 1 -1
    100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1

    10 5 20 1 8 40 7 9 -1
    30 20 25 15 17 32 37 -1

    100 20 10 5 1 -1 -1 7 -1 9 -1 -1 15 -1 -1 30 25 -1 -1 40 -1 50 45 -1 -1 -1 120 -1 -1
    */

    node*root=NULL;
    cout << "createBST-> \n";
    createBST(root);
    cout << "printLevelOrderTraversal(root)-> \n";
    printLevelOrderTraversal(root);

    node*root2=NULL;
    cout << "createBST-> \n";
    createBST(root2);
    cout << "printLevelOrderTraversal(root2)-> \n";
    printLevelOrderTraversal(root2);

    cout << "merge2BST(root, root2)-> \n";
    // createBST( merge2BST(root, root2) );
    node*root3 = merge2BST(root, root2);
    cout << "printLevelOrderTraversal(root3)-> \n";
    printLevelOrderTraversal(root3);

    cout << "merge2BST2(root, root2)-> \n";
    node*root4 = merge2BST2(root, root2);
    cout << "printLevelOrderTraversal(root4)-> \n";
    printLevelOrderTraversal(root4);
    cout << "printLevelOrderTraversal(root)-> \n";
    printLevelOrderTraversal(root);
    cout << "printLevelOrderTraversal(root2)-> \n";
    printLevelOrderTraversal(root2);






    return 0;
}