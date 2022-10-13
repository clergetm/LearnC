#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=yFboyOwk2oM&ab_channel=CodeVault

typedef struct {
    char * name;
    int age;
} person;

int main (int argc, char *argv[]) {

    // Create a variable with dynamically allocate memory of the size of the struct person
    // the malloc is cast as a pointer of person because malloc return a void pointer
    person * myperson = (person *) malloc(sizeof(person));

    myperson->name = "John";
    myperson->age = 27;

    printf("The name is: %s \n",myperson->name);
    printf("The age is:  %d \n",myperson->age);
    // Release the data points by myperson variable. myperson still exists.
    free(myperson);

    printf("After calling free function:\n");
    printf("The name is: %s \n",myperson->name);
    printf("The age is:  %d \n",myperson->age);


    // Create a int variable with dynamically allocate memory of the size of a int
    int * p_a = (int *) malloc(sizeof(int));
    *p_a = 3;
    printf("a is equals to %d \n",*p_a);
    free(p_a);
    
    // Create a int table variable with dynamically allocate memory of the size of a 3 int
    int * p_t1 = (int *) malloc(3*sizeof(int));
    printf("before initialization:\n");
    printf("- table p_t1 contains [%d, %d, %d]\n",p_t1[0],p_t1[1],p_t1[2]);   
    p_t1[0] = 20;
    p_t1[1] = 31;
    p_t1[2] = 42;

    printf("after initialization:\n");
    printf("- table p_t1 contains [%d, %d, %d]\n",p_t1[0],p_t1[1],p_t1[2]);
    free(p_t1);


     // Create a int table variable with dynamically allocate memory of the size of a 3 int
     // https://stackoverflow.com/a/1538427
     // "calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized."
    int * p_t2 = (int *) calloc(3,sizeof(int));
    printf("before initialization:\n");
    printf("- table p_t1 contains [%d, %d, %d]\n",p_t2[0],p_t2[1],p_t2[2]);

    p_t2[0] = 20;
    p_t2[1] = 31;
    p_t2[2] = 42;
    printf("after initialization:\n");
    printf("- table p_t2 contains [%d, %d, %d]\n",p_t2[0],p_t2[1],p_t2[2]);
    free(p_t2);
   
    return 0;
}
