#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"
#include "PNBRelation.h"




// Relation PNB

// Function to create a new PNB Tuple
PNB newPNB(char* playerId, char* name, char* birthDate) {
    PNB pnb = malloc(sizeof(struct PNB));
    if (pnb == NULL) {
        // error handling
        return NULL;
    }

    // Set the fields of the PNB struct
    strcpy(pnb->PlayerId, playerId);
    strcpy(pnb->Name, name);
    strcpy(pnb->BirthDate, birthDate);

    return pnb;
}

// Function to create a new PNB Relation (HashTables))
PNBRelation newPNBRelation(int capacity) {
    PNBRelation pnbRelation = malloc(sizeof(struct PNBRelation));
    pnbRelation->entries = 0;
    pnbRelation->capacity = capacity;
    pnbRelation->playerIDHashTable = newHashTable(capacity);
    pnbRelation->nameHashTable = newHashTable(capacity);
    pnbRelation->birthDateHashTable = newHashTable(capacity);
    return pnbRelation;
}

// Function to insert a new PNB Tuple into the Relation
bool insert_PNB(char* playerId, char* name, char* birthDate, struct PNBRelation *pnbRelation) {
    // Check if the PNB Tuple already exists in the Relation
    // If it does, return and do not insert (No duplicates/or multiple PlayerIDs with different name or birthdate)
    Bucket tupleBucket = lookup_PNB(playerId, "*", "*", pnbRelation); // Use Primary Key Only

    if (!tupleBucket) {

        PNB pnbNew = newPNB(playerId, name, birthDate);
        printf("\n\nInserting: \n PlayerID: %s\n Name: %s\n BirthDate: %s\n", playerId, name, birthDate);



        // Insert into PlayerID HashTable
        insert(pnbRelation->playerIDHashTable, playerId, pnbNew);
        // Insert into Name HashTable
        insert(pnbRelation->nameHashTable, name, pnbNew);
        // Insert into BirthDate HashTable
        insert(pnbRelation->birthDateHashTable, birthDate, pnbNew);
        // Increment the number of entries in the PNB Relation
        pnbRelation->entries++;

        printf("\n\nDuplicate Doesn't Exist, Insert Successful!\n");
        printf("Entries in PNB Relation: %d\n\n", pnbRelation->entries);

        return true;

    }

    printf("\nInserting: \n PlayerID: %s\n Name: %s\n BirthDate: %s\n", playerId, name, birthDate);
    printf("\nDuplicate Exists, Insert Unsuccessful!\n");
    printf("Entries in PNB Relation: %d\n\n", pnbRelation->entries);
    return false;
}

// Look Up Function
Bucket lookup_PNB(char* playerId, char* playerName, char* birthDate, struct PNBRelation *pnbRelation) {

    // Player ID asterisk
    bool playerIDisAst = strcmp(playerId, "*") == 0;
    // Player Name asterisk
    bool playerNameisAst = strcmp(playerName, "*") == 0;
    // Player BirthDate asterisk
    bool playDOBisAst = strcmp(birthDate, "*") == 0;

    // Parameters: playerId, playerName and birthDate passed to the lookup_PNB function
    // Can be of various combinations:
    // They can either take "*" or a specific value


    // 1. playerId = *, playerName = *, birthDate = *
    // If all parameters are asterisks, then have to return all the tuples in the relation
    // @TODO: Instead of returning a list of buckets with all the tuples:
    // @TODO: Condition Check this in insertpnb function in Database
    // @TODO: And use a print hashtable function to print all the tuples in the relation

    // But still create a chain of buckets to return

    if (playerIDisAst && playerNameisAst && playDOBisAst) {
        return getAllBuckets(pnbRelation->playerIDHashTable);
    }

        // 2. playerId = *, playerName = *, birthDate = specific value
        // 3. playerId = *, playerName = specific value, birthDate = *
    else if (playerIDisAst && (!playerNameisAst ^ !playDOBisAst)) {

        if (!playerNameisAst) {
            return lookUpBucket(pnbRelation->nameHashTable, pnbRelation->capacity, playerName);
        } else {
            return lookUpBucket(pnbRelation->birthDateHashTable, pnbRelation->capacity, birthDate);
        }
    }

        // @TODO: Fix this -> Condition Testing
        // 4. playerId = "*", playerName = specific value, birthDate = specific value
    else if (playerIDisAst && !playerNameisAst && !playDOBisAst) {

        Bucket bucket = lookUpBucket(pnbRelation->nameHashTable, pnbRelation->capacity, playerName);
        while (bucket) {
            PNB pnbTuple = bucket->relationTuple;
            char *pnbTupleBirthDate = pnbTuple->BirthDate;
            char *pnbTuplePlayerName = pnbTuple->Name;
            if (strcmp(pnbTupleBirthDate, birthDate) == 0 && strcmp(pnbTuplePlayerName, playerName) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }

    }

    // 5. playerId = specific value, playerName = *, birthDate = *
    if (!playerIDisAst && playerNameisAst && playDOBisAst) {
        Bucket bucket = lookUpBucket(pnbRelation->playerIDHashTable, pnbRelation->capacity, playerId);
        return bucket;
    }
    // 6. playerId = specific value, playerName = *, birthDate = specific value
    if (!playerIDisAst && playerNameisAst && !playDOBisAst) {
        Bucket bucket = lookUpBucket(pnbRelation->playerIDHashTable, pnbRelation->capacity, playerId);
        while (bucket) {
            PNB pnbTuple = bucket->relationTuple;
            char *pnbTupleBirthDate = pnbTuple->BirthDate;
            if (strcmp(pnbTupleBirthDate, birthDate) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
    }
    // 7. playerId = specific value, playerName = specific value, birthDate = *
    if (!playerIDisAst && !playerNameisAst && playDOBisAst) {
        Bucket bucket = lookUpBucket(pnbRelation->playerIDHashTable, pnbRelation->capacity, playerId);
        while (bucket) {
            PNB pnbTuple = bucket->relationTuple;
            char *pnbTupleName = pnbTuple->Name;
            if (strcmp(pnbTupleName, playerName) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
    }
    // 8. playerId = specific value, playerName = specific value, birthDate = specific value
    if (!playerIDisAst && !playerNameisAst && !playDOBisAst) {
        Bucket bucket = lookUpBucket(pnbRelation->playerIDHashTable, pnbRelation->capacity, playerId);
        while (bucket) {
            PNB pnbTuple = bucket->relationTuple;
            char *pnbTupleName = pnbTuple->Name;
            char *pnbTupleBirthDate = pnbTuple->BirthDate;
            if (strcmp(pnbTupleName, playerName) == 0 && strcmp(pnbTupleBirthDate, birthDate) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
    }

    return NULL;
}


// @TODO: Implement Delete Function

// Delete Function
bool delete_PNB(char* playerId, char* playerName, char* birthDate, struct PNBRelation *pnbRelation) {

    Bucket deletePNBTupleBucket = lookup_PNB(playerId, playerName, birthDate, pnbRelation);

    // If both name and birthDate are not * then do something
    if (strcmp(playerId, "*") == 0 && strcmp(playerName, "*") != 0 && strcmp(birthDate, "*") != 0) {

        while (deletePNBTupleBucket->next) {
            // Check: If the name and birthDate match the name and birthDate in the bucket
            PNB pnbFirst = (PNB)deletePNBTupleBucket->relationTuple;
            PNB pnbSecond = (PNB)deletePNBTupleBucket->next->relationTuple;
            char *playerNameDelete = pnbFirst->Name;
            char *playerBirthDate = pnbFirst->BirthDate;

            deleteBucket(pnbRelation->playerIDHashTable, pnbFirst->PlayerId, pnbFirst);
            deleteBucket(pnbRelation->nameHashTable, pnbFirst->Name, pnbFirst);
            deleteBucketandTuple(pnbRelation->birthDateHashTable, pnbFirst->BirthDate, pnbFirst);
            pnbRelation->entries--;






            if (strcmp(playerNameDelete, pnbSecond->Name) == 0 && strcmp(playerBirthDate, pnbSecond->BirthDate) == 0) {
                deletePNBTupleBucket = deletePNBTupleBucket->next;

            }
            else {
                return false;
            }
        }
    }


    else if (deletePNBTupleBucket) {


        while (deletePNBTupleBucket) {

            PNB pnbTuple = deletePNBTupleBucket->relationTuple;

            char *playerIDDelete = pnbTuple->PlayerId;
            char *playerNameDelete = pnbTuple->Name;
            char *playerBirthDate = pnbTuple->BirthDate;

            deletePNBTupleBucket = deletePNBTupleBucket->next;


            deleteBucket(pnbRelation->playerIDHashTable, playerIDDelete, pnbTuple);
            deleteBucket(pnbRelation->nameHashTable, playerNameDelete, pnbTuple);
            deleteBucketandTuple(pnbRelation->birthDateHashTable, playerBirthDate, pnbTuple);
            pnbRelation->entries--;


        }

        return true;

    }

    return false;
}

// Free PNB Relation
void freePNBRelation(struct PNBRelation *pnbRelation) {

    // Free the Bucket->Value
    HashTable hashTable = pnbRelation->playerIDHashTable;
    for (int i = 0; i < pnbRelation->capacity; i++) {

        Bucket bucket = hashTable->table[i];

        while (bucket != NULL) {
            if(bucket->relationTuple != NULL) {
                freePNB((PNB) bucket->relationTuple);

            }
            bucket = bucket->next;
        }
    }

    freeHashTable(pnbRelation->playerIDHashTable);
    freeHashTable(pnbRelation->nameHashTable);
    freeHashTable(pnbRelation->birthDateHashTable);
    free(pnbRelation);
}

// Free PNB Tuple
void freePNB(PNB pnb) {
    free(pnb);
}

// Print Function
void printPNB(Bucket bucketPointer) {
    PNB tuple = (PNB) bucketPointer->relationTuple;
    printf("\n PlayerID: %s \n PlayerName: %s \n BirthDate: %s \n", tuple->PlayerId, tuple->Name, tuple->BirthDate);

}

