#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"
#include "GPGRelation.h"



// Relation GPG

// Function to create a new GPG Tuple
GPG newGPG(char* gameId, char* playerId, char* goals) {
    GPG gpg = malloc(sizeof(struct GPG));
    if (gpg == NULL) {
        // error handling
        return NULL;
    }

    // Set the fields of the GPG struct
    strcpy(gpg->GameId, gameId);
    strcpy(gpg->PlayerId, playerId);
    strcpy(gpg->Goals, goals);

    return gpg;
}

// Function to create a new GPG Relation (HashTables))

GPGRelation newGPGRelation(int capacity) {
    GPGRelation gpgRelation = malloc(sizeof(struct GPGRelation));
    gpgRelation->capacity = capacity;
    gpgRelation->gameIdHashTable = newHashTable(capacity);
    gpgRelation->playerIdHashTable = newHashTable(capacity);
    gpgRelation->goalsHashTable = newHashTable(capacity);
    return gpgRelation;
}

// Function to insert a new GPG Tuple into the Relation

bool insert_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation) {
    GPG gpg = newGPG(gameId, playerId, goals);
    // Check if the GPG Tuple already exists in the Relation
    // If it does, return and do not insert (No duplicates/or multiple PlayerIDs with different name or birthdate)
    Bucket tuple = lookup_GPG(gameId, playerId, goals, gpgRelation);

    if (tuple != NULL) {
        return false;

    }

    // Insert into GameID HashTable
    insert(gpgRelation->gameIdHashTable, gameId, gpg);
    // Insert into PlayerID HashTable
    insert(gpgRelation->playerIdHashTable, playerId, gpg);
    // Insert into Goals HashTable
    insert(gpgRelation->goalsHashTable, goals, gpg);

    return true;
}

// Look Up Function

Bucket lookup_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation) {
    // Accommodate for when user enters asterisk to return tuples that match

    // If GameID is not *
    if (strcmp(gameId, "*") != 0 && strcmp(playerId, "*") != 0 && strcmp(goals, "*") != 0) {
        // Look up in GameID HashTable
        Bucket bucket = lookUpBucket(gpgRelation->gameIdHashTable, gpgRelation->capacity, gameId);
        while (bucket != NULL) {
            GPG gpg = (GPG) bucket->relationTuple;
            if (strcmp(gpg->GameId, gameId) == 0 && strcmp(gpg->PlayerId, playerId) == 0 &&
                strcmp(gpg->Goals, goals) == 0) {
                printGPG(bucket);
                return bucket;
            }
            bucket = bucket->next;
        }
    }

    return NULL;
}


// Free GPG Relation
void freeGPGRelation(struct GPGRelation *gpgRelation) {

    // Free the Bucket->Value
    HashTable hashTable = gpgRelation->gameIdHashTable;
    for (int i = 0; i < gpgRelation->capacity; i++) {

        Bucket bucket = hashTable->table[i];

        while (bucket != NULL) {
            freeGPG((GPG) bucket->relationTuple);
            bucket = bucket->next;
        }
    }

    freeHashTable(gpgRelation->gameIdHashTable);
    freeHashTable(gpgRelation->playerIdHashTable);
    freeHashTable(gpgRelation->goalsHashTable);
    free(gpgRelation);
}

// Free GPG Tuple
void freeGPG(GPG gpg) {
    free(gpg);
}

// Print Function
void printGPG(Bucket bucketPointer) {
    GPG tuple = (GPG) bucketPointer->relationTuple;
    printf("\n GameID: %s \n PlayerID: %s \n Goals: %s \n", tuple->GameId, tuple->PlayerId, tuple->Goals);
}










