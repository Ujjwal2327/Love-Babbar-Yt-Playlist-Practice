/*
    https://cplusplus.com/reference/
    https://cplusplus.com/reference/iterator/
    https://cplusplus.com/reference/stl/
    https://cplusplus.com/reference/algorithm/
*/

#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
int main(){
    
    // array
    int basic[3]={1,2,3};

    // making an array
    // implementation of array stl is done by static array of fixed size
    // array<type,size> name;
    array<int,4>a={10,20,30,40};

    // size of array
    int sizea=a.size();     //time complexity-O(1)
    cout<<sizea<<"\n\n";

    // access all items of an array
    for(int i=0; i<sizea; i++){
        cout<<a[i]<<' ';
    }
    cout<<"\n\n";
    // cout<<a[10]<<'\n';      //gv
    
    // initialize array with 0
    array<int,5>arr1={0};        //all elements are initialised with 0
    array<int,5>arr2={5};        //all elements are initialised with 0 except arr2[0]
    array<int,5>arr3={10,7};        //all elements are initialised with 0 except arr3[0] and arr3[1]

    // access the element at index i;
    cout<<a[2]<<'\n';
    // name.at(index)
    cout<<"element at index 2 is "<<a.at(2)<<"\n\n";      //time complexity-O(1)

    // check whether the array is empty or not
    // name.empty()         return boolean value 0(for nonempty) or 1
    cout<<"Empty or not-> "<<a.empty()<<"\n\n";       //time complexity-O(1)

    // first and last element of an array
    cout<<"first element is "<<a.front()<<'\n';     //time complexity-O(1)
    cout<<"last element is "<<a.back()<<"\n\n";       //time complexity-O(1)
    cout<<"\n";





    // vector   
    // dynamic array       doubles the size when needed        make a new vector with double size of the old vector and store all the elements of the old vector and the old vector gets dead

    // vector<type> name
    vector<int> v;

    // size and capacity
    // capacity and size of new vector is 0
    // size means number of current elements in it
    // capacity is space assign in the memory for how many elements     maximum number of elements that can be inserted
    cout<<"sizeof of vector is "<<sizeof(v)<<'\n';
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<"\n\n";

    // enter a element in a vector at last position
    v.push_back(10);
    cout<<"sizeof vector (constant) is "<<sizeof(v)<<'\n';
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<'\n';     //1
    v.push_back(20);
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<'\n';     //2>1 => 2*1=2
    v.push_back(30);
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<'\n';     //3>2 => 2*2=4
    v.push_back(40);
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<'\n';     //4<=4
    v.push_back(50);
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<"\n\n";     //5>4 => 2*4=8

    cout<<"element at index 3 is "<<v.at(3)<<"\n\n";

    cout<<"first element is "<<v.front()<<'\n';
    cout<<"last element is "<<v.back()<<"\n\n";

    cout<<"elements in a vector before pop"<<'\n';
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    // delete the last element in a vector
    v.pop_back();
    cout<<"elements in a vector after pop"<<'\n';
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    cout<<"size_of vector (constant) is "<<sizeof(v)<<'\n';
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<" (capacity does not changes after definition)\n";
    cout<<"first element is "<<v.front()<<'\n';
    cout<<"last element is "<<v.back()<<"\n\n";

    // delete all elements in a vector
    v.clear();      // size gets 0 but not its capacity
    cout<<"elements in a vector after clear"<<'\n';
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    cout<<"size_of vector (constant) is "<<sizeof(v)<<'\n';
    cout<<"size of vector is "<<v.size()<<'\n';
    cout<<"capacity of vector is "<<v.capacity()<<" (capacity does not changes after definition)\n";
/**/    cout<<"first element is "<<v.front()<<'\n';     //how the first element is 10
    cout<<"last element is "<<v.back()<<'\n';       //gv
    cout<<'\n';

    // cout<<v.begin();
    // cout<<v.at(v.begin());

    // initialize the vector with size and value
    // vector<type> name(size)
    // vector<type> name(size,value)
    vector<int> v2(5,2);
    cout<<"v2 is ";
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<' ';
    }
    cout<<"\n";

    cout<<"v3 is ";
    vector<int> v3(5);      //initialise with 0
    for(int i:v3){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<"v3 is ";
    for(int i=0; i<v3.size(); i++){
        cout<<v3[i]<<' ';
    }
    cout<<'\n';

    // copy a vector
    cout<<"c(v2) is ";
    vector<int>c(v2);
    for(int i=0; i<c.size(); i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
    cout<<"c properties are "<<c.capacity()<<' '<<c.size()<<' '<<c.front()<<' '<<c.back()<<'\n';
    
    cout<<"c2(v) is ";
    vector<int>c2(v);
    for(int i=0; i<c2.size(); i++){
        cout<<c2[i]<<' ';
    }
    cout<<'\n';
    cout<<c2.capacity()<<' '<<c2.size()<<'\n';
/**/    // cout<<c2.capacity()<<' '<<c2.size()<<' '<<c2.front()<<' '<<c2.back()<<'\n';      //why is it not working
    cout<<"\n\n";
    // v3(5,1);      //give ERROR by defining again.

    



    // deque    
    // dynamic, doubly ended queue
    // insertion and deletion from both ends
    deque<int>d;
    d.push_back(10);
    d.push_front(20);
    d.push_back(30);
    d.push_front(40);
    for(int i:d){
        cout<<i<<' ';
    }
    cout<<'\n';
    d.pop_back();
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    d.pop_front();
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    d.pop_back();
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';

    d.push_back(10);
    d.push_front(20);
    d.push_back(30);
    d.push_front(40);
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';

    cout<<"element at index 2 is "<<d.at(2)<<'\n';
    cout<<"first element is "<<d.front()<<'\n';
    cout<<"last element is "<<d.back()<<'\n';
    cout<<"is d empty-> "<<d.empty()<<'\n';
    cout<<d.size()<<'\n';

    d.erase(d.begin(),d.begin()+2);     //d.begin()+2 is not included
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    cout<<d.size()<<'\n';
    cout<<d.max_size()<<'\n';           //always constant   memory allocate to deque

    d.clear();
    for(int i=0; i<d.size(); i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';

    // iterators for begin and end
    // d.begin()
    // d.end()

    cout<<d.size()<<'\n';
    cout<<d.max_size()<<'\n';           //always constant
    cout<<"\n\n";





    // list
    // implemented by doubly linklist(having 2 pointers front and back)
    // direct access is not possible
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_front(30);

    // for(int x:l){
    //     cout<<l<<' ';
    // }
    for(int i:l){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<'\n';

    cout<<"size of list is "<<l.size()<<'\n';

    cout<<"is l empty -> "<<l.empty()<<'\n';

    l.erase(l.begin());     //time complexity-O(n)  delete 1 element at a time
    for(int i:l){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<'\n';

    // l.erase(l.end());     //time complexity-O(n)
    // for(int i:l){       //means-> i belongs to l
    //     cout<<i<<' ';
    // }
    // cout<<'\n';
    // why is it giving infinite loop

    l.push_back(20);
    l.push_back(30);
    l.pop_back();
    l.pop_front();
    for(int i:l){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<'\n';

    // make a copy of list l in l2
    list<int>l2(l);
    for(int i:l2){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<'\n';

    list<int> l3(5,100);
    for(int i:l3){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<'\n';

    list<int> l4(5);
    for(int i:l4){       //means-> i belongs to l
        cout<<i<<' ';
    }
    cout<<"\n\n";



    // stack
    // last in first out
    stack<string> st;
    st.push("hey");
    st.push("hello");
    st.push("hi");

    cout<<"top element is "<<st.top()<<'\n';
    cout<<"size of stack is "<<st.size()<<'\n';
    st.pop();
    cout<<"top element is "<<st.top()<<'\n';
    cout<<"size of stack is "<<st.size()<<'\n';
    cout<<"is empty ->"<<st.empty()<<'\n';
    // for(int i:s.top()){      //how to print a stack
    //     cout<<i<<' ';
    // }
    // cout<<'\n';
    cout<<"\n";



    // queue
    // first in first out
    queue<string>q;
    q.push("hey");
    q.push("hello");
    q.push("hi");
    cout<<"first element is "<<q.front()<<'\n';
    cout<<"last element is "<<q.back()<<'\n';
    cout<<"size od q is "<<q.size()<<'\n';
    q.pop();
    cout<<"first element is "<<q.front()<<'\n';
    cout<<"last element is "<<q.back()<<'\n';
    cout<<"size od q is "<<q.size()<<'\n';
    cout<<'\n';



    // priority queue
    // first element will be always greatest (max heap)
    // default priority queue is max heap
    // elements are access and deleted in decreasing or increasing order
    // max-heap
    priority_queue<int>maxp;
    // min-heap
    priority_queue<int, vector<int>,greater<int> >minp;

    maxp.push(10);
    maxp.push(30);
    maxp.push(20);
    maxp.push(40);
    cout<<"is empty ->"<<maxp.empty()<<'\n';
    int maxpsize=maxp.size();
    cout<<"size of maxp is "<<maxpsize<<'\n';

    for(int i=0; i<maxpsize; i++){
        cout<<maxp.top()<<' ';
        maxp.pop();
    }
    cout<<'\n';
    cout<<"is empty ->"<<maxp.empty()<<'\n';

    maxp.push(10);
    maxp.push(30);
    maxp.push(20);
    maxp.push(40);
    for(int i=0; i<maxp.size(); i++){   //0,4   1,3   2,2(condition FAILED) 
        cout<<maxp.top()<<' ';
        maxp.pop();
    }
    cout<<'\n';

    minp.push(10);
    minp.push(30);
    minp.push(20);
    minp.push(40);
    cout<<"is empty ->"<<minp.empty()<<'\n';
    int minpsize=minp.size();
    cout<<"size of minp is "<<minpsize<<'\n';

    for(int i=0; i<minpsize; i++){
        cout<<minp.top()<<' ';
        minp.pop();
    }
    cout<<'\n';
    cout<<"is empty ->"<<minp.empty()<<'\n';

    minp.push(10);
    minp.push(30);
    minp.push(20);
    minp.push(40);
    for(int i=0; i<minp.size(); i++){   //0,4   1,3   2,2(condition FAILED) 
        cout<<minp.top()<<' ';
        minp.pop();
    }
    cout<<'\n';
    cout<<'\n';
    
     

    // set
    // all elements are unique
    // implementation is using bst
    // no modification after initialisation, either enter the element or delete the element
    // elements are return in sorted order
    // unordered set
    // set is slower than unordered set
    // elements are return in random order
    set<int>s;
    s.insert(40);       //time complexity- O(log n)
    s.insert(20);
    s.insert(30);
    s.insert(10);

    for(int i:s){
        cout<<i<<' ';
    }
    cout<<'\n';

    s.insert(40);
    s.insert(40);
    s.insert(20);
    for(int i:s){
        cout<<i<<' ';
    }
    cout<<"(no change, only some once in a set)\n";

    s.erase(1);     //why does it not work
    for(int i:s){
        cout<<i<<' ';
    }
    cout<<'\n';

    s.erase(s.begin());
    // s.erase(s.begin()+1);        //why is it giving an ERROR
    for(int i:s){
        cout<<i<<' ';
    }
    cout<<'\n';
    cout<<"is empty -> "<<s.empty()<<'\n';
    
    set<int>::iterator it=s.begin();
    it++;
    s.erase(it);
    // s.erase(s.begin()+1);        //why is it giving an ERROR
    for(int i:s){
        cout<<i<<' ';
    }
    cout<<'\n';

    // s.erase(s.end());        //why all deleted
    // for(int i:s){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';

    cout<<"20 is present or not -> "<<s.count(20)<<'\n';
    cout<<"50 is present or not -> "<<s.count(50)<<'\n';


    // set<int>::iterator itr=s.find(20);       //not understandable17:40
    // cout<<*itr<<'\n';
    // it=s.find(20);
    // cout<<*it<<'\n';

    // for(auto it=itr; it!=s.end(); it++){
    //     cout<<*it<<' ';
    // }
    // cout<<'\n';



    // map
    // data is stored in key:value pair
    // key is pointing to value;
    // all keys are unique and one key point to only one (uniqueness not mandatory) value
    // access in sorted order in ordered map and in random order in unordered map
    map<int,string> m;
    m[1]="hello";
    m[5]="hey";
    m[10]="hi";
    for(auto i:m){
        cout<<i.first<<' '<<i.second<<"  ";
    }
    cout<<'\n';

    m.insert({3,"hola"});       //time complexity- O(log n)
    for(auto i:m){
        cout<<i.first<<' '<<i.second<<"  ";
    }
    cout<<'\n';
    cout<<m.count(3)<<'\n';     //time complexity- O(log n)
    cout<<m.count(-3)<<'\n';

    // erase is done by key
    cout<<"after erase\n";  
    m.erase(5);                 //time complexity- O(log n)
    for(auto i:m){
        cout<<i.first<<' '<<i.second<<"  ";
    }
    cout<<"\n\n";

    // auto it =m.find(3);               //time complexity- O(log n)
    // for(auto i=it; i!=m.end(); i++){
    //     cout<<(*i).first()<<' ';
    // }
    // cout<<'\n';



    // binary search
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(3);
    v4.push_back(5);
    v4.push_back(7);
    //for binary search element should be sorted

    cout<<"finding 1-> "<<binary_search(v.begin(), v4.end(),1)<<'\n';       //give boolean value
    cout<<"finding 4-> "<<binary_search(v.begin(), v4.end(),4)<<'\n';
    // last 7 minutes are remaining from 50:40




    return 0;
}