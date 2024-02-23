#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildTree(node*&root){      //it is preorder traversal      both this and below line will work same as we are chaning in its derefeference
// node*buildTree(node*root){      //it is preorder traversal
    cout << "enter data\n";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;    //NULL will be stored in root->left or root->right in the next recursion if any of them contain -1
    }

    cout << "enter the left child of " << data << "\n";
    root->left = buildTree(root->left);

    cout << "enter the right child of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node*root){    //usually done by using queue   BFS
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);   //NULL is pointer
    while(!q.empty()){
        if(q.front()){
            cout<<q.front()->data<<' ';
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        else{
            cout<<'\n';
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

void levelOrderTraversal2(node*root){    //usually done by using queue   BFS
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);   //NULL is pointer
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
            cout<<'\n';
            if(!q.empty()){
                q.push(NULL);       //why -1 are not printing
            }
        }
    }
    cout<<'\n';
}

void inorderTraversal(node*root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}

void preorderTraversal(node*root){
    if(root==NULL){
        return;
    }
    cout << root->data << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node*root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << ' ';
}

void buildFromLevelOrderTraversal(node*&root){     // not complete code
    cout<<"enter data\n";
    int data;
    cin>>data;
    if(data==-1){
        return;
    }
    root=new node(data);
    if(data==-1){
        return;
    }
    queue<node*>q;
    q.push(root);
    cin>>data;
    while(data!=-1){
        node*temp=new node(data);
        if(q.front()->left == NULL){
            q.front()->left = temp;
        }
        else if(q.front()->right == NULL){
            q.front()->right = temp;
            q.pop();
        }
        q.push(temp);
        cin>>data;
    }
}

void buildFromLevelOrderTraversal2(node*&root){     // complete code
    cout<<"enter data\n";
    int data;
    cin>>data;
    if(data==-1){
        return;
    }
    root=new node(data);
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"enter left child data of "<<temp->data<<"\n";
        cin>>data;
        node*leftChild=new node(data);
        if(data!=-1){
            temp->left=leftChild;
            q.push(leftChild);
        }
        cout<<"enter right child data of "<<temp->data<<"\n";
        cin>>data;
        node*rightChild=new node(data);
        if(data!=-1){
            temp->right=rightChild;
            q.push(rightChild);
        }
    }
}

int numberOfLeafNodes(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    return numberOfLeafNodes(root->left) + numberOfLeafNodes(root->right);
}

int numberOfLeafNodes2(node*root, int cnt=0){       //this method can be use from any level order, inorder, preorder, postorder traversal
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        cnt++;
    }
    if(root->left)
        numberOfLeafNodes2(root->left, cnt);
    if(root->right)
        numberOfLeafNodes2(root->right, cnt);
    return cnt;
}

void inorderTraversal2(node*root){
    stack<node*>s;
    node*temp=root;
    while(temp!=NULL || !s.empty()){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<' ';
        temp=temp->right;
    }
    cout<<'\n';
}

void preorderTraversal2(node*root){
    stack<node*>s;
    node*temp=root;
    while(temp!=NULL || !s.empty()){
        while(temp!=NULL){
            cout<<temp->data<<' ';
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        temp=temp->right;
    }
    cout<<'\n';
}

void reverseLevelOrderTraversal(node*root){     // space complexity-O(n)    time complexity-O(n)
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    stack<vector<int>>s;
    // node*temp=root;
    vector<int>currVector;
    s.push(currVector);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        if(curr==NULL){
            vector<int>newVector;
            s.push(newVector);
            if(!q.empty())
                q.push(NULL);
        }
        else{
            s.top().push_back(curr->data);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    while(!s.empty()){
        vector<int>currVector=s.top();
        for(int i=0; i<currVector.size(); i++){
            cout<<currVector[i]<<' ';
        }
        cout<<'\n';
        s.pop();
    }
}



int main(){

    /*
    Tree-
    non linear data structure
    node    element of the tree containing data and pointer(s) containing address(es) of its child node
    root    node from where the tree starts
    child   
    parent
    sibling     having same parents
    ancestor    all the nodes going upwards in the path from that node to root node
    descendent      all the nodes going downwards in the path from that node to leaf node
    leaf    node that has no child

    binary tree-    can have less than or equal to 2 childs
    node{
        int data;
        mode*left;
        mode*right;
    }

    n-ary tree- having multiple children, more than 2
    node{
        int data;
        list<node*>child;   //make a list and it can store as many node pointers as you want
    }

    level-  start from 0 at root node

    level order traveral    traverse level wise from root to deepest leaf node

    inorder traversal       left -> root -> right
    preorder traversal      root -> left -> right
    postorder traversal     left -> right -> root

    */

    // inputs
    // 5 10 -1 2 -1 -1 15 -1 -1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 

    node*root=NULL;

    root=buildTree(root);

    levelOrderTraversal2(root);

    inorderTraversal(root);
    cout<<'\n';
    preorderTraversal(root);
    cout<<'\n';
    postorderTraversal(root);
    cout<<"\n\n";

    node*root2=NULL;
    buildFromLevelOrderTraversal2(root2);
    levelOrderTraversal2(root2);

    cout << numberOfLeafNodes(root2) <<'\n';

    cout << numberOfLeafNodes2(root2) <<"\n\n";



    /*
    HOMEWORK
    reverse level order traversal
    do inorder, postorder, preorder using iteration / loops

    */

    inorderTraversal2(root);
    preorderTraversal2(root);
    reverseLevelOrderTraversal(root2);

    return 0;
}