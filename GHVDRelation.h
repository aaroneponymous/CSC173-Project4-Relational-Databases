#ifndef GHVDRelation_h
#define GHVDRelation_h
#include <stdbool.h>
#include "Hashtable.h"




// Relation GHVD
typedef struct GHVD* GHVD;

struct GHVD {
    char GameId[5];
    char HomeTeam[20];
    char VisitorTeam[20];
    char Date[15];
};

typedef struct GHVDRelation* GHVDRelation;

struct GHVDRelation {
    int entries;
    int capacity;
    HashTable gameIdHashTable;
    HashTable homeTeamHashTable;
    HashTable visitorTeamHashTable;
    HashTable dateHashTable;
};



// ------------------------------------------------------------GHVD--------------------------------------------------------------//

extern GHVD newGHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date);

extern GHVDRelation newGHVDRelation(int capacity);

extern void printGHVD(Bucket ghvd);

extern Bucket lookup_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation);

extern bool insert_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation);

extern bool delete_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation);

extern void freeGHVDRelation(GHVDRelation ghvdRelation);

extern void freeGHVD(GHVD ghvd);

#endif

