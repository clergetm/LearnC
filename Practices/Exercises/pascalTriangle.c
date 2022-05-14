#include <stdio.h>
#include <stdlib.h>
/**
 * The objective of this exercise is the manipulation of the dynamical allocation of memory.
 * 
 * For more information about Pascal Triangle:
 * https://www.knowprogram.com/c-programming/pascal-triangle-in-c/
 * https://mathworld.wolfram.com/PascalsTriangle.html
 */


void pascalTriangle(unsigned int);

int main (int argc, char *argv[]) {

    pascalTriangle(5);
    return 0;
}

/**
 * @brief The representation of pascal triangle.
 * 
 * @param int The size of the triangle, the amount of row.
 */
void pascalTriangle(unsigned int _size){

    // Allocation but better with information from stackoverflow.
    // https://stackoverflow.com/a/1733945
    int ** triangle = malloc(_size * sizeof(*triangle)) ;

    // Initialize the triangle
    for (size_t i = 0; i < _size; i++)
    {
        size_t nbEle = i+1;
        triangle[i] = (int *) malloc(nbEle*sizeof(*(triangle[i]))); 
 
    }
    
    // Hydrate the triangle
    for (size_t i = 0; i < _size; i++)
    {
        int value = 1;
        for (size_t j = 0; j <=i; j++)
        {
            if(j==0||j==i) 
                triangle[i][j]=1;
            else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
                // printf("[i-1][j-1] [%i][%i]: %i\n",i-1,j-1,triangle[i-1][j-1]);
                // printf("[i-1][j]   [%i][%i]: %i\n",i-1,j,triangle[i-1][j]);
            }
        }
    }

    // Print the triangle
    for (size_t i = 0; i < _size; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            printf("%i ",triangle[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory
    // We need to free each row and then the triangle
    for (size_t i = 0; i < _size; i++) 
        free(triangle[i]);
    free(triangle);
}