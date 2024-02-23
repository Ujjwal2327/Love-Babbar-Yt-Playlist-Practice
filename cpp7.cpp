#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    // return a reverse of a number, if the number lies outside the range, return 0
    int n, rev=0,d;
    cin>>n;
    bool flag=true;
    while(n){
        d=n%10;
        n=n/10;
        rev=rev*10+d;
        if(rev>INT64_MAX/10 || rev<INT64_MIN/10){      //INT64MIN and INT64MAX are the minimum and maximum values of an integer
            flag = false; 
            break;
        }
    }
    if(flag){
        cout<<rev<<'\n';
    }
    else{
        cout<< 0<<'\n';
    }
    // if(rev>INT64_MIN && rev<INT64_MAX){     //wrong approach
    //     cout<<rev<<'\n';
    // }
    // else{
    //     cout<<0;
    // }


    // GOOD QUESTION
    // complement of a base 10 integer
    cin>>n;
    int i=0;
    if(n==0){       //edge case
        cout<<1<<'\n';
    }
    else{
        int cnt = 0;
        int x = n;
        while(x){
            cnt++;
            x = x>>1;
        }
        while(cnt){
            x = x<<1;
            x = x|1;
            cnt--;
        }

        int ans = (x&(~n));
        cout<<ans<<"\n\n";
    }

    // chack whether the number is in the power of 2 or not
    cin>>n;
    flag=true;
    for(int i=0; i<=30; i++){
        if(n==pow(2,i)){
            flag=false;
            cout<<"is power of 2\n";
        }
    }
    if(flag){
        cout<<"is not a power of 2\n";
    }


    return 0;
}