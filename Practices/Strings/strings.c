#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char * foo = "John";        // Changeable
    char bar[] = "John Smith";  // Unchangeable
    foo = "Joe Doe";

    char test[] = "Bob";
    /* is the same as */
    char test2[11] = "Alice";

    printf("name is %s\n",foo);
    printf("name is %s\n",bar);
    printf("name is %s\n",test);
    printf("name is %s\n",test2);

    printf("len foo: %d\n",strlen(foo));


    // Comparison
    if (strncmp(bar, "John", 4) == 0) {
    printf("Hello, John!\n");
    } else {
        printf("You are not John. Go away.\n");
    }

    // Concatenation
    char dest[20]="Hello";
    char src[20]="World";
    // char * tes = strncat(dest,src,3); // Initialise tes but modify dest too.
    // printf("%s\n",tes);
    strncat(dest,src,20);
    printf("%s\n",dest);
   
    return 0;
}
