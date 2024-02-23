#include<iostream>
using namespace std;
int main()
{
    /*
    bitwise operators
    & and
    | or
    ~ not
    ^ xor
    work on bit level i.e. bitwise
    use with ()
    */

    int a=4,b=5;                      //a=00000000 00000000 00000000 00000100, b=00000000 00000000 00000000 00000101
    cout<<"a & b is "<<(a&b)<<'\n';     //00000000 00000000 00000000 00000100
    cout<<"a | b is "<<(a|b)<<'\n';     //00000000 00000000 00000000 00000101
    cout<<"~a is "<<~a<<'\n';           //11111111 11111111 11111111 11111011
    cout<<"~ b is "<<(~b)<<'\n';        //11111111 11111111 11111111 11111010
    cout<<"a ^ b is "<<(a^b)<<'\n';     //00000000 00000000 00000000 00000001
    cout<<'\n';


    /*
    left shift operator  <<
    a<<b; left shift a, b times
    gives the result by multiplying 2^b times into a except the case when either of 2 left most bit is 1/setbit  

    right shift operator  <<
    a<<b; right shift a, b times
    gives the result by dividing a by 2^b times

    for +ve numbers, in both left and right shifts, padding will be 0, i.e. the new added bits will be 0 in both left and right side of a number in left and right shifts
    for -ve numbers, it is compiler dependent
    */
    cout<<(b<<2)<<'\n';                       //00000000 00000000 00000000 00000101 to 00000000 00000000 00000000 00010100
    cout<<(b<<a)<<'\n';                       //00000000 00000000 00000000 00000101 to 00000000 00000000 00000000 01010000
    cout<<(1000000000000000000<<a)<<'\n';     //gives -ve, case when the second left (set) bit is 1
    cout<<(-2<<1)<<'\n';                      //compiler dependent
    // -2 stored in memory 11111111 11111111 11111111 11111110

    cout<<(b>>2)<<'\n';                       //00000000 00000000 00000000 00000101 to 00000000 00000000 00000000 00000001
    cout<<(b>>a)<<'\n';                       //00000000 00000000 00000000 00000101 to 00000000 00000000 00000000 00000000
    cout<<(-100000000000000000<<a)<<'\n';     //compiler dependent
    cout<<(-1000000000000000000<<a)<<'\n';    //compiler dependent
    cout<<(-2>>1)<<'\n';                      //compiler dependent
    cout<<'\n';

    /*
    increament and decreament operators
    i=i+1       i+=1
    increament operator
    i++ post increeament
    first use i, then increament i to i+1
    ++i pre increament
    first increament, then use i+1 as i=i+1

    i=i-1       i-=1
    decreament operator
    i-- post decreeament
    first use i, then decreament i to i-1
    --i pre decreament
    first decreament, then use i-1 as i=i-1
    */

    int i=7;    
    cout<<i++<<'\n';
    cout<<++i<<'\n';
    cout<<i--<<'\n';
    cout<<--i<<'\n';
    cout<<--i<<'\n';
    cout<<'\n';



    /*
    for loops
    for(initialise; condition; update){         these 3 tings are not necessary to write in the loop, but ; is necessary and multiple variables can be used simultaneously
        body statement;
    }
    flow of for loops
    initialisation-> condition-> body-> update ->condition-> and so on...
    */

    int n;
    cout<<"Enter n\n";
    cin>>n;

    //1st method print numbers from 1 to n
    for(i=1; i<=n; i++){
        cout<<i<<' ';
    }
    cout<<'\n';

    //2nd method print numbers from 1 to n
    i=1;
    for(; i<=n; i++){
        cout<<i<<' ';
    }
    cout<<'\n';

    //3rd method print numbers from 1 to n
    i=1;
    for(; i<=n;){
        cout<<i<<' ';
        i++;
    }
    cout<<'\n';

    //4th method print numbers from 1 to n
    i=1;
    for(; ;){
        if(i<=n){
            cout<<i<<' ';
        }
        else{
            break;      //breaks the loop and gets you out of the loop
        }
        i++;
    }
    cout<<"\n\n";

    // write the table of 5 using 2 variables
    int j;
    for(i=0,j=0 ; i<=10,j<=100 ; i++,j+=5){     // i<=10,j<=100 means i<=10 || j<=100
        cout<<"5 * "<<i<<" = "<<j<<'\n';
    }
    cout<<'\n';

    // write the table of 10 using 2 variables
    for(i=0,j=0 ; i<=10 && j<=100 ; i++,j+=10){
        cout<<"10 * "<<i<<" = "<<j<<'\n';
    }
    cout<<'\n';

    // write a mix table
    int k;
    for(i=0,j=0,k=0; i<=10,j<=10,k<=100; i+=2,j++,k+=i){
        cout<<i<<" "<<j<<" "<<k<<'\n';
    }
    cout<<'\n';

    // print sum from 1 to n
    int sum=0;
    for(i=1; i<=n; i++){
        sum+=i;
    }
    cout<<sum<<'\n';

    // print first n numbers of fibonacci series
    a=0,b=1;
    if(n==1){
        cout<<a<<'\n';
    }
    else if(n==2){
        cout<<a<<' '<<b<<'\n';
    }
    else{
        cout<<a<<' '<<b<<' ';
        for(i=3; i<=n; i++){
            sum=b+a;
            a=b;
            b=sum;
            cout<<sum<<' ';
        }
    }
    cout<<'\n';

    // print whether the number is prime or not
    if(n==1)
        cout<<n<<" is neither prime nor composite number";
    else if(n==2)
        cout<<n<<" is a prime number";
    for(i=2; i<n; i++){
        if(n%i==0){
            cout<<n<<" is not a prime number";
            break;
        }
        if(i==n-1){
            cout<<n<<" is a prime number";
        }
    }
    cout<<'\n';



    /*
    continue
    to skip the code below it in the loop from execution
    the below part will not be executed
    */

    for(i=0; i<3; i++){
        cout<<"hii ";
        cout<<"hey ";
        continue;
        cout<<"reply to krde";
    }
    cout<<"\n\n";

    // forloop1
    for(i=0; i<=5; i++){
        cout<<i<<' ';       // 0 2 4
        i++;
    }
    cout<<"\n\n";

    // forloop2
    for(i=0; i<=15; i+=2){
        cout<<i<<' ';
        if(i&1){
            continue;
        }
        i++;
    }
    cout<<"\n\n";

    // forloop3
    for(i=0; i<5; i++){
        for(int j=i; j<=5;j++){
            cout<<i<<' '<<j<<endl;
        }
    }
    cout<<'\n';

    // forloop4
    for(i=0; i<5;i++){
        for(int j=i; j<=5;j++){
            if(i+j==7){
                break;
            }
            cout<<i<<' '<<j<<endl;
        }
    }
    cout<<'\n';



    // scope of a variable;
    int x=3;
    // int x=5;        INVALID  can initialize only one time in a scope, but VALID for different scopes
    int z=3;
    cout<<"x is "<<x<<'\n';
    cout<<"z is "<<z<<'\n';
    if(true){
        int x=5;
        cout<<"x is "<<x<<'\n';
        z=5;
        cout<<"z is "<<z<<'\n';
        int y=7;
        cout<<"y is "<<y<<'\n';
    }
    cout<<"x is "<<x<<'\n';
    // cout<<y<<'\n';       INVALID
    cout<<"z is "<<z<<'\n';

    i=8;
    for(int i=0; i<5; i++){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<i<<'\n';
    cout<<'\n';
    for(i=0; i<5; i++){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<i<<'\n';
    cout<<'\n';

    if(1){
        int a=2;
        int b=2;
        cout<<a<<' '<<b<<'\n';      //2 2
        if(1){
            a=3;
            int b=3;
            cout<<a<<' '<<b<<'\n';      //3 3
            if(1){
                a=4;
                int b=4;
                cout<<a<<' '<<b<<'\n';      //4 4
            }
            cout<<a<<' '<<b<<'\n';      //4 3
        }
        cout<<a<<' '<<b<<'\n';      //4 2
    }
    cout<<'\n';



    /*
    operator precedence
    no need to remember, just use brackets properly
    can watch the table on internet
    */



    // print the difference between the product and sum of the digits of a number n
    cout<<"inout n\n";
    cin>>n;
    int q,r,s=0,p=1;
    while(q){
        q=n/10;
        r=n%10;
        n=q;
        s+=r;
        p*=r;
    }
    cout<<p-s<<"\n";

    // print the difference between the product and sum of the digits of a number n
    cin>>n;
    s=0,p=1;  
    q=n/10; 
    r=n%10;  
    s+=r;  
    p*=r;  
    while(q>0){  
        n=q;  
        q=n/10;  
        r=n%10;  
        s+=r;  
        p*=r;  
    }
    cout<<p-s;  //6
    cout<<"\n\n";

    //print number of 1 bits in a number method1
    i=0;
    b=0;
    sum=0;
    cin>>n;
    while(n){       
        r=n%2;      
        b=b*10+r;     
        n=n/2;      
    }
    // cout<<b;
    while(b){
        r=b%2;
        b=b/10 ;
        if(r==1){
            sum++;
        }
    }
    cout<<sum<<'\n';

    //print number of 1 bits in a number method2
    i=0;
    b=0;
    sum=0;
    cin>>n;
    while(n){       
        r=n%2;      
        n=n/2;      
        if(r==1){
            sum++;
        }
    }
    cout<<sum<<'\n';

    //print number of 1 bits in a number method3
    i=0;
    b=0;
    sum=0;
    cin>>n;
    while(n){       
        r=n%2;      
        b=b*10+r;     
        n=n/2;      
    }
    // cout<<b;
    while(b){
        if(b%10==1){
            sum++;
        }
        b=b/10;
    }
    cout<<sum<<'\n';

    //print number of 1 bits in a number method4
    i=0;
    b=0;
    sum=0;
    cin>>n;
    while(n){       
        r=n%2;      
        b=b*10+r;     
        n=n/2;
    }
    // cout<<b;
    while(b){
        if(b%10){
            sum++;
        }
        b=b/10;
    }
    cout<<sum<<'\n';

    //print number of 1 bits in a number method5
    cin>>n;
    i=0;
    sum=0;
    while(n){
        if(n&1){
            sum++;
        }
        n=n>>1;
    }
    cout<<sum<<"\n\n";
    

    
    // some if and while conditions
    if(-3){
        cout<<"Hello dear -3"<<'\n';
    }
    if(0){
        cout<<"Hello dear 0"<<'\n';
    }
    int xy=-3;
    while(xy){
        cout<<"Hello dear "<<xy<<'\n';
        xy++;
    }
    while(-2){
        cout<<"yo"<<'\n';
        break;;
    }
    while(0){
        cout<<"yo 0"<<'\n';
        break;;
    }
    xy=0;
    while(xy){
        cout<<"yo xy"<<'\n';
        break;
    }
    cout<<'\n';

    return 0;
}