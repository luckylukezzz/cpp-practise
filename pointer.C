#include <iostream>
using namespace std;


void func3(int **ptr1) { // pointer pass-by-reference
    int *ptr2;
    printf("%i %i\n",**ptr1,*ptr2);
    *ptr1 =(int*) malloc(sizeof(int)); // allocate memory
    ptr2 =(int*)  malloc(sizeof(int)); // allocate memory
    printf("%i %i\n",**ptr1,*ptr2);
    }
int main() {
int *ptr1; // memory for pointer in stack but the data points to in heap (random values)
printf("%i\n",*ptr1);
func3(&ptr1);
printf("%i\n",*ptr1);
free(ptr1); // deallocate memory
printf("%i\n",*ptr1);

    return 0;
}
