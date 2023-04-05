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
extern void loadDatabase(Database database);
extern void destroyDatabase(Database database);

// Insert Functions for each relation given the parameters of the relation
extern bool insertPNB(char *playerID, char *name, char *birthDate, Database database);
extern bool insertTPN(char *team, char *playerID, char *number, Database database);
extern bool insertTC(char *team, char *city, Database database);
extern bool insertGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date, Database database);
extern bool insertGPG(char *gameID, char *playerID, char *goals, Database database);

extern void lookupPNB(char *playerID, char *name, char *birthDate, Database database);
extern void lookupTPN(char *team, char *playerID, char *number, Database database);
extern void lookupTC(char *team, char *city, Database database);
extern void lookupGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date,Database database);
extern void lookupGPG(char *gameID, char *playerID, char *goals, Database database);

extern void deletePNB(char*playerID, char *name, char *birthDate, Database database);
extern void deletePNBREPL(Database database);

extern void deleteTPN(char *team, char *playerID, char *number, Database database);
extern void deleteTPNREPL(Database database);

extern void deleteTC(char *team, char *city, Database database);
extern void deleteTCREPL(Database database);

extern void deleteGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date, Database database);
extern void deleteGHVDREPL(Database database);

extern void deleteGPG(char *gameID, char *playerID, char *goals, Database database);
extern void deleteGPGREPL(Database database);


// Print Each Tuple in the Relation
extern void printAll(Database database);
extern void printPNBRelation(Database database);
extern void printTCRelation(Database database);
extern void printTPNRelation(Database database);
extern void printGHVDRelation(Database database);
extern void printGPGRelation(Database database);


extern void qNameNumberREPL(Database database);
extern void qNameGoalsREPL(Database database);


#endif