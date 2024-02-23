#include<iostream>
using namespace std;
int main()
{

    // always keep in mind, jb heap me koi memory use kri hai to , jb uska kaam khtm ho jayega, to use free bhi krni hai

    int m,n;
    cin>>m>>n;
    // int arr[m][n];       BAD practice
    // 2d arry-> multiple rows-> multiple 1d arrays
    int **arr= new int*[m];     //arrays of m pointers acting as pointing to m rows     a column is declared with column size m     as arr is pointing to m pointers, it is a declared as double pointer
    for(int i=0; i<m; i++){
        arr[i]=new int[n];      //1d array acting as all columns of a single row    a row is declared with row size n
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>(arr[i])[j];       //from this, we get to know that arr[i][j] and (arr[i])[j] are same
        }
    }
    cout<<'\n';

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<(arr[i])[j]<<' ';
        }
        cout<<endl;
    }
    // we have to manually free the heap memory
    // to free the memory in 2d array, first we have to free all the arrays of columns, then we have to free array of rows

    // releasing memory

    for(int i=0; i<m; i++){
        delete []arr[i];
    }
    delete []arr;

    /*
    HOMEWORK
    // create a jaggered array dynamically
    */



    return 0;
}