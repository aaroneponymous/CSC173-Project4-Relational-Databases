#include <stdbool.h>

#ifndef TPN_Relation_h
#define TPN_Relation_h

#include "Hashtable.h"

// Relation TPN
typedef struct TPN* TPN;

struct TPN {
    char Team[20];
    char PlayerId[6];
    char Number[3];
};

typedef struct TPNRelation* TPNRelation;

struct TPNRelation {
    int entries;
    int capacity;
    HashTable teamHashTable;
    HashTable playerIDHashTable;
    HashTable numberHashTable;
};


// ------------------------------------------------------------TPN--------------------------------------------------------------//


extern TPN newTPN(char* team, char* playerId, char* number);

extern TPNRelation newTPNRelation(int capacity);

extern void printTPN(Bucket tpn);

extern Bucket lookup_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation);

extern bool insert_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation);

extern bool delete_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation);

extern void freeTPNRelation(TPNRelation tpnRelation);

extern void freeTPN(TPN tpn);


#endif
