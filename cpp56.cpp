#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>&arr){
    vector<int>ans=arr;
    stack<int>st;
    st.push(-1);
    int i= arr.size()-1;
    for(; i>=0; i--){
        if(st.top()<arr[i]){
            ans[i]=st.top();
            st.push(arr[i]);
        }
        else{
            stack<int>st2;
            while(st.top()>=arr[i]){
                st2.push(st.top());
                st.pop();
            }
            ans[i]=st.top();
            while(!st2.empty()){
                st.push(st2.top());
                st2.pop();
            }
            st.push(arr[i]);
        }
    }
    return ans;
}

vector<int> nextSmallerElement2(vector<int>arr, int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        int item = arr[i];
        if(item > s.top()){
            ans[i]=s.top();
        }
        else{
            while(item <= s.top()){
                s.pop();
            }
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

vector<int> nextSmallerElementIndex(vector<int>arr, int n){
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

vector<int> prevSmallerElement(vector<int>arr, int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0; i<n; i++){
        int item = arr[i];
        if(item > s.top()){
            ans[i]=s.top();
        }
        else{
            while(item <= s.top()){
                s.pop();
            }
            ans[i]=s.top();
        }
        s.push(item);
    }
    return ans;
}

vector<int> prevSmallerElementIndex(vector<int>arr, int n){
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

int largestRectangleInHistogram(vector<int>&heights){
    int n=heights.size();
    vector<int>prevSmallerVector = prevSmallerElementIndex(heights, n);
    vector<int>nextSmallerVector = nextSmallerElementIndex(heights, n);
    int ans=INT_MIN;
    for(int i=0; i<heights.size(); i++){
        int length=heights[i];
        int breath=nextSmallerVector[i]-prevSmallerVector[i]-1;
        ans=max(ans, length*breath);
    }
    return ans;
}

void print(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n\n";
}

int main(){


    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';

    int n=arr.size();

    vector<int>ans=nextSmallerElementIndex(arr, n);
    for(int i=0; i<arr.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';

    vector<int>ans2=prevSmallerElementIndex(arr, n);
    for(int i=0; i<arr.size(); i++){
        cout<<ans2[i]<<' ';
    }
    cout<<'\n';

    vector<int>heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    cout << largestRectangleInHistogram(heights)<<'\n';
    
    return 0;
}