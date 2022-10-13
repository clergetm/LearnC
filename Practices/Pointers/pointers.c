#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    // string pointer
    char * name = "John";
    for (size_t i = 0; i < strlen(name); i++) 
        printf("%c",*(name+i));
    printf("\n");
    
    int a = 1;
    int * pointer_to_a = &a;
    /* let's change the variable a */
    a += 1;
    /* we just changed the variable again! */
    *pointer_to_a += 1;
    /* will print out 3 */
    printf("The value of a is now %d\n", a);

    return 0;
}
