#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};

node* buildTree(node*root){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"enter data for left child of " << data <<'\n';
    root->left=buildTree(root->left);
    cout<<"enter data for right child of " << data <<'\n';
    root->right=buildTree(root->right);
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

vector<int>zigZagTraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size=q.size();
        vector<int>curr(size);
        for(int i=0; i<size; i++){
            node*temp=q.front();
            q.pop();
            int index = leftToRight ? i : size-i-1;
            curr[index] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight;
        for(int i=0; i<curr.size(); i++){
            ans.push_back(curr[i]);
        }
        // for(auto i:curr){        // above ans this work same
        //     ans.push_back(i);
        // }
    }
    return ans;
}

vector<int> printLeft(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    while(root!=NULL && (root->left!=NULL ||root->right!=NULL)){
        ans.push_back(root->data);
        if(root->left){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ans;
}

vector<int> printLeaf(node*root, vector<int>&ans){
    if(root==NULL){
        return ans;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ans;
    }
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
    return ans;
}

vector<int> printright(node*root, vector<int>&ans){
    if(root==NULL){
        return ans;
    }
    if(root->left==NULL && root->right==NULL){
        return ans;
    }
    if(root->right){
        printright(root->right, ans);
    }
    else{
        printright(root->left, ans);
    }
    ans.push_back(root->data);
    return ans;
}

vector<int> boundaryTraversal(node *root){
    vector<int>ans;
    vector<int>ans1;
    ans.push_back(root->data);
    ans1 = printLeft(root->left);
    vector<int>ans2_1;
    ans2_1 = printLeaf(root->left, ans2_1);
    vector<int>ans2_2;
    ans2_2 = printLeaf(root->right, ans2_2);
    // while(root->right==NULL){
    //     root=root->left;
    // }
    vector<int>ans3;
    // if(root!=NULL)
        ans3 = printright(root->right, ans3);
    for(auto i:ans1){
        ans.push_back(i);
    }
    for(auto i:ans2_1){
        ans.push_back(i);
    }
    for(auto i:ans2_2){
        ans.push_back(i);
    }
    for(auto i:ans3){
        ans.push_back(i);
    }
    return ans;
}

map<node*, int> leftRightind(node*root, map<node*, int>&m, int ind=0){
    if(root==NULL){
        return m;
    }
    m[root]=ind;
    m=leftRightind(root->left, m, ind-1);
    m=leftRightind(root->right, m, ind+1);
    // leftRightind(root->left, m, ind-1);      // is it wrong
    // leftRightind(root->right, m, ind+1);     // is it wrong
    return m;
}

// vector<int> verticalOrderTraversalSolve(node* root, vector<vector<int>>&ans, map<node*, int>m){
//     if(root==NULL){
//         vector<int>result;
//         return result;
//     }
//     int leftInd;
//     for(auto i:m){
//         leftInd=min(leftInd,i.second);
//     }
//     queue<node*>q;
//     q.push(root);
//     while(!q.empty()){
//         node*temp=q.front();
//         q.pop();
//         int ind=m[temp];
//         ans[ind-leftInd].push_back(temp->data);
//         if(temp->left)
//             q.push(temp->left);
//         if(temp->right)
//             q.push(temp->right);
//     }
//     vector<int>result;
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             result.push_back(ans[i][j]);
//         }
//     }
//     return result;
// }

// vector<int> verticalOrderTraversal(node* root){
//     if(root==0){
//         vector<int>ans;
//         return ans;
//     }
//     // leftInd=>0, root=>-leftInd, rightInd=>rightInd-leftInd

//     map<node*, int>m = leftRightind(root, m, 0);
//     cout<<"m is\n";
//     for(auto i:m){
//         cout<<i.first->data<<' '<<i.second<<'\n';
//     }
//     int leftInd;
//     int rightInd;
//     for(auto i:m){
//         leftInd=min(leftInd,i.second);
//         rightInd=max(rightInd,i.second);
//     }
//     vector<vector<int>>arr(rightInd-leftInd);
//     return verticalOrderTraversalSolve(root, arr, m);
// }

int main(){

    // inputs
    // 5 10 -1 2 -1 -1 15 -1 -1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 

    node*root=NULL;
    root=buildTree(root);

    levelOrderTraversal(root);
    cout<<'\n';

    vector<int>ans=zigZagTraversal(root);       // why is it not printing
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<"\n\n";

    ans=boundaryTraversal(root);
    for(auto i:ans){
        cout<<i<<' ';
    }
    cout<<"\n\n";

    // ans=verticalOrderTraversal(root);
    // for(auto i:ans){
    //     cout<<i<<' ';
    // }
    // cout<<"\n\n";

    map<node*, int>m=leftRightind(root, m, 0);
    for(auto i:m){
        cout<<i.first<<' '<<i.second<<'\n';
    }

  
    return 0;
}