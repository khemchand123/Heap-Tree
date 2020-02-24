#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void heapify(vector<int> &heap,int child){
     if(child==0)
        return;
     int parent = (child-1)/2;
     if(heap[parent]<heap[child]){
        swap(heap[parent],heap[child]);
        heapify(heap,parent);
     }
     else{
        return;
     }
}

void buildHeap(vector<int> &heap,int data){
     heap.push_back(data);
     heapify(heap,heap.size()-1);
}

void display(vector<int> heap){
     for(auto it=heap.begin();it!=heap.end();it++)
        cout<<*it<<",";
}

void Dheapify(vector<int> &heap,int parent){

     int leftChild = 2*parent+1;
     int rightChild = 2*parent+2;

     if(leftChild<=heap.size() and rightChild<=heap.size())
    {


          cout<<"right chil :"<<heap[rightChild]<<endl;
          int lp;//local child pointer max
          if(heap[leftChild]>heap[rightChild]){
          lp = leftChild;
          }
          else{
             lp = rightChild;
          }
         if(heap[parent]<heap[lp]){
             swap(heap[parent],heap[lp]);
            Dheapify(heap,lp);
         }
        else{
          return;
        }
    }
    else{
        if(leftChild==heap.size()){
             if(heap[parent]<heap[leftChild]){
                swap(heap[parent],heap[leftChild]);
         }
         else{
            return;
         }
        }
    }
}

void deletePeek(vector<int> &heap){
     int S = heap.size();
     if(S==1){
        heap.pop_back();
        return;
     }
     else{
        int lastChild = S-1;
        heap[0]=heap[lastChild];
        heap.pop_back();
        Dheapify(heap,0);
     }
}

/* int main(){
 *     vector<int> heap;
 *     //cout<<heap[3]<<"enter number : ";
 *     for(int i=0;i<3;i++){
 *         int data;
 *         cin>>data;
 *         buildHeap(heap,data);
 *     }
 *     display(heap);
 *
 *     deletePeek(heap);
 *     cout<<endl;
 *     display(heap);
 * }
 */

void x2(int a){
    cout<<a*2<<"'";
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



    for_each(heap.begin(),heap.end(),x2);

    for(auto it=heap.begin();it!=heap.end();it++){
        cout<<*it<<",";
    }

}
