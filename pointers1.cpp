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
    printf("%p\n",ptr2);   //memory location of pointer 1


    int* ptr3=(int*) new int; //casting a int object 
    *ptr3=7;            //dereferencing
    printf("%d\n",*ptr3); 

    return 0;
}
