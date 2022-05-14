#include <stdio.h>
#include "message.h"

int main (int argc, char *argv[]) {
    message m = create_message("It's an example");
    printMessage(&m);
    return 0;
}