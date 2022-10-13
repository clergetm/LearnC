#ifndef NODE_H
#define NODE_H

/**
 * @brief The structure of the Node
 * 
 * We write typedef struct Node because we implement a Node variable inside itself 
 * and by naming the Node only after the struct variables the variable cannot recognize the struct.
 */
typedef struct Node {
    int value;
    struct Node * next;
} Node;

/**
 * @brief Create a Node object.
 * 
 * @param _value    The value stored by the Node.
 * @return The initialized Node.
 */
Node CreateNode(int _value);

/**
 * @brief Print method of a Node.
 * 
 * @param _self the Node to print.
 */
void PrintNode(Node * _self);
#endif