#include <bits/stdc++.h>

using namespace std;

int lilysHomework(vector<int> arr) {
    vector<int> arr2(arr);
    int n = arr.size();
    int min;
    int minID;
    int temp;
    int noSwaps1=0;
    int noSwaps2=0;
    for (int i=0;i<=n-2;i++){
        min=arr[i+1];
        minID=i+1;
        for (int j=i+2;j<=n-1;j++){
            if (arr[j]<min){
                min=arr[j];
                minID=j;
            }
                
        }
        if (min<arr[i]){
            temp=arr[i];
            arr[i]=min;
            arr[minID]=temp;
            noSwaps1++;
            
        }
        
    }
    for (int i=0;i<=n-2;i++){
        min=arr2[i+1];
        minID=i+1;
        for (int j=i+2;j<=n-1;j++){
            if (arr2[j]>min){
                min=arr2[j];
                minID=j;
            }
                
        }
        if (min>arr2[i]){
            temp=arr2[i];
            arr2[i]=min;
            arr2[minID]=temp;
            noSwaps2++;
//          for (int x:arr2){
//              cout<<x<<" ";
             
//          }
//            cout<<"\n"; 
         }
        
    }
    return (noSwaps2< noSwaps1 ) ? noSwaps2 : noSwaps1 ;
}