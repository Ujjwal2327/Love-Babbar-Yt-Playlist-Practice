#include<iostream>
using namespace std;

void goingHome(int src, int dest){
    cout<<src<<' '<<dest<<'\n';

    // base case
    if(src==dest){
        cout<<"reach home"<<'\n';
        return;
    }

    // recursive function
    // src++;
    // goingHome(src, dest);
    goingHome(++src, dest);     //this line or aboth 2 lines are same
    // goingHome(src++, dest);     
    //infinite loop     src in 1st goingHome->1
                        // after goingHome(src++, dest);
                        // src in 1st goingHome->2 but src in 2nd goingHome->1
                        // after goingHome(src++, dest);
                        // src in 2nd goingHome->2 but src in 3rd goingHome->1
                        // and so on and no function will return 
                        // stack of function call overhead get full and overflow
}

int nthfibonacci(int n){
    if(n==0 || n==1){
        return n;
    }

    int ans= nthfibonacci(n-1)+nthfibonacci(n-2);
    // cout<<ans<<' ';
    return ans;
}

int nthfibonacci2(int n) {
    if(n==0 || n==1)
        return n;
    int ans1=0, ans2=1, ans;
    for(int i=2; i<=n; i++){
        ans=ans1+ans2;
        ans1=ans2;
        ans2=ans;
    }
    return ans;
}

int countDistinctWayToClimbStair(long long n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	return countDistinctWayToClimbStair(n-1)+countDistinctWayToClimbStair(n-2);
}

int countDistinctWayToClimbStair2(long long n){
	if(n==0 || n==1){
		return 1;
	}
	return countDistinctWayToClimbStair(n-1)+countDistinctWayToClimbStair(n-2);
}

void readDigits(int n, string *arr){
    // base case
    if(n==0){
        return;
    }
    // processing
    int d=n%10;
    n=n/10;

    // reccursive function
    readDigits(n,arr);

    // processing
    cout<<arr[d]<<' ';
}

int main(){

    // recursion    aapko ek case ki chinta krni hai, baaki apne aap solve ho jayega

    int src=1, dest=10;
    goingHome(src,dest);
    cout<<'\n';

    int n;
    cin>>n;
    cout<<nthfibonacci(n)<<'\n';
    cout<<nthfibonacci2(n)<<'\n';
    cout<<countDistinctWayToClimbStair(n)<<'\n';
    cout<<countDistinctWayToClimbStair2(n)<<'\n';

    cin>>n;
    string arr[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    readDigits(n, arr);
    cout<<'\n';

    return 0;
}