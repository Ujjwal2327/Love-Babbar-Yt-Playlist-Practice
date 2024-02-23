#include<bits/stdc++.h>
using namespace std;

void reverseString(string s, int st, int e){    //no change in the string in the n=main function, so we have 2 ways, either use the string function or use pass by reference
    if(st>e)
        return;
    swap(s[st],s[e]);
    reverseString(s,++st,--e);
}

// void reverseString2(string &s, int st, int e=s.length()-1){      WHY IS IT GIVING ERROR
void reverseString2(string &s, int st, int e){
    if(st>e)
        return;
    swap(s[st],s[e]);
    reverseString2(s,++st,--e);
}

void reverseString3(string &s, int st){
    if(st>s.length()-st-1)
        return;
    swap(s[st],s[s.length()-st-1]);
    reverseString3(s,++st);
}

string reverseString4(string s, int st, int e){
    if(st>e)
        return s;
    swap(s[st],s[e]);

    return reverseString4(s, ++st, --e);
}

bool isPalindrome(string &s, int st){
    if(st>s.length()-st-1)
        return true;
    if(s[st]!=s[s.length()-st-1])
        return false;
    return isPalindrome(s,++st);
}

bool isPalindromeCaseSensitive(string &s, int st){
    if(st>s.length()-st-1)
        return true;
    if( (s[st]!=s[s.length()-st-1])  &&  (s[st]!=s[s.length()-st-1]-'a')  &&  (s[st]!=s[s.length()-st-1]+'a') )
        return false;
    return isPalindrome(s,++st);
}

int aToPowerb(int a, int b){
    if(b==0)
        return 1;
    return a*aToPowerb(a,b-1);
}

int aToPowerb2(int a, int b){       //time complexity- O(logBase2(b))
    if(b==0)
        return 1;
    if(b&1)
        return a*aToPowerb(a,b/2)*aToPowerb(a,b/2);
    else
        return aToPowerb(a,b/2)*aToPowerb(a,b/2);
}

void bubbleSort(int *arr, int n){
    if(n==0 || n==1)        //n=0 if given array is empty
        return;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
            swap(arr[i], arr[i+1]);        
    }
    bubbleSort(arr,n-1);
}

void bubbleSort2(int *arr, int n, bool flag=0){
    if(n==0 || n==1)        //n=0 if given array is empty
        return;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
            swap(arr[i], arr[i+1]);
            flag=1;
    }
    if(flag==0)
        return;
    else
    bubbleSort2(arr,n-1, flag);
}

void selectionSort(int arr[], int n){
    if(n==0 || n==1)        //n=0 if given array is empty
        return;
    int smallest=INT_MAX, mini=0;
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            smallest=arr[i];
            mini=i;
        }
    }
    swap(arr[0],arr[mini]);
    selectionSort(arr+1,n-1);
}

void insertionSort(int arr[], int n, int e=1){
    if(e==n)
        return;
    int k=arr[e];
    int i=e-1;
    for(; i>=0; i--){
        if(arr[e]<arr[i])
            arr[i+1]=arr[i];
        else
            break;
    }
    arr[i+1]=k;
    insertionSort(arr,n,e+1);
}

int main(){

    string s;
    cin>>s;
    cout<<s<<"\n\n";

    int st=0, e=s.length()-1;
    cout<<"before reverseString, s is "<<s<<'\n';
    reverseString(s, st,e);
    cout<<"after reverseString, s is "<<s;
    cout<<"\n\n";

    cout<<"before reverseString2, s is "<<s<<'\n';
    reverseString2(s, st,e);
    cout<<"after reverseString2, s is "<<s;
    cout<<"\n\n";

    cout<<"before reverseString3, s is "<<s<<'\n';
    reverseString3(s, st);
    cout<<"after reverseString3, s is "<<s;
    cout<<"\n\n";

    cout<<"before reverseString4, s is "<<s<<'\n';
    cout<<reverseString4(s, st, e)<<'\n';
    cout<<"after reverseString4, s is "<<s;
    cout<<"\n\n";

    cout<<"isPallindrome-> "<<isPalindrome(s, st)<<'\n';
    cout<<"isPallindromeCaseSensitive-> "<<isPalindromeCaseSensitive(s, st)<<'\n';
    cout<<"\n\n";

    string s2;
    cin>>s2;
    if(s==s2){
        cout<<"true"<<'\n';
    }
    else{
        cout<<"false"<<'\n';
    }
    cout<<'\n';

    string s3;
    s3=s;
    cout<<s<<'\t'<<s2<<'\t'<<s3<<'\n';
    cout<<'\n';

    int a,b;
    cin>>a>>b;
    cout<<aToPowerb(a,b);
    cout<<'\n';
    cout<<aToPowerb2(a,b);
    cout<<"\n\n";

    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';

    bubbleSort2(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n\n";

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    cout<<'\n';
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n\n";


    array<int, 10>a1={1,9,2,8,3,7,4,6,5,0};
    array<int, 10>a2=a1;
    n=10;
    
    // selection sort
    for(int i=0; i<n-1; i++){
        int minIndex=i;
        int j;
        for(j=i+1; j<n; j++){
            if(a2[j]<a2[minIndex]){
                minIndex=j;
            }
        }
        swap(a2[i], a2[minIndex]);
    }
    for(int i=0; i<n; i++){
        cout<<a2[i]<<' ';
    }
    cout<<'\n';

    // bubble sort
    a2=a1;
    for(int i=0; i<n-1; i++){
        bool flag=0;
        for(int j=0; j<n-i-1; j++){
            if(a2[j]>a2[j+1]){
                swap(a2[j], a2[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a2[i]<<' ';
    }
    cout<<'\n';

    // insertion sort
    a2=a1;
    for(int i=1; i<n; i++){
        int temp=a2[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(a2[j]>temp){
                a2[j+1]=a2[j];
            }
            else{
            // a2[j+1]=temp;        //how is it wrong
                break;
            }
        }
        a2[j+1]=temp;
    }
    for(int i=0; i<n; i++){
        cout<<a2[i]<<' ';
    }
    cout<<"\n\n";


    return 0;
}