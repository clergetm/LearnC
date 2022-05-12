#include <stdio.h>
#define count 10
int main (int argc, char *argv[]) {
    //one-dimensional array
    int n[count];
    for (size_t i = 0; i < count; i++) n[i]=i;
    
    printf("Array : [");
    for (size_t i = 0; i < count; i++) printf("%d,",n[i]);
    printf("]\n");

    // Multidimensional Arrays
    // You can declare a multidimensional array in several ways:

    // The size of the array:
    int a[3][3];

    // The size and values:
    int b[1][2] = {0,1};

    // You can declare a two dimensionals array with only y value
    // int foo[][y];
    char vowels[][5] = {
        {'A', 'E', 'I', 'O', 'U'},
        {'a', 'e', 'i', 'o', 'u'}
    };

    // You can initialize each row of a two dimensional array this way:
    int test[2][2] = {
        {1,2},
        {3,4}
    };

    int test2[2][2] = {1,2,3,4};

    for (size_t x = 0; x < 2; x++)
    {
        for (size_t y = 0; y < 2; y++)
        {
            printf("value test[%d][%d]=[%d]\n",x,y,test[x][y]);
        }
        
    }
    
    return 0;
}