#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

node*buildTree(node*root){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

pair<int, int> longestPathSum(node*root){
    if(root==NULL){
        pair<int, int>p=make_pair(0,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<int, int>p=make_pair(root->data,1);
        return p;
    }
    pair<int, int>left = longestPathSum(root->left);
    pair<int, int>right = longestPathSum(root->right);
    int height = max(left.second, right.second)+1;
    int subtreeSum;
    if(left.second>right.second){
        subtreeSum=left.first;
    }
    else{
        subtreeSum=right.first;
    }
    int sum = subtreeSum + root->data;
    pair<int, int>p = make_pair(sum, height);
    return p;
}

pair<int, int> longestPathSum2(node*root, pair<int, int>&p){
    if(root==NULL){
        return p;
    }
    pair<int, int>temp1=p;
    if(root->left){
        temp1.first+=root->left->data;
        temp1.second+=1;
    }
    pair<int, int>left = longestPathSum2(root->left, temp1);
    pair<int, int>temp2=p;
    if(root->right){
        temp2.first+=root->right->data;
        temp2.second+=1;
    }
    pair<int, int>right = longestPathSum2(root->right, temp2);
    if(left.second>right.second){
        return left;
    }
    else{
        return right;
    }
}

vector<node*> ancestors(node*root, int n, vector<node*>&ans){
    if(root==NULL){
        return ans;
    }
    if(root->data==n){
        return ans;
    }
    ancestors(root->left, n, ans);
    ancestors(root->right, n, ans);
    if(root->right->data==n || root->left->data==n){
        ans.push_back(root);
        return ans;
    }
    int size=ans.size();
    if(size>0){
        if(root->right==ans[size-1] || root->left==ans[size-1]){
            ans.push_back(root);
            return ans;
        }
    }
}

node*lowestCommonAncestorOf2Nodes(node*root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    vector<node*>ancestor1=ancestors(root, n1, ancestor1);
    vector<node*>ancestor2=ancestors(root, n2, ancestor2);
    for(int i=0; i<ancestor1.size(); i++){
        if(count(ancestor1.begin(), ancestor1.end(), ancestor2[i])){
            return ancestor2[i];
        }
    }
    return NULL;
}

node*lowestCommonAncestorOf2Nodes2(node*root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node*left=lowestCommonAncestorOf2Nodes2(root->left, n1, n2);
    node*right=lowestCommonAncestorOf2Nodes2(root->right, n1, n2);

    if(left && right){
        return root;
    }
    else if(left){
        return left;
    }
    else if(right){
        return right;
    }
    else{
        return NULL;
    }

}

void kSumPath(node*root, int k, pair<int, int>&p){
    // if(root==NULL){
    //     return;
    // }

    // int cnt=p.first;
    // int sum=p.second+root->data;

    // if(root->data==k){
    //     cnt++;
    // }

    // if(sum==k){
    //     cnt++;
    // }
    
    // if(sum>k){
    //     if(root->data<=k)
    //         sum=root->data;
    //     else
    //         sum=0;      //wrong here    kyuki ho skta hai aur neeche jane pr poore root se us node tk ka sum k ke equal aa jaye
    // }

    // p.first=cnt;
    // p.second=sum;

    // kSumPath(root->left, k, p);
    // kSumPath(root->right, k, p);
}

void kSumPath2(node*root, int k, int &cnt, vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    kSumPath2(root->left, k, cnt, path);
    kSumPath2(root->right, k, cnt, path);
    int size=path.size();
    int sum=0;
    for(int i=size-1; i>=0; i--){
        sum+=path[i];
        if(sum==k){
            cnt++;
        }
    }
    path.pop_back();
    return;
}

node*kAncestor(node*root, int n, int k, int &cnt){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n){
        cnt++;
        return root;
    }
    node*left=kAncestor(root->left, n, k, cnt);
    node*right=kAncestor(root->right, n, k, cnt);
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(cnt==k && (left || right)){
        cnt++;
        return root;
    }
    if(left){
        cnt++;
        return left;
    }
    if(right){
        cnt++;
        return right;
    }
}

void kAncestor2(node*root, int n, vector<node*>&path){
    if(root==NULL){
        return;
    }
    if(root->data==n){
        path.push_back(root);
        return;
    }
    path.push_back(root);
    kAncestor2(root->left, n, path);
    kAncestor2(root->right, n, path);
    int size=path.size();
    if((path[size-1])->data==n){
        return;
    }
    path.pop_back();
}

void kAncestor3(node*root, int n, vector<node*>&path){
    if(root==NULL){
        return;
    }
    if(root->data==n){
        path.push_back(root);
        return;
    }
    cout<<"hello "<<root->data<<'\n';
    kAncestor3(root->right, n, path);
    if((path[0])->data==n){
        cout<<"h1 "<<root->data<<'\n';
        path.push_back(root);
        return;
    }
    kAncestor3(root->left, n, path);
    if((path[0])->data==n){
        path.push_back(root);
        return;
    }
}

pair<int, int> maxSumOfNonAdjacentNodes(node*root){
    if(root==NULL){
        pair<int, int>p=make_pair(0, 0);
        return p;
    }
    pair<int, int> left = maxSumOfNonAdjacentNodes(root->left);
    pair<int, int> right = maxSumOfNonAdjacentNodes(root->right);
    pair<int, int>p;

    // includeing
    p.first = root->data + left.second + right.second;

    // excluding
    p.second = max(left.first, left.second) + max(right.first, right.second);

    return p;
}

int main(){
    // inputs
    // 5 10 -1 2 -1 -1 15 -1 -1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    // 1 3 7 19 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1

    node*root=NULL;
    cout<<"buildTree(root)\n";
    root=buildTree(root);

    cout<<"longestPathSum(root).first\n";
    cout<<longestPathSum(root).first<<"\n\n";

    cout<<"longestPathSum2(root, p).first\n";
    pair<int, int>p = make_pair(root->data, 1);
    cout<<longestPathSum2(root, p).first<<"\n\n";

    // 1 3 7 19 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"lowestCommonAncestorOf2Nodes2(root, 11, 19)->data\n";
    cout<<lowestCommonAncestorOf2Nodes2(root, 11, 19)->data<<"\n\n";

    // 1 3 2 -1 -1 1 1 -1 -1 -1 -2 3 2 -1 -1 3 -1 -1 6 -1 5 -1 -1
    node*root2=NULL;
    cout<<"buildTree(root2)\n";
    root2=buildTree(root2);

    int cnt=0;
    vector<int>path;
    cout<<"kSumPath2(root2,6, cnt, path)\n";
    kSumPath2(root2,6, cnt, path);
    cout<<cnt<<"\n\n";

    // 1 3 7 19 -1 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cnt=0;
    cout<<"kAncestor(root, 19, 2, cnt)->data\n";
    int n;
    cin>>n;
    if(n==root->data || kAncestor(root, n, 2, cnt)==NULL)
        cout<<-1<<"\n\n";
    else{
        cnt=0;
        cout<< kAncestor(root, n, 2, cnt)->data<<"\n\n";
    }

    vector<node*>path2;
    cout<<"kAncestor2(root, 19, path2)\n";
    kAncestor2(root, n, path2);
    int size2=path2.size();
    if(size2==0 || root->data==n){
        cout<<-1<<"\n\n";
    }
    else
        cout<<path2[size2-2-1]->data<<"\n\n";

    // vector<node*>path3;
    // cout<<"kAncestor3(root, 19, path3)\n";
    // kAncestor3(root, n, path3);
    // int size3=path3.size();
    // if(size3==0 || root->data==n){
    //     cout<<-1;
    // }
    // else
    //     cout<<path3[2]->data<<"\n\n";
    
    cout<<"maxSumOfNonAdjacentNodes(root)\n";
    pair<int, int>ans=maxSumOfNonAdjacentNodes(root);
    cout<<max(ans.first, ans.second)<<"\n\n";

    return 0;
}

// hi