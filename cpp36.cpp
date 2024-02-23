#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int s, int e){
    // for(int i=0; i<e+1; i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<'\n';
    int pivot=a[s];
    int count=0;
    for(int i=s+1; i<=e; i++){
        if(pivot>=a[i]){
            count++;
        }
    }

    int pivotIndex=s+count;
    swap(a[s],a[pivotIndex]);
    
    int i=s, j=e;
    // while(i<pivotIndex && j>pivotIndex){
    //     if(a[i]>=pivot && a[j]<pivot){
    //         swap(a[i++], a[j--]);
    //     }
    //     else if(a[i]>=pivot){
    //         j--;
    //     }
    //     else if(a[j]<pivot){
    //         i++;
    //     }
    // }

    while(i<pivotIndex && j>pivotIndex){
        while(a[i]<pivot){
            i++;
        }

        while(a[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
            swap(a[i++], a[j--]);
        // cout<<i<<' '<<j<<'\n';
    }

    return pivotIndex;
}

void quickSort(int *a, int s, int e){
    if(s>=e)
        return;

    // for(int i=0; i<e+1; i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<'\n';
    
    int p = partition(a, s, e);
    quickSort(a, s, p-1);
    quickSort(a, p+1, e);
}

int main(){

    int a[100000];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    quickSort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';

    /*
        quick sort is in-place algo
        quick sort is not a stable algo but can be made stable
        TC- 
            average case- O(nlogn)
            best case- O(nlogn)
            worst case- O(n^2)
            space complexity- O(n)
            
    */

    return 0;
}