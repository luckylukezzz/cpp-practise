#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lilysHomework(vector<int> arr) {
    int val = INT_MAX;


    vector<int> revSortArr(arr);
    sort(revSortArr.rbegin(), revSortArr.rend());

    for (int i = 0; i < 2; i++) {
        int curSwap = 0;
        if (i) {
            reverse(revSortArr.begin(), revSortArr.end());
        }
        vector<int> newArr(arr);
        // val, pos
        unordered_map<int, int> valMap2;
        for (int i = 0; i < (int) newArr.size(); i++) {
            valMap2[newArr[i]] = i;
        }


        for (int i = 0; i < (int) newArr.size(); i++) {
            if (newArr[i] == revSortArr[i]) {
                continue;
            }
            int ai = newArr[i];
            int si = revSortArr[i];

            swap(newArr[i], newArr[valMap2[si]]);
            curSwap++;


            valMap2[ai] = valMap2[si];
            valMap2[si] = i;


        }

        val = min(val, curSwap);

    }


    return val;


}