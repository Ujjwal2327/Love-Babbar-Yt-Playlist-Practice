#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<int>q){
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout<<'\n';
}

void reverse(queue<int>&q){     //time complexity-O(n)  space complexity-O(n)
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void reverse2(queue<int>&q, queue<int>&q2){     //time complexity-O(n)  space complexity-O(n)
    if(q.empty()){
        return;
    }
    int item=q.front();
    q.pop();
    reverse2(q, q2);
    q2.push(item);
}

void printVector(vector<int>v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}

vector<int> firstNegIntInEveryWinOfSizek(int *arr, int n, int k){   // what is its time complexity
    vector<int>ans;
    int value=0;
    for(int i=0; i<k; i++){
        if(arr[i]<0){
            value=arr[i];
            break;
        }
    }
    ans.push_back(value);
    queue<int>q;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
    }
    for(int i=1; i<=n-k; i++){
        int frontValue=q.front();
        q.pop();
        q.push(arr[i+k-1]);
        if(frontValue<0){
            int j=i;
            value=0;
            while(j<i+k){
                if(arr[j]<0){
                    value=arr[j];
                    break;
                }
                j++;
            }
            ans.push_back(value);
            // cout<<"value "<<value<<'\n';
        }
        else{
            ans.push_back(value);
        }
    }
    return ans;
}

vector<int> firstNegIntInEveryWinOfSizek2(int *arr, int n, int k){   // what is its time complexity
    vector<int>ans;
    int value=-1;
    for(int i=0; i<k; i++){
        if(arr[i]<0){
            value=i;
            break;
        }
    }
    ans.push_back(arr[value]);
    queue<int>q;
    q.push(value);
    for(int i=1; i<=n-k; i++){
        if(q.front()==-1){
            if(arr[i+k-1]<0){
                q.pop();
                q.push(i+k-1);
            }
        }
        else{
            if(q.front()==i-1){
                for(int j=i; j<i+k; j++){
                    if(arr[j]<0){
                        q.pop();
                        q.push(arr[j]);
                        break;
                    }
                }
            }
        }
        ans.push_back(arr[q.front()]);
    }
    return ans;
}

vector<int> firstNegIntInEveryWinOfSizek3(int *arr, int n, int k){
    vector<int>ans;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    for(int i=0; i<=n-k; i++){
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            while(q.front()<i){
                q.pop();
            }
            if(q.front()<i+k){
                ans.push_back(arr[q.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
    }
    return ans;
}

int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    printQueue(q);

    reverse(q);
    printQueue(q);

    queue<int>q2;
    reverse2(q, q2);
    printQueue(q2);
    printQueue(q);

    int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int>ans = firstNegIntInEveryWinOfSizek3(arr, 8, 3);

    printVector(ans);

    return 0;
}