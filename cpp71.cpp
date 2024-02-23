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
    cout<<'\n';
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

void inorder(node*root, vector<int>&ans){
    if(root==NULL)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void inorder2(node*root, vector<node*>&ans){
    if(root==NULL)
        return;
    
    inorder2(root->left, ans);
    ans.push_back(root);
    inorder2(root->right, ans);
}

bool twoSumInBST(node*root, int sum){       // time complexity- o(n)    space compexity-o(n)
    vector<int>in;
    inorder(root, in);

    int i=0, j=in.size()-1;
    while(i<j){
        if(in[i]+in[j]==sum)
            return true;
        else if(in[i]+in[j]>sum)
            j--;
        else
            i++;
    }
    return false;
}

void flattenBSTInSortedLL(node*&root){      // time complexity- o(n)    space compexity-o(n)
    vector<node*>ans;
    inorder2(root, ans);

    for(int i=0; i<ans.size()-1; i++){
        ans[i]->right=ans[i+1];
        ans[i]->left=NULL;
    }
    ans[ans.size()-1]->left = ans[ans.size()-1]->right = NULL;

    root = ans[0];
}

void flattenBSTInSortedLL2(node*&root){      // time complexity- o(n)    space compexity-o(n)
    vector<int>ans;
    inorder(root, ans);

    node*curr = new node(ans[0]);
    root = curr;

    for(int i=1; i<ans.size(); i++){
        node*temp = new node(ans[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=curr->right=NULL;
}

pair<bool, int> isBBST(node*root){     //BalancedBST    time complexity- o(n)    space compexity-o(n)
    if(root==NULL){
        pair<bool, int>p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = isBBST(root->left);
    pair<bool, int> right = isBBST(root->right);
    pair<bool, int>p;
    p.second = max(left.second, right.second) + 1;
    bool flag = abs(left.second - right.second) <=1;
    p.first = flag && left.first && right.first;
    return p;
}

node* inorderToBST(vector<int>&in, int s, int e){       //&in is used to save space
    if(s>e)
        return NULL;

    int mid = s+(e-s)/2;
    node*root=new node(in[mid]);
    root->left = inorderToBST(in, s, mid-1);
    root->right = inorderToBST(in, mid+1, e);
    return root;
}

node* normalBSTToBBST(node*root){       // time complexity- o(n)    space compexity-o(n)
    vector<int>ans;
    inorder(root, ans);

    int s=0, e=ans.size()-1;
    root= inorderToBST(ans, s, e);
    return root;
}

// WRONG METHOD as the resultant tree will not have the same preorder
node* preorderToBST(vector<int>pre){
    vector<int>in=pre;
    sort(in.begin(), in.end());
    return inorderToBST(in, 0, in.size()-1);
}

node* in_preorder(vector<int>in, vector<int>pre, int inStartIndex, int inEndIndex, int preStartIndex){
    if(inStartIndex>inEndIndex && preStartIndex>=pre.size())
        return NULL;

    int value = pre[preStartIndex++];
    node*root = new node(value);
    int inRootIndex = -1;
    for(int i=inStartIndex; i<=inEndIndex; i++){
        if(in[i]==value){
            inRootIndex = i;
            break;
        }
    }
    root->left = in_preorder(in, pre, inStartIndex, inRootIndex-1, preStartIndex);
    root->right = in_preorder(in, pre, inRootIndex+1, inEndIndex, preStartIndex);
    return root;
}

// WRONG METHOD as the resultant tree will not have the same preorder
node* preorderToBST2(vector<int>pre){
    vector<int>in = pre;
    sort(in.begin(), in.end());
    node*root = in_preorder(in, pre, 0, in.size()-1, 0);
    return root;
}

node* preorderToBST3(vector<int>&pre, int minRange, int maxRange, int &index){
    if(index>pre.size())
        return NULL;

    int value = pre[index];
    node*root = new node(value);

    if(pre[index+1]>minRange && pre[index+1]<root->data){
        index++;
        root->left = preorderToBST3(pre, minRange, root->data, index);
    }

    if(pre[index+1]>root->data && pre[index+1]<maxRange){
        index++;
        root->right = preorderToBST3(pre, root->data, maxRange, index);
    }

    return root;
}

node* preorderToBST4(vector<int>&pre, int minRange, int maxRange, int &index){
    if(index>pre.size())
        return NULL;
    
    if(pre[index]<minRange || pre[index]>maxRange)
        return NULL;

    node*root = new node(pre[index++]);
    root->left = preorderToBST4(pre, minRange, root->data, index);
    root->right = preorderToBST4(pre, root->data, maxRange, index);

    return root;
}

node* preorderToBST5(vector<int>&pre, int maxRange, int &index){
    if(index>pre.size())
        return NULL;
    
    if(pre[index]>maxRange)     //bcz bs right wale child ke liye hi waps upr jana pdega
        return NULL;

    node*root = new node(pre[index++]);
    root->left = preorderToBST5(pre, root->data, index);
    root->right = preorderToBST5(pre, maxRange, index);

    return root;
}

bool isBST(node*root, int minRange, int maxRange){
    if(root==NULL)
        return true;
    
    if(root->data > minRange && root->data<maxRange){
        bool left = isBST(root->left, minRange, root->data);
        bool right = isBST(root->right, root->data, maxRange);
        return right && left;
    }
    return false;
}

int main(){

    node*root=NULL;

    /*  inputs
    20 10 30 15 40 25 5 1 -1
    100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1
    100 20 10 5 1 -1 -1 7 -1 9 -1 -1 15 -1 -1 30 25 -1 -1 40 -1 50 45 -1 -1 -1 120 -1 -1
    */

    cout<<"createBST-> \n";
    createBST(root);

    cout<<"printLevelOrderTraversal-> \n";
    printLevelOrderTraversal(root);
    cout<<"\n\n";

    int sum=20;
    cout<<"2SumInBST-> "<<twoSumInBST(root, sum)<<"\n\n";

    cout<<"flattenBSTInSortedLL-> \n";
    flattenBSTInSortedLL(root);
    cout<<"printLevelOrderTraversal(root)-> \n";
    printLevelOrderTraversal(root);
    cout<<'\n';

    node*root2=NULL;
    cout<<"createBST(root2)-> \n";
    createBST(root2);
    cout<<"printLevelOrderTraversal(root2)-> \n";
    printLevelOrderTraversal(root2);
    cout<<"\n\n";

    cout<<"isBBST.first-> "<<isBBST(root2).first<<"\n\n";

    cout<<"normalBSTToBBST-> \n";
    node*root3 = normalBSTToBBST(root2);
    cout<<"printLevelOrderTraversal(root2)-> \n";
    printLevelOrderTraversal(root2);
    cout<<"\n\n";
    cout<<"printLevelOrderTraversal(root3)-> \n";
    printLevelOrderTraversal(root3);
    cout<<"\n\n";

    vector<int>pre={100, 20, 10, 5, 1, 7, 9, 15, 30, 25, 40, 50, 45, 120};
    // node*root4 = preorderToBST(pre);
    // cout<<"printLevelOrderTraversal(root4)-> \n";
    // printLevelOrderTraversal(root4);
    // cout<<"\n\n";

    // node*root5 = preorderToBST2(pre);
    // cout<<"printLevelOrderTraversal(root5)-> \n";
    // printLevelOrderTraversal(root5);
    // cout<<"\n\n";

    int index=0;
    node*root6 = preorderToBST3(pre, INT_MIN, INT_MAX, index);
    cout<<"printLevelOrderTraversal(root6)-> \n";
    printLevelOrderTraversal(root6);
    cout<<"\n\n";

    index=0;
    node*root7 = preorderToBST4(pre, INT_MIN, INT_MAX, index);
    cout<<"printLevelOrderTraversal(root7)-> \n";
    printLevelOrderTraversal(root7);
    cout<<"\n\n";
    
    index=0;
    node*root8 = preorderToBST5(pre, INT_MAX, index);
    cout<<"printLevelOrderTraversal(root8)-> \n";
    printLevelOrderTraversal(root8);
    cout<<"\n\n";

    cout<<"isBST(root)-> "<<isBST(root, INT_MIN, INT_MAX)<<"\n";
    cout<<"isBST(root2)-> "<<isBST(root2, INT_MIN, INT_MAX)<<"\n";
    cout<<"isBST(root3)-> "<<isBST(root3, INT_MIN, INT_MAX)<<"\n";
    cout<<"isBST(root6)-> "<<isBST(root6, INT_MIN, INT_MAX)<<"\n";
    cout<<"isBST(root7)-> "<<isBST(root7, INT_MIN, INT_MAX)<<"\n";
    cout<<"isBST(root8)-> "<<isBST(root8, INT_MIN, INT_MAX)<<"\n";

    return 0;
}