#include<bits/stdc++.h>
using namespace std;

// next largest smaller element
// 3 4 7 5 3 4 2 2
// 2 3 5 4 2 2 -1 -1

int kthSmallest(int a[], int l, int r, int k){      // time complexuty-O(n)     space complexuty-O(k)
    int n=r-l+1;
    if(k>n)
        return -1;
    priority_queue<int>pq;      // max heap
    for(int i=l; i<k; i++){
        pq.push(a[i]);
    }

    for(int i=k; i<=r; i++){
        if(a[i] < pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.top();
}

int kthLargest(int a[], int l, int r, int k){       // time complexuty-O(n)     space complexuty-O(k)
    int n=r-l+1;
    if(k>n)
        return -1;
    priority_queue<int, vector<int>, greater<int>> pq;      //min heap
    for(int i=l; i<k; i++){
        pq.push(a[i]);
    }

    for(int i=k; i<=r; i++){
        if(a[i] > pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.top();
}

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node*buildTree(node*&root){
    cout << "enter data\n";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }

    cout << "enter the left child of " << data << "\n";
    root->left = buildTree(root->left);

    cout << "enter the right child of " << data << "\n";
    root->right = buildTree(root->right);
    return root;
}

int cntNodes(node*root){
    if(root==NULL)
        return 0;
    
    return 1 + cntNodes(root->left) + cntNodes(root->right);
}

bool isCBT(node*root, int n, int i){
    if(root==NULL){
        return true;
    }

    if(i>n){
        return false;
    }

    bool left = isCBT(root->left, n, 2*i);
    bool right = isCBT(root->right, n, 2*i+1);

    return left && right;
}

// only execute if tree is CBT 
bool isMaxOrder(node*root){
    if(root==NULL){
        return true;
    }

    if(root->left){
        if(root->data < root->left->data){
            return false;
        }

        if(root->right && root->data < root->right->data){
            return false;
        }
    }

    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    return left && right;   
}

// only execute if tree is CBT 
bool isMaxOrder2(node*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    else if(root->right==NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder2(root->left);
        bool right = isMaxOrder2(root->right);
        bool curr = (root->data > root->left->data) && (root->data > root->right->data);
        return left && right && curr;
    }
}

bool isBinaryTreeHeap(node*root){
    int n = cntNodes(root);
    return (isCBT(root, n, 1) && isMaxOrder(root));
}

void heapify(vector<int>&a, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && a[largest] < a[left])
        left = largest;
    if(right<n && a[largest] < a[right])
        right = largest;
    
    if(largest!=i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<int>&a){
    int n = a.size();
    for(int i=n/2-1; i>=0; i--){    // 0 based indexing
        heapify(a,n,i);
    }
}

vector<int>mergeHeap(vector<int>&a, vector<int>&b, int n, int m){
    vector<int>c = a;
    for(auto i:b){
        c.push_back(i);
    }

    buildHeap(c);
}

int minCostOfRopes(vector<int>a, int n){
    priority_queue<int, vector<int>, greater<int> >pq;
    for(auto i:a)
        pq.push(i);
    
    int ans = 0;
    while(pq.size()>1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        int temp = num1 + num2;
        ans+=temp;
        pq.push(temp);
    }
    return ans;
}

void inorder(node*&root, vector<int>&in){
    if(root==NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorderFill(node*&root, vector<int>&in, int &ind){
    if(ind >= in.size() || root==NULL){
        return;
    }

    root->data = in[ind++];
    preorderFill(root->left, in, ind);
    preorderFill(root->right, in, ind);
}

void completeBstToHeap(node*&root){
    if(root==NULL){
        return;
    }
    vector<int>in;
    inorder(root, in);

    int ind = 0;
    preorderFill(root, in, ind);
}

int main(){

    int a[]={14,7,6,43,3,15,3};
    cout << "kthSmallest(a, k)-> " << kthSmallest(a, 0, 6, 5) <<'\n';
    cout << "kthLargest(a, k)-> " << kthLargest(a, 0, 6, 5) <<'\n';

    /*
        IMP
        we can find k largest element using max heap of size k
        we can find k smallest element using min heap of size k
    */

    

    return 0;
}