#include <bits/stdc++.h>

using namespace std;


vector<int> quickSort(vector<int> arr) {
    vector<int> left;
    vector <int> right;
    vector <int> equal;
    int p=arr[0];
    for (int i:arr){
        if (p==i){
            equal.push_back(i);
        } else if (p<i){
            right.push_back(i);
        }
        else{
            left.push_back(i);
        }
        
    }
    vector <int> v;
    copy(left.begin(), left.end(), back_inserter(v));
    copy(equal.begin(), equal.end(), back_inserter(v));
    copy(right.begin(), right.end(), back_inserter(v));
    return v;
}
