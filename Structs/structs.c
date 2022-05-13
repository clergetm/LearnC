#include <stdio.h>

// https://www.youtube.com/watch?v=dByGjQyLJww&ab_channel=dev-creations

/**
 * @brief The basic way to create a structure. But every time we will use it, we will need to write 
 * 'struct person'.
 */
struct person {
        char * first_name;
        char * last_name;
    };

void printPerson(struct person _person){
    printf("His/Her full name is %s, %s \n",_person.first_name,_person.last_name);
}

/**
 * @brief Create structure with different name. 
 * we can use 'struct personAndAge pX' 
 * we can use 'per pX'
 * 
 * We can change 
 * 'typedef struct personAndAge {' into
 * 'typedef struct {' and only use per.
 */
typedef struct personAndAge {
        char * first_name;
        char * last_name;
        short age;    
} per;

void printPer(per _person){
    printf("His/Her full name is %s, %s and is %d year old\n",_person.first_name,_person.last_name,_person.age);

}

void fullName(char * _first, char * _last){
        printf("His/Her full name is %s, %s \n",_first,_last);
}
int main (int argc, char *argv[]) {
    
    struct person p1 = {"John","Smith"};
    printPerson(p1);
   
    per p2 = {"Alice", "Smith",30};
    fullName(p2.first_name,p2.last_name);

    struct personAndAge p3;
    p3.first_name = "Bob";
    p3.last_name = "Smith";
    p3.age = 20;

    printPer(p3);
    return 0;
}