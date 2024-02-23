#include<bits/stdc++.h>
using namespace std;

void copyString(string s1, string &s2){
    for(int i=0; i<s1.length(); i++){
        s2.append(1, s1[i]);
    }
}

vector<string> letterCombination(string digits, string output, vector<string>&ans, int i, string mapping[]){
    if(i==digits.length()){
        ans.push_back(output);
        return ans;
    }

    int d=digits[i] -'0';

    for(int j=0; j<mapping[d].length(); j++){
        output.push_back(mapping[d][j]);
        letterCombination(digits, output, ans, i+1, mapping);
        output.pop_back();      //backtracking
    }

    return ans;
}

int main(){

    string s1;
    cin>>s1;
    string s2;
    vector<string>a;
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>ans = letterCombination(s1, s2, a, 0, mapping);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}