/*  QUESTIONS
    swap alternates in an array
    https://www.codingninjas.com/codestudio/problems/find-unique_625159
    https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
    https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149
    https://www.codingninjas.com/codestudio/problems/pair-sum_697295
    https://www.codingninjas.com/codestudio/problems/sort-array-of-0s-and-1s_2656186?leftPanelTab=0
    
    HOMEWORK
    https://leetcode.com/problems/unique-number-of-occurrences
    https://leetcode.com/problems/find-all-duplicates-in-an-array/
/**/https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028
    https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055
*/

#include<bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n){
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void swapAlternate(int a[], int n){
    for(int i=0; i+1<n; i+=2){
        swap(a[i], a[i+1]);
    }
}

// GOOD QUESTION
int findUnique(int a[], int n){
    // 0 ^ a = a
    // a ^ a = 0
    int ans=0;
    for(int i=0; i<n; i++){
        ans=ans^a[i];
    }
    return ans;
}

bool uniqueNoOfOccurences(int a[], int n){
    int cnts[100000]={0};  //count
    int isUnique[100000]={0};  //comparing the count

    for(int i=0; i<n; i++){
        cnts[a[i]]++;
    }

    printArray(cnts, 6);

    for(int i=0; i<n; i++){
        if(isUnique[cnts[i]]==1 && cnts[i]!=0){
            return false;
        }
        isUnique[cnts[i]]=1;
    }
    return true;
}

int findDuplicate(int a[], int n){
    int cnts[100000]={0};  //count

    for(int i=0; i<n; i++){
        cnts[a[i]]++;
    }
    
    for(int i=1; i<100000; i++){
        if(cnts[i]==2)
            return i;
    }
}

int findDuplicate2(int a[], int n){
    int ans=0;
    for(int i=0; i<n; i++){
        ans^=i;
    }
    for(int i=0; i<n; i++){
        ans^=a[i];
    }
    return ans;
}

// find all duplicate of an array leet code

void intersection(int a[], int m, int b[], int n){  //array are sorted in non- decreasing order
    int i=0, j=0, k=0;
    int ans[100000];
    while(i<m && j<n){
        if(a[i]==b[j]){
            ans[k++]=a[i++];
            j++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            i++;
        }
    }

    if(k==0){
        cout<<"no intersection\n";
        return;
    }

    for(int i=0; i<k; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

void pairSum(int a[], int n, int s){        // not sorted ans
    pair<int, int> b[100000];
    int k=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]+a[j]==s){
                b[k].first=min(a[i], a[j]);
                b[k].second=max(a[i], a[j]);
                k++;
            }
        }
    }

    for(int i=0; i<k; i++){
        cout<<b[i].first<<','<<b[i].second<<"  ";
    }
    cout<<'\n';
}

vector<vector<int>> pairSum2(int a[], int n, int s){    // sorted ans
    vector<vector<int>>v;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]+a[j]==s){
                vector<int>temp;
                temp.push_back(min(a[i], a[j]));
                temp.push_back(max(a[i], a[j]));
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

void tripletOfSum(int a[], int n, int s){
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(a[i]+a[j]+a[k]==s){
                    cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<"  ";
                }
            }
        }
    }
    cout<<'\n';
}

// optimise solution for tiplet of given sum

int main(){

    int a[100000];
    int n;
    cin>>n;
    inputArray(a,n);
    swapAlternate(a,n);
    printArray(a,n);
    cout<<'\n';

    cin>>n;
    inputArray(a,n);
    cout<<findUnique(a, n)<<'\n';
    cout<<'\n';

    cout<<uniqueNoOfOccurences(a, n)<<'\n';
    cout<<'\n';

    cout<<findDuplicate(a, n)<<'\n';
    cout<<findDuplicate2(a, n)<<'\n';
    cout<<'\n';

    int m;
    int b[100000];
    cin>>m>>n;
    inputArray(a,m);
    inputArray(b,n);
    printArray(a,m);
    printArray(b,n);
    intersection(a,m,b,n);
    cout<<'\n';

    cin>>n;
    inputArray(a,n);
    pairSum(a,n,5);
    vector<vector<int>>v=pairSum2(a,n,5);
    for(int i=0; i<v.size(); i++){
        // for(int j=0; j<v[0].size(); j++){
            cout<<v[i][0]<<',';
            cout<<v[i][1];
        // }
        cout<<"  ";
    }
    cout<<'\n';

    cin>>n;
    inputArray(a,n);
    tripletOfSum(a,n,5);


    

    /*
    time complexity-
        how much time it will take
        to find whether the particular algorithm is fast or slow
        worst case time complexity O() with increasing order
            O{1}        constant time
            O{log n}    logarithamic time
            O(n^(1/2))
            O{n}        linear time
            O{n log n}
            O{n^2}      quatratic time
            O{n^3}      cubic time
            O{2^n}
            O{n!}
            O{n^n}

    for seperate statements,    +   add
    for nested statements,      *   multiply

    10^8 operation rule, use to determine, which algo should we use to solve a ques
    modern machine can perform 10^8 operations per second

    Let n be the main input variable in the problem.
        If n ≤ 12, the time complexity can be O(n!).
        If n ≤ 25, the time complexity can be O(2^n).
        If n ≤ 100, the time complexity can be O(n^4).
        If n ≤ 500, the time complexity can be O(n^3).
        If n ≤ 10^4, the time complexity can be O(n^2).
        If n ≤ 10^6, the time complexity can be O(n log n).
        If n ≤ 10^8, the time complexity can be O(n).
        If n > 10^8, the time complexity can be O(log n) or O(1).


    space complexity- how much memory it will take memory to run a program
        for(int i=0; i<n; i++){         // space complexity-O(n), not O(n^2)
            vector<int>arr(n);  
        }
    */

    return 0;
}