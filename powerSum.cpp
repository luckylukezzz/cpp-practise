#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void combinations(int start, int end, int length, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (length == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= end - length + 1; i++) {
        current.push_back(i);
        combinations(i + 1, end, length - 1, current, result);
        current.pop_back();
    }
}

int powerSum(int X, int N) {
    int x=X;
    int count=0;
    int sum=1;

    while (true){
        if (pow(sum,N)==X){
            X=sum;
            count++;
            break;
        }
        else if(pow(sum,N)>X){
            X=sum-1;
            break;
        }
       sum++;

    }
    int start=1, end=X, length;
    for (int i=2;i<=X;i++ ) {

        length=i;

        std::vector<int> current;
        std::vector<std::vector<int>> result;

        combinations(start, end, length, current, result);
        for (auto vec: result) {
            sum = 0;
            for (auto num: vec) {
                sum += pow(num, N);

            }
            if (sum == x) {
                count++;
            }

        }
    }
    return count;

}



int main() {
    
    cout<< powerSum(10,2);
    return 0;
}




