#include<iostream>
using namespace std;

void updatepointers(int ***p){
    cout<<"inside: before update function->\t"<<p<<' '<<*p<<' '<<**p<<' '<<***p<<' '<<'\n';
    ***p++;
    **p++;
    *p++;
    p++;
    cout<<"inside: after update function->\t"<<p<<' '<<*p<<' '<<**p<<' '<<***p<<' '<<'\n';
}

void update(int *p){
    *p=(*p)*2;
}

void increament(int **p){
    ++(**p);
}

int main(){

    /*
    pointer me jiska address dlta hai, pointer use point krta hai
    pointer hmesha address hi store krega
    how to read->
    *-> value at
    &-> address of
    */

    int i=5;
    // int p1=&i;
    int *p1=&i;
    // int *p2=&p1;     //ERROR
    int **p2=&p1;       //double pointer-> pointer pointing to pointer p1
    int * * * p3=&p2;      //triple pointer-> pointer pointing to pointer p2 that points to pointer p1
                        //and so on
    cout<<"p1 -> "<<p1<<'\n';
    cout<<"*p1 -> "<<*p1<<'\n';
    cout<<"&p1 -> "<<&p1<<'\n';
    cout<<"p2 -> "<<p2<<"\t\t(&p1)\n";
    cout<<"*p2 -> "<<*p2<<"\t\t(p1)\n";
    cout<<"&p2 -> "<<&p2<<'\n';
    cout<<"p3 -> "<<p3<<"\t\t(&p2)\n";
    cout<<"*p3 -> "<<*p3<<"\t\t(p2)\t(&p1)\n";
    cout<<"&p3 -> "<<&p3<<'\n';
    cout<<'\n';

    cout<<"*p1 -> "<<*p1<<"\t\t(*(p1))\t(i)\n";
    cout<<"**p2 -> "<<**p2<<"\t\t(*(*p2))\t(*(p1))\t(i)\n";
    cout<<"***p3 -> "<<***p3<<"\t\t(*(*(*p3)))\t(*(*p2))\t(*(p1))\t(i)\n";
    cout<<'\n';

    cout<<"&i -> "<<&i<<"\t\t\n";
    cout<<"p1 -> "<<p1<<"\t\t\n";
    cout<<"*p2 -> "<<*p2<<"\t\t(*p2)    (p1)\n";
    cout<<"**p3 -> "<<**p3<<"\t(*(*p3))    (*p2)    (p1)\n";
    cout<<'\n';

    cout<<"outside: before update function->\t"<<p3<<' '<<*p3<<' '<<**p3<<' '<<***p3<<' '<<'\n';
    // updatepointers(p3);
    cout<<"outside: after update function->\t"<<p3<<' '<<*p3<<' '<<**p3<<' '<<***p3<<' '<<'\n';
    cout<<'\n';

    int first=8, second=18;
    int *p4=&second;
    *p4=9;
    cout<<"first is "<<first<<"\tsecond is "<<second<<'\n';
    cout<<'\n';

    first=6;
    p4=&first;
    int *p5=p4;
    (*p5)++;
    cout<<"first is "<<first<<'\n';
    cout<<'\n';
    
    first=8;
    int *p6=&first;
    cout<<(*p6)++<<'\n';
    cout<<"first is "<<first<<'\n';
    cout<<'\n';

    int *p7=0;
    first=110;
    // *p7=first;      //it is like insert 110 in the content of NULL
    // should be initialised like p7=&first
    // cout<<*p7<<'\n';        //gives ERROR

    int *p8=0;
    first=110;
    p8=&first;
    cout<<*p8<<'\n';
    cout<<'\n';

    first=8, second=11;
    int *p9=&second;
    first=*p9;
    *p9= *p9 +2;
    cout<<"first is "<<first<<"\tsecond is "<<second<<'\n';
    cout<<'\n';

    float f1=12.5;
    float f2=21.5;
    float *p10=&f1;
    (*p10)++;
    *p10=f2;
    cout<<*p10<<' '<<f1<<' '<<f2<<'\n';
    cout<<'\n';

    int arr1[5];
    int *p11;
    cout<<sizeof(arr1)<<" "<<sizeof(p11)/*size of address*/<<endl;
    cout<<'\n';

    int arr2[]={11,21,13,14};       //CAN WE DECLARE ARRAY WITHOUT ITS SIZE??
    cout<<*(arr2)<<' '<<*(arr2+1)<<'\n';
    cout<<'\n';

    int arr3[6]={11,12,31};
    cout<<arr3<<' '<<&arr3<<endl;
    cout<<'\n';
    
    int arr4[6]={11,21,13};
    cout<<arr4+1<<' '<<&arr4<<endl;
    cout<<'\n';

    int arr5[6]={11,21,31};
    int *p12=arr5;
    cout<<p12[2]<<'\n';         //p12[2] is *(p+2) is *(&arr[0]+2) / *(arr+2)
                                //SHOW THAT p12[2] is *(p+2)
    cout<<'\n';

    int arr6[]={11,12,13,14,15};
    cout<<*(arr6)<<' '<<*(arr6+3)<<'\n';
    cout<<'\n';


    int arr7[]={11,21,31,41};
    // int *p13=arr7++;     //GIVE ERROR        we can't update arr as it is in the symbol table
    int *p13=arr7+1;
    cout<<*p13<<'\n';
    cout<<'\n';

    char ch1='a';
    char *p14=&ch1;
    ch1++;
    cout<<*p14<<'\n';
    cout<<'\n';

    char arr8[]="abcde";
    char *p15=&arr8[0];
    cout<<p15<<' '<<arr8<<endl;
    cout<<'\n';
   
    char arr9[]="abcde";
    char *p16=&arr9[0];
    p16++;
    cout<<p16<<' '<<arr9<<endl;
    cout<<'\n';
    
    char arr10[]="abcde";
    char *p17=arr10;
    cout<<arr10[0]<<" "<<p17[0]<<' '<<endl;     //p17[0] is *(p17 + 0) is *(p17)
    cout<<'\n';

    i=10;
    update(&i);
    // update(p);   here for pointer p, we always send address of the pointer
    cout<<i<<endl;
    cout<<'\n';

    first=110;
    int *p18=&first;
    int **p19=&p18;
    second=(**p19)++ + 9;
    cout<<first<<' '<<second<<'\n';
    cout<<'\n';

    first=100;
    int *p20=&first;
    int **p21=&p20;
    second=++(**p21);
    int *p22=*p21;
    ++(*p22);
    cout<<first<<' '<<second<<'\n';
    cout<<'\n';
    
    int num=110;
    int *p23=&num;
    increament(&p23);
    cout<<num<<'\n';
    cout<<'\n';

    return 0;
}