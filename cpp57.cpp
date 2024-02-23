#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>names, int n){
    stack<int>s;
    for(int i=0; i<n; i++){
        s.push(i);
    }
    while(s.size()!=1){
        int name1=s.top();
        s.pop();
        int name2=s.top();
        s.pop();
        if(names[name1][name2]){    //if name1 knows name2
            s.push(name2);
        }
        else{
            s.push(name1);
        }
    }
    int name=s.top();
    for(int i=0; i<n; i++){
        if(i!=name && names[name][i]==1){
            return -1;
        }
    }
    for(int i=0; i<n; i++){
        if(i!=name && names[i][name]==0){
            return -1;
        }
    }
    return name;
}

vector<int> nextSmallerElementIndex(int *arr, int n){
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        int item = arr[i];
        if(s.empty()){
            ans[i]=n;
            s.push(i);
        }
        else{
            if(item > arr[s.top()]){
                ans[i]=s.top();
            }
            else{
                while(!s.empty() && item <= arr[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    ans[i]=n;
                }
                else{
                    ans[i]=s.top();
                }
            }
            s.push(i);
        }
    }
    return ans;
}

vector<int> prevSmallerElementIndex(int arr[], int n){
    stack<int>s;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        int item = arr[i];
        if(s.empty()){
            ans[i]=-1;
            s.push(i);
        }
        else{
            if(item > arr[s.top()]){
                ans[i]=s.top();
            }
            else{
                while(!s.empty() && item <= arr[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=s.top();
                }
            }
            s.push(i);
        }
    }
    return ans;
}

int largestRectangleInHistogram(int *heights, int n){
    vector<int>prevSmallerVector = prevSmallerElementIndex(heights, n);
    vector<int>nextSmallerVector = nextSmallerElementIndex(heights, n);
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        int length=heights[i];
        int breath=nextSmallerVector[i]-prevSmallerVector[i]-1;
        ans=max(ans, length*breath);
    }
    return ans;
}

int maxRectangleWithAll1s(int matrix[][100], int m, int n){     //space complexity-O(n), time complexity-O(m*n)
    int ans=0;
    for(int i=0; i<m; i++){
        if(i!=0){
            for(int j=0; j<n; j++){
                if(matrix[i][j]!=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int area=largestRectangleInHistogram(matrix[i], n);
        ans=max(ans, area);
    }
    return ans;
}

int main(){

    vector<vector<int>>names;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int>namesRow;
        for(int j=0; j<n; j++){
            int value;
            cin>>value;
            namesRow.push_back(value);
        }
        names.push_back(namesRow);
    }
    cout<<'\n';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<names[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';

    cout<<celebrity(names, n)<<'\n';

    int m;
    cin>>m>>n;
    int matrix[100][100];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
 
    cout<<'\n';
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<< maxRectangleWithAll1s(matrix, m, n)<<'\n';

    /*
    HOMEWORK
    more approaches for celebrity problem
    */

    return 0;
}