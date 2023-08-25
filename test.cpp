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
int main(int argc, char const *argv[])
{
    vector<int> arr{7,4,9,10,12};
    //  auto it = find(arr.begin(), arr.end(), 3);
    //       int index = it - arr.begin();
    // buildHeap(arr,arr.size());
    // //heapsort(arr,arr.size());
    // // auto it = find(arr.begin(), arr.end(),7);
    // // int index = it - arr.begin();
    // // arr[index]=arr[arr.size()-1];
    // // arr.pop_back();
    // // heapify(arr,arr.size(),index);


    // auto newarr = arr;
    // heapsort(newarr,newarr.size());
    // cout<<newarr[0]<<endl;
    // for (int i=0; i<(int) newarr.size(); ++i)
    //         cout << newarr[i] << " ";
    // cout << "\n";
    int index = arr.end() - arr.begin();
    cout<<index;
    return 0;
}
