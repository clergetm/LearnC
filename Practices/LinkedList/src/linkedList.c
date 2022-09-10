#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "node.h"

LinkedList CreateLinkedList() {
    LinkedList list = {
        (Node *) malloc(sizeof(Node)),  // top
        (Node *) malloc(sizeof(Node)),  // current
        (Node *) malloc(sizeof(Node))   // queue
    };
    list.top = list.current = list.queue;
    return list;
}

void DeleteLinkedList(LinkedList * self){
    Node * temp = self->top;
    while(self->top) {
        temp = self->top;
        self->top = self->top->next;
        free(temp);
    }
    free(self);
}

void Push(LinkedList * self, Node * _node){
    self->queue = self->queue->next;
    self->queue->next = _node;
}

void Remove(LinkedList * self){
    if(!IsInList(self)) return;
    Node * temp = self->current->next;
    self->current->next = temp->next;
    if(self->queue == temp) self->queue = self->current;
    free(temp);
}

void Pop(LinkedList * self){
    if(!self->top->next) return;
    Node * temp = self->top->next;
    self->top = temp->next;
    free(temp);
}

void PrintList(LinkedList * self){
    printf("Print List\n");
    Node * temp = self->top->next;
    while(temp != NULL) {
        PrintNode(temp->next);
        temp = temp->next;
    }
    free(temp);
}

bool IsInList(LinkedList * self){
    return self->current && self->current->next;
}

bool IsEmpty(LinkedList * self){
    return (self->top->next == NULL);
}