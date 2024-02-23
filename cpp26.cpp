#include<bits/stdc++.h>
using namespace std;

void print(int *p){     //when we call in the main function, we send content of p i.e. we send p or &(*p), not *p
    cout<<"by function call\n";
    cout<<"p ->"<<p<<'\n';
    cout<<"*p ->"<<*p<<'\n';
    cout<<"&p ->"<<&p<<'\n';
    cout<<endl;
}

void update(int *p){
    (*p)++;
    cout<<*p<<'\n';
    cout<<endl;
}

void updatevalueaddress(int *p){
    cout<<"inside: before update function->\t"<<p<<'\n';
    p++;
    cout<<"inside: after update function->\t\t"<<p<<'\n';
}

void printaddress(int *p){
    cout<<"inside:->\t"<<&p<<'\n';
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int getSum(int a[],int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    return sum;
}

int getSum2(int *a,int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=i[a];
    }
    return sum;
}

// void passing_arr(int a[], int n){        //both a[] and *a are same
void passing_arr(int *a, int n){
    cout<<"inside-> size of arr is "<<sizeof(a)<<"\t size of pointer as pointer passes in the function in case of array, not an entire array. It does not copy an entire array\n";
}
    
int main(){

    /*
    pointer me jiska address dlta hai, pointer use point krta hai
    pointer hmesha address hi store krega
    how to read->
    *-> value at
    &-> address of
    */

    //int array and pointers
    int arr[10]={10,20,30};
    cout<<"arr-> "<<arr<<endl;       // address of first memory block        array ka name array ke phle location ke address ko return krta hai
    cout<<"&arr[0]-> "<<&arr[0]<<endl;
    cout<<"*arr-> "<<*arr<<endl;  //in sybol table, arr is mapped with A1 (address of arr[0]), so *arr points to value at A1 which is arr[0]
    cout<<"*arr+1-> "<<*arr+1<<endl;
    cout<<"&arr-> "<<&arr<<endl;
    cout<<"*(&arr)-> "<<*(&arr)<<endl;  //*(&arr) and *&arr are same
    cout<<"&(*arr)-> "<<&(*arr)<<endl;  //&(*arr) and &*arr are same
    cout<<'\n';

    cout<<"*(&(*arr)+1)-> "<<*(&(*arr)+1)<<endl;  //(*arr)->arr[0]    &(*arr)->add(arr[0])    &(*arr)+1->increment the add(arr[0]), as array is contiguous memory locations, &(*arr)+1->add(arr[1])   *(&(*arr)+1)->arr[1]
    // &{*arr} and arr are same things
    cout<<"*(arr+1)-> "<<*(arr+1)<<endl;  //arr+1->increment the add(arr[0]), as array is contiguous memory locations, arr+1->add(arr[1])   *(arr+1)->arr[1]
    //arr[i] computes internally by compiler as *(arr+i) 
    cout<<"arr[2]-> "<<arr[2]<<'\t'<<"*(arr+2)-> "<<*(arr+2)<<'\t'<<"2[arr]-> "<<2[arr]<<"(FOCUS), it is VALID syntax"<<'\t'<<"*(2+arr)-> "<<*(2+arr)<<'\t'<<endl;
    //arr[i] <-> *(arr+i) <-> *(i+arr) <-> i[arr]
    cout<<'\n';

    // *{&arr} and arr are same things???????????????????????????????????????
/**/// NON UNDERSTANDABLE
    cout<<"&arr-> "<<&arr<<'\n';       //here arr is add(arr[0]) ot name of variable arr???????
    cout<<"size of &arr->"<<sizeof(&arr)<<'\n';
    cout<<"*(&arr)-> "<<*(&arr)<<'\n';    //what does it show???????
    cout<<"size of *(&arr)->"<<sizeof(*(&arr))<<'\n';
    cout<<'\n';


    cout<<"*arr is "<<*arr<<'\n';
    cout<<"arr is "<<arr<<'\n';
    cout<<"&arr is "<<&arr<<'\n';
    cout<<"&arr[0] is "<<&arr[0]<<'\n';
    cout<<"size of *arr (size of int value at arr/&arr[0])-> "<<sizeof(*arr)<<'\n';
    cout<<"size of arr (size of whole array)->"<<sizeof(arr)<<'\n';
    cout<<"size of &arr (size of address)-> "<<sizeof(&arr)<<'\n';
    cout<<'\n';

    int *p1=&arr[0];
    int *p2=arr;
    cout<<"p1 is "<<p1<<'\n';
    cout<<"p2 is "<<p2<<'\n';
    cout<<"*p1 is "<<*p1<<'\n';
    cout<<"*p2 is "<<*p2<<'\n';
    cout<<"&p1 is "<<&p1<<'\n';
    cout<<"&p2 is "<<&p2<<'\n';
    cout<<'\n';

    /*
    content of symbol table cant be changed
    address cannot be change
    arr++;       gives ERROR
    &p1++;       gives ERROR     it is also in the symbol table
    p1++;        it is VALID     we are changing th content stored in p1, not address of p1
    */
    
    //char array and pointers
    int brr[5]={10,20,30,40,50};
    // char ca[5]="abcde";      gives ERROR     as there must be a NUll character in a character array
    char ca[5]="abcd";      //same as char ca[5]={'a', 'b', 'c', 'd'};
    //first they are stored in temporary memory as |'a'|'b'|'c'|'d'|'\0'|
    //and then it will copy in ca5 as |'a'|'b'|'c'|'d'|'\0'|
    cout<<"behaviour of cout is different in case of int array and char array "<<'\n';
    cout<<"brr is "<<brr<<'\n';
    cout<<"ca is "<<ca<<'\n';
    cout<<'\n';

    char *c1=&ca[0];
    char *c2=&ca[1];
    cout<<"c1 is "<<c1<<"\t(entire string from ca[1] until white space or NULL char is found) "<<'\n';
    cout<<"c2 is "<<c2<<"\t(entire string from ca[1] until white space or NULL char is found) "<<'\n';
    cout<<"*c1 is "<<*c1<<'\n';
    cout<<"*c2 is "<<*c2<<'\n';
    cout<<"&c1 is "<<&c1<<'\n';
    cout<<"&c2 is "<<&c2<<'\n';
    cout<<'\n';

    char ch='z';
    char *c3=&ch;
    cout<<"c3 is "<<c3<<"\t(entire string from z until NULL char is found, goes from &ch to next locations (i.e. &ch++ and so on) until NULL char is found) "<<'\n';
    cout<<"*c3 is "<<*c3<<'\n';
    cout<<"&c3 is "<<&c3<<'\n';
    cout<<'\n';

    /*
    char ca2[5]="abcd";
    first they are stored in temporary memory as "abcd"
    and then it will copy in ca5 as |'a'|'b'|'c'|'d'|'\0'|

    char *c4="abcd";        //gives ERROR       very bad and risky
    first they are stored in temporary memory as "abcd"
    and address of 'a' from "abcd" in temporary memory is stored in pointer c4
    it is very very RISKY and very very bad practice
    */


    // functions and pointers
    int value=5;
    int *p3=&value;
    print(p3);

    update(p3);
    update(&value);     //both are same
    
    cout<<"outside: before update function->\t"<<p3<<'\n';
    updatevalueaddress(p3);
    cout<<"outside: after update function->\t"<<p3<<"\tNO CHANGE due to PASS BY VALUE"<<'\n';
    cout<<'\n';

    printaddress(p3);
    cout<<"outside:->\t"<<&p3<<"\tDIFF addresses due to PASS BY VALUE (a copy of pointer is created)"<<'\n';
    cout<<'\n';

    cout<<"array is\n";
    printArray(arr, 10);

    cout<<"sum is "<<getSum(arr,3);
    cout<<'\n';
    cout<<"sum is "<<getSum2(arr,3);
    cout<<'\n';

    passing_arr(arr,3);
    cout<<"outside-> size of arr is "<<sizeof(arr)<<"\t size of an entire array\n";
    cout<<'\n';

    // benifit od passing pointer in the function in case of array
    // by this we can send a part of an array inside the function by passing (arr+i) instead of arr
    cout<<"sum of part is "<<getSum(arr+1,1)<<'\n';     //only {20} is passed
    cout<<"sum of part is "<<getSum(arr+1,2)<<'\n';     //only {20,30} is passed
    cout<<"sum of part is "<<getSum2(arr+2,1);          //only {30} is passed


    return 0;
}