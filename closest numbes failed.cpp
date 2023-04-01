#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int minDiff=INT_MAX;
    vector<int> closest;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int diff=abs((arr[i]-arr[j]));
            if (diff<minDiff){
                closest.clear();
                closest.push_back(arr[i]);
                closest.push_back(arr[j]);
                minDiff=diff;
            }
            
            else if (diff==minDiff){
                 closest.push_back(arr[i]);
                closest.push_back(arr[j]);
            }

        }
     }
    return closest;
}
