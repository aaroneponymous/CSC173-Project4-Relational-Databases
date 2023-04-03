#ifndef TCRelation_h
#define TCRelation_h
#include <stdbool.h>
#include "Hashtable.h"



// Relation TC
typedef struct TC* TC;

struct TC {
    char Team[20];
    char City[10];
};

typedef struct TCRelation* TCRelation;

struct TCRelation {
    int entries;
    int capacity;
    HashTable teamHashTable;
    HashTable cityHashTable;
};

// ------------------------------------------------------------TC--------------------------------------------------------------//

extern TC newTC(char* team, char* city);

extern TCRelation newTCRelation(int capacity);

extern void printTC(Bucket tc);

extern Bucket lookup_TC(char* team, char* city, struct TCRelation *tcRelation);

extern bool insert_TC(char* team, char* city, struct TCRelation *tcRelation);

extern bool delete_TC(char* team, char* city, struct TCRelation *tcRelation);

extern void freeTCRelation(TCRelation tcRelation);

extern void freeTC(TC tc);

#endif