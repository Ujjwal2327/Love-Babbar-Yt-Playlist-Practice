#include<bits/stdc++.h>
using namespace std;
int main(){

    /*
    int num=5;      //a memory block of name num is made and store in the memory
                    //memory block doesn't have names like in the above line
    memory has address and then content is present in that address
    memory has symbol table which maps name and address (that contains content of that name)
    num is map to address and then that adsress is mapped with 5
    so a block is created on address A and has content 5 and num is mapped to that address A in symbol table
    Symbol Table is an important data structure created and maintained by the compiler in order to keep track of semantics of variables i.e. it stores information about the scope and binding information about names, information about instances of various entities such as variable and function names, classes, objects, etc.
    content of symbol table cannot be change
        &num=&num+1;    gives ERROR
        address of a variable is not assignable
    */
    int num=5;
    cout<<num<<"\n\n";
    // go to n8um in symbol table, num is mapped with A address, give the content that is present at A


    // address of operator- &nameofoperator
    cout<<"address of num is "<<&num<<" given in hexadecimal form"<<"\n\n";


    /*
    pointer
    used to store the address and points to that variable
    datatypeofvariablename *ptrname = &variablename    ->right declaration
    datatypeofvariablename *ptrname            ->very very bad declaration     a pointer with address of garbage value
                        very bad and risky practice     it means you point it to unknown memory (a memory that is perhaps not a memory of our program)
    always initialize with some value (either with variablenameaddress or with NULL value)
    int *ptr=0;
    int *ptr = &num;
    memory block of ptr is created and address of num is put in it
    in symbol table- ptr <-> A1 (address of ptr) and points to the value/address stored in A1
    A1 contains the address A2 (address of num), so ptr points to num
    process will continue until address/ memory block contains the value
o   &num is A2
    */
    int *p1=&num;       //p1 is a pointer to int datatype   same type of pointer as the type of variable it points
    // now both num (in the symbol table) and *p1 are pointing to the same address
    // The asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier) and should not be confused with the dereference operato
    char a;
    char *p1_2=&a;
    num++;
    cout<<num<<'\n';
    (*p1)++;        //will increase the value of num 
                    //increase the value at address pointed by p1
    cout<<"num is "<<num<<'\n';        //no change () is necessary
    cout<<"*p1 is "<<*p1<<'\n';        //* is dereference operator      returns value at the address pointed by p1
    cout<<"p1 is "<<p1<<" (value present in p1 / address of num)"<<"\n\n";     //print the value preasent in p1
    
    *p1++;      // act as *(p1++)
                // by increament by 1, it goes to point out next int / location and that is of size 4 in memory
    cout<<"num is "<<num<<'\n';        //no change () is necessary
    cout<<"*p1 is "<<*p1<<" (gv)\n";        //* is dereference operator      returns value at the address pointed by p1
    cout<<"p1 is "<<p1<<" (changed) increase by 4 as it is of int type "<<"\n\n";     //print the value preasent in p1

    cout<<"sizeof num (storing integer) is "<<sizeof(num)<<"\n";
    cout<<"sizeof *p1 (storing intege) is "<<sizeof(*p1)<<"\n";      //* is dereference operator     (pointing to num), so size of num
    cout<<"sizeof p1 (storing address) is "<<sizeof(p1)<<"\n";        //storing address, doesn't matter the type of variable whose address is stored        compiler dependent
    cout<<'\n';

    // int *ptr;       // pointer to int is created and pointed to some gv
    int *ptr=0;
    // cout<<"*ptr is "<<*ptr<<'\n';    //will stop the execution
    cout<< "size of *ptr (pointing to NULL), of int datatype is " << sizeof(*ptr) << '\n';      //* is dereference operator
    cout<< "ptr is (address of NULL pointer is) " << ptr << '\n';
    cout<< "size of ptr (storing address) is " << sizeof(ptr) << '\n';       //doesn't matter the tyoe of variable whose address is stored
    cout<<'\n';

    int num1=5;
    int num2=num1;      //a new memory block of num2 is created and value of num1 is inserted in it

    // pointer me jiska address dlta hai, pointer use point krta hai
    p1=&num;
    // int p2=&num;
    int *p2=0;
    // *p2=num;     //give ERROR, Not initialised like this
    p2=&num;        //these 2 lines are same as int p2=&num;
    int *p3=p2;     //copying a pointer
    int *p4=&(*p3);     //&*p3 and &(*p3) are same
    cout<<"*p1 (means where the pointer p1 points) is "<<*p1<<'\n';
    cout<<"*p2 is "<<*p2<<'\n';
    cout<<"*p3 is "<<*p3<<'\n';
    cout<<"*p4 is "<<*p4<<'\n';
    cout<<"p1 is "<<p1<<'\n';
    cout<<"p2 is "<<p2<<'\n';
    cout<<"p3 is "<<p3<<'\n';
    cout<<"p4 is "<<p4<<'\n';
    cout<<"&p1 is "<<&p1<<'\n';
    cout<<"&p2 is "<<&p2<<'\n';
    cout<<"&p3 is "<<&p3<<'\n';
    cout<<"&p4 is "<<&p4<<'\n';
    cout<<"&(*p1) is &(num) is "<<&(*p1)<<'\n';
    cout<<"&(*p2) is &(num) is "<<&(*p2)<<'\n';
    cout<<"&(*p3) is &(num) is "<<&(*p3)<<'\n';
    cout<<"&(*p4) is &(num) is "<<&(*p4)<<'\n';
    cout<<'\n';

    /*
    int p3=0;
    *p3=&num;   //INVALID
    */

    int a1=num;
    a1*=10;
    cout<<"num is "<<num<<'\n';
    cout<<"a1 is "<<a1<<'\n';

    int a2=*p1;     //int *p1=&num    [defined above],so a pointer p1 stores address of num and points to that address that stoes value of num, so *p1 points to the value of num
    a2*=10;
    cout<<"num is "<<num<<'\n';
    cout<<"a2 is "<<a2<<'\n';

    (*p1)*=10;
    cout<<"num is "<<num<<'\n';
    
    // pointer hmesha address hi store krega jiski vjha se pointer ke content pr hm operations nhi lga skte except + and - with a integer value (increament and decreament)
    cout<<"p1 is "<<p1<<'\n';
    p1++;                   //increase by 4(as *p1 is an integer which takes 4 bytes, so the next address will be 4 ahead of p1)    goes to next memory location
    cout<<"p1 is "<<p1<<'\n';
    p1=p1+1;                //increase by 4
    cout<<"p1 is "<<p1<<'\n';
    p1=p1-1;                //decrease by 4
    cout<<"p1 is "<<p1<<'\n';
    p1=p1-2;                //decrease by 8
    cout<<"p1 is "<<p1<<'\n';
    p1=p1+2;                //increase by 8
    cout<<"p1 is "<<p1<<'\n';

    cout<<"num is "<<num<<'\n';    //no effect
    cout<<"*p1 is "<<*p1<<'\n';    //now it does not points num as its stored address is changes


    /*
    HOMEWORK
    code studio pointers theory and problems
    difference between *ptr and (*ptr)      both are same but use () always
    difference between *ptr++ and (*ptr)++
    */

    return 0;
}