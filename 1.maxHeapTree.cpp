
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void Display(vector<int> heap){

     for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<",";
     }
     cout<<endl;
}

void dHeapify(vector<int> &heap,int parent,int heapSize){
     int lChild = 2*parent+1;
     int rChild = 2*parent+2;

     if(lChild>=heapSize && rChild>=heapSize){
        return;
     }

     int largest=parent;
     if(lChild<heapSize && heap[lChild]>heap[parent]){
        largest=lChild;
     }
     if(rChild<heapSize && heap[rChild]>heap[largest]){
        largest=rChild;
     }
     if(heap[parent]<heap[largest]){
        swap(heap[parent],heap[largest]);
        dHeapify(heap,largest,heapSize);
     }
     else{
        return;
     }
}

void buildHeapD(vector<int> &heap){
     for(int i=(heap.size())-1;i>=0;i--){
         dHeapify(heap,i,heap.size());
     }
}
int main(){
    vector<int> heap;
    cout<<"enter the size of heap Array representation : ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int item;
        cin>>item;
        heap.push_back(item);
    }

    buildHeapD(heap);
    cout<<" heap tree :";
    Display(heap);

    int lastElementLoc = heap.size()-1;


    while(lastElementLoc>0){
        swap(heap[0],heap[lastElementLoc]);
        lastElementLoc=lastElementLoc-1;     //location
        dHeapify(heap,0,lastElementLoc+1);  //reapresent size of heap
    }
    cout<<"sorted array : ";
    Display(heap);

}
