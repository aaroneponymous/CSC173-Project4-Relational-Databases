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
    gpgRelation->entries = 0;
    gpgRelation->capacity = capacity;
    gpgRelation->gameIdHashTable = newHashTable(capacity);
    gpgRelation->playerIdHashTable = newHashTable(capacity);
    gpgRelation->goalsHashTable = newHashTable(capacity);
    return gpgRelation;
}

// Function to insert a new GPG Tuple into the Relation

bool insert_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation) {

    // Check if the GPG Tuple already exists in the Relation
    // If it does, return and do not insert (No duplicates/or multiple PlayerIDs with different name or birthdate)
    Bucket tupleBucket = lookup_GPG(gameId, playerId, goals, gpgRelation);

    if (!tupleBucket) {

        GPG gpgNew = newGPG(gameId, playerId, goals);
        printf("\n\nInserting: \n GameID: %s\n PlayerID: %s\n Goals: %s\n", gameId, playerId, goals);

        // Insert into GameID HashTable
        insert(gpgRelation->gameIdHashTable, gameId, gpgNew);
        // Insert into PlayerID HashTable
        insert(gpgRelation->playerIdHashTable, playerId, gpgNew);
        // Insert into Goals HashTable
        insert(gpgRelation->goalsHashTable, goals, gpgNew);
        // Increment the number of entries in the GPG Relation
        gpgRelation->entries++;

        printf("\n\nDuplicate Doesn't Exist, Insert Successful!\n");
        printf("Entries in GPG Relation: %d\n\n", gpgRelation->entries);
        return true;
    }

    printf("\n\nDuplicate Exists, Insert Unsuccessful!\n");
    printf("Entries in GPG Relation: %d\n\n", gpgRelation->entries);

    return false;

}

// Look Up Function

Bucket lookup_GPG(char* gameId, char* playerId, char* goals, struct GPGRelation *gpgRelation) {

    // gameID Asterisk
    bool gameIDAsterisk = strcmp(gameId, "*") == 0;
    // playerID Asterisk
    bool playerIDAsterisk = strcmp(playerId, "*") == 0;
    // goals Asterisk
    bool goalsAsterisk = strcmp(goals, "*") == 0;

    // Parameters: gameId, playerId, goals
    // Can be any combination of asterisks and values
    // If all asterisks, return getAllBucket()
    // 2^3 = 8 cases

    // Case 1: gameID = *, playerID = *, goals = *
    if (gameIDAsterisk && playerIDAsterisk && goalsAsterisk) {
        return getAllBuckets(gpgRelation->gameIdHashTable);
    }

    // Case 2: gameID = *, playerID = *, goals = value
    if (gameIDAsterisk && playerIDAsterisk && !goalsAsterisk) {
        return lookUpBucket(gpgRelation->goalsHashTable, gpgRelation->capacity, goals);
    }

    // Case 3: gameID = *, playerID = value, goals = *
    if (gameIDAsterisk && !playerIDAsterisk && goalsAsterisk) {
        return lookUpBucket(gpgRelation->playerIdHashTable, gpgRelation->capacity, playerId);
    }

    // Case 4: gameID = *, playerID = value, goals = value
    if (gameIDAsterisk && !playerIDAsterisk && !goalsAsterisk) {
        Bucket bucket = lookUpBucket(gpgRelation->playerIdHashTable, gpgRelation->capacity, playerId);
        while (bucket != NULL) {
            GPG gpg = (GPG) bucket->relationTuple;
            if (strcmp(gpg->Goals, goals) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

    // Case 5: gameID = value, playerID = *, goals = *
    if (!gameIDAsterisk && playerIDAsterisk && goalsAsterisk) {
        return lookUpBucket(gpgRelation->gameIdHashTable, gpgRelation->capacity, gameId);
    }

    // Case 6: gameID = value, playerID = *, goals = value
    if (!gameIDAsterisk && playerIDAsterisk && !goalsAsterisk) {
        Bucket bucket = lookUpBucket(gpgRelation->gameIdHashTable, gpgRelation->capacity, gameId);
        while (bucket != NULL) {
            GPG gpg = (GPG) bucket->relationTuple;
            if (strcmp(gpg->Goals, goals) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

    // Case 7: gameID = value, playerID = value, goals = *
    if (!gameIDAsterisk && !playerIDAsterisk && goalsAsterisk) {
        Bucket bucket = lookUpBucket(gpgRelation->gameIdHashTable, gpgRelation->capacity, gameId);
        while (bucket != NULL) {
            GPG gpg = (GPG) bucket->relationTuple;
            if (strcmp(gpg->PlayerId, playerId) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

    // Case 8: gameID = value, playerID = value, goals = value
    if (!gameIDAsterisk && !playerIDAsterisk && !goalsAsterisk) {
        Bucket bucket = lookUpBucket(gpgRelation->gameIdHashTable, gpgRelation->capacity, gameId);
        while (bucket != NULL) {
            GPG gpg = (GPG) bucket->relationTuple;
            if (strcmp(gpg->PlayerId, playerId) == 0 && strcmp(gpg->Goals, goals) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
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










