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

node* buildTree(node*root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void printLevelOrderTraversal(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp){
            cout<<temp->data<<' ';
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else{
            cout<<'\n';
            if(!q.empty())
                q.push(NULL);
        }
    }
}

void in_preOrder(node*&root, vector<int>inorder, vector<int>preorder){
    if(preorder.size()==0){
        return;
    }

    root=new node(preorder[0]);
    int inorderRootIndex=-1;
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i]==root->data){
            inorderRootIndex=i;
            break;
        }
    }

    vector<int>leftInorder;
    for(int i=0; i<inorderRootIndex; i++){
        leftInorder.push_back(inorder[i]);
    }

    vector<int>rightInorder;
    for(int i=inorderRootIndex+1; i<inorder.size(); i++){
        rightInorder.push_back(inorder[i]);
    }

    vector<int>leftPreorder;
    for(int i=1; i<=inorderRootIndex; i++){
        leftPreorder.push_back(preorder[i]);
    }
    
    vector<int>rightPreorder;
    for(int i=inorderRootIndex+1; i<preorder.size(); i++){
        rightPreorder.push_back(preorder[i]);
    }

    in_preOrder(root->left, leftInorder, leftPreorder);
    in_preOrder(root->right, rightInorder, rightPreorder);
}

void in_preOrder2(node*&root, vector<int>inorder, vector<int>preorder, map<int, int>m){
    if(preorder.size()==0){
        return;
    }

    root=new node(preorder[0]);
    int inorderRootIndex=m[preorder[0]];
    // int inorderRootIndex=m[root->data];

    vector<int>leftInorder;
    for(int i=0; i<inorderRootIndex; i++){
        leftInorder.push_back(inorder[i]);
    }

    vector<int>rightInorder;
    for(int i=inorderRootIndex+1; i<inorder.size(); i++){
        rightInorder.push_back(inorder[i]);
    }

    vector<int>leftPreorder;
    for(int i=1; i<=inorderRootIndex; i++){
        leftPreorder.push_back(preorder[i]);
    }
    
    vector<int>rightPreorder;
    for(int i=inorderRootIndex+1; i<preorder.size(); i++){
        rightPreorder.push_back(preorder[i]);
    }

    in_preOrder2(root->left, leftInorder, leftPreorder, m);
    in_preOrder2(root->right, rightInorder, rightPreorder, m);
}

void in_preOrder3(node*&root, int inorder[], int preorder[], int inorderStartIndex, int inorderEndIndex, int &index, int n,  map<int, int>m){
    if(index>=n || inorderStartIndex > inorderEndIndex){
        return;
    }
    root=new node(preorder[index++]);
    int inorderRootIndex=m[root->data];
    // left subtree first
    in_preOrder3(root->left, inorder, preorder, inorderStartIndex, inorderRootIndex-1, index, n, m);
    in_preOrder3(root->right, inorder, preorder, inorderRootIndex+1, inorderEndIndex, index, n, m);
}

void in_postOrder(node*&root, int inorder[], int postorder[], int inorderStartIndex, int inorderEndIndex, int &index, int n,  map<int, int>m){
    if(index<0 || inorderStartIndex > inorderEndIndex){
        return;
    }
    root=new node(postorder[index--]);
    int inorderRootIndex=m[root->data];
    // right subtree first
    in_postOrder(root->right, inorder, postorder, inorderRootIndex+1, inorderEndIndex, index, n, m);
    in_postOrder(root->left, inorder, postorder, inorderStartIndex, inorderRootIndex-1, index, n, m);
}

int main(){

    node*root=NULL;
    
    vector<int>inorder = {19,7,3,11,1,17,5};
    vector<int>preorder = {1,3,7,19,11,5,17};
    map<int, int>m;
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]]=i;
    }
    in_preOrder(root, inorder, preorder);
    printLevelOrderTraversal(root);
    cout<<"\n\n";


    node*root2=NULL;
    in_preOrder2(root2, inorder, preorder, m);
    printLevelOrderTraversal(root2);
    cout<<"\n\n";
    

    int inorder2[] = {19,7,3,11,1,17,5};
    int preorder2[] = {1,3,7,19,11,5,17};
    int postorder[] = {19,7,11,3,17,5,1};
    int n=7;
    map<int, int>m2;
    for(int i=0; i<n; i++){
        m[inorder2[i]]=i;
    }
    node*root3=NULL;
    int index=0;
    in_preOrder3(root3, inorder2, postorder, 0, n-1, index, n, m2);
    printLevelOrderTraversal(root3);
    cout<<"\n\n";
    
    
    node*root4=NULL;
    index=0;
    in_postOrder(root4, inorder2, postorder, 0, n-1, index, n, m2);
    printLevelOrderTraversal(root4);
    cout<<"\n\n";

    return 0;
}