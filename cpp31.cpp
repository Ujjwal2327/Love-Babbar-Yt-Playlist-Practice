#include<iostream>
using namespace std;

int fact1(int n){
    int ans=1;
    if(n==0)
        return 1;
    else{
        ans=n*fact1(n-1);
        return ans;
    }
}

int fact2(int n){
    int ans=1;
    if(n==0)
        return ans;
    else{
        ans=n*fact2(n-1);
        return ans;
    }
}

int fact3(int n){
    if(n==0)
        return 1;
    else{
        return n*fact3(n-1);
    }
}

int powerOf2(int n){
    if(n==0)
        return 1;
    
    int smallerProblem=powerOf2(n-1)
    int biggerProblem=2*smallerProblem;
    return biggerProblem;
}

int printrevcount(int n){
    if(n==1){
        cout<<1<<' ';
        return 0;
    }
    else{
        cout<<n<<' ';
        printrevcount(n-1);
    }
    return 0;
}

void printrevcount2(int n){
    if(n==1){
        cout<<1<<' ';
        return;
    }
    else{
        cout<<n<<' ';
        printrevcount2(n-1);
        return;
    }
}

void printrevcount3(int n){
    if(n==1){
        cout<<1<<' ';
        // return;
    }
    else{
        cout<<n<<' ';
        printrevcount3(n-1);
    }
}

int printcount(int n){
    // cout<<n<<' ';
    if(n==1){
        return 1;
    }
    else{
        cout<<printcount(n-1)<<' ';
        return n;
    }
}

void printcount2(int n){        //head recursive
    // cout<<n<<' ';
    if(n==0){
        return;
    }
    printcount2(n-1);
    cout<<n<<' ';
}

void printrevcount4(int n){     //tail recursive
    // cout<<n<<' ';
    if(n==0){
        return;
    }
    cout<<n<<' ';
    printrevcount4(n-1);
}

int main(){

    /*
    recursion- when a function calls itself directly or indirectly
    when big complex problem solution depends on same type of small simple problem
    recurrance / recursive relation- f(n)=g(f(n))
    2^n=2*2^(n-1)
    n!=n*(n-1)!
    base case/condition- where recursion inside function stops
    if base case is not applied-> function call stack overflow  segmentation fault
    base case-> 2^0=1       0!=1
    use of return keyword in base case is mandatory

    so we need 3 things -> reccurence relation, processing part (print, update, etc) and base case
    reccursion tree

    tail recursion: base case-> processing part -> recursive relation
    head recursion: base case -> recursive relation-> processing part

    */

    int n;
    cin>>n;
    cout<<fact1(n)<<'\n';
    cout<<fact2(n)<<'\n';
    cout<<fact3(n)<<'\n';
    cout<<powerOf2(n)<<'\n';
    printrevcount(n)<<'\n';
    cout<<endl;
    cout<<endl;
    printrevcount2(n);
    cout<<endl;
    cout<<endl;
    printrevcount3(n);
    cout<<endl;
    cout<<endl;
    cout<<printcount(n)<<'\n';
    cout<<endl;
    cout<<endl;
    printcount2(n);
    cout<<endl;
    cout<<endl;
    printrevcount4(n);
    cout<<endl;
    cout<<endl;





    return 0;
}