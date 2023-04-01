#include <bits/stdc++.h>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int minDiff = INT_MAX;
    vector<int> closest;

    for (int i = 1; i < n; i++) {
        int diff = abs(arr[i] - arr[i-1]);

        if (diff < minDiff) {
            closest.clear();
            closest.push_back(arr[i-1]);
            closest.push_back(arr[i]);
            minDiff = diff;
        }
        else if (diff == minDiff) {
            closest.push_back(arr[i-1]);
            closest.push_back(arr[i]);
        }
    }

    return closest;
}