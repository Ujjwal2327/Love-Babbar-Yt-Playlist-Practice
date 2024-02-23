#include<bits/stdc++.h>
using namespace std;

void generatePermutations(string s, vector<string> &ans, int i){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }

    for(int j=0; j<s.length(); j++){
        swap(s[i], s[j]);
        generatePermutations(s, ans, i+1);
        swap(s[i], s[j]);
    }

}


int main(){

    string s;
    cin>>s;
    vector<string> ans;
    generatePermutations(s, ans, 0);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;



    return 0;
}