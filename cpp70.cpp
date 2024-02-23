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

bool searchInBST(node*root, int value){     //avg time complexity- O(h)      worst time complexity- O(n)
    if(root==NULL)
        return 0;
    
    if(root->data == value)
        return 1;
    else if(value > root->data)
        return searchInBST(root->right, value);
    else
        return searchInBST(root->left, value);
}

void inorder(node*root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

void inorderStore(node*root, vector<int>&ans){
    if(root==NULL)
        return;
    
    inorderStore(root->left, ans);
    ans.push_back(root->data);
    inorderStore(root->right, ans);
}

void preorder(node*root){
    if(root==NULL)
        return;
    
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(root==NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';
}

int getMin(node*root){
    if(root==NULL)
        return -1;
    while(root->left!=NULL)
        root=root->left;
        
    return root->data;
}

int getMax(node*root){
    if(root==NULL)
        return -1;
    while(root->right!=NULL)
        root=root->right;

    return root->data;
}

bool validateBST(node*root, int minRange, int maxRange){
    if(root==NULL)
        return true;
    
    bool curr=false;
    if(root->data>minRange && root->data<maxRange){
        curr=true;
    }
    bool left = validateBST(root->left, minRange, root->data);
    bool right = validateBST(root->right, root->data, maxRange);

    return left && right && curr;
}

bool validateBST2(node*root){
    vector<int>ans;
    inorderStore(root, ans);
    for(int i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<' ';
    }
    for(int i=0; i<ans.size()-1; i++){
        if(ans[i]>ans[i+1])
            return false;
    }

    return true;
}

int kSmallestInBST(node*root, int &k){
    if(root==NULL)
        return -1;
    
    int left = kSmallestInBST(root->left, k);
    k--;
    if(k==0){
        return root->data;
    }
    if(left!=-1){
        return left;
    }
    int right = kSmallestInBST(root->right, k);
    return right;
}

void totalElements(node*root, int &cnt){
    if(root==NULL)
        return;
    totalElements(root->left, cnt);
    totalElements(root->right, cnt);
    cnt++;
    return;
}

int kLargestInBST(node*root, int &k, int totalElements){
    if(root==NULL)
    return -1;

    int left=kLargestInBST(root->left, k, totalElements);
    k++;
    if(k==totalElements+1)
        return root->data;
    if(left!=-1)
        return left;
    int right=kLargestInBST(root->right, k, totalElements);
    return right;
}

int LCA(node*root, int n1, int n2){
    if(root==NULL)
        return -1;

    // if(root->data==n1 || root->data==n2)
    //     return root->data;

    if(n1<root->data && n2<root->data){
        return LCA(root->left, n1, n2);
    }
    if(n1>root->data && n2>root->data){
        return LCA(root->right, n1, n2);
    }
    if((n1<root->data && n2>root->data) || (n2<root->data && n1>root->data)){
        return root->data;
    }
}

int LCA2(node*root, int n1, int n2){
    while(root!=NULL){
        if(n1<root->data && n2<root->data){
            root=root->left;
        }
        else if(n1>root->data && n2>root->data){
            root=root->right;
        }
        else
            return root->data;
    }
}

int main(){

    node*root=NULL;

    // 20 10 30 15 40 25 5 1 -1
    // 100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1
    // 100 20 10 5 1 -1 -1 7 -1 9 -1 -1 15 -1 -1 30 25 -1 -1 40 -1 50 45 -1 -1 -1 120 -1 -1
    cout<<"buildTree-> "<<'\n';
    buildTree(root);
    cout<<'\n';
    cout<<"printLevelOrderTraversal-> "<<'\n';
    printLevelOrderTraversal(root);
    cout<<'\n';

    cout<<"validateBST-> "<<validateBST(root, INT_MIN, INT_MAX)<<"\n\n";

    cout<<"validateBST2-> "<<validateBST2(root)<<"\n\n";

    inorder(root);
    cout<<"\n\n";
    int cnt=0;
    totalElements(root, cnt);
    int k=5;
    cout<<"kSmallestInBST-> "<<kSmallestInBST(root,k)<<"\n\n";
    k=5;
    cout<<"kLargestInBST-> "<<kLargestInBST(root,k, cnt)<<"\n\n";

    cout<<"LCA-> "<<LCA(root, 25, 43)<<"\n\n";
    cout<<"LCA2-? "<<LCA2(root, 25, 43)<<"\n\n";

    /*
    HOMEWORK
    write code of kSmallestElement in morris traversal
    */
    
    return 0;
}