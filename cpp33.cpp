#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i=0){
    if(n==0)
        return true;
    if(i==n-1){
        return true;
    }
    if(arr[i]>arr[i+1])
        return false;
    i++;
    return isSorted(arr, n,i);
}

bool isSorted2(int arr[], int n){
    if(n==0)
        return true;
    if(arr==&arr[n-1]){
        return true;
    }
    if(*(arr)>*(arr+1))
        return false;
    arr++;
    // isSorted(arr, n);        // WHY IS IT WORKING
    return isSorted(arr, n-1);
}

bool isSorted3(int arr[], int n){
    if(n==0)
        return true;
    if(arr==&arr[n-1]){         // size is 1
        return true;
    }
    if(arr[0]>arr[1])
        return false;
    arr++;
    return isSorted3(arr, n-1);
}

bool isSorted4(int arr[], int n){
    if(n==0 || n==1)
        return true;
    if(arr[0]>arr[1])
        return false;
    arr++;
    return isSorted4(arr, n-1);
}

int sum(int arr[], int n){
    if(n==0){
        return 0;
    }
    int d=arr[0];
    arr++;
    return sum(arr, n-1)+d;
}

bool linearSearch(int arr[], int n, int key){
    if(n==0){
        return false;
    }
    if(key==arr[0])
        return true;
    linearSearch(arr+1, n-1, key);      //return krna is also important, vrna pta kse chalega
                                        //yha code thik chl rha hai due to compiler, pr vse ye code glt hai
}

bool linearSearch2(int arr[], int n, int key){
    if(n==0){
        return false;
    }
    if(key==arr[0])
        return true;
    return linearSearch2(arr+1, n-1, key);
}

bool binarySearch(int arr[], int n, int s, int e,int key){
    if(s>e)
        return false;

    int mid=s+(e-s)/2;
    if(key==arr[mid])
        return true;
    else if(key>arr[mid]){
        s=mid+1;
        return binarySearch(arr, n, s, e, key);
    }
    else{
        e=mid-1;
        return binarySearch(arr, n, s, e, key);
    }
}

bool binarySearch2(int arr[], int s, int e,int key){
    if(s>e)
        return false;

    int mid=s+(e-s)/2;
    if(key==arr[mid])
        return true;
    else if(key>arr[mid]){
        s=mid+1;
        return binarySearch2(arr, s, e, key);
    }
    else{
        e=mid-1;
        return binarySearch2(arr, s, e, key);
    }
}

int binarySearch3(int arr[], int s, int e,int key){
    if(s>e)
        return -1;

    int mid=s+(e-s)/2;
    if(key==arr[mid])
        return mid;
    else if(key>arr[mid]){
        s=mid+1;
        return binarySearch3(arr, s, e, key);
    }
    else{
        e=mid-1;
        return binarySearch3(arr, s, e, key);
    }
}

int main(){

    int n;
    cin>>n;
    cout<<"\n";
    int arr[100000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<isSorted(arr,n)<<'\n';
    cout<<isSorted2(arr,n)<<'\n';
    cout<<isSorted3(arr,n)<<'\n';
    cout<<isSorted4(arr,n)<<'\n';
    cout<<"\n";
    cout<<sum(arr,n)<<'\n';
    cout<<"\n";
    int key;
    cin>>key;
    cout<<linearSearch(arr,n,key)<<'\n';
    cout<<linearSearch2(arr,n,key)<<'\n';
    cout<<"\n";
    cout<<binarySearch(arr,n,0,n-1,key)<<'\n';      // array should be sorted
    cout<<binarySearch2(arr,0,n-1,key)<<'\n';        // array should be sorted (wihtoud size)
    cout<<binarySearch3(arr,0,n-1,key)<<'\n';        // array should be sorted (wihtoud size)
    cout<<"\n";

    /*
    HOMEWORK
    do all binary search questions that are been solves in earlier lectures using reccursion


    */

    return 0;
}