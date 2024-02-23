// 5 2 5 5 2 5 a 5 
#include<iostream>
using namespace std;
int main()
{
    // input
    int n;
    cout << "Hello" << '\n';
    cout << "input n\n";
    cin >> n;
    cout << "Hello" << '\n';
    cout << "Value of n is " << n << '\n';
    cout << '\n';

    int a,b;
    cout<<"input a and b\n";
    cin>>a>>b;      //cin doesn't read space, tab and enter
    cout<<"value of a nad b are "<<a<<" and "<<b<<" respectively\n\n";

    /* cin.get()
    int c;
    c=cin.get();
    cin.get() reads input AS character
    so cin.get() read space, tab and enter too
    reads only first character given to it
    */

    // if else
    // print n is positive or negative
    int m;
    cout<<"input value of m"<<'\n';
    cin>>m;
    if(m>0){
        cout<<"m is positive\n\n";
    }
    else{
        cout<<"m is negative or zero\n\n";
    }

    // print bigger number of 2 numbers
    cout<<"input a again\n";
    cin>>a;
    cout<<"input b again\n";
    cin>>b;
    // 1st method
    if(a>b){
        cout<<a<<" is bigger\n\n";
    }
    else if(a<b){
        cout<<b<<" is bigger\n\n";
    }
    else{
        cout<<"a and b are equal\n\n";
    }
    
    // 2nd method
    if(a>b){
        cout<<a<<" is bigger\n\n";
    }
    else if(a<b){
        cout<<b<<" is bigger\n\n";
    }
    else if(a==b){
        cout<<"a and b are equal\n\n";
    }
    // no need to end with else, you can end with else if too

    // 3rd method
    if(a>b){
        cout<<a<<" is bigger\n\n";
    }
    else{
        if(a<b){
            cout<<b<<" is bigger\n\n";
        }
        else{
            cout<<"a and b are equal\n\n";
        }
    }
    
    // print type of character
    char c;
    cout<<"input c\n";
    cin>>c;
    if(c>='A'&&c<='Z'){
        cout<<"c is UPPERCASE\n\n";
    }
    else if(c>='a'&&c<='z'){
        cout<<"c is lowercase\n\n";
    }
    else if(c>='0'&&c<='9'){
        cout<<"c is numerical value\n\n";
    }

    // while loops
    // print number 1 to n
    cout<<"input n\n";
    cin>>n;
    int i=1;
    while(i<=n){
        cout<<i<<' ';
        i=i+1;
    }
    cout<<'\n';

    // print sum from 1 to n
    i=1;
    int sum=0;
    while(i<=n){
        sum=sum+i;
        i=i+1;
    }
    cout<<sum<<'\n';
    
    // print sum of all even numbers from 1 to n
    // 1st method
    i=2;
    sum=0;
    while(i<=n){
        sum=sum+i;
        i=i+2;
    }
    cout<<sum<<'\n';
    
    // 2nd method
    i=1;
    sum=0;
    while(i<=n){
        if(i%2==0){
            sum=sum+i;
        }
        i=i+1;
    }
    cout<<sum<<'\n';

    // print whether the number is prime or not
    // 1st method
    i=2;
    if(n==2 || n==3){
            cout<<"n is prime by 1st method\n";
    }
    while(i<n){
        if(n%i==0){
            cout<<"n is not prime by 1st method\n";
            break;
        }
        else{
            i=i+1;
        }
        if(i==n-1){
            cout<<"n is prime by 1st method\n";
            break;
        }
    }
  
    // 2nd method
    i=2;
    if(n==2){
            cout<<"n is prime by 2nd method\n";
    }
    while(i<n){
        if(i==n-1){
            cout<<"n is prime by 2nd method\n";
            break;
        }
        if(n%i==0){
            cout<<"n is not prime by 2nd method\n";
            break;
        }
        else{
            i=i+1;
        }
    }

    // 3rd method
    i=2;
    int flag=0;
    while(i<n){
        if(n%i==0){
            cout<<"n is not prime by 3rd method\n";
            flag=1;
            break;
        }
        else{
            i=i+1;
        }
    }
    if(flag==0){
        cout<<"n is prime by 3rd method\n";
    }

    // 4th method
    i=2;
    flag=0;
    while(i<n){
        if(n%i==0){
            flag=1;
            break;
        }
        else{
            i=i+1;
        }
    }
    if(flag==0){
        cout<<"n is prime by 4th method\n";
    }
    else{
        cout<<"n is not prime by 4th method\n";
    }
    cout<<"\n\n";

    // patterns
    cout<<"Input number of rows for patterns\n";
    cin>>n;

    // pattern1
    cout<<"pattern 1"<<'\n';
    i=0;
    while(i<n){
        int j=0;
        while(j<n){
            cout<<"* ";
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
    cout<<"\n";

    // pattern2
    cout<<"pattern 2"<<'\n';
    i=1;
    while (i<=n)
    {
        int j=1;
        while(j<=n){
            cout<<i<<' ';
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
    cout<<"\n";

    // pattern3
    cout<<"pattern 3"<<'\n';
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<j<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }    
    cout<<'\n';
   
    // pattern4 method1
    cout<<"pattern 4 Method 1"<<'\n';
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<n-j+1<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }    
    cout<<'\n';
   
    // pattern4 method2
    cout<<"pattern 4 Method 2"<<'\n';
    i=1;
    while(i<=n){
        int j=n;
        while(j>=1){
            cout<<j<<' ';
            j=j-1;
        }
        i=i+1;
        cout<<'\n';
    }    
    cout<<'\n';

    // pattern5 method1
    cout<<"pattern 5 Method 1"<<'\n';
    i=1;
    int j=1;
    while(i<=n){
        int k=1;
        while(k<=n){
            cout<<j<<' ';
            k=k+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern5 method2
    cout<<"pattern 5 Method 2"<<'\n';
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<n*(i-1)+j<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern6
    cout<<"pattern 6"<<'\n';
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<"* ";
            j=j+1;
        }
        cout<<'\n';
        i=i+1;
    }
    cout<<'\n';

    // pattern7
    cout<<"pattern 7"<<'\n';
    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            cout<<i<<' ';
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
    cout<<"\n";

    // pattern8
    cout<<"pattern 8"<<'\n';
    i=1;
    int k=1;
    while(i<=n){
        j=1;
        while(j<=i){
            cout<<k<<' ';
            k=k+1;
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }
    cout<<"\n";

    // pattern9 method1
    cout<<"pattern 9 Method 1"<<'\n';
    i=1;
    while(i<=n){
        j=1;
        k=i;
        while(j<=i){
            cout<<k<<' ';
            k=k+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<"\n";

    // pattern9 method2
    cout<<"pattern 9 Method 2"<<'\n';
    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            cout<<i+j-1<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<"\n";

    // pattern10 method1
    cout<<"pattern 10 Method 1"<<'\n';
    i=1;
    while(i<=n){
        j=i;
        while(j>=1){
            cout<<j<<' ';
            j=j-1;
        }
        cout<<'\n';
        i=i+1;
    }
    cout<<'\n';

    // pattern10 method2
    cout<<"pattern 10 Method 2"<<'\n';
    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            cout<<i-j+1<<' ';
            j=j+1;
        }
        cout<<'\n';
        i=i+1;
    }
    cout<<'\n';

    // pattern11 method1
    cout<<"pattern 11 Method 1"<<'\n';
    i=0;
    while(i<n){
        j=0;
        char c=0;
        while(j<n){
            c=i+65;
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern11 method2
    cout<<"pattern 11 Method 2\n";
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            char c=i+65;
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern11 method3
    cout<<"pattern 11 Method 3\n";
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            char c='A'+i;
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';
   
    // pattern11 method4
    cout<<"pattern 11 Method 4\n";
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            cout<<char('A'+i)<<' ';     //char op int give int, so we typecast it to char
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern12
    cout<<"pattern 12\n";
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char c='A'+j-1;
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern13 method1
    cout<<"pattern 13 Method 1\n";
    i=1;
    k=0;
    while(i<=n){
        j=1;
        while(j<=n){
            char c=k+65;     //or c='A'+k
            cout<<c<<' ';
            k=k+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern13 method2
    cout<<"pattern 13 Method 2\n";
    i=1;
    c='A';
    while(i<=n){
        j=1;
        while(j<=n){
            cout<<c<<' ';
            c=c+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern14 method1
    cout<<"pattern 14 Method 1\n";
    i=1;
    while(i<=n){
        c='A'+i-1;
        j=1;
        while(j<=n){
            cout<<c<<' ';
            c=c+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern14 method2
    cout<<"pattern 14 Method 2\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n){
            c='A'+i+j-2;        // i+j  when the matrix pattern form as symmetric matrix
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern15 method1
    cout<<"pattern 15 Method 1\n";
    i=0;
    c='A';
    while(i<n){
        j=0;
        while(j<=i){
            cout<<c<<' ';
            j=j+1;
        }
        c=c+1;
        i=i+1;
        cout<<endl;
    }
    cout<<endl;

    // pattern15 method2
    cout<<"pattern 15 Method 2\n";
    i=0;
    while(i<n){
        c='A'+i;
        j=0;
        while(j<=i){
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<endl;
    }
    cout<<endl;

    // pattern16
    cout<<"pattern 16\n";
    i=1;
    c='A';
    while(i<=n){
        j=1;
        while(j<=i){
            cout<<c<<' ';
            c=c+1;
            j=j+1;
        }
        i=i+1;
        cout<<endl;
    }
    cout<<'\n';

    // pattern17
    cout<<"pattern 17\n";
    i=0;
    while(i<n){
        c='A'+i;
        j=0;
        while(j<=i){
            cout<<c<<' ';
            c=c+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern18
    cout<<"pattern 18\n";
    i=0;
    while(i<n){
        c='A'+n-i-1;
        j=0;
        while(j<=i){
            cout<<c<<' ';
            c=c-1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';
    
    // pattern19 method1
    cout<<"pattern 19 Method 1\n";
    i=0;
    while(i<n){
        c='A'+n-i-1;
        j=0;
        while(j<=i){
            cout<<c<<' ';
            c=c+1;
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern19 method2
    cout<<"pattern 19 Method 2\n";
    i=0;
    while(i<n){
        j=0;
        while(j<=i){
        c='A'+n-i+j-1;
            cout<<c<<' ';
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern20 method1
    cout<<"pattern 20 Method 1\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n){
            if(j<=n-i){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern20 method2
    cout<<"pattern 20 Method 2\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<"  ";
            j=j+1;
        }
        while(j<=n){
            cout<<"* ";
            j=j+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern20 method3
    cout<<"pattern 20 Method 3\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<"  ";
            j=j+1;
        }
        k=1;
        while(k<=i){
            cout<<"* ";
            k=k+1;
        }
        i=i+1;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern21
    cout<<"pattern 21\n";
    i=n;
    while(i>=1){
        j=i;
        while(j>=1){
            cout<<"* ";
            j--;
        }
        i--;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern22
    cout<<"pattern 22\n";
    i=0;
    while(i<n){
        j=0;
        while(j<i){
            cout<<"  ";
            j++;
        }
        while(j<n){
            cout<<"* ";
            j++;
        }
        cout<<'\n';
        i++;
    }
    cout<<'\n';

    // pattern23
    cout<<"pattern 23\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<i){
            cout<<"  ";
            j++;
        }
        while(j<=n){
            cout<<i<<' ';
            j++;
        }
        cout<<'\n';
        i++;
    }
    cout<<'\n';

    // pattern24
    cout<<"pattern 24\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<"  ";
            j++;
        }
        while(j<=n){
            cout<<i<<' ';
            j++;
        }
        cout<<'\n';
        i++;
    }
    cout<<'\n';

    // pattern25
    cout<<"pattern 25\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<i){
            cout<<"  ";
            j++;
        }
        while(j<=n){
            cout<<j<<' ';
            j++;
        }
        i++;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern26
    cout<<"pattern 26\n";
    i=1;
    k=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<"  ";
            j++;
        }
        while(j<=n){
            cout<<k<<' ';
            k++;
            j++;
        }
        i++;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern27
    cout<<"pattern 27\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<"  ";
            j++;
        }
        j=1;
        while(j<=i){
            cout<<j<<' ';
            j++;
        }
        j=j-2;
        while(j>=1){
            cout<<j<<' ';
            j--;
        }
        i++;
        cout<<'\n';
    }
    cout<<'\n';

    // pattern28
    cout<<"pattern 28\n";
    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout<<j<<' ';
            j++;
        }
        j=1;
        while(j<=2*(i-1)){
            cout<<"* ";
            j++;
        }
        j=n-i+1;
        while(j>=1){
            cout<<j<<' ';
            j--;
        }
        i++;
        cout<<'\n';
    }
    cout<<'\n';

    /*
    INPUTS OF THE CODE
    5
    6 7
    -2
    2 2
    U
    7
    5
    */

    return 0;
}