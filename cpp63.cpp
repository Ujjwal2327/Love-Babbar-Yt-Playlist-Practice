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

void buildTree(node*&root){
    int data;
    cin>>data;
    if(data==-1){
        return;
    }
    root=new node(data);
    cout<<"enter left child data of "<<data<<'\n';
    buildTree(root->left);
    cout<<"enter right child data of "<<data<<'\n';
    buildTree(root->right);
    return;
}
// unbalanced tree input    5 10 15 -1 -1 -1 20 25 30 -1 -1 -1 -1 -1
// balanced tree input    5 10 15 -1 -1 -1 20 25 30 -1 -1 -1 35 -1 -1 
// 50 15 15 -1 -1 -1 10 5 5 -1 -1 -1 -1 -1
// 3 1 1 -1 -1 -1 1 -1 -1

void printLevelOrder(node*root){
    queue<node*>q;
    if(root==NULL){
        return;
    }
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
            cout<<'\n';
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

int height(node*root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left), height(root->right))+1;
}

int diameter(node*root){    //time complexity-O(n^2)
    if(root==NULL){
        return 0;
    }

    int option1=diameter(root->left);
    int option2=diameter(root->right);
    int option3=height(root->left) + height(root->right) + 1;
    return max(option1, max(option2, option3));
}

pair<int, int> diameterFast(node*root){    //time complexity-O(n)
    if(root==NULL){
        pair<int, int>p= make_pair(0,0);
        return p;
    }
    pair<int, int>p;
    pair<int, int>left = diameterFast(root->left);
    pair<int, int>right = diameterFast(root->right);
    p.second=max(left.second,right.second)+1;
    int option1 = left.first;
    int option2 =right.first;
    int option3 = left.second +right.second +1;
    p.first= max(option1, max(option2, option3));
    return p;
}

bool isBalancedTree(node*root){
    if(root==NULL){
        return true;
    }
    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);
    bool compute = abs(height(root->left)-height(root->right))<=1;
    return (left && right && compute);
}

pair<bool, int> isBalancedTreeFast(node*root){
    if(root==NULL){
        pair<bool, int>p=make_pair(true, 0);
        return p;
    }
    pair<bool,int>p;
    pair<bool, int>left = isBalancedTreeFast(root->left);
    pair<bool, int>right = isBalancedTreeFast(root->right);
    int leftHeight = left.second;
    int rightHeight = right.second;
    int leftCompute = left.first;
    int rightCompute = right.first;
    p.second=max(leftHeight, rightHeight)+1;
    bool compute= abs(leftHeight - rightHeight) <=1;
    p.first = rightCompute && leftCompute && compute;
    return p;
}

bool identicalTrees(node*root1, node*root2){    // time complexity-O(n)     space complexity-O(n)
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root2==NULL && root1!=NULL)){
        return false;
    }
    bool left = identicalTrees(root1->left, root2->left);
    bool right = identicalTrees(root1->right, root2->right);
    bool curr = root1->data==root2->data;
    return left && right && curr;
}

bool identicalTrees2(node*root1, node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root2==NULL && root1!=NULL)){
        return false;
    }
    bool curr = root1->data==root2->data;
    if(curr){
        bool left = identicalTrees2(root1->left, root2->left);
        bool right = identicalTrees2(root1->right, root2->right);
        return left && right && curr;
    }
    else{
        return false;
    }
}

pair<bool, int> isSumTree(node*root){
    if(root==NULL){
        pair<bool, int>p=make_pair(true, 0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool, int>p=make_pair(true, root->data);
        return p;
    }
    pair<bool,int>left = isSumTree(root->left);
    pair<bool,int>right = isSumTree(root->right);
    pair<bool, int>p;
    p.second = left.second + right.second;
    p.first = root->data == p.second && left.first && right.first;
    p.second = left.second + right.second + root->data;
    return p;
}

pair<bool, int> isSumTree2(node*root){
    if(root==NULL){
        pair<bool, int>p=make_pair(true, 0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool, int>p=make_pair(true, root->data);
        return p;
    }
    pair<bool,int>left = isSumTree(root->left);
    pair<bool,int>right = isSumTree(root->right);
    int sum = left.second + right.second;
    pair<bool, int>p;
    p.first = root->data == sum && left.first && right.first;
    if(p.first){
        p.second = 2*(root->data);
        // p.second = root->data + left.second + right.second;      // both above and this line are same
    }
    return p;
}

int main(){

    node*root=NULL;
    buildTree(root);

    printLevelOrder(root);

    cout << "height of the tree is " << height(root) << '\n';

    /*
    skew tree   having either only left subtree or right subtree

    height- lenght of the path from root node to deepest leaf node
    diameter / width- largest path from leaf node to another leaf / root node

    */
    cout << "width / diameter of the tree is " << diameter(root) << '\n';
    cout << "width / diameter of the tree is " << diameterFast(root).first << '\n';
    cout << "height of the tree is " << diameterFast(root).second << '\n';
    cout << "isBalancedTree-> " << isBalancedTree(root) << '\n';
    cout << "isBalancedTreeFast.first-> " << isBalancedTreeFast(root).first << '\n';

    // node*root2=NULL;
    // buildTree(root2);
    // cout << "identicalTrees-> " << identicalTrees2(root, root2) << '\n';
    cout << "isSumTree-> " << isSumTree(root).first << '\n';

    return 0;
}