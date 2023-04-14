#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int x=5;
    printf("%p\n",&x);  //memory location of 5

    int* ptr = &x;
    printf("%p\n",ptr);  //memory location of 5
    printf("%p\n",&ptr);  //memory location of pointer 1


    int** ptr2;
     printf("%p\n",ptr2);

    ptr2 = &ptr;
    printf("%p",ptr2);   //memory location of pointer 1




    return 0;
}
