#include "HashTable.h"
#include "PNBRelation.h"
#include "TPNRelation.h"
#include "TCRelation.h"
#include "GHVDRelation.h"
#include "GPGRelation.h"
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdbool.h>

#ifndef DATABASE_H
#define DATABASE_H

// Database Structure that holds all the relations
typedef struct Database* Database;

struct Database {
    int capacity;
    char Name[25];
    PNBRelation pnbRelation;
    TPNRelation tpnRelation;
    TCRelation tcRelation;
    GHVDRelation ghvdRelation;
    GPGRelation gpgRelation;
};

extern Database createDatabase(int capacity, char *name);

// Insert Functions for each relation given the parameters of the relation
extern bool insertPNB(char *playerID, char *name, char *birthDate, Database database);
extern bool insertTPN(char *team, char *playerID, char *number, Database database);
extern bool insertTC(char *team, char *city, Database database);
extern bool insertGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date, Database database);
extern bool insertGPG(char *gameID, char *playerID, char *goals, Database database);
extern void lookupPNB(char *playerID, char *name, char *birthDate, Database database);
extern void lookupTPN(char *team, char *playerID, char *number, Database database);
extern Bucket lookupTC(char *team, char *city, Database database);
extern Bucket lookupGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date,Database database);
extern Bucket lookupGPG(char *gameID, char *playerID, char *goals, Database database);





extern void loadDatabase(Database database);
extern void destroyDatabase(Database database);
// Print Each Tuple in the Relation
extern void printAll(Database database);


#endif