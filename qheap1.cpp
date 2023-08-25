#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(vector<int> &arr, int n, int root)
{
   int l= 2*root +1;
   int r= 2*root +2;
   int largest;
   if (l < n && arr[l]>arr[root]){
      largest = l;
   }else{
      largest = root;
   }
   if (r < n && arr[r]>arr[largest]){
      largest = r;
   }
   if(largest != root){
      int temp= arr[root];
      arr[root]=arr[largest];
      arr[largest]=temp;
      heapify (arr, n, largest);
   }
   
}
  

void buildHeap(vector<int> &arr, int n)
{
   for(int i = (n/ 2)-1 ; i>=0; i--){
        heapify(arr,n,i);
    }
    
   
}
void heapsort(vector<int> &arr, int n)
{
for(int i = n-1 ; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}

int main() {
    vector<int> arr;
    int n;
    int y;
    int x;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>y;
        cin>>x;
        if (y == 1 ){
            arr.push_back(x);
            buildHeap(arr,arr.size() );
        }
        else if (y == 2 ){
           auto it = find(arr.begin(), arr.end(),7);
            int index = it - arr.begin();
            arr[index]=arr[arr.size()-1];
            arr.pop_back();
            heapify(arr,arr.size(),index);
        }
        else{
            auto newarr = arr;
            heapsort(newarr,newarr.size());
            cout<<newarr[0]<<endl;
        }
    }
    return 0;
}
