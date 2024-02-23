#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){        //what is its time complexity   gives TLE for 5*10^6
    int i=2;
    int j=n/(i-1);
    if(n<=1){
        return false;
    }
    if(n==2||n==3){
        return true;
    }
    while(i<=j){
        if(n%i==0){
            cout<<i<<" is a first factor of n\n";
            return false;
        }
        else{
            i++;
            j=n/(i-1);
        }
    }
    return true;
}

// sieve of eratosthenes theorem    //does not give TLE for 5*10^6
int countPrimes(int n){     //time complexity=O(nlog(logn))
    array<int, 1000>a;
    a[0]=0;
    a[1]=0;
    for(int i=2; i<n; i++){
        a[i]=1;
    }

    int count=0;
    for(int i=2; i<n; i++){
        if(a[i]==1){
            count++;
            cout<<i<<'\n';
            for(int j=2*i; j<n; j=j+i){
                a[j]=0;
            }
        }
    }
    return count;
}

// both below functions are euclid gcd algorithms
int gcd(int a, int b){
    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}

int gcd2(int a, int b){
    while(a!=0 || b!=0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
        // cout<<a<<' '<<b<<'\n';
    }

    if(a==0)
        return b;
    
    if(b==0)
        return a;
}

int main(){

    int n;
    cin>>n;
    if(isPrime(n)){
        cout<<"n is prime\n\n";
    }
    else{
        cout<<"n is non-prime\n\n";
    }


    // sieve of eratostheres theorem
    //time complexity=O(nlog(logn))
    countPrimes(n);
    // cout<<countPrimes(n)<<'\n';
    

    //gcd(a,b)=gcd(a-b,b)=gcd(a%b,b)    a>b 
    int a,b;
    cin>>a>>b;
    // cout<<gcd(a,b)<<'\n';
    cout<<gcd2(a,b)<<'\n';

    // gcd(a,b)=gcd(a-b,b)=gcd(a%b,b)    a>b 
    // lcm(a,b)*gcd(a,b)=a*b
    // 
    // (a+b) % n = [ (a%n) + (b%n) ] %n
    // (a-b) % n = [ (a%n) - (b%n) ] %n
    // (a*b) % n = [ (a%n) * (b%n) ] %n
    // a%n = (a%n)%n = ((a%n)%n)%n and so on...


    // fast exponentiation
    





    // HOMEWORK
    // segmented sieve
    // euclid gcd algorithm
    // piegon hole principle
    // catalan number   + its application
    // inclusion exclusion principle
    // factorial of a number    212!mode(10^9)+7


    return 0;
}