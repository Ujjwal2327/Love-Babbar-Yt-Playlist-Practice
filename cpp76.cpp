#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(vector<int>&arr, int k){      //time complexity-O((n^2)log(n))    space complexity-O(n^2)
    int n = arr.size();
    vector<int>sums;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            sums.push_back(sum);
        }
    }
    sort(sums.begin(), sums.end());
    return sums[sums.size()-k];
}

int kthLargestSum2(vector<int>&arr, int k){     //time complexity-O((n^2)log(k))    space complexity-O(k)
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>>minHeap;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[i];
            if(minHeap.size()<k){
                minHeap.push(sum);      //log(k)
            }
            else{                       //log(k)
                if(sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

pair<int, int>minElement(vector<int>a){
    int element = INT_MAX;
    int index;
    for(int i=0; i<a.size(); i++){
        if(a[i] < element){
            element = a[i];
            index = i;
        }
    }
    return {element, index};
}

int kthLargestSum3(vector<int>&arr, int k){     //time complexity-O((n^2)*k)    space complexity-O(k)
    int n = arr.size();
    vector<int>mini;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[i];
            if(mini.size()<k){
                mini.push_back(sum);    //O(1)
            }
            else{                       //O(k)
                pair<int, int>p = minElement(mini);
                if(sum > p.first){
                    mini[p.second] = sum;
                }
            }
        }
    }
    
    // find max element in mini
    int ans = mini[0];
    for(int i=1; i<mini.size(); i++){
        ans = max(ans, mini[i]);
    }
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>kArrays, int k){      //time complexity-O((n*k)*log(n*k)) 
    vector<int>ans;
    for(int i=0; i<k; i++){
        for(int j=0; j<kArrays[i].size(); j++){
            ans.push_back(kArrays[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int i, int j){
        this->data = data;
        row = i;
        col = j;
    }
};

class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays2(vector<vector<int>>kArrays, int k){     //time complexity-O((n*k)*log(k))
    vector<int>ans;
    priority_queue<node*, vector<node*>, compare>minHeap;
    // insert first element of all k arraya
    for(int i=0; i<k; i++){     // O(klog(k))
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while(!minHeap.empty()){    // O((n*k)*log(k))
        node*temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);
        int i = temp->row;
        int j = temp->col;
        if(j+1 < kArrays[i].size()){
            node* nextTemp = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(nextTemp);
        }
    }
    return ans;
}

class compare2{
    public:
    bool operator()(node a, node b){
        return a.data > b.data;
    }
};

vector<int> mergeKSortedArrays3(vector<vector<int>>kArrays, int k){     //time complexity-O((n*k)*log(k))
    vector<int>ans;
    priority_queue<node, vector<node>, compare2>minHeap;
    // insert first element of all k arraya
    for(int i=0; i<k; i++){     // O(klog(k))
        node temp = node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while(!minHeap.empty()){    // O((n*k)*log(k))
        node temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp.data);
        int i = temp.row;
        int j = temp.col;
        if(j+1 < kArrays[i].size()){
            node newTemp = node(kArrays[i][j], i, j+1);
            minHeap.push(newTemp);
        }
    }
    return ans;
}

class listNode{
    public:
    int data;
    listNode*next;

    listNode(int data){
        this->data = data;
        next = NULL;
    }
};

class compare3{
    public:
    bool operator()(listNode*a, listNode*b){
        return (a->data > b->data);
    }
};

listNode* mergeKSortedLists(vector<listNode*>listArray, int k){
    priority_queue<listNode*, vector<listNode*>, compare3>minHeap;
    for(int i=0; i<k; i++){
        minHeap.push(listArray[i]);
    }

    listNode*curr = new listNode(-1);
    listNode*ans = curr;

    while(!minHeap.empty()){
        listNode*temp = minHeap.top();
        curr->next = temp;
        curr = curr->next;
        minHeap.pop();
        if(temp->next)
            minHeap.push(temp->next);
    }
    return (*ans).next;
}

int main(){



    return 0;
}