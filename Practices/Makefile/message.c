#include <stdio.h>
#include "message.h"

message create_message(char * _text){
    message _message = {_text};
    return _message;
}

void printMessage(message * _m){
    printf("%s",_m->text);
}