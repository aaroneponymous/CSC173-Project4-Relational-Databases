#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hashtable.h"
#include "TCRelation.h"




// Relation TC

// Function to create a new TC Tuple
TC newTC(char* teamId, char* city) {
    TC tc = malloc(sizeof(struct TC));
    if (tc == NULL) {
        // error handling
        return NULL;
    }

    // Set the fields of the TC struct
    strcpy(tc->Team, teamId);
    strcpy(tc->City, city);

    return tc;
}

// Function to create a new TC Relation (HashTables))
TCRelation newTCRelation(int capacity) {
    TCRelation tcRelation = malloc(sizeof(struct TCRelation));
    tcRelation->entries = 0;
    tcRelation->capacity = capacity;
    tcRelation->teamHashTable = newHashTable(capacity);
    tcRelation->cityHashTable = newHashTable(capacity);
    return tcRelation;
}


// Function to insert a new TC Tuple into the Relation
bool insert_TC(char* team, char* city, struct TCRelation *tcRelation) {

    // Check if the TC Tuple already exists in the Relation
    // If it does, return and do not insert (No duplicates/or multiple PlayerIDs with different name or birthdate)
    Bucket tupleBucket = lookup_TC(team, city, tcRelation); // Primary Key (All three fields)

    if (!tupleBucket) {

        TC tcNew = newTC(team, city);
        printf("\n\nInserting: \n Team: %s\n City: %s\n", team, city);

        // Insert into Team HashTable
        insert(tcRelation->teamHashTable, team, tcNew);
        // Insert into City HashTable
        insert(tcRelation->cityHashTable, city, tcNew);
        // Increment the number of entries in the TC Relation
        tcRelation->entries++;

        printf("\n\nDuplicate Doesn't Exist, Insert Successful!\n");
        printf("Entries in TC Relation: %d\n\n", tcRelation->entries);

        return true;
    }

    printf("\n\nDuplicate Exists, Insert Unsuccessful!\n");
    printf("Entries in TC Relation: %d\n\n", tcRelation->entries);

    return false;
}

// Look Up Function

Bucket lookup_TC(char* team, char* city, struct TCRelation *tcRelation) {

    // Team Asterisk
    bool teamAsterisk = strcmp(team, "*") == 0;
    // City Asterisk
    bool cityAsterisk = strcmp(city, "*") == 0;

    // Parameters: team and city to the lookup function
    // Can be either a value or an asterisk
    // 2^n = 4 cases

    // Case 1: team = *, city = *
    if (teamAsterisk && cityAsterisk) {
        return getAllBuckets(tcRelation->teamHashTable);
    }

    // Case 2: team = *, city = value
    if (teamAsterisk && !cityAsterisk) {
        return lookUpBucket(tcRelation->cityHashTable, tcRelation->capacity, city);
    }

    // Case 3: team = value, city = *
    if (!teamAsterisk && cityAsterisk) {
        return lookUpBucket(tcRelation->teamHashTable, tcRelation->capacity, team);
    }

    // Case 4: team = value, city = value
    if (!teamAsterisk && !cityAsterisk) {
        Bucket bucket = lookUpBucket(tcRelation->teamHashTable, tcRelation->capacity, team);
        if (bucket != NULL) {
            TC tc = (TC) bucket->relationTuple;
            if (strcmp(tc->City, city) == 0) {
                return bucket;
            }
        }
    }

    return NULL;

}

// Free TC Relation
void freeTCRelation(struct TCRelation *tcRelation) {

    // Free the Bucket->Value
    HashTable hashTable = tcRelation->teamHashTable;
    for (int i = 0; i < tcRelation->capacity; i++) {

        Bucket bucket = hashTable->table[i];

        while (bucket != NULL) {
            freeTC((TC) bucket->relationTuple);
            bucket = bucket->next;
        }
    }

    freeHashTable(tcRelation->teamHashTable);
    freeHashTable(tcRelation->cityHashTable);
    free(tcRelation);
}

// Free TC Tuple
void freeTC(TC tc) {
    free(tc);
}

// Print Function
void printTC(Bucket bucketPointer) {
    TC tuple = (TC) bucketPointer->relationTuple;
    printf("\n TeamID: %s \n City: %s \n", tuple->Team, tuple->City);
}