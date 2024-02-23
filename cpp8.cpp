#include<bits/stdc++.h>
using namespace std;

int power1(int n1, int n2){
    int ans=1;
    for(int i=1; i<=n2; i++){
        ans*=n1;
    }
    return ans;
}

int power2(){   //more optimized
    int n1,n2,ans=1;
    cin>>n1>>n2;
    for(int i=1; i<=n2; i++){
        ans*=n1;
    }
    return ans;
}

bool evenodd(int n){
    if(n%2==0){
        cout<<"number is even"<<'\n';
    }
    else{
        cout<<"number is odd"<<'\n';
    }
    return true;
}

bool iseven(int n){
    if(n&1){
        return 0;
    }
    return 1;
}

int fact(int n){
    int ans=1;
    if(n>1){
        for(int i=2; i<=n; i++){
            ans*=i;
        }
    }
    return ans;
}

int nCr1 (int n, int r){
    int ans=(fact(n))/(fact(r)*fact(n-r));
    return ans;
}

int nCr2 (int n, int r){
    return (fact(n))/(fact(r)*fact(n-r));
}

int nCr3(int n, int r){     // more optimised
    int ans = 1;
    for(int i=1; i<=r; i++){
        ans = ans*n/i;
        n--;
    }
    return ans;
}

void printcount(int n){
    for(int i=1; i<=n; i++){
        cout<<i<<' ';
    }
    cout<<'\n';
    return ;    //not mandatory to use, means exit from the function
}

bool isprime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void dummy(int n){
    n+=10;
    cout<<"n is "<<n <<" inside the dummy\n";
}

int ap(int n){
    int ans=3*n+7;
    return ans;
}

int dtob(int d){
    int ans=0,i=1;
    while(d){
        int a=d%2;
        d=d/2;
        ans=ans+a*i;
        i*=10;
    }
    return ans;
}

int setbits(int n){
    int a=dtob(n);
    int ans=0;
    while(a){
        if(a%10){
            ans++;
        }
        a=a/10;
    }
    return ans;
}

int setbits2(int n){
    int ans=0;
    while(n){
        if(n&1){
            ans++;
        }
        n=n>>1;
    }
    return ans;
}

void fib(int n){
    int a=0, b=1,c;
    if(n==1){
        cout<<"fibonacci series is "<<a<<'\n';
        cout<<"nth fibonacci number is "<<a<<'\n';
    }
    else if(n==2){
        cout<<"fibonacci series is "<<a<<' '<<b<<'\n';
        cout<<"nth fibonacci number is "<<b<<'\n';
    }
    else{
        cout<<"fibonacci series is "<<a<<' '<<b<<' ';
        while(n>2){
            c=a+b;
            a=b;
            b=c;
            cout<<c<<' ';
            n--;
        }
        cout<<'\n';
        cout<<"nth fibonacci number is "<<c<<'\n';
    }
}

int main()
{
    /*
    switch case
    switch(expression){
        case constant1:     can be int or char, not a float or string, the case in which constant is same as expression (both value and datatype), will be executed
            statement;
            break;  //may or may not be used
        case constant2:
            statement;
            break;  //may or may not be used
        case constantn:
            statement;
            break;  //may or may not be used
        default:    //may or may not be used
            statement;
    }
    */

    // switch case1
    int num=5;
    switch(num){
        case 1:
            cout<<"first"<<'\n';
            cout<<"second"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';

    // switch case2
    char c='5';
    switch(c){
        case 1:
            cout<<"first"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        case '5':
            cout<<"forth"<<'\n';
            break;
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';

    // switch case3 use of default
    c='a';
    switch(c){
        case 1:
            cout<<"first"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        case '5':
            cout<<"forth"<<'\n';
            break;
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';

    // switch case4
    c='a';
    switch(c){
        case 1:
            cout<<"first"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        case '5':
            cout<<"forth"<<'\n';
            break;
    }
    cout<<'\n';

    // switch case5 without break
    c='1';      // all cases after that particular case will be executed too
    switch(c){
        case '1':
            cout<<"first"<<'\n';
        case 1:
            cout<<"second"<<'\n';
        case 5:
            cout<<"third"<<'\n';
        case '5':
            cout<<"forth"<<'\n';
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';

    // switch case6
    num=3;
    switch(2+num){
        case 1:
            cout<<"first"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';

    // nested switch
    c='5', num=5;
    switch(c){
        case 1:
            cout<<"first"<<'\n';
            break;
        case 5:
            cout<<"third"<<'\n';
            break;
        case '5':
            cout<<"forth"<<'\n';
            switch (num)
            {
                case 2:
                    cout<<"value of num is 2"<<'\n';
                    break;
                case 5:
                    cout<<"value of num is 5"<<'\n';
                    break;
            }
            cout<<"value of char is "<<c<<'\n';
        default:
            cout<<"Hey buddy"<<'\n';
    }
    cout<<'\n';


    // use of continue keyword in switch is INVALID
    // continue can only use within loops
        // c='b';
        // switch(c){
        //     case 'a':
        //         cout<<"c is 'a'"<<'\n';
        //         continue;
        //     case 'b':
        //         cout<<"c is 'b'"<<'\n';
        //     case 'c':
        //         cout<<"c is 'c'"<<'\n';
        //     default:
        //         cout<<"c is any other character"<<'\n';
        // }


    // calculator using switch
    int a,b;
    char op;
    cout<<"input a, b and operator\n";
    cin>>a>>b>>op;
    switch (op){
        case '+':
            cout << "a + b is " << a+b << '\n';
            break;
        case '-':
            cout << "a - b is " << a-b << '\n';
            break;
        case '*':
            cout << "a * b is " << a*b << '\n';
            break;
        case '/':
            cout << "a / b is " << a/b << '\n';
            break;
        case '%':
            cout << "a % b is " << a%b << '\n';
            break;
        default:
            cout<<"you input a wrong operator\n";
            break;
    }
    cout<<"\n\n";


    /*
    functions
        program with well defined task
        to make the code short, less bulky and more readable, less buggy
        return_type name(parameter){        //function signature
            statement;
        }
    */


    // power(a,b)
    power1(2,3);           //it will only return, not store in the memory, doesn't print in output
    cout<<power1(2,3)<<'\n';

    int ans=power1(2,3);
    cout<<ans<<'\n';
    cout<<'\n';
    

    // for printing 3 times using power1
    cout<<"printing power(a,b) 3 times using power1\n";
    cin>>a>>b;
    cout<<power1(a,b)<<'\n';
    cin>>a>>b;
    cout<<power1(a,b)<<'\n';
    cin>>a>>b;
    cout<<power1(a,b)<<'\n';
    cout<<'\n';


    // for printing 3 times using power2 more optimized
    cout<<"printing power(a,b) 3 times using power2\n";
    cout<<power2()<<'\n';
    cout<<power2()<<'\n';
    cout<<power2()<<'\n';
    cout<<'\n';


    // tell whether the particular number is even or odd using evenodd
    cout<<"input a number using evenodd"<<'\n';
    cin>>a;
    evenodd(a);
    cout<<'\n';
    cout<<evenodd(a)<<"\n\n";


    // tell whether the particular number is even or odd using iseven
    cout<<"input a number using iseven"<<'\n';
    cin>>a;
    cout<<iseven(a)<<'\n';
    if(iseven(a)){
        cout<<"number is even\n";
    }
    else{
        cout<<"number is odd\n";
    }
    cout<<'\n';


    // find nCr using nCr1
    cout<<"input n and r for nCr using nCr1"<<'\n';
    cin>>a>>b;
    cout<<nCr1(a,b)<<"\n\n";

    // find nCr using nCr2
    cout<<"input n and r for nCr using nCr2"<<'\n';
    cin>>a>>b;
    cout<<nCr2(a,b)<<"\n\n";

    // find nCr using nCr3
    cout<<"input n and r for nCr using nCr3"<<'\n';
    cin>>a>>b;
    cout<<nCr3(a,b)<<"\n\n";


    // print counting from 1 to n
    cout<<"input n for counting"<<'\n';
    cin>>a;
    printcount(a);
    // cout<<printcount(a);         //it is INVALID as void function returns nothing in terms of value
    cout<<'\n';


    // find whether a number is prime or not
    cout<<"input n to find whether a number is prime or not"<<'\n';
    cin>>a;
    cout<<isprime(a)<<'\n';
    if(isprime(a)){
        cout<<"number is prime"<<'\n';
    }
    else{
        cout<<"number is non-prime"<<'\n';
    }
    cout<<'\n';



    /*
    function call stack
    ex->
                        fact
                nCr     nCr     nCr
        main    main    main    main    main
    */



    // pass by value
    cout<<"input n to understand pass by value using dummy"<<'\n';
    int n;
    cin>>n;
    cout<<"n is "<<n<<" inside main before dummy\n";
    dummy(n);
    cout<<"n is "<<n<<" inside main after dummy\n";
    // both n are different in main and dummy function, n in dummy function creates a new variable of name n, dummy function create a new copy of that variable
    cout<<"\n\n";
    cout<<"\n\n";




    /*HOMEWORK
    // switch case is in the infinite loop and you have to come outside of loop by doing something in switch only, not in loop, how can you do it?
    // hint- use of exit()

    // total amount is 1330, tell the number of 100,50,20,1 notes using switch statement

    // ap=3n+7, input-n, output- nth term of ap

    // input-a,b ; output-total number of set bits(1) in a and b

    // fibonacci series and nth fibonacci series    
    */


    // total amount is 1330, tell the number of 100,50,20,1 notes using switch statement
    cout<<"Input rupees\n";
    cin>>n;
    switch('a'){
        case 'a':
            cout<<"number of Rs 1000 notes is "<<n/1000<<'\n';
            n=n%1000;
        case 50:
            cout<<"number of Rs 50 notes is "<<n/50<<'\n';
            n=n%50;
        case 20:
            cout<<"number of Rs 20 notes is "<<n/20<<'\n';
            n=n%20;
        case 1:
            cout<<"number of Rs 1 notes is "<<n/1<<'\n';
    }
    cout<<'\n';

    // ap=3n+7, input-n, output- nth term of ap
    cout<<"Input n to find nth term of ap 3n+7\n";
    cin>>n;
    cout<<ap(n)<<"\n\n";

    // input-a,b ; output- total number of set bits(1) in a and b using setbits
    cout<<"Input a and b to find total number of set bits(1) in a and b using setbits\n";
    cin>>a>>b;
    cout<<setbits(a)+setbits(b)<<"\n\n";
    
    // input-a,b ; output- total number of set bits(1) in a and b
    cout<<"Input a and b to find total number of set bits(1) in a and b using setbits2\n";
    cin>>a>>b;
    cout<<setbits2(a)+setbits2(b)<<"\n\n";
    
    // fibonacci series and nth fibonacci series
    cout<<"Input n for fibonacci series\n";
    cin>>n;
    fib(n);

    return 0;

    /*
    INPUTS
    11 1024 *
    4 5
    5 6
    6 7
    4 3
    5 4
    6 5
    9
    8
    7 3
    7 3
    7 3
    11
    11
    20
    1330
    7
    5 7
    5 7
    10
    */
}