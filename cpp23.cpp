#include<bits/stdc++.h>
using namespace std;

void findkey(int a[][4], int key, int m, int n){       //we need to specify number of columns, when passing a 2d array as a parameter
    int flag=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(key==a[i][j]){
                cout<<"key is found (first) at index "<<i<<", "<<j<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==0){
        cout<<"key is not found\n";
    }
}

void findkey2(int a[][4], int key,int m, int n){       //we need to specify a column size, when passing a 2d array as a parameter
    int flag=0;
    cout<<"key is found at index ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(key==a[i][j]){
                flag=1;
                cout<<"("<<i<<", "<<j<<"),  ";
            }
        }
    }
    if(flag==0){
        cout<<"key is not found\n";
    }
}

int main()
{
    
    /*
    how 2d array is stored in memory
    _|___|___|___|_     row wise inserting in the memory
    _|_0_|_1_|_2_|_     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  -> representation of 2d array in memory
    _|_3_|_4_|_5_|_     ind= c*i+j  ind:index of 1 d array in memory 
    _|_6_|_7_|_8_|_                 c: number of columns in a row in 2d array
     |   |   |   |                  i: rowth index of that element  j: columnth index of that element
                                    total number of elements=r*c

    how to create
    int a[number of rows][number of columns];
    cin>>a[i][j];
    cout<<a[i][j];

    _|_________|_________|_________|_
     |         |         |         |     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |  -> representation of 2d array in memory
     | a[0][0] | a[0][1] | a[0][2] |
    _|_________|_________|_________|_
     |         |         |         |
     | a[1][0] | a[1][1] | a[1][2] |
    _|_________|_________|_________|_
     |         |         |         |
     | a[2][0] | a[2][1] | a[2][2] |
    _|_________|_________|_________|_
     |         |         |         |
    */

    int m,n;
    cin>>m>>n;

    cout<<"a\n";
    // input row wise
    int a[m][n];
    cout<<"enter row wise input\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    // print a
    cout<<'\n';
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    
    // enter col wise
    cout<<"enter col wise input\n";
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            cin>>a[i][j];
        }
    }

    // print a
    cout<<'\n';
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n\n";



    cout<<"a2\n";
    // input a2
    // int a2[m][n]={1};
    int a2[m][n]={1,2,3,4,5,6,7,8,9,10};    //why not printing all elements from 5to 10

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a2[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';

    // input rowwise
    cout<<"enter row wise input\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a2[i][j];      //overwrites a[0][0]
        }
    }
    cout<<'\n';

    // print a2
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a2[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n\n";



    cout<<"a3\n";
    // inpput a3
    int a3[3][4]={1,2,3,4,5,6,7,8,9,0};
    // print a3
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<a3[i][j]<<' ';        //get 0 which are not initialised
        }
        cout<<'\n';
    }
    cout<<"\n\n";



    cout<<"a4\n";
    // input a4
    int a4[3][4]={1,2,3,4,5,6,7,8,9,0};     //inserting is row-wise

    // print a4
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<a4[i][j]<<' ';        //get 0 which are not initialised
        }
        cout<<'\n';
    }
    cout<<'\n';

    // input only some elements
    cout<<"enter only some row wise input\n";
    for(int i=2; i<3; i++){
        for(int j=2; j<4; j++){
            cin>>a4[i][j];
        }
    }
    cout<<'\n';

    // print a4
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<a4[i][j]<<' ';        //get 0 which are not initialised
        }
        cout<<'\n';
    }
    cout<<'\n';
    
    

    cout<<"a5\n";
    // input a5
    int a5[3][4]={{1}, {2,4}, {3,5,6}};     //inserting is row-wise (phle ek row ke poore dalenge)

    // print a5
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<a5[i][j]<<' ';        //get 0 which are not initialised
        }
        cout<<'\n';
    }
    cout<<'\n';



    cout<<"a6\n";
    // input number of rows and columns
    cout<<"enter number of rows \n";
    cin>>m;
    int a6[m][4];

    // input row wise
    cout<<"enter row wise input\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<4; j++){
            cin>>a6[i][j];
        }
    }
    cout<<'\n';

    cout<<"enter the element to be searched\n";
    int key;
    cin>>key;

    findkey(a6,key,m,n);
    cout<<'\n';
    // findkey2(a6,key,m,n);
    cout<<"\n\n";
    


    cout<<"a7\n";
    int a7[m][n];
    // input a7
    cout<<"enter row wise input\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a7[i][j];
        }
    }
    cout<<'\n';


    cout<<"row-wise sums are: \n";
    for(int i=0; i<m; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=a7[i][j];
        }
        cout<<sum<<' ';
    }
    cout<<'\n';
    

    cout<<"col-wise sums are: \n";
    for(int j=0; j<n; j++){
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=a7[i][j];
        }
        cout<<sum<<' ';
    }
    cout<<'\n';


    cout<<"largest and smallest row-wise sum : \n";
    int Max=INT_MIN, Min=INT_MAX, Maxind=-1, Minind=-1;
    for(int i=0; i<m; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=a7[i][j];
        }
        if(sum>Max){
            Max=sum;
            Maxind=i;
        }
        if(sum<Min){
            Min=sum;
            Minind=i;
        }
    }
    cout<<"largest row-wise sum is "<<Max<<" at index "<<Maxind<<'\n';
    cout<<"smallest row-wise sum is "<<Min<<" at index "<<Minind<<'\n';
    cout<<'\n';
    

    cout<<"largest and smallest col-wise sum : \n";
    Max=INT_MIN, Min=INT_MAX;
    Maxind=-1, Minind=-1;
    for(int j=0; j<n; j++){
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=a7[i][j];
        }
        if(sum>Max){
            Max=sum;
            Maxind=j;
        }
        if(sum<Min){
            Min=sum;
            Minind=j;
        }
    }
    cout<<"largest col-wise sum is "<<Max<<" at index "<<Maxind<<'\n';
    cout<<"smallest col-wise sum is "<<Min<<" at index "<<Minind<<'\n';
    cout<<'\n';
    

    // waveform output
    // vector<vector<int>>       //same as 2d array of int type
    cout<<"wave form is\n";
    for(int j=0; j<n; j++){
        if(j&1){
            for(int i=m-1; i>=0; i--)
                cout<<a7[i][j]<<' ';
        }
        else{
            for(int i=0; i<m; i++)
                cout<<a7[i][j]<<' ';
        }
    }
    cout<<'\n';


    // spiral form
    cout<<"Spiral Form\n";
    cout<<"enter number of rows and columns\n";
    cin>>m>>n;
    int a7_2[m][n];
    cout<<"enter elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a7_2[i][j];
        }
    }
    int count=m*n;
    int blength=count;
    int b[count];
    int sr=0, sc=0, er=m-1, ec=n-1, k=0;
    // sr->starting row
    // sc->starting column
    // er->ending row
    // ec->ending column
    while(count){
        // starting row
        for(int j=sc; j<=ec && count>0; j++){
            b[k++]=a7_2[sr][j];
            count--;
        }
        sr++;

        // ending column
        for(int i=sr; i<=er && count>0; i++){
            b[k++]=a7_2[i][ec];
            count--;
        }
        ec--;


        // ending row
        for(int j=ec; j>=sc && count>0; j--){
            b[k++]=a7_2[er][j];
            count--;
        }
        er--;

        // starting column
        for(int i=er; i>=sr && count>0; i--){
            b[k++]=a7_2[i][sc];
            count--;
        }
        sc++;
    }

    for(int i=0; i<blength; i++){
        cout<<b[i]<<' ';
    }
    cout<<"\n\n";


    // rotate array by 90 degree 
    cout<<"rotate array by 90 degree\n";
    cin>>m>>n;
    int a7_3[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a7_3[i][j];
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a7_3[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    
    int b2[n][m];

    for(int ia=0; ia<m; ia++){
        int jb=m-ia-1;
        for(int ja=0;  ja<n;  ja++){
            int ib=ja;
            b2[ib][jb]=a7_3[ia][ja];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<b2[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';


    // binary search
    cout<<"input number of rows and cols\n";
    cin>>m>>n;
    int a8[m][n];
    // int row=a8.size();
    // int col=a8[0].size();
    cout<<"input sorted elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            cin>>a8[i][j];
        }
    }
    cout<<"input the element to be searched\n";
    cin>>key;
    int s=0, e=m*n-1, mid=s+(e-s)/2, flag=0;;
    while(s<e){
        int r=mid/n;
        int c=mid%n;
        if(key>a8[r][c]){
            s=mid+1;
        }
        else if(key<a8[r][c]){
            e=mid-1;
        }
        else{
            cout<<"element found\n";
            flag=1;
            break;
        }
        mid=s+(e-s)/2;
    }
    if(flag==0){
        cout<<"element not found\n";
    }
    cout<<'\n';
    // mid, s and e are of a linear array form of 2d array
    // time complexity- O(log(m*n))


    // elements are sorted row wise and col wise method1
    cout<<"elements are sorted row wise and col wise method1\n";
    cout<<"a9\n";
    cout<<"input number of rows and cols\n";
    cin>>m>>n;
    int a9[m][n];
    cout<<"input sorted elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            cin>>a9[i][j];
        }
    }
    cout<<"input the element to be searched\n";
    cin>>key;
    flag=0;
    for(int i=0; i<m; i++){
        int j=i;
        // horizontal
        for(j=i; j<n*i; j++){
            if(key==a9[i][j]){
                cout<<"element fount at index "<<i<<' '<<j<<'\n';
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
        j=i;
        for(i; i<=n*(m-1)+j; i+=n){
            if(key==a9[i][j]){
                cout<<"element fount at index "<<i<<' '<<j<<'\n';
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
        i=j;
    }
    if(flag==0){
        cout<<"element not found\n";
    }
    cout<<"\n\n";


    // elements are sorted row wise and col wise method2
    cout<<"elements are sorted row wise and col wise method2 \na10\n";
    array < array<int,4> , 4 > a10;
    m=a10.size();
    cout<<m<<'\n';
    n=a10[0].size();
    cout<<n<<'\n';

    /*  input
        1 2  3  4
        2 3  4  5
        4 5  6  7
        8 9 10 11
    */

    cout<<"input sorted elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a10[i][j];
        }
    }

    cin>>key;

    int i=0, j=n-1;
    flag=0;
    while(1<m && j>=0){
        if(key==a10[i][j]){
            flag=1;
            cout<<"present at "<<i<<' '<<j<<'\n';
            break;
        }
        else if(key>a10[i][j]){
            i++;
        }
        else{
            j--;
        }
    }
    if(flag==0){
        cout<<"not present\n";
    }

    /*
    //rotated array by 90 degree


    */

    
    return 0;
}