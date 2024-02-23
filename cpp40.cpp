#include<bits/stdc++.h>
using namespace std;

void ratInAMaze(string output, vector<string>&ans, vector<vector<int>>&a, int n, int i=0, int j=0){
    if(a[i][j]==0){
        return;
    }

    if(i==n-1 && j==n-1){
        ans.push_back(output);
        return;
    }

    if(i>0){
        output.push_back('U');
        a[i][j]=0;
        ratInAMaze(output, ans, a, n, i-1, j);
        a[i][j]=1;
        output.pop_back();
    }
    if(i<n-1){
        a[i][j]=0;
        output.push_back('D');
        ratInAMaze(output, ans, a, n, i+1, j);
        a[i][j]=1;
        output.pop_back();
    }
    if(j>0){
        a[i][j]=0;
        output.push_back('L');
        ratInAMaze(output, ans, a, n, i, j-1);
        a[i][j]=1;
        output.pop_back();
    }
    if(j<n-1){
        a[i][j]=0;
        output.push_back('R');
        ratInAMaze(output, ans, a, n, i, j+1);
        a[i][j]=1;
        output.pop_back();
    }
}

int main(){

    vector<vector<int>>a;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int>v;
        for(int j=0; j<n; j++){
            int value;
            cin>>value;
            v.push_back(value);
        }
        a.push_back(v);
    }

    vector<string>ans;
    string s;
    ratInAMaze(s, ans, a, n, 0, 0);

    sort(ans.begin(), ans.end());

    for(int i=0; i<n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';


    return 0;
}