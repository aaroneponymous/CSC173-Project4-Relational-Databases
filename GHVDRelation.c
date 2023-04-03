#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"
#include "GHVDRelation.h"



// Relation GHVD

// Function to create a new GHVD Tuple
GHVD newGHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date) {
    GHVD ghvd = malloc(sizeof(struct GHVD));
    if (ghvd == NULL) {
        // error handling
        return NULL;
    }

    // Set the fields of the GHVD struct
    strcpy(ghvd->GameId, gameId);
    strcpy(ghvd->HomeTeam, homeTeam);
    strcpy(ghvd->VisitorTeam, visitorTeam);
    strcpy(ghvd->Date, date);

    return ghvd;
}

// Function to create a new GHVD Relation (HashTables))

GHVDRelation newGHVDRelation(int capacity) {
    GHVDRelation ghvdRelation = malloc(sizeof(struct GHVDRelation));
    ghvdRelation->entries = 0;
    ghvdRelation->capacity = capacity;
    ghvdRelation->gameIdHashTable = newHashTable(capacity);
    ghvdRelation->homeTeamHashTable = newHashTable(capacity);
    ghvdRelation->visitorTeamHashTable = newHashTable(capacity);
    ghvdRelation->dateHashTable = newHashTable(capacity);
    return ghvdRelation;
}

// Function to insert a new GHVD Tuple into the Relation

bool insert_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation) {

    // Check if the GHVD Tuple already exists in the Relation
    // If it does, return and do not insert
    // Game ID is the primary key, so we only need to check that
    Bucket tupleBucket = lookup_GHVD(gameId, homeTeam, visitorTeam, date, ghvdRelation);

    if (!tupleBucket) {

        GHVD ghvdNew = newGHVD(gameId, homeTeam, visitorTeam, date);
        printf("\n\nInserting: \n GameID: %s\n HomeTeam: %s\n VisitorTeam: %s\n Date: %s\n", gameId, homeTeam, visitorTeam, date);

        // Insert into GameID HashTable
        insert(ghvdRelation->gameIdHashTable, gameId, ghvdNew);
        // Insert into HomeTeam HashTable
        insert(ghvdRelation->homeTeamHashTable, homeTeam, ghvdNew);
        // Insert into VisitorTeam HashTable
        insert(ghvdRelation->visitorTeamHashTable, visitorTeam, ghvdNew);
        // Insert into Date HashTable
        insert(ghvdRelation->dateHashTable, date, ghvdNew);
        ghvdRelation->entries++;

        printf("\n\nDuplicates Doesn't Exist, Insert Successful!\n");
        printf("Entries in GHVD Relation: %d\n\n", ghvdRelation->entries);

        return true;
    }

    printf("\nInserting: \n GameID: %s\n HomeTeam: %s\n VisitorTeam: %s\n Date: %s\n", gameId, homeTeam, visitorTeam, date);
    printf("\n\nDuplicate Exists, Insert Unsuccessful!\n\n");
    printf("Entries in GHVD Relation: %d\n\n", ghvdRelation->entries);

    return false;
}




// Free GHVD Relation
void freeGHVDRelation(struct GHVDRelation *ghvdRelation) {

    // Free the Bucket->Value
    HashTable hashTable = ghvdRelation->gameIdHashTable;
    for (int i = 0; i < ghvdRelation->capacity; i++) {

        Bucket bucket = hashTable->table[i];

        while (bucket != NULL) {
            freeGHVD((GHVD) bucket->relationTuple);
            bucket = bucket->next;
        }
    }

    freeHashTable(ghvdRelation->gameIdHashTable);
    freeHashTable(ghvdRelation->homeTeamHashTable);
    freeHashTable(ghvdRelation->visitorTeamHashTable);
    freeHashTable(ghvdRelation->dateHashTable);
    free(ghvdRelation);
}

// Free GHVD Tuple
void freeGHVD(GHVD ghvd) {
    free(ghvd);
}

// Print Function
void printGHVD(Bucket bucketPointer) {
    GHVD tuple = (GHVD) bucketPointer->relationTuple;
    printf("\n GameID: %s \n HomeTeam: %s \n VisitorTeam: %s \n Date: %s \n", tuple->GameId, tuple->HomeTeam,
           tuple->VisitorTeam, tuple->Date);
}
