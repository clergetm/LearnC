#include <stdio.h>
#include "linkedList.h"
#include "node.h"

int main () {

    Node _0 = CreateNode(0);
    Node _1 = CreateNode(1);
    Node _2 = CreateNode(2);
    Node _3 = CreateNode(3);
    
    LinkedList list = CreateLinkedList();
    Push(&list,&_0);
    Push(&list,&_1);
    Push(&list,&_2);
    Push(&list,&_3);

    
    PrintList(&list);

    return 0;
}