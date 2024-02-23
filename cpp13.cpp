/*  QUESTIONS
    https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549    
    https://www.codingninjas.com/codestudio/problems/occurrence-of-x-in-a-sorted-array_630456?leftPanelTab=1
    https://leetcode.com/problems/peak-index-in-a-mountain-array/

    HOMEWORK
    GOOD QUESTION
/**/find pivot element in a sorted and rotated array
*/

#include<bits/stdc++.h>
using namespace std;

void inputArray(int *a, int n){
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
}

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

pair<int, int> firstAndLastOccurence(int a[], int n, int key){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int tempFirst=-1;
    pair<int, int>p;
   
    while(s<=e){
        mid=s+(e-s)/2;
        if(key>a[mid]){
            s=mid+1;
        }
        else if(key<a[mid]){
            e=mid-1;
        }
        else{
            tempFirst=mid;
            e=mid-1;
        }
    }
    p.first=tempFirst;
    
    
    s=0;
    e=n-1;
    int tempLast=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(key>a[mid]){
            s=mid+1;
        }
        else if(key<a[mid]){
            e=mid-1;
        }
        else{
            tempLast=mid;
            s=mid+1;
        }
    }
    p.second=tempLast;

    int num= ( p.first!=-1 ) ? ( p.second-p.first+1 ) : ( 0 );
    cout<<"total number of occurence ->"<< num;
    cout<<"\n";

    return p;
}

int findPeakInMountainArray(int *a, int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        mid=s+(e-s)/2;
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
            return a[mid];
        }
        else if(a[mid]>a[mid+1]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

}

//what is wrong with it
// 5
// 1 2 3 2 -32
int findPeakInMountainArray2(int *a, int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        mid=s+(e-s)/2;
        if(a[mid]<a[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    // return a[mid];
    return a[s];
}

// find pivot in an array
int getPivot(int a[], int n){   // bad approach     not valid if pivot is first or last element of an array
    int s=0, e=n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]<a[mid-1] && (mid+1<n && a[mid]<a[mid+1])){
            return mid;
        }
        else{
            if(a[mid]>=a[0]){       // left subarray
                s=mid+1;
            }
            else{                   // right subarray
                e=mid-1;
            }
        }
    }
    return -1;
}

// GOOD QUESTION
int getPivot2(int a[], int n){  // good approach
    int s=0, e=n-1;
    while(s<e){
        int mid = s+ (e-s)/2;
        if(a[mid]>=a[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    // can be done by any of the below line
    return s;
    return e;
}

int main(){

    int a[100000];
    int n;

    cin>>n;
    inputArray(a,n);
    int key;
    cin>>key;
    pair<int, int>p=firstAndLastOccurence(a, n, key);
    cout<<p.first<<' '<<p.second<<'\n';
    cout<<'\n';

    cin>>n;
    inputArray(a,n);
    cout<<findPeakInMountainArray(a,n);
    cout<<findPeakInMountainArray2(a,n);
    cout<<'\n';




    return 0;
}