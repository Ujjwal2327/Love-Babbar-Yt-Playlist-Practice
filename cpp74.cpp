#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    int next;

    node(int data){
        this->data = data;
    }
};

class heap{     //max heap
    public:
    vector<int>a;
    int size;

    heap(){
        a.push_back(-1);
        size=0;
    }

    void insert(int d){     // time complexity - O(log(n))
        size++;
        a.push_back(d);
        int ind = size;

        while(ind>1){
            int parent = ind/2;
            if(a[parent] < a[ind]){
                swap(a[ind], a[parent]);
                ind = parent;
            }
            else{
                return;
            }
        }
    }
    
    void print(){
        for(int i=1; i<=size; i++){
            cout<<a[i]<<' ';
        }
        cout<<"\n\n";
    }

    void Delete(){          // time complexity - O(log(n))
        if(size==0){
            cout<<"nothing to delete\n";
            return;
        }

        // put last element into first index
        a[1]=a[size];
        // remove last element
        size--;

        // take root node to its correct position
        int i=1;
        while(i<=size/2){
            int left = 2*i;
            int right = 2*i+1;

            int largest = i;
            if(left<=size && a[left]>a[largest]){
                largest = left;
            }
            if(right<=size && a[right]>a[largest]){
                largest = right;
            }

            if(largest != i){
                swap(a[i], a[largest]);
                i=largest;
            }
            else{
                return;
            }
            // //   may be this one is also right code
            // if(right<=size){
            //     if(a[right]>a[left] && a[right]>a[i]){
            //         swap(a[right], a[i]);
            //         i=right;
            //     }
            //     else if(a[left]>a[right] && a[left]>a[i]){
            //         swap(a[left], a[i]);
            //         i=left;
            //     }
            // }
            // else if(left<=size && a[left]>a[i]){
            //         swap(a[left], a[i]);
            //         i=left;
            // }
            // else{
            //     return;
            // }

            // may be this is not fully correct code
            // if(left<=size && a[left]>a[i]){
            //         swap(a[left], a[i]);
            //         i=left;
            // }
            // else if(right<=size && a[right]>a[i]){
            //         swap(a[right], a[i]);
            //         i=right;
            // }
            // else{
            //     return;
            // }
        }
    }

};

void heapify(vector<int>&a, int n, int i){      // put a node at its correct position
    if(i==0){
        return;
    }
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left < n && a[left] > a[largest]){
        largest=left;
    }
    if(right < n && a[right] > a[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<int>&a, int n){     // time complexity- O(n)    not O(nlog(n))
    int heapSize=n-1;
    for(int i=heapSize/2; i>=1; i--){
        heapify(a, n, i);
    }
}

void printVector(vector<int>&a){
    for(int i=1; i<a.size(); i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

void heapSort(vector<int>&a){        // time complexity- O(nlog(n))
    int n = a.size();
    // build heap
    buildHeap(a,n);

    // heap sort
    while(n>2){
        swap(a[1],a[n-1]);
        n--;
        heapify(a, n, 1);
    }
}

int main(){

    /*
    heap
        complete binary tree (CBT) that comes with heap order properties
    CBT
        all levels must be completely filled (may not the last level)
        nodes always add from the left
        no blank space in its array form
    heap order properties
        max heap
            every child has lower value than its parent
        min heap
            every child has higher value than its parent
        left child of ith pos-> 2*i pos in array
        right child of ith pos-> 2*i+1 pos in array
        parent of ith pos-> i/2 pos in array
    
    in CBT, from n/2+1 to nth index -> leaf nodes lie there     indexing start from 1
    */

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.Delete();
    h.print();


    vector<int>h2={-1, 54, 53, 55, 52, 50};
    buildHeap(h2, h2.size());
    cout<<"printing h2 after buildHeap(h2, h2.size())-\n";
    printVector(h2);

    vector<int>h3={-1, 54, 53, 55, 52, 50};
    heapSort(h3);
    cout<<"printing h3 after heapSort(h3)-\n";
    printVector(h3);

    cout<<"\n\n";
    cout<<"Using STL Priority Queue\n";
    cout<<"Max Heap\n";
    priority_queue<int>pq;      // by default act as max heap
    pq.push(4);     //time complexity-O(log(n))
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.push(2);

    cout << "pq.top()-> " << pq.top()<<'\n';
    pq.pop();       //time complexity-O(log(n))
    cout << "pq.top()-> " << pq.top()<<'\n';        //time complexity-O(1)
    cout << "pq.size()-> " << pq.size()<<'\n';      
    cout << "pq.empty()-> " << pq.empty()<<"\n\n";  //time complexity-O(1)
   
    cout<<"Min Heap\n";
    priority_queue< int, vector<int>, greater<int> >minHeap;      // priority queue will act as min heap now
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(2);

    cout << "minHeap.top()-> " << minHeap.top()<<'\n';
    minHeap.pop();
    cout << "minHeap.top()-> " << minHeap.top()<<'\n';
    cout << "minHeap.size()-> " << minHeap.size()<<'\n';
    cout << "minHeap.empty()-> " << minHeap.empty()<<'\n';





    return 0;
}