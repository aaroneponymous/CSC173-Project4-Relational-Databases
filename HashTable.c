#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"
#include "PNBRelation.h"
#include "TPNRelation.h"
#include "TCRelation.h"
#include "GHVDRelation.h"
#include "GPGRelation.h"
#include "Database.h"



// Create a new HashTable
HashTable newHashTable(int capacity) {
    HashTable newTable = malloc(sizeof(struct HashTable));
    newTable->capacity = capacity;
    newTable->entries = 0;
    for (int i = 0; i < newTable->capacity; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}

// Hash Function

int hashFunction(char *value, int capacity) {
    int hash = 0;
    for (int i = 0; i < strlen(value); i++) {
        hash = (hash + value[i]) % capacity;
    }
    return hash;
}
// Insert a relationTuple into the HashTable
void insert(HashTable table, char *key, void *relationTuple){
    int index = hashFunction(key, table->capacity);

    if (table->table[index] == NULL) {
        table->table[index] = malloc(sizeof(struct Bucket));
        table->table[index]->relationTuple = relationTuple;
        table->table[index]->next = NULL;
        table->entries += 1;

    }

    else {

        Bucket current = table->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        Bucket newBucket = malloc(sizeof(struct Bucket));
        current->next = newBucket;
        newBucket->relationTuple = relationTuple;
        newBucket->next = NULL;
        table->entries += 1;

    }

}

// Look Up a relationTuple in the HashTable and return the Bucket
Bucket lookUpBucket(HashTable table, int capacity, void *value) {
    int index = hashFunction(value, capacity);
    Bucket current = table->table[index];
    if (current) {
        return current;
    }
    else {
        return NULL;
    }
}

// @TODO: Remember to properly free this list of buckets
Bucket getAllBuckets(HashTable hashTable) {
    if (hashTable->entries != 0) {
        // First, you need to create a returnBucket Bucket and allocate memory to it. This will be the head of your list.
        Bucket returnBucket = malloc(sizeof(struct Bucket));
        //Initialize a pointer to the head of your list, and a temporary bucket pointer.
        Bucket allBucketsHead = returnBucket;
        Bucket temp;

        // Iterate through each index in the hash table, and for each non-empty bucket,
        // iterate through the linked list of buckets.
        for (int i = 0; i < hashTable->capacity; i++) {
            temp = hashTable->table[i];
            while (temp != NULL) {
                // add the current bucket to the list
                allBucketsHead->next = temp;
                allBucketsHead = allBucketsHead->next;
                // move to the next bucket in the linked list
                temp = temp->next;
            }
        }

        allBucketsHead->next = NULL;
        return returnBucket->next;
    }
    else {
        return NULL;
    }
}


// @TODO: Implement this function: In the Relations Delete Functions
// @TODO: Relation Delete Functions check the tuple's existence
// @TODO: if yes, then it frees the tuple and then calls
// @TODO: deleteBucket to delete the bucket and maintain the
// @TODO: integrity of the Bucket List
// @TODO: And then that functions moves on bucket->next
// @TODO: and repeats the process
/*bool deleteBucket(HashTable hashTable, Bucket bucket) {
    free(bucket);
}*/

// Print the HashTable PIB
void printHashTablePNB(HashTable table) {
    printf("\n\nPrinting PNB Relation Tuples:\n");
    printf("\nEntries in PNB Relation: %d\n\n", table->entries);
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            printf("\nEntry at Index: %d\n", i);
            printPNB(current);
            current = current->next;
        }
    }
}

// Print the HashTable TPN
void printHashTableTPN(HashTable table) {
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            printTPN(current);
            current = current->next;
        }
    }
}

// Print the HashTable TC
void printHashTableTC(HashTable table) {
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            printTC(current);
            current = current->next;
        }
    }
}

// Print the HashTable GHVD
void printHashTableGHVD(HashTable table) {
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            printGHVD(current);
            current = current->next;
        }
    }
}

// Print the HashTable GPG
void printHashTableGPG(HashTable table) {
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            printGPG(current);
            current = current->next;
        }
    }
}

// Free the HashTable

void freeHashTable(HashTable table) {
    for (int i = 0; i < table->capacity; i++) {
        Bucket current = table->table[i];
        while (current != NULL) {
            Bucket temp = current;
            current = current->next;
            free(temp);
            temp = NULL;
        }

        table->table[i] = NULL;
    }

    free(table);
}



