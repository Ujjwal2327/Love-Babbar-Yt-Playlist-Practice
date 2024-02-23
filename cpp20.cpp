/*  QUESTIONS
    reverse an array
    https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298
    https://leetcode.com/problems/merge-sorted-array/
    https://leetcode.com/problems/move-zeroes/

*/

#include<bits/stdc++.h>
using namespace std;

void reverse_array(){
    int a[5]={11,7,3,12,4};
    int i,j;
    // int sizea=a.size();
    for(i=0 ,j=4; i<j; i++, j--){
        swap(a[i],a[j]);
    }
    for(i=0; i<5; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void reverse_array_after_nth_position(int n){
    array <int,5>a={11,7,3,12,4};
    int i,j;
    // int sizea=a.size();
    for(i=n+1 ,j=a.size()-1; i<j; i++, j--){
        swap(a[i],a[j]);
    }
    for(i=0; i<5; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void mergesortedarray(){
    array<int,5>a={1,3,5,7,9};  
    array<int,6>b={1,2,3,4,5,6};
    array<int,100>c;
    int i=0, j=0, k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<a.size()){
        c[k++]=a[i++];
    }
    while(j<b.size()){
        c[k++]=b[j++];
    }
    for(int i=0; i<a.size()+b.size(); i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}

void movezeroes(){
    array<int,9>a={5,2,3,1,0,0,0,3,12};
    int i=0, j=1;
    while(i<9 && j<9){
        if(a[i]==0 && a[j]==0){
            j++;
        }
        else if(a[i]==0 && a[j]!=0){
            swap(a[i],a[j]);
            i++;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void movezeroes2(){
    array<int,9>a={5,2,3,1,0,0,0,3,12};
    int i=0, j=0;
    // 1st non-zero value should come to 0th index and so on
    // nth non-zero value should come to n-1th index
    while(i<a.size() && j<a.size()){
        if(a[j]!=0){
            swap(a[i],a[j]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void movezeroes3(){
    array<int,9>a={5,2,3,1,0,0,0,3,12};
    int i=0, j=0;
    // 1st non-zero value should come to 0th index and so on
    // nth non-zero value should come to n-1th index
    while(i<a.size() && j<a.size()){
        if(a[j]!=0){
            a[i]=a[j];
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    while(i<a.size()){
        a[i]=0;
        i++;
    }
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    reverse_array();

    int n;
    cin>>n;
    // reverse the array        coding ninja
    reverse_array_after_nth_position(n);

    // int a[5]={1,2,3,4,5};
    array<int,100>a={10,20,30,40,50};
    int sizea=a.size();     //time complexity-O(1)
    cout<<sizea<<'\n';
    // cout<<a.size();

    mergesortedarray();

    movezeroes();   //leetcode
    movezeroes2();
    movezeroes3();

    return 0;
}