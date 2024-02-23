/*  QUESTIONS
    https://leetcode.com/problems/rotate-array/
    https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
    https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186

    HOMEWORK
    complexities of all 3 solutions

*/

#include<iostream>
#include<array>
#include<vector>
using namespace std;

void rotatedarray(int k){
    // give error for k>7
    array<int,7>a={1,7,9,11,5,15,10};
    array<int,7>b={0};
    int i=0, j=0;
    while(i<a.size()){
        if(i<a.size()-k){
            b[k+i]=a[i];
        }
        else{
            b[j]=a[i];
            j++;
        }
        i++;
    }
    for(i=0; i<a.size(); i++){
        a[i]=b[i];
    }
    for(i=0; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void rotatedarray2(int k){
    array<int,7>a={1,7,9,11,5,15,10};
    array<int,7>b={0};
    int i=0, j=0;
    while(i<a.size()){
        b[(k+i)%a.size()]=a[i];
        i++;
    }
    a=b;    //copy all elements of array b to array a   also in vector
    // for(i=0; i<a.size(); i++){
    //     a[i]=b[i];
    // }
    for(i=0; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

bool issortedandrotatedarray(){
    // array<int,8>a={53,67,2,3,4,5,7,23};
    // array<int,5>a={3,5,7,1,6};
    array<int,5>a={1,1,1,1,1};       //it should give true
    int i=0;
    int flag=0;
    for(i=0; i<a.size(); i++){
        if(a[i]>a[(i+1)%a.size()]){      //%a.size() is used for the case of a[a.size()-1]
            flag++;
        }
        if(flag>1){
        cout<<"array is not sorted and rotated\n";
            return false;
        }
    }
    cout<<"array is sorted and rotated\n";
    return true;
}

void sumoftwoarrays(){
    array<int,1>a={6};
    // array<int,4>b={9,9,9,9};
    array<int,4>b={1,2,3,4};
    array<int,5>c={0};
    int i=a.size()-1, j=b.size()-1, k=c.size()-1, carry=0;
    while(i>-1 && j>-1){
        c[k]=(a[i]+b[j]+carry)%10;
        carry=(a[i]+b[j]+carry)/10;
        k--;
        i--;
        j--;
    }
    while(i>-1){
        c[k--]=(a[i]+carry)%10;
        carry=(a[i]+carry)/10;
        i--;
    }
    while(j>-1){
        c[k--]=(b[j]+carry)%10;
        carry=(b[j]+carry)/10;
        j--;
    }
    if(carry!=0){
        c[k]=carry;
        for(i=0;i<c.size(); i++){
        cout<<c[i]<<' ';
        }
    }
    else{
        for(i=1;i<c.size(); i++){
        cout<<c[i]<<' ';
        }
    }
    cout<<'\n';
}

void sumoftwoarrays2(){
    array<int,1>a={6};
    array<int,4>b={1,2,3,4};
    int i=0,s1=0,s2=0,ans=0;
    for(i;i<a.size();i++){
        s1=s1*10+a[i];
    }
    for(i=0;i<b.size();i++){
        s2=s2*10+b[i];
    }
    ans=s1+s2;
    cout<<ans<<'\n';
    
}

void sumoftwoarrays3(){
    vector<int>a={6};
    vector<int>b={1,2,3,4};
    vector<int>c;
    int i=a.size()-1, j=b.size()-1, carry=0;
    while(i>-1 && j>-1){
        int d=(a[i]+b[j]+carry)%10;
        c.push_back(d);
        carry=(a[i]+b[j]+carry)/10;
        i--;
        j--;
    }
    while(i>-1){
        c.push_back((a[i]+carry)%10);
        carry=(a[i]+carry)/10;
        i--;
    }
    while(j>-1){
        c.push_back((b[j]+carry)%10);
        carry=(b[j]+carry)/10;
        j--;
    }
    while(carry!=0){
        c.push_back(carry%10);
        carry/=10;
    }
    int s=0,e=c.size()-1;
    for(s,e;s<e;s++,e--){
        swap(c[s],c[e]);
    }
    for(i=0;i<c.size(); i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}

int main(){

    int k;
    cin>>k;
    rotatedarray(k);
    rotatedarray2(k);
    issortedandrotatedarray();

    sumoftwoarrays();
    sumoftwoarrays2();
    sumoftwoarrays3();
    

    return 0;
}