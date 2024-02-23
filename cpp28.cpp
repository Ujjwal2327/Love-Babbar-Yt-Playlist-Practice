#include<iostream>
using namespace std;

void update1(int n){        //pass by value
    n++;
}

void update2(int & n){      // pass by reference
    n++;
}

int & update3 (int n){      //return by reference
    int a=10;
    int &ans=a;
    return ans;     //return nothing as a and ans are the local variable whose memory will get clear outside this function due to their scope
    // very bad practice
}

int & update4 (int n){
    int a=n;
    int &ans=a;
    return ans;     //return nothing as a and ans are the local variable whose memory will get clear outside this function due to their scope
}

int & update5 (int n){
    int &ans=n;
    return ans;     //return nothing as ans is the local variable whose memory will get clear outside this function due to its scope
}

int update6 (int n){
    int ans=n;
    return ans;     //how is it VALID?
}

int update7(int *arr, int n){
    int sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

int * update8(int n){
    int *p=&n;
    return p;       //WHY IS IT VALID   p is a pointer but the value of p is address, so it outputs as address
    // return *p;       //dereference operator and *p is int, not a pointer
}

// int * update8(int n){
//     int *p=&n;
//     return *p;      //WHY IS IT WRONG
// }

int main(){

    // same variable with same memory bloack but different names
    int i=5;
    int &j=i;       //creating a reference variable- same memory but different names
    cout<<"i-> "<<i<<"\t&i->"<<&i<<'\n';
    cout<<"j-> "<<j<<"\t&j->"<<&j<<'\n';
    i++;
    cout<<"i-> "<<i<<"\tj-> "<<j<<'\n';
    j++;
    cout<<"i-> "<<i<<"\tj-> "<<j<<'\n';
    j=i+1;
    cout<<"i-> "<<i<<"\tj-> "<<j<<'\n';
    j=i++;      //j=8=> i=9=> j=9 but IT IS NOT THE SAME
    cout<<"i-> "<<i<<"\tj-> "<<j<<'\n';
    cout<<'\n';

    int n=5;
    cout<<"PASS BY VALUE \n";   // when function a calls function b, then, data is copied in NEW variable with NEW MEMORY block is created in memory and update is going on that new memory block
    cout<<"before update function\tn-> "<<n<<'\n';
    update1(n);
    cout<<"after update function\tn-> "<<n<<'\n';
    cout<<'\n';
    
    cout<<"PASS BY REFERENCE \n";   // when function a calls function b, then, only reference variable (NEW variable) is created, but NO NEW MEMORY is created, all upadates are in the same old memory block
    cout<<"before update function\tn-> "<<n<<'\n';
    update2(n);     //now n of main function and n of update2 function can calls the same number
    cout<<"after update function\tn-> "<<n<<'\n';
    cout<<'\n';


    cout<<"update3 function\n";
    cout<<update3(n)<<'\n';
    cout<<'\n';
    
    cout<<"update4 function\n";
    cout<<update4(n)<<'\n';
    cout<<'\n';
    
    cout<<"update5 function\n";
    cout<<update5(n)<<'\n';
    cout<<'\n';
    
    cout<<"update6 function\n";
    cout<<update6(n)<<'\n';
    cout<<'\n';
    
    int arr[]={1,2,3,4,5};
    cout<<"update7 function\n";
    cout<<update7(arr,5)<<'\n';
    cout<<'\n';
    
    cout<<"update8 function\n";
    cout<<update8(n)<<'\n';
    cout<<'\n';
    
    /*
    when a program starts, it gets its memory before getting any input
    it has 2 types of memory: stack memory and heap memory
    when we use stack memory-> static memory allocation
    when we use heap memory-> dynamic memory allocation
    stack memory is smaller than dynamic memory in size
    arr[n] is very BAD practice because in it we use stack and there may be case in which stack memory is less than tha required memory for an array if n is large, then the compiler will crash
    whatever you made till now, that has no need of input size, is created instack memory
    
    for heap memory / dynamic memory allocation, we use new keyword
        ex- new char;       returns adderss
            by declaring like this, memory needed for char is booked in heap memory
        you cant define its name
    */

    // creating a char in heap memory
    new char;               //made in heap      1 byte
    char *ch=new char;      //way of giving it a name       pointer is made in stack   4/8 bytes (depend upon 32/64 bit system) as pointer stores address
    // pointer is created in stack memory and char is created in heap memory
    // 4 bytes (in stack) + 1 byte (in heap) =9 bytes are required

    // creating an int in heap memory
    int *value1=new int;     //4 + 4 bytes
    
    // creating an array in heap memory
    new int[5];     //memory of 5 ints is booked in heap memory     returns the starting address of that booked location
    int *arr1=new int[5];       //array is created in heap memory and a pointer is created pointing the first address of an array

    new char[5];     //memory of 5 chars is booked in heap memory     returns the starting address of that booked location
    char *arr1_2=new char[5];   //array is created in heap memory and a pointer is created pointing the first address of an array

    // variable size array
    cout<<"enter number of elements in an array\n";
    cin>>n;
    int *arr2=new int[n];   //here it is VALID      4(in stack memory) + 5*4 (in heap memory)= 24 bytes total in memory
    
    cout<<"enter elements in an array\n";
    for(int i=0; i<n; i++){
        cin>>arr2[i];       //as arr2[i] is *(arr2 + i)
    }
    cout<<"array in heap memory is\n";
    for(int i=0; i<n; i++){
        cout<<arr2[i]<<' ';       //as arr2[i] is *(arr2 + i)
    }
    cout<<"\n";
    cout<<"sum of elements is " << update7(arr2, n)<<'\n';
    cout<<'\n';

    /*
    difference between static and dynamic allocation

    1st difference
        int arr[10];    //40 bytes memory
        int *arr = neint[10];    //4+40 bytes     44 bytes memory


    2nd difference
        after 1 iteration of a loop the memory from STACK used in that iteration gets automatically free
        but the memory from HEAP used in that iteration does not get automatically free, we have to free it manually by using delete keyword

        while(1){
            int i=5;     //take only 4 bytes and get automatically free / released after one iteration of a loop
        }

        while(1){
            int *i=new int;  //take 4 bytes (of pointer storing address) in STACK memory (free after each iteration ) and 4 bytes (of int) in HEAP memory (will not free after each iteration ) due to which program gets crashed as all heap memory get full and overflowed
            *i=5;
        }

        HEAP memory can be free or released by using delete keyword
        while(1){
            int *i=new int;  //take 4 bytes (of pointer storing address) in STACK memory (free after each iteration ) and 4 bytes (of int) in HEAP memory (will not free after each iteration ) due to which program gets crashed as all heap memory get full and overflowed
            *i=5;
            delete i;
        }
    */

    cout<<"size of new int is "<<sizeof(new int)<<"\n\n";

    // int deletion
    int *value2=new int;
    *value2=5;
    cout<<"before delete->\n";
    cout<<"value2 is " << value2 <<'\n';
    cout<<"*value2 is " << *value2 <<'\n';
    cout<<"size of value2 is "<< sizeof(value2) << "\n\n";
    delete value2;
    cout<<"after delete->\n";
    cout<<"value2 is " << value2 <<'\n';
    cout<<"*value2 is " << *value2 <<" \tHEAP memory is released\n";
    cout<<"size of value2 is " << sizeof(value2) << "\n\n";

    cout<<"size of new int[10] is "<<sizeof(new int[10])<<"\n\n";

    // array deletion
    int *arr3=new int[10];
    *arr3=5;
    *(arr3+1)=10;
    cout<<"before delete->\n";
    cout<<"arr3 is " << arr3 <<'\n';
    cout<<"*arr3 is " << *arr3 <<'\n';
    cout<<"size of arr3 is "<< sizeof(arr3) << "\n\n";
    delete []arr3;
    cout<<"after delete->\n";
    cout<<"arr3 is " << arr3 <<'\n';
    cout<<"*arr3 is " << *arr3 <<" \tHEAP memory is released\n";
    cout<<"size of arr3 is " << sizeof(arr3) << "\n\n";


    /*
    void pointer
    address typecasting
    */


    return 0;
}