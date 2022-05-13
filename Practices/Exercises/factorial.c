#include <stdio.h>

unsigned int factorial(unsigned int _x){
    if(_x == 0) {
        return 1;
    }
    return _x * factorial(_x-1);
}

int main (int argc, char *argv[]) {
    printf("factorial 5: %i\n",factorial(5));
}