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

bool searchInBST2(node*root, int value){    //avg time complexity- O(h)      worst time complexity- O(n)
    if(root==NULL)
        return 0;
    
    node*temp=root;
    while(temp!=NULL){
        if(temp->data==value)
            return 1;
        if(temp->data > value)
            temp=temp->left;
        if(temp->data < value)
            temp=temp->right;
    }
    return false;
}

void inorder(node*root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
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

node* inorderPredecessor(node*root, int key){
    if(root==NULL)
        return NULL;
    
    if(root->data==key){
        if(root->left){
            node*temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            return temp;
        }
        return NULL;
    }
    
    node*left = inorderPredecessor(root->left, key);
    node*right = inorderPredecessor(root->right, key);

    if(root->right){
        if(root->right->data==key){
            node*temp=root->right->left;
            if(temp){
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                return temp;
            }
            return root;
        }
        if(root->right->left){
            if(root->right->left->data==key)
                return root;
        }
    }

    if(root->left){
        if(root->left->data==key){
            if(root->left->left){
                node*temp=root->left->left;
                while(temp->right)
                    temp=temp->right;
                return temp;
            }
        }
    }

    if(left)
        return left;
    
    if(right)
        return right;
        
    if(left==NULL && right==NULL)
        return NULL;
}

node* inorderSuccessor(node*root, int key){
    if(root==NULL)
        return NULL;
    
    if(root->data==key)
        return root;
    
    if(root->left){
        if(root->left->data==key){
            if(root->left->left){
                node*temp=root->left->left;
                while(temp->right)
                    temp=temp->right;
                return temp;
            }
            return root;
        }
    }

    if(root->right){
        if(root->right->data==key){
            if(root->right->left){
                node*temp=root->right->left;
                while(temp->right)
                    temp=temp->right;
                return temp;
            }
            return root;
            
        }
        if(root->right){
            if(root->right->left){
                node*temp=root->right;
                while(temp->left){
                    if(temp->data==key){
                        return root;
                    }
                    temp=temp->left;
                }
            }
        }
    }

    node*left=inorderPredecessor(root->left)

}

void printSuccessors(node*&root, node*temp){
    if(root==NULL)
        return;
    
    printSuccessors(root, temp->left);
    cout<<inorderPredecessor(root, temp->data)->data<<" ";
    printSuccessors(root, temp->right);
}

node* deleteInBST(node*root, int key){
    if(root==NULL)
        return NULL; 

    if(root->data==key){
        // 0 child
        if(root->left==NULL && root->right==NULL)
            delete root;
            return NULL;

        // 1 child
        if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right==NULL){   
            node*temp=root->left;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left && root->right){
            int maxi = getMax(root->left);
            root->data=maxi;
            root->left = deleteInBST(root->left, maxi);
            return root;
        }
    }

    if(root->data>key)
        root->left=deleteInBST(root->left, key);
    else
        root->right=deleteInBST(root->right, key);
    return root; 
}

int main(){

    node*root=NULL;

    // 20 10 30 15 40 25 5 1 -1
    // 100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1
    cout<<"createBST-> "<<'\n';
    createBST(root);
    cout<<'\n';
    cout<<"printLevelOrderTraversal-> "<<'\n';
    printLevelOrderTraversal(root);
    cout<<'\n';

    int value;
    cin>>value;
    cout<<"searchInBST-> "<<searchInBST(root, value)<<"\n\n";
    cout<<"searchInBST2-> "<<searchInBST2(root, value)<<"\n\n";
    
    // inorder of BST is always sorted
    cout<<"inorder-> "<<' ';
    inorder(root);
    cout<<"\n\n";

    cout<<"preorder-> "<<' ';
    preorder(root);
    cout<<"\n\n";

    cout<<"postorder-> "<<' ';
    postorder(root);
    cout<<"\n\n";

    cout<<"getMin-> "<<getMin(root)<<"\n\n";
    cout<<"getMax-> "<<getMax(root)<<"\n\n";

    
    cout<<inorderPredecessor(root, 5)->data<<" ";
    cout<<inorderPredecessor(root, 7)->data<<" ";
    cout<<inorderPredecessor(root, 9)->data<<" ";
    cout<<inorderPredecessor(root, 10)->data<<" ";
    cout<<inorderPredecessor(root, 15)->data<<" ";
    cout<<inorderPredecessor(root, 20)->data<<" ";
    cout<<inorderPredecessor(root, 25)->data<<" ";
    cout<<inorderPredecessor(root, 30)->data<<" ";
    cout<<inorderPredecessor(root, 40)->data<<" ";
    cout<<inorderPredecessor(root, 45)->data<<" ";
    cout<<inorderPredecessor(root, 50)->data<<" ";
    cout<<inorderPredecessor(root, 100)->data<<" ";
    cout<<inorderPredecessor(root, 120)->data<<" ";
    // printSuccessors(root, root);

    deleteInBST(root, 40);
    cout<<"printLevelOrderTraversal-> "<<'\n';
    printLevelOrderTraversal(root);
    cout<<'\n';

    /*
    HOMEWORK
    how to find inorder predecessor
    how to find inorder successor
    */
    // 100 20 120 10 30 5 15 25 40 1 7 50 9 45 -1 5 

    return 0;
}