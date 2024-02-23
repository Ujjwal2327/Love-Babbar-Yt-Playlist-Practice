#include<iostream>
using namespace std;

// #define name value
#define PI pi
#define pi 3.46
#define ri pi
int score=5;

void a(){
    cout<<score<<" in a"<<'\n';
}

void b(int a, int b){
    cout<<a<<' '<<b;
}

void func(int a, int b){
    a++;
    b++;
    cout<<a<<' '<<b<<'\n';
}

int getMax(int a, int b){
    return (a>b)?a:b;
}

int getMax2(int& a, int& b){        //to save memory
    return (a>b)?a:b;
}

inline int getMax3(int& a, int& b){        //to reduce function call
    return (a>b)?a:b;
}

void printArray1(int arr[], int n, int start){
    for(int i=start; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

void printArray2(int arr[], int n, int start=0){            //default argument
    for(int i=start; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

void printArray3(int arr[], int n=3, int start=0){
    for(int i=start; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

// void printArray4(int arr[], int n=3, int start){            //gives ERROR    default arguments should be at last(rightmost side)    start with rightmost parameter   
void printArray4(int arr[], int start, int n=3){
    for(int i=start; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int main(){

    // double pi=3.14;      take storage (very less effect on performance)

    /*
    macro-
        #define name value
        declared outside of all functions
        a piece of code in a program that is replaced by a value of macro BEFORE COMPILATION
        so no need of extra memory
        can't be change in any function
        easy maintanence of code
        cant be modified using its name
        // pi+=1;       gives ERROR     INVALID
    */
    // pi+=1;       gives ERROR     INVALID
    cout << "PI is " <<PI << '\n';
    cout << "pi is " <<pi << '\n';
    cout << "ri is " <<ri << '\n';
    cout<<'\n';
    cout<<score<<" in main"<<'\n';
    a();
    
    /*
    to use a same variable between function
    1st way->   uaing reference variable
    2nd way->   global variable

    local variable  variable of only one function
                    its scope is a function only 
                    its scope is in between a block {}

    global variable
        globally declared 
        globle scope    
        should be above all functions
        don't use global variables     BAD practice    because any function can update this
        so for using a variable between functions, use concept of reference variables
    */

    /*
    inline functions- 
        a function call in a program is replaced by its body BEFORE COMPILATION
        used to reduce the function call overhead (inside stack space)
            reduce time and memory usage 
        if function is of one line,     compiler makes it inline function after writing inline keyword 
        if function is of 1-3 lines,    depends on compiler after writing inline keyword
        if function is > 3 lines,       compiler does not make it inline after writing inline keyword
    advantage- 
        more readable, 
        no extra memory usage (if we are using reference variable too), 
        no need for function call overhead
    */

    int a=1,b=2;        //is it valid to have a same name for a function as well as a variable  YUP
    // b(a,b);          //then why is it not valid      we cant use same variable name in that function
    func(a,b);

    int ans=INT32_MIN;
    if(a>b)
        ans=a;
    else
        ans=b;
    cout<<ans<<'\n';

    /*
    tertiary operator
    (condition) ? iftruestatement : iffalsestatement;
    */

    // writing above code in tertiary operator method1
    ans = (a>b) ? a : b;
    cout<<ans<<'\n';

    // writing above code in tertiary operator method2
    (a>b) ? ans=a : ans=b;
    cout<<ans<<'\n';

    // for multiple statements in tertiary operators
    (a>b) ? (ans=a, ans++, cout<<ans<<'\n') : (ans=b, ans++, cout<<ans<<'\n');

    ans=getMax(a,b);
    cout<<ans<<'\n';

    ans=getMax2(a,b);
    cout<<ans<<'\n';

    ans=getMax3(a,b);
    cout<<ans<<'\n';

    /*
    HOMEWORK
    gfg article macros and its types and constant variable
    */

    int arr[]={1,3,5,7,9};
    printArray1(arr,5,3);
    printArray2(arr,5);
    printArray2(arr,5,3);
    printArray3(arr);
    // printArray4(arr,0);
    // printArray4(arr,5,0);

    cout<<arr<<'\n';
    // cout<<arr[]<<'\n';       //INVALID

    return 0;
}