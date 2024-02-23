#include<bits/stdc++.h>
using namespace std;

void printarray1(int a[], int size){        //better due to line 112
    int i=0;
    for(i; i<size; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

// void printarray2(int a[]){       
//     int i=0, size=sizeof(a)/sizeof(a[0]);
//     for(i;i<size; i++){
//         cout<<a[i]<<' ';
//     }
//     cout<<'\n';
// }

void printarray3(int a[10]){        //can be done but it is bad approach as it will only work for an array of size 10
    int i=0;
    for(i;i<10; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void minmax1(int a[], int size){
    int i=0, min=INT_MAX, max=INT_MIN;  //INT64_MAX and INT64_MIN are not valid as they are out of range of int, range of int is INT32_MIN to INT32_MAX
    // we have to use bits/stdc++.h for using INT_MAX and INT_MIN
    for(i=0; i<size; i++){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    cout<<"max and min of an array using minmax1 are "<<max<<" and "<<min<<'\n';
}

void minmax2(int a[], int size){
    int i=0, Min=INT_MAX, Max=INT_MIN;  //INT64_MAX and INT64_MIN are not valid as they are out of range of int, range of int is INT32_MIN to INT32_MAX
    // we have to use bits/stdc++.h for using INT_MAX and INT_MIN
    for(i=0; i<size; i++){
        Max=max(Max,a[i]);
        Min=min(Min,a[i]);
        // max=max(max,a[i]);       we can declare max and min only when we dont use max and min functions
        // min=min(min,a[i]);       we can declare max and min only when we dont use max and min functions
    }
    cout<<"max and min of an array using minmax2 are "<<Max<<" and "<<Min<<'\n';
}

void update(int a[], int size){     //in functions, here a is an address that is passed, not an whole array     and that address tells the add of first location in an array
    cout<<"a12 inside update function\n";
    // updatation
    a[0]=100;
    for(int i=0; i<5; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

bool linearSearch(int a[], int size, int item){
    for(int i=0; i<size; i++){
        if(item==a[i]){
            return true;
        }
    }
    return false;
}

void reverse(int a[], int size){
    for(int i=0, j=size-1; i<j; i++, j--){
        swap(a[i],a[j]);
    }
    cout<<"reverse array in reverse function\n";
    for(int i=0; i<size; i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main()
{
    /*
    array
        list of storing datas/values/items/elements of same datatype
        values stored in the memory are in contiguous locations
        can access array and their elements/values through index
        when we want to store multiple similar values in a single variable
    
    declaration-
        datatype name[size];        //size is length of array, not the number of bytes
            name also shows the address of the first location of an array
            a contiguous n(size of array) memory locations are defined in memory 
            initially the values of each element contain garbage value (random value)
        
        int a[5];
        a is an array having 5 elements with random values
    
    access-
        indexing is from 0 to size-1
        a[k]->  value at (k)th index   or  value at (k+1)th location(if starts with 1) 
        make sure what you are accessing is with in the range of size of an array
    
    addressing
        base address BA is the address of the 0th index of an array and it is also an address of array
        int a[5];
        a = returns BA
        add of a[0] = BA
        add of a[1] = BA + 1*size of int(size of a[0]) 
        add of a[2] = BA + 2*size of int(size of a[0] and a[1]) 
        add of a[n] = BA + n*size of int(size of a[0], a[1],..., a[n-1]) 
    
    initialisation
        int num[];
            []
        int num[3];
            [gv, gv, gv]
        int num[3] = {5,7,11};
            [5, 7, 11]
        int num[] = {1,2,3};
            [1, 2, 3]
        int num[3] = {0};       // initialise all values with 0
            [0, 0, 0]           // only in the case of 0
        int num[3] = {1};       // the rest of them will be 0
            [1, 0, 0]
        int num[4] = {1,2};     // the rest of them will be 0
            [1, 2, 0, 0]
        int num[4];
        fill_n(num, 4, 1);      // populate first 4 elements with 1
            // fill_n(name, number of elements, value)
            [1, 1, 1, 1]
        int num[4];
        fill_n(num, 2, 1);      // populate first 2 elements with 1 and rest of them with gv
            [1, 1, gv, gv]
    */

    // accessing all elements of an array
    int i=0;
    int a1[3];
    for(i=0; i<3; i++){
        cout<<a1[i]<<' ';        //give garbage value gv
    }
    cout<<'\n';
    cout<<"value of a1[4] is "<<a1[4]<<'\n';      //give garbage value gv
    cout<<'\n';


    int a2[3]={5,7,11};
    for(i=0; i<3; i++){
        cout<<a2[i]<<' ';
    }
    cout<<'\n';
    cout<<"value of a2[4] is "<<a2[4]<<'\n';      //give garbage value gv
    cout<<'\n';


    int a3[3]={5,7};
    for(i=0; i<3; i++){
        cout<<a3[i]<<' ';       //a3[2] will give 0
    }
    cout<<'\n';
    cout<<"value of a3[4] is "<<a3[4]<<'\n';      //give garbage value gv
    cout<<'\n';


    int a4[3]={0};
    for(i=0; i<3; i++){
        cout<<a4[i]<<' ';       //all will give 0
    }
    cout<<'\n';
    cout<<"value of a4[4] is "<<a4[4]<<'\n';      //give garbage value gv
    cout<<'\n';


    int a5[3]={5};
    for(i=0; i<3; i++){
        cout<<a5[i]<<' ';       //a5[0] is 5 and all others will give 0
    }
    cout<<'\n';
    cout<<"value of a5[47465] is "<<a5[47465]<<'\n';      //give garbage value gv
    cout<<'\n';


    cout<<"print a5 using printarray1\n";
    printarray1(a5,3);

    // printarray2(a5);
    cout<<"print a5 using printarray3 (bad approach)\n";
    printarray3(a5);
    cout<<'\n';


    // length of array
    int a1size = sizeof(a1) / sizeof(int);
    cout << a1size << '\n';
    int a2size = sizeof(a2) / sizeof(a2[0]);
    cout << a2size << '\n';
    int a3size = sizeof(a3) / sizeof(a3[0]);
    cout << a3size << '\n';
    int a4size = sizeof(a4) / sizeof(a4[0]);
    cout << a4size << '\n';
    int a5size = sizeof(a5) / sizeof(a5[0]);        //i want 1 here as i only give one element in a5, but it will give the total number of elements that are defined in an array
    cout << a5size << '\n';
    cout<<'\n';


    int a6[3]={5,'a'};
    for(i=0; i<3; i++){
        cout<<a6[i]<<' ';       //a6[0] is 5, a6[1] is 97(ASCII value of a) and all others will give 0
    }
    cout<<'\n';
    cout<<"value of a6[47465] is "<<a6[47465]<<'\n';      //give garbage value gv
    cout<<'\n';


    char a7[3]={5,'a'};
    for(i=0; i<3; i++){
        cout<<a7[i]<<' ';       //a7[0] gives a char of ASCII value 5 and all others will give nothing
    }
    cout<<'\n';
    cout<<"value of a7[47465] is "<<a7[47465]<<'\n';      //give garbage value gv
    cout<<'\n';

    float a8[3]={5,'a'};
    for(i=0; i<3; i++){
        cout<<a8[i]<<' ';       //a8[0] is 5, a8[1] is 97(ASCII value of a) and all others will give 0
    }
    cout<<"\n\n";


    double a9[3]={5,'a'};
    for(i=0; i<3; i++){
        cout<<a9[i]<<' ';       //a9[0] is 5, a9[1] is 97(ASCII value of a) and all others will give 0
    }
    cout<<"\n\n";

    bool a10[5]={5,'a',1};
    for(i=0; i<5; i++){
        cout<<a10[i]<<' ';       //all initialised items (without 0) will give 1 and non-initialised items will give 0
    }
    cout<<'\n';
    cout<<'\n';




    // a[variable size] is worse than a[very big size]
    // a11[sizea8] is worse than a11[100000]
    int a11[1000],sizea11;
    cout<<"input size of an array\n";
    cin>>sizea11;
    for(i=0; i<sizea11; i++){
        cin>>a11[i];        // taking input in an array
    }
    minmax1(a11,sizea11);
    minmax2(a11,sizea11);
    cout<<'\n';



    /*
    when we write function: name(a[], size){}, we send the ADDRESS of 0th index of array a by which UNLIKE in case of variable, a new copy of an array is NOT created, all updatation is going on in the actual array, so mind it
    copy of an array is NOT created in the function 
    */
    int a12[5]={1,2,3,4,5};
    cout<<"a12 before update function\n";
    for(i=0; i<5; i++){
        cout<<a12[i]<<' ';
    }
    cout<<'\n';
    update(a12,5);
    cout<<"a12 after update function\n";
    for(i=0; i<5; i++){
        cout<<a12[i]<<' ';
    }
    cout<<"\n\n";



    // linear search
    int a13[5]={1,2,3,4,5};
    cout<<"input the element to be searched\n";
    int item;
    cin>>item;
    cout<<linearSearch(a13, 5, item)<<"\n";
    if(linearSearch(a13, 5, item)){
        cout<<"item is present";
    }
    else{
        cout<<"item is not present";
    }
    cout<<"\n\n";



    // reverse an array
    int sizea14, a14[100];
    cout<<"input number of elements\n";
    cin>>sizea14;
    cout<<"input elements in an array\n";
    for(i=0; i<sizea14; i++){
        cin>>a14[i];
    }
    reverse(a14, sizea14);
    cout<<"reverse array in main function after reverse function\n";
    for(int i=0; i<sizea14; i++){
        cout<<a14[i]<<' ';
    }
    cout<<"\n\n";
    cout<<"\n\n";


    /*HOMEWORK
    //how to initialize an entire array from any value without a loop

    //input- size of an array, elements of an array;    output- sum of all elements in an array

    GOOD QUESTION
    //ispowerof2 by using number of set bits
    */

    //how to initialize an entire array from any value without a loop
    int a15[100], sizea15;
    cout<<"input number of elements of an array\n";
    cin>>sizea15;
    cout<<"input elements of an array\n";
    fill_n(a15, sizea15, 10);
    for(i=0; i<sizea15; i++){
        cout<<a15[i]<<' ';
    }
    cout<<'\n';
    
    //input- size of an array, elements of array;   output- sum of all elements in an array
    int a16[100],sizea16,sum=0;
    cout<<"input number of elements of an array\n";
    cin>>sizea16;
    cout<<"input elements of an array\n";
    for(i=0; i<sizea16; i++){
        cin>>a16[i];
        sum+=a16[i];
    }
    cout<<sum<<"\n\n";

    // GOOD QUESTION
    //ispowerof2 by using number of set bits
    int n;
    cout<<"input n\n";
    cin>>n;
    int ans = 0;
    while(n){
        if(n&1){
            ans++;
        }
        n = n>>1;
    }
    if(ans==1){
        cout<<"is a power of 2\n\n";
    }
    else{
        cout<<"is not a power of 2\n\n";
    }

    return 0;
}