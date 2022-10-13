#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>
#include "node.h"

/**
 * @brief The LinkedList is composed of Nodes.
 * One pointer is the first element of the list.
 * One at the last element of the list.
 * And the current Pointer is use to search through the list.
 */
typedef struct {
    Node * top;
    Node * queue;
    Node * current;
} LinkedList;

/**
 * @brief Create a LinkedList object
 * 
 * @return LinkedList 
 */
LinkedList CreateLinkedList();

/**
 * @brief Free the dynamically allocated memory of the whole LinkedList.
 * 
 * @param self The pointer of a LinkedList.
 */
void DeleteLinkedList(LinkedList * self );

/**
 * @brief Add a Node at the end of the LinkedList.
 * 
 * @param self  The pointer of a LinkedList.
 * @param _node The Node to add to the LinkedList.
 */
void Push(LinkedList * self, Node * _node);

/**
 * @brief Remove the Node at the current position in a LinkedList.
 * 
 * @param self The pointer of a LinkedList in which the current Node will be remove.
 */
void Remove(LinkedList * self);

/**
 * @brief Remove the top Node of a LinkedList.
 * 
 * @param self The pointer of a LinkedList in which the top Node will be remove.
 */
void Pop(LinkedList * self);

/**
 * @brief printf all element of a LinkedList.
 * 
 * @param self The pointer of a LinkedList.
 */
void PrintList(LinkedList * self);

/**
 * @brief Check if the current Node is in the LinkedList.
 * 
 * @param self The pointer of a LinkedList. 
 * @return true     if the pointer current and the next are not null.
 * @return false    else.
 */
bool IsInList(LinkedList * self);

/**
 * @brief Check if the list is empty.
 * 
 * @param self The pointer of a LinkedList. 
 * @return true     if the list is empty.
 * @return false    if the list in not empty.
 */
bool IsEmpty(LinkedList * self);
#endif