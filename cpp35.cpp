#include<iostream>
using namespace std;
// int count=0;

void mergeSortPartition(int arr[], int s, int e){
    if(s>=e)
        return;
    
    int mid=s+(e-s)/2;
    mergeSortPartition(arr, s, mid);
    mergeSortPartition(arr, mid+1, e);

    mergeSortMerge(arr,s,e);
}

void mergeSortMerge(int arr[], int s, int e){
    int mid=s+(e-s)/2;

    // create 2 new arrays  left (first) and right (second)
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    //copying an array into 2 new arrays
    int k=s;
    for(int i=0; i<len1; i++){
        first[i]=arr[k++];
    }
    for(int i=0; i<len2; i++){
        second[i]=arr[k++];
    }

    //merge these 2 sorted arrays
    k=s;
    int i=0;
    int j=0;
    while(i<len1 && j< len2){
        if(first[i]<second[j]){
            // if(arr[k]!=first[i])
            //     count++;
            arr[k++]=first[i++];
        }
        else{
            // if(arr[k]!=second[j])
            //     count++;
            arr[k++]=second[j++];
        }
    }
    while(i<len1){
        // if(arr[k]!=first[i])
        //     count++;
        arr[k++]=first[i++];
    }
    while(j<len2){
        // if(arr[k]!=second[j])
        //     count++;
        arr[k++]=second[j++];
    }
}

int main(){

    int n;
    cin>>n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSortPartition(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }

    // merge sort time complexity is O(nlogn) in all cases worst case, average case, best case
    // as merge sort always divides the array into two halves and takes linear time to merge two halves.
    // Space Complexity: O(n)

    // Merge sort is stable but not inplace algorithm





    return 0;
}