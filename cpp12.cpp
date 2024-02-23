/*  QUESTIONS
    binary search
*/

#include<bits/stdc++.h>
using namespace std;

int binary(int a[], int size, int key){
    int s=0, e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main()
{
    /*
    binary search
        only in monotonic functions (either increasing or decreasing)
    */

    int n;
    cin>>n;
    int a[100000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<binary(a,n,key)<<'\n';


    return 0;
}