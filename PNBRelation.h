#include <stdbool.h>

#ifndef PNB_Relation_h
#define PNB_Relation_h

#include "Hashtable.h"


// Relation PNB
typedef struct PNB* PNB;

struct PNB {
    char PlayerId[7];
    char Name[15];
    char BirthDate[15];
};


typedef struct PNBRelation* PNBRelation;

struct PNBRelation {
    int entries;
    int capacity;
    HashTable playerIDHashTable;
    HashTable nameHashTable;
    HashTable birthDateHashTable;
};

// ------------------------------------------------------------PNB--------------------------------------------------------------//

extern PNB newPNB(char* playerId, char* name, char* birthDate);

extern PNBRelation newPNBRelation(int capacity);

extern void printPNB(Bucket PNB);

extern Bucket lookup_PNB(char* playerID, char* name, char* birthDate, struct PNBRelation *pnbRelation);

extern bool delete_PNB(char* playerId, char* name, char* birthDate, struct PNBRelation *pnbRelation);

extern bool insert_PNB(char* playerId, char* name, char* birthDate, struct PNBRelation *pnbRelation);

extern void freePNBRelation(PNBRelation pnbRelation);

extern void freePNB(PNB pnb);

#endif
