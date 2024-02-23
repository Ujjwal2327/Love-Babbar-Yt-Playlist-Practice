// WHOLE LECTURE CONTAINS GOOD QUESTIONS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // find whether the number is even or odd by & or | method1
    cout<<"Input n\n";
    int n;
    cin>>n;
    if(n&1==1){
        cout<<"number is odd";
    }
    else{
        cout<<"number is even";
    }
    cout<<'\n';

    // find whether the number is even or odd by & or | method2
    if((n|1)==n){
        cout<<"number is odd";
    }
    else{
        cout<<"number is even";     //where is it wrong
    }
    cout<<'\n';

    // convert digits to number and reverse number
    cout<<"input number of digits\n";
    cin>>n;
    int i,d,ans=0, revans=0;
    for(i=0; i<n; i++){
        cin>>d;
        ans=ans*10+d;
        // cout<<revans<<' '<<(pow(10,i))<<"  ";
        revans = revans + (pow(10,i)) * d;    //what is wrong     input=1,2,3,4
        // cout<<revans<<'\n';
    }
    cout<<ans<<'\n';
/**/cout<<revans<<'\n';     //why this is wrong



    // positive decimal to binary method1
    cout<<"input n\n";
    cin>>n;
    d=0;
    i=1;
    int b=0;
    while(n){
        d=n%2;
        d=d*i;
        i*=10;
        b=b+d;      //concept of revans
        n/=2;
    }
    cout<<b<<'\n';

    // positive decimal to binary method2
    cin>>n;
    d=0, ans=0, i=0;
    while(n){
        d=n&1;      //wherever we can apply n%2, we can apply n&1
        ans=ans+(d*pow(10,i));
        n = n>>1;      //wherever we can apply n/2, we may apply n>>1
        i++;
    }
/**/cout<<ans<<'\n';    //why this is wrong

/**/// negative decimal to binary
    cout<<"input a negative number\n";
    cin>>n;
    d=0, ans=0, i=0;
    n=-n;
    while(n){
        d=n%2;
        ans=ans+d*(pow(10,i));
        i++;
        n=n/2;
    }
    cout<<ans<<'\n';
    ans+=pow(10,30);
    cout<<ans<<'\n';
    cout<<"\n";



    // negative decimal to binary
    cout<<"input a negative number\n";
    cin>>n;
    ans=0;
    if(n==0){
        cout<<0<<"\n\n";
    }
    else{
        bool flag = false;
        if(n<0){
            flag=true;
            n=-n;
        }
        int i=1;
        while(n){
            int bit = n&1;
            n=n>>1;
            ans = ans + bit*i;
            i*=10;
        }
        if(!flag){
            cout<<ans<<"\n\n";
        }
        else{
            cout<<ans<<"\n\n";
            int newAns = 2sCompliment(ans);
            cout<<newAns<<"\n\n";
            string result = "";
            result = to_string(newAns) + result;
            int len = result.length();
            // string(number of times, character to concatenate)
            result = string(32-len, '1') + result;       // this is how to concatinate strings
            cout<<result<<"\n\n";

        }
    }



    // binary to decimal
    cin>>n;
    i=0,b=0,d=0;
    while(n){
        b=n%10;
        n=n/10;
        d=d+b*(pow(2,i));
        i++;
    }
    cout<<d<<'\n';

    return 0;

    /*
    INPUTS
    6
    4
    1 2 3 4
    13
    13
    -25
    -6
    11001

    */
}