#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(vector<int> &arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

double func1(vector<int> &arr,int n){
    bubbleSort(arr,n);
    double median;
    int m=n/2;
    if(n==1){
        median=arr[0];
    }
    else if (n%2==0){

        median=(arr[m]+arr[m-1])/2.0;

    }
    else{
        median=arr[m];
    }
    return median;
}


int main (){
    cout<<"enter the no of elements in the array"<<endl;
    int n;
    cin>>n;
    cout<<"enter elements"<<endl;

    vector<int> arr;
    int x;

    for (int i=1;i<=n;i++) {
        cin>>x;
        arr.push_back(x);
        if (i==1){
            cout.width(20); cout << left << "array";
            cout.width(20); cout << left << "median"<<"\n";
        }
        double median=func1(arr,i);
        string str="[";
        for( int m:arr){
            str=str+" "+to_string(m);
        }
        str+=" ]";
        cout.width(20); cout << left << str;
        cout << fixed << setprecision(1);
        cout.width(20); cout << left << median<<endl;

    }

    return 0;
}