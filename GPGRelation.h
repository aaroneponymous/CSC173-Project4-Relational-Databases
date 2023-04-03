#ifndef GPG_Relation_h
#define GPG_Relation_h
#include <stdbool.h>
#include "Hashtable.h"



// Relation GPG
typedef struct GPG* GPG;

struct GPG {
    char GameId[5];
    char PlayerId[7];
    char Goals[2];
};

typedef struct GPGRelation* GPGRelation;

struct GPGRelation {
    int entries;
    int capacity;
    HashTable gameIdHashTable;
    HashTable playerIdHashTable;
    HashTable goalsHashTable;
};



// FUNCTIONS ASSOCIATED WITH ALL RELATIONS:



// ------------------------------------------------------------GPG--------------------------------------------------------------//

extern GPG newGPG(char* gameId, char* playerId, char* goals);

extern GPGRelation newGPGRelation(int capacity);

extern void printGPG(Bucket gpg);

extern Bucket lookup_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation);

extern bool insert_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation);

extern bool delete_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation);

extern void freeGPGRelation(GPGRelation gpgRelation);

extern void freeGPG(GPG gpg);

#endif