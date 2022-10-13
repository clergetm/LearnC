#include <stdio.h>
#include "node.h"

Node CreateNode(int _value){
    Node newNode = {_value, NULL};
    return newNode;
}

void PrintNode(Node * _self) {
    printf("%d \n", _self->value);
}