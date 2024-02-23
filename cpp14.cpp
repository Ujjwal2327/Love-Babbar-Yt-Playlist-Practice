/*  QUESTIONS
    GOOD QUESTION
    search pivot index in a sorted and rotated array having distinct values
    https://www.codingninjas.com/codestudio/problems/630450
    https://leetcode.com/problems/sqrtx/
    sqrt of a number with more precision after decimal point

    HOMEWORK
    read about book allocation problem
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

int findHighPivot(int a[], int n){      // bad approach     not valid if pivot is first or last element of an array
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]>=a[mid+1] && a[mid]>=a[mid-1]){
            return mid;
        }
        else if(a[mid]<a[0]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}

int findHighPivot2(int a[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]<=a[n-1]){    //right subarray
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return e;
}

int findLowPivot(int a[], int n){       // bad approach     not valid if pivot is first or last element of ana array
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]<=a[mid+1] && a[mid]<=a[mid-1]){
            return mid;
        }
        else if(a[mid]<a[0]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}

// not true in 1 2 array of 2 size
int findLowPivot2(int a[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]>=a[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
    // return e;    //both are true
}

int binarySearch(int a[], int s, int e, int key){
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(key>a[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

// there are 2 more approaches
// GOOD QUESTION
int searchInRotatedSortedArray(int a[], int n, int key){
    // if >a[0] 0 to pivot-1
    // if <a[0] pivot to n-1
    int pivot=findLowPivot(a, n);
    if(key>=a[pivot] && key<=a[n-1]){
        return binarySearch(a, pivot, n-1, key);
    }
    else{
        return binarySearch(a, 0, pivot-1, key);
    }
}

int squareRoot(int n){
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e){
        long long int mid=s+(e-s)/2;        // ise bhi long long int bnana pdega
        long long int sq=mid*mid;
        if(sq==n){
            return mid;
        }
        else if(sq<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

float squareRoot2(int n){
    float curr = squareRoot(n);
    float ans = curr;
    float factor = 1;
    for(int i=0; i<7; i++){
        factor = factor/10;
        int s=0, e=9;
        float temp = ans;
        while(s<=e){
            int mid = (s+e)/2;
            curr = ans + mid*factor;
            double prod = curr*curr;
            if(prod==n){
                return curr;
            }
            else if(prod>n){
                e=mid-1;
            }
            else{
                temp=curr;
                s=mid+1;
            }
        }
        ans = temp;
    }
    return ans;
}

int main(){

    int a[100000];
    int n;
    cin>>n;
    inputArray(a,n);
    cout<<findHighPivot(a,n)<<'\n';
    cout<<findHighPivot2(a,n)<<'\n';
    cout<<findLowPivot(a,n)<<'\n';
    cout<<findLowPivot2(a,n)<<'\n';
    cout<<'\n';

    cin>>n;
    inputArray(a,n);
    int key;
    cin>>key;
    cout << searchInRotatedSortedArray(a,n,key) <<'\n';
    cout<<'\n';

    cin>>n;
    cout<<squareRoot(n)<<'\n';
    cout<<squareRoot2(n)<<'\n';

    return 0;

    /*
    INPUTS
    2
    1 2
    5
    7 9 1 3 5
    1
    37
    */
}