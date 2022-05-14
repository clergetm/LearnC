#ifndef MESSAGE_H
#define MESSAGE_H

/**
 * @brief The message structure
 * 
 */
typedef struct {
    char * text;
} message;

/**
 * @brief Create a message object
 * 
 * @param _text The text value
 * @return message Initialized message
 */
message create_message(char * _text);


/**
 * @brief print the value of the message
 * 
 * @param _m a message pointer
 */
void printMessage(message * _m);

#endif