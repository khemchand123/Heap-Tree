#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void upHeapify(vector<int> &heap,int child){
     //base case
     if(child==0){
        return;
     }

     //recursive case
     int parent = (child-1)/2;
     if(heap[parent]<heap[child]){
        swap(heap[parent],heap[child]);
        upHeapify(heap,parent);
     }
     else{
        return;
     }
}

void buildHeapU(vector<int> &heap){
     for(int i=0;i<heap.size();i++){
        upHeapify(heap,i);
     }
}

void Display(vector<int> heap){
     cout<<"heap representation :";
     for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<",";
     }
     cout<<endl;
}

void dHeapify(vector<int> &heap,int parent){
     int lChild = 2*parent+1;
     int rChild = 2*parent+2;

     if(lChild>=heap.size() && rChild>=heap.size()){
        return;
     }

     int largest=parent;
     if(lChild<heap.size() && heap[lChild]>heap[parent]){
        largest=lChild;
     }
     if(rChild<heap.size() && heap[rChild]>heap[largest]){
        largest=rChild;
     }
     if(heap[parent]<heap[largest]){
        swap(heap[parent],heap[largest]);
        dHeapify(heap,largest);
     }
     else{
        return;
     }
}

void buildHeapD(vector<int> &heap){
     for(int i=(heap.size())-1;i>=0;i--){
         dHeapify(heap,i);
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

    //buildHeapU(heap);  //time o(nlogn)
    buildHeapD(heap);    //time o(n)
    Display(heap);
}
