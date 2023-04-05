#ifndef RelationalAlgebra_h
#define RelationalAlgebra_h

#include "Hashtable.h"
#include "TPNRelation.h"
#include "Database.h"
#include "stdlib.h"


typedef struct ProjectionTPN* ProjectionTPN;
struct ProjectionTPN {
    char Team[20];
};
typedef struct ProjectionTPNRelation* ProjectionTPNRelation;
struct ProjectionTPNRelation {
    int entries;
    int capacity;
    char key[10];
    HashTable teamHashTable;
};

typedef struct JoinGHVDPG* JoinGHVDPG;
struct JoinGHVDPG {
    char GameId[6];
    char HomeTeam[20];
    char VisitorTeam[20];
    char Date[20];
    char PlayerId[6];
    char Goals[3];
};
typedef struct JoinGHVDPGRelation* JoinGHVDPGRelation;
struct JoinGHVDPGRelation {
    int entries;
    int capacity;
    HashTable gameIdHashTable;
    HashTable homeTeamHashTable;
    HashTable visitorTeamHashTable;
    HashTable dateHashTable;
    HashTable playerIdHashTable;
    HashTable goalsHashTable;
};


extern ProjectionTPN newProjectionTPN(char* team);
extern ProjectionTPNRelation newProjectionTPNRelation(char* key, int capacity);
extern bool insertProjectTPN(char* team, ProjectionTPNRelation projectionTPNRelation);
extern void printProjectedTPN(ProjectionTPNRelation relation);
extern void freeProjectedTPNRelation(ProjectionTPNRelation tpnProjectedrelation);


extern JoinGHVDPG newJoinGHVDPG(char* gameId, char* homeTeam, char* visitorTeam, char* date, char* playerId, char* goals);
extern JoinGHVDPGRelation newJoinGHVDPGRelation(int capacity);
extern bool insertJoinGHVDPG(char* gameId, char* homeTeam, char* visitorTeam, char* date, char* playerId, char* goals, JoinGHVDPGRelation joinGHVDPGRelation);
extern void printJoinGHVDPG(Bucket joinGHVDPG);
extern void printJoinGHVDPGRelation(JoinGHVDPGRelation joinGHVDPGRelation);
extern void freeJoinGHVDPGRelation(JoinGHVDPGRelation joinGHVDPGRelation);
extern void freeJoinGHVDPG(JoinGHVDPG joinGHVDPG);




// Relational Algebra

// Select
extern TPNRelation select_TPN(char* playerID, TPNRelation tpnRelation);
// Project
extern ProjectionTPNRelation project_TPN(char* playerID, TPNRelation tpnRelation);
// Join
extern JoinGHVDPGRelation join_GHVDPG(GHVDRelation ghvdRelation, GPGRelation gpgRelation);





#endif
