/*
procedure to solve a programme
problem
understand
given values
approach
rough sol- flowchart and pseudo code
code of rough sol

flowchart
round rectangle/terminator: start and end
parallelogram: input output
rectangle: calculation / processing     including assigning operators i.e. initialising varibales
rhombus: decision making    yes or no   to check the condition
arrows: connect the diff components and show the flow
circle: connector and used in functions

pseudo code
generic way of representing code
can implement in any language

loops
to do something repeatedly

prograaming language
to instruct a computer to do a particular task in computer language

source code-> compiler-> binary language-> executavle file (file of binary language)-> computer-> running a programme

compiler
for translation and finding error

IDE
integrated development enviornment
where you can write and execute the code
*/

#include<iostream>
using namespace std;
int main()      // everything starts with main function
{
    // print Namaste Duniya and how to start from new line
    // cout<<       to write standard output
    // endl and '\n' are mapped with enter
    // ;    to show the end of a statement
    cout<< "Namaste Duniya"<<endl;
    cout<< "Namaste Duniya ";
    cout<< "Namaste Duniya"<<endl;
    cout<< "Namaste Duniya"<<'\n';
    cout<< "Namaste Duniya\n";
    cout<< "Namaste Duniya";
    cout<<"\n\n";

    // Datatypes and variables
    int a=5;        // a block for a variable a is created in the memory of name a and type integer and store 4 bytes on that block and the content (5) of variable will be stored in that space
    cout<< a<<'\n';

    char b='h';
    cout<< b<<'\n';
    b='7';
    cout<< b<<'\n';

    bool c;
    c=2;
    cout<<c<<'\n';        //stores the boolean value only   0 or 1
    c="hello";
    cout<<c<<'\n';
    c=true;
    cout<<c<<'\n';
    c=false;
    cout<<c<<'\n';
    // bool c;      can't initialuze again

    float d=1.2;
    cout<< d<<'\n';

    double e=1.2;
    cout << e << "\n\n";
    // variable name can't start with digit
    // variable name can start with _

    // sizeof() function        return the size of a variable
    int size = sizeof(a);
    cout << size << '\n';
    cout << sizeof(b) << '\n';
    cout << sizeof(c) << '\n';
    cout << sizeof(d) << '\n';
    cout << sizeof(e) << "\n\n";
    
    /* how datatypes store in memory
    int a=5         32 bits     00000000 00000000 00000000 00000101
    int a=-5        32 bits     11111111 11111111 11111111 11111011     in 2's complement form
    int a=0         32 bits     00000000 00000000 00000000 00000000
    int a=-2^31     32 bits     10000000 00000000 00000000 00000000     in 2's complement form
    now at execution time, left most 1 shows -ve and then take 2's complement of all bits which forms 00000000 00000000 00000000 00000101 that refers to 5 and combinely means -5
    in 2's complement representation, the range is -2^31 to 2^31-1 so number is stored in 2's complement
    if we write -5 as 10000000 00000000 00000000 00000101, then the range would be -2^31-1 to 2^31-1, and to save one more number, we use 2's complement representation
    default is signed integer
    for storing only +ve int, declare unsigned int
    unsigned int u=-5       convert -5 as 2's complement 11111111 11111111 11111111 11111011 and it then act as +ve number which leads to a very big number
    char b='a'      8 bits (can store 0 to 2^8-1)      by ASCii table      ASCII value of the character is stored in binary form in memory
    compiler differentiae between int and char by its declared datatype
    */
    unsigned g=-5;
    cout<<g<<"\n\n";        // it will give 11111111 11111111 11111111 11111011 in deciamal

    // type casting
    a='b';
    cout<<a<<'\n';      //b is typecast into int
    b=98;
    cout<<b<<'\n';      //98 is typecast into char
    b=97;
    cout<<b<<"\n\n";
    // b=12345;
    cout<<b<<"\n\n";      //overflow in implicit constant conversion as char has only 8 bits, so by converting 12345 into binary, char b will only store the last (right most) 8 bits of that binary number

    /*
    operarators
    arithmatic operators
    + - * % /
    int     op   int    always  gives  int
    char    op   int    always  gives  int
    float   op   int    always  gives  float
    int     op   float  always  gives  float
    int     op   double always  gives  double
    double  op   int    always  gives  double
    priotity:   double > float > int > char

    relational operators
    == >= <= > < != 
    use with ()
    returns boolean vlue
    char acts as int by its ASCII value

    assignment operator
    =

    logical operator
    && || !
    returns boolean vlue
    char acts as int by its ASCII value

    bitwise operators
    learn ahead
    */
    cout<<'a'+2<<'\n';      //will give int ASCII value 99, not char value c
    b='a'+2;
    cout<<b<<'\n';          //will give char value c, not int ASCII value 99, as it is typecasted
    cout<<2/5<<'\n';        //will give 0, not 0.4
    cout<<2.0/5<<'\n';      //will give 0.4, not 0
    cout<<2/5.0<<'\n';      //will give 0.4, not 0
    a=7;
    b='7';
    cout<<(a==b)<<'\n';
    cout<<(a>b)<<'\n';
    cout<<(a<b)<<'\n';      //as b stores ASCII value of 7
    cout<<!a<<'\n';
    cout<<!b<<'\n';
    b='0';
    cout<<!b<<'\n';
    a=0;
    cout<<!a<<'\n';
    a=-0;
    cout<<a<<' '<<!a<<'\n';
    a=-7;
    cout<<!a<<'\n';

    /*
    stack overflow
    https://stackoverflow.com/questions/18914106/what-is-the-use-of-using-namespace-std?lq=1
    */

    return 0;
}