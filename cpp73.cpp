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

void insertAtBST(node*root, int data){
    if(data==-1)
        return;
    if(root==NULL){
        root=new node(data);
        return;
    }
    else{
        if(data > root->data)
            insertAtBST(root->right, data);
        else if(data < root->data)
            insertAtBST(root->left, data);
        else
            return;
    }
}

void createBST(node*&root){
    cout<<"createBST->\n";
    int data;
    cin>>data;
    while(data!=-1){
        insertAtBST(root, data);
        cin>>data;
    }
}

void createBinaryTree(node*&root){
    int data;
    cin>>data;
    if(data==-1)
        return;
    
    root = new node(data);
    createBinaryTree(root->left);
    createBinaryTree(root->right);
}

void printLevelOrderTraversal(node*root){
    cout<<"printLevelOrderTraversal->\n";
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
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
    cout<<'\n';
}

int sizeOfLargestBST(node*root){
    if(root==NULL){
        return 0;
    }

    int left = sizeOfLargestBST(root->left);
    int right = sizeOfLargestBST(root->right);

    int currLeft = 0;
    int currRight = 0;
    if(root->left){
        if(root->left->data < root->data){
            currLeft = left;
        }
    }
    if(root->right){
        if(root->right->data > root->data){
            currRight = right;
        }
    }

    int curr = currLeft + currRight + 1;

    return max(curr, max(left, right));
}

class info{
    int size
};

/*
pair<int, bool> sizeOfLargestBSTasSubtree(node*root){
    if(root==NULL){
        pair<int, bool>p = make_pair(0, true);
        return p;
    }

    pair<int, bool>left = sizeOfLargestBSTasSubtree(root->left);
    pair<int, bool>right = sizeOfLargestBSTasSubtree(root->right);
    pair<int, bool>p;
    bool flag = true;
    if(root->left){
        if(root->left->data > root->data)
            flag = false;
        if(root->right->data < root->data)
            flag = false;
    }
    p.second = left.second && right.second && flag;

    if(p.second)
        p.first = left.first + right.first + 1;
    else
        p.first = max(left.first, right.first);

    return p;
}
*/


int main(){

    /*  inputs
    5 6 7 -1 -1 8 4 -1 -1 10 11 -1 -1 15 -1 -1 9 3 -1 -1 12 -1 -1

    20 10 30 15 40 25 5 1 -1
    100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1

    10 5 20 1 8 40 7 9 -1
    30 20 25 15 17 32 37 -1

    100 20 10 5 1 -1 -1 7 -1 9 -1 -1 15 -1 -1 30 25 -1 -1 40 -1 50 45 -1 -1 -1 120 -1 -1
    */

    node*root=NULL;
    cout << "createBinaryTree(root)\n";
    createBinaryTree(root);

    printLevelOrderTraversal(root);

    cout<<"sizeOfLargestBST(root)-> "<<sizeOfLargestBST(root)<<"\n\n";

    cout<<"sizeOfLargestBSTasSubtree(root)-> "<<sizeOfLargestBSTasSubtree(root).first<<"\n\n";

}