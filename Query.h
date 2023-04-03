#include "HashTable.h"
#include "Database.h"
#include "PNBRelation.h"
#include "TCRelation.h"
#include "TPNRelation.h"


#ifndef Query_h
#define Query_h

extern void qNameNumber(char* name, char* team, struct Database *database);
extern void qNameGoals(char* name, char* date, struct Database *database);


#endif