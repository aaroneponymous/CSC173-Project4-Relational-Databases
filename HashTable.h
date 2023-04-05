#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef HashTable_h
#define HashTable_h

#define MAX_TABLE_SIZE 1009


typedef struct Bucket* Bucket;

struct Bucket {
    void *relationTuple;
    struct Bucket *next;
};

typedef struct HashTable* HashTable;

struct HashTable {
    int capacity;
    int entries;
    Bucket table[MAX_TABLE_SIZE];
};



// Create a new HashTable
extern HashTable newHashTable(int capacity);

// Hash Function
extern int hashFunction(char *value, int capacity);

// Insert a relationTuple into the HashTable
extern void insert(HashTable table, char *key, void *relationTuple);

// Look Up a relationTuple in the HashTable and return the Bucket
extern Bucket lookUpBucket(HashTable table, int capacity, void *value);

extern bool deleteBucket(HashTable table, char *key, void *relationTuple);

extern bool deleteBucketandTuple(HashTable table, char *key, void *relationTuple);

extern void deleteAllBuckets(HashTable table);



// Get All Populated Buckets
extern Bucket getAllBuckets(HashTable hashTable);

// Delete a relationTuple from the HashTable
//extern bool deleteBucket(HashTable table, void *value);

// Print the HashTable
extern void printHashTablePNB(HashTable table);
extern void printHashTableTPN(HashTable table);
extern void printHashTableTC(HashTable table);
extern void printHashTableGHVD(HashTable table);
extern void printHashTableGPG(HashTable table);


// Free the HashTable
extern void freeHashTable(HashTable table);
extern void freeAllTuples(HashTable table);


#endif
