#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"
#include "TPNRelation.h"

// Relation TPN

// Function to create a new TPN Tuple
TPN newTPN(char* teamId, char* playerId, char* number) {
    TPN tpn = malloc(sizeof(struct TPN));
    if (tpn == NULL) {
        // error handling
        return NULL;
    }

    // Set the fields of the TPN struct
    strcpy(tpn->Team, teamId);
    strcpy(tpn->PlayerId, playerId);
    strcpy(tpn->Number, number);

    return tpn;
}

// Function to create a new TPN Relation (HashTables))
TPNRelation newTPNRelation(int capacity) {
    TPNRelation tpnRelation = malloc(sizeof(struct TPNRelation));
    tpnRelation->entries = 0;
    tpnRelation->capacity = capacity;
    tpnRelation->teamHashTable = newHashTable(capacity);
    tpnRelation->playerIDHashTable = newHashTable(capacity);
    tpnRelation->numberHashTable = newHashTable(capacity);
    return tpnRelation;
}

// Function to insert a new TPN Tuple into the Relation
bool insert_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation) {

    // Check if the TPN Tuple already exists in the Relation
    // If it does, return and do not insert (No duplicates/or multiple PlayerIDs with different name or birthdate)
    Bucket tupleBucket = lookup_TPN(team, playerId, number, tpnRelation); // Primary Key (All three fields)

    if (!tupleBucket) {

        TPN tpnNew = newTPN(team, playerId, number);
        printf("\n\nInserting: \n Team: %s\n PlayerID: %s\n Number: %s\n", team, playerId, number);

        // Insert into Team HashTable
        insert(tpnRelation->teamHashTable, team, tpnNew);
        // Insert into PlayerID HashTable
        insert(tpnRelation->playerIDHashTable, playerId, tpnNew);
        // Insert into Number HashTable
        insert(tpnRelation->numberHashTable, number, tpnNew);
        // Increment the number of entries in the TPN Relation
        tpnRelation->entries++;

        printf("\n\nDuplicate Doesn't Exist, Insert Successful!\n");
        printf("Entries in TPN Relation: %d\n\n", tpnRelation->entries);

        return true;

    }

    printf("\nInserting: \n Team: %s\n PlayerID: %s\n Number: %s\n", team, playerId, number);
    printf("\n\nDuplicate Exists, Insert Unsuccessful!\n");
    printf("Entries in TPN Relation: %d\n\n", tpnRelation->entries);
    return false;
}

// Look Up Function

Bucket lookup_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation) {

    // Team Asterisk
    bool teamIsAsterisk = strcmp(team, "*") == 0;
    // PlayerID Asterisk
    bool playerIdIsAsterisk = strcmp(playerId, "*") == 0;
    // Number Asterisk
    bool numberIsAsterisk = strcmp(number, "*") == 0;

    // Parameters: team, playerId, number passed to the lookup_TPN function
    // Can be of various combinations:
    // They can either take "*" as a parameter, or a specific value

    // List of all possible combinations of parameters

    // 1. team = *, playerId = *, number = *
    // If all the parameters are asterisks, then have to return all the tuples in the relation
    if (teamIsAsterisk && playerIdIsAsterisk && numberIsAsterisk) {
        return getAllBuckets(tpnRelation->playerIDHashTable);
    }

    // 2. team = *, playerId = *, number = specific value
    if (teamIsAsterisk && playerIdIsAsterisk && !numberIsAsterisk) {
        return lookUpBucket(tpnRelation->numberHashTable, tpnRelation->capacity, number);
    }

    // 3. team = *, playerId = specific value, number = *
    if (teamIsAsterisk && !playerIdIsAsterisk && numberIsAsterisk) {
        return lookUpBucket(tpnRelation->playerIDHashTable, tpnRelation->capacity, playerId);
    }
    // 4. team = specific value, playerId = *, number = *
    if (!teamIsAsterisk && playerIdIsAsterisk && numberIsAsterisk) {
        return lookUpBucket(tpnRelation->teamHashTable, tpnRelation->capacity, team);
    }
    // 5. team = specific value, playerId = specific value, number = *
    if (!teamIsAsterisk && !playerIdIsAsterisk && numberIsAsterisk) {
        Bucket bucket = lookUpBucket(tpnRelation->playerIDHashTable, tpnRelation->capacity, playerId);
        while (bucket != NULL) {
            TPN tpn = (TPN) bucket->relationTuple;
            if (strcmp(tpn->PlayerId, playerId) == 0 && strcmp(tpn->Team, team) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }
    // 6. team = specific value, playerId = *, number = specific value
    if (!teamIsAsterisk && playerIdIsAsterisk && !numberIsAsterisk) {
        Bucket bucket = lookUpBucket(tpnRelation->numberHashTable, tpnRelation->capacity, number);
        while (bucket != NULL) {
            TPN tpn = (TPN) bucket->relationTuple;
            if (strcmp(tpn->Number, number) == 0 && strcmp(tpn->Team, team) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }
    // 7. team = *, playerId = specific value, number = specific value
    if (teamIsAsterisk && !playerIdIsAsterisk && !numberIsAsterisk) {
        Bucket bucket = lookUpBucket(tpnRelation->playerIDHashTable, tpnRelation->capacity, playerId);
        while (bucket != NULL) {
            TPN tpn = (TPN) bucket->relationTuple;
            if (strcmp(tpn->PlayerId, playerId) == 0 && strcmp(tpn->Number, number) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }
    // 8. team = specific value, playerId = specific value, number = specific value
    if (!teamIsAsterisk && !playerIdIsAsterisk && !numberIsAsterisk) {
        Bucket bucket = lookUpBucket(tpnRelation->playerIDHashTable, tpnRelation->capacity, playerId);
        while (bucket != NULL) {
            TPN tpn = (TPN) bucket->relationTuple;
            if (strcmp(tpn->PlayerId, playerId) == 0 && strcmp(tpn->Team, team) == 0 && strcmp(tpn->Number, number) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

    return NULL;

}

bool delete_TPN(char* team, char* playerId, char* number, struct TPNRelation *tpnRelation) {

    // Team Asterisk
    bool teamIsAsterisk = strcmp(team, "*") == 0;
    // PlayerID Asterisk
    bool playerIdIsAsterisk = strcmp(playerId, "*") == 0;
    // Number Asterisk
    bool numberIsAsterisk = strcmp(number, "*") == 0;

    // 1. team = *, playerId = *, number = *
    // If all the parameters are asterisks, then have to return all the tuples in the relation
    if (teamIsAsterisk && playerIdIsAsterisk && numberIsAsterisk) {

        // Delete the tuple from all the hash tables
        deleteAllBuckets(tpnRelation->teamHashTable);
        deleteAllBuckets(tpnRelation->playerIDHashTable);
        freeAllTuples(tpnRelation->numberHashTable);

        return true;
    }

    Bucket deleteTPNBucket = lookup_TPN(team, playerId, number, tpnRelation);

    // Parameters: team, playerId, number passed to the lookup_TPN function
    // Can be of various combinations:
    // They can either take "*" as a parameter, or a specific value

    // List of all possible combinations of parameters



    // 2. team = *, playerId = *, number = specific value
    if (teamIsAsterisk && playerIdIsAsterisk && !numberIsAsterisk) {

        TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;

        while (deleteTPNBucket) {

            char *numberTuple = deleteTupleTPN->Number;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(numberTuple, number) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;
    }

    // 3. team = *, playerId = specific value, number = *
    if (teamIsAsterisk && !playerIdIsAsterisk && numberIsAsterisk) {

        TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;

        while (deleteTPNBucket) {

            char *playerIdTuple = deleteTupleTPN->PlayerId;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(playerIdTuple, playerId) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;

    }

    // 4. team = specific value, playerId = *, number = *
    if (!teamIsAsterisk && playerIdIsAsterisk && numberIsAsterisk) {



        while (deleteTPNBucket) {
            TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;
            char *teamTuple = deleteTupleTPN->Team;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(teamTuple, team) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;

    }


    // 5. team = specific value, playerId = specific value, number = *
    if (!teamIsAsterisk && !playerIdIsAsterisk && numberIsAsterisk) {

        while (deleteTPNBucket) {

            TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;
            char *teamTuple = deleteTupleTPN->Team;
            char *playerIdTuple = deleteTupleTPN->PlayerId;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(teamTuple, team) == 0 && strcmp(playerIdTuple, playerId) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;

    }

    // 6. team = specific value, playerId = *, number = specific value
    if (!teamIsAsterisk && playerIdIsAsterisk && !numberIsAsterisk) {



        while (deleteTPNBucket) {
            TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;
            char *teamTuple = deleteTupleTPN->Team;
            char *numberTuple = deleteTupleTPN->Number;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(teamTuple, team) == 0 && strcmp(numberTuple, number) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;

    }

    // 7. team = *, playerId = specific value, number = specific value
    if (teamIsAsterisk && !playerIdIsAsterisk && !numberIsAsterisk) {



        while (deleteTPNBucket) {
            TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;
            char *playerIdTuple = deleteTupleTPN->PlayerId;
            char *numberTuple = deleteTupleTPN->Number;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(playerIdTuple, playerId) == 0 && strcmp(numberTuple, number) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;


    }

    // 8. team = specific value, playerId = specific value, number = specific value
    if (!teamIsAsterisk && !playerIdIsAsterisk && !numberIsAsterisk) {



        while (deleteTPNBucket) {
            TPN deleteTupleTPN = (TPN) deleteTPNBucket->relationTuple;
            char *teamTuple = deleteTupleTPN->Team;
            char *playerIdTuple = deleteTupleTPN->PlayerId;
            char *numberTuple = deleteTupleTPN->Number;

            deleteTPNBucket = deleteTPNBucket->next;

            if (strcmp(teamTuple, team) == 0 && strcmp(playerIdTuple, playerId) == 0 && strcmp(numberTuple, number) == 0) {
                deleteBucket(tpnRelation->teamHashTable, deleteTupleTPN->Team, deleteTupleTPN);
                deleteBucket(tpnRelation->playerIDHashTable, deleteTupleTPN->PlayerId, deleteTupleTPN);
                deleteBucketandTuple(tpnRelation->numberHashTable, deleteTupleTPN->Number, deleteTupleTPN);
                tpnRelation->entries--;
            }

        }

        return true;

    }

    return NULL;
}

// Free TPN Relation
void freeTPNRelation(struct TPNRelation *tpnRelation) {

    // Free the Bucket->Value
    HashTable hashTable = tpnRelation->teamHashTable;
    for (int i = 0; i < tpnRelation->capacity; i++) {

        Bucket bucket = hashTable->table[i];

        while (bucket != NULL) {
            freeTPN((TPN) bucket->relationTuple);
            bucket = bucket->next;
        }
    }

    freeHashTable(tpnRelation->teamHashTable);
    freeHashTable(tpnRelation->playerIDHashTable);
    freeHashTable(tpnRelation->numberHashTable);
    free(tpnRelation);
}

// Free TPN Tuple
void freeTPN(TPN tpn) {
    free(tpn);
}

// Print Function
void printTPN(Bucket bucketPointer) {
    TPN tuple = (TPN) bucketPointer->relationTuple;
    printf("\n TeamID: %s \n PlayerID: %s \n Number: %s \n", tuple->Team, tuple->PlayerId, tuple->Number);
}
