#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> permutation(vector<int> v1, vector<int> v2, vector<vector<int>>&ans, int i){
    if(i==v1.size()){
        ans.push_back(v2);
        return ans;
    }
    permutation(v1, v2, ans, i+1);
    v2.push_back(v1[i]);
    permutation(v1, v2, ans, i+1);
    return ans;
}

void permutation2(vector<int> v1, vector<int> v2, vector<vector<int>>&ans, int i){
    if(i==v1.size()){
        ans.push_back(v2);
        return;
    }
    permutation2(v1, v2, ans, i+1);
    v2.push_back(v1[i]);
    permutation2(v1, v2, ans, i+1);
    return;
}

vector<string> subsequences(string s1, string s2, vector<string>&ans, int i){
    if(i==s1.length()){
        if(s2.length()>0)
            ans.push_back(s2);
        return ans;
    }
    subsequences(s1, s2, ans, i+1);
    // string s2_2[s2.length()+1];
    // int j=0;
    // for(; j<s2.length(); j++){
    //     s2_2[j]=s2[j];
    // }
    // s2_2[j]=s1[i];
    // subsequences(s1, s2_2, ans, i+1);
    s2.push_back(s1[i]);
    subsequences(s1, s2, ans, i+1);
    return ans;
}

int main(){

    vector<int> v1;
    int n;
    cin>>n;
    int value;
    for(int i=0; i<n; i++){
        cin>>value;
        v1.push_back(value);
    }
    vector<int>v2;
    vector<vector<int>>a;
    vector<vector<int>>ans=permutation(v1, v2, a, 0);
    for(int i=0; i<ans.size(); i++){
        cout<<"{ ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<"}  ";
    }
    cout<<endl;

    vector<vector<int>>ans2;
    permutation2(v1, v2, ans2, 0);
    for(int i=0; i<ans2.size(); i++){
        cout<<"{ ";
        for(int j=0; j<ans2[i].size(); j++){
            cout<<ans2[i][j]<<' ';
        }
        cout<<"}  ";
    }
    cout<<endl;

    // subsequences and subset are kind of same

    string s1;
    cin>>s1;
    string s2="";
    vector<string>a3;
    vector<string>ans3=subsequences(s1, s2, a3, 0);
    for(int i=0; i<ans3.size(); i++){
        cout<<ans3[i]<<' ';
    }
    cout<<endl;


    return 0;

}