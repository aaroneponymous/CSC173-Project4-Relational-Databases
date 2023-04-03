#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Database.h"
#include "Hashtable.h"
#include "Query.h"

void partA() {
        printf("\n----------------------------Part A----------------------------\n");
        Database database = createDatabase(MAX_TABLE_SIZE, "CSC173 RELATIONAL DATABASE");
        loadDatabase(database);

        // (a) lookup(⟨“Americans”, 61367, 99⟩, Team-PlayerId-Number)
        printf("\n----------Testing Lookup Function for TPN Relation-------------\n");
        printf("Looking up TPN Tuple with Team: Americans, PlayerID: 61367, Number: 99\n\n");
        lookupTPN("Americans", "61367", "99", database);
        // (b) lookup(⟨“Crunch”, 51213, ∗⟩, Team-PlayerId-Number)
        printf("\n----------Testing Lookup Function for TPN Relation-------------\n");
        printf("Looking up TPN Tuple with Team: Crunch, PlayerID: 51213, Number: *\n\n");
        lookupTPN("Crunch", "51213", "*", database);
        // (c) lookup(⟨“Americans”, “Toronto”⟩, Team-City)
        printf("\n----------Testing Lookup Function for TC Relation-------------\n");
        printf("Looking up TC Tuple with Team: Americans, City: Toronto\n\n");
        lookupTC("Americans", "Toronto", database);


        printf("\n----------Testing Insertion-------------\n");
        // (g) insert(⟨“Ice Pilots”, “Pensacola”⟩, Team-City)
        insertTC("Ice Pilots", "Pensacola", database);
        printf("TC Relation after Insertion:\n");
        printTCRelation(database);
        // (h) insert(⟨“Crunch”, “Syracuse”⟩, Team-City)
        insertTC("Crunch", "Syracuse", database);
        printf("TC Relation after Insertion:\n");
        printTCRelation(database);

        destroyDatabase(database);

        printf("\n--------------------------------------------------------------\n");


}

void partB() {
    printf("\n----------------------------Part B----------------------------\n");
    Database database = createDatabase(MAX_TABLE_SIZE, "CSC173 RELATIONAL DATABASE");
    loadDatabase(database);

    // Call the REPL for the PNB Relation
    printf("\n----------Testing REPL for PNB Relation-------------\n");
    qNameNumberREPL(database);
    // Call the REPL for the TPN Relation
    printf("\n----------Testing REPL for TPN Relation-------------\n");
    qNameGoalsREPL(database);

    qNameGoals("A. Moore", "3 Jan 2023", database);

    qNameGoals("T. Sullivan", "3 Jan 2023", database);

    destroyDatabase(database);

    printf("\n-------------------------------------------------------------\n");
}


int main() {
    clock_t start_time = clock();
    partA();
    partB();
    clock_t end_time = clock();
    double time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds \n", time);
    return 0;

}
/*
int main() {

    clock_t start_time = clock();



*/
/*
    printf("\n\n\n\n---------------------------------------------Look Up Tuples:----------------------------------------------\n\n\n\n");

    // Look Up Tuples
    // GHVD
    printf("Query 1: \n");
    lookupGHVD("5", "*", "*", "8 Jan 2023", database);
    printf("\nQuery 2: \n");
    lookupGHVD("*", "*", "*", "3 Jan 2023", database);
    printf("\nQuery 3: \n");
    lookupGHVD("2", "Crunch", "Redwings", "*", database);
    printf("\nQuery 4: \n");
    lookupGHVD("4", "Redwings", "*", "6 Jan 2023", database);


    // Query Function
    printf("------------------------------------------------NAME - TEAM --> Number------------------------------------------------\n\n\n\n");

    qNameNumber("A. Moore", "Americans", database);

    // Query Function NAME - DATE --> Goal
    printf("------------------------------------------------NAME - DATE --> Goals------------------------------------------------\n\n\n\n");

    qNameGoals("A. Moore", "12 Jan 2023", database);


*//*







    */
/*  // Print Database
      printf("\n\n\n\nPrinting All Relations: \n");
      printAll(database);*//*


*/
/*    // Test qNameTeam Function
    printf("\n\n\n\nRunning Query for T. Sullivan and Crunch\n\n");
    qNameTeam("T. Sullivan", "Crunch", database);*//*



*/
/*    Bucket tpnBucket = lookup_TPN("Crunch", "51213", "11", database->tpnRelation);

    while(tpnBucket) {
        TPN tpnTest = tpnBucket->relationTuple;
        // Print the Team, PlayerID, and Number
        printf("\n\nTeam: %s, PlayerID: %s, Number: %s", tpnTest->Team, tpnTest->PlayerId, tpnTest->Number);
        tpnBucket = tpnBucket->next;
    }*//*


    // Destroy Database



    clock_t end_time = clock();

    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\n\n\nTime Taken: %f seconds", elapsed_time);




    return 0;
}




*/
/*
    // PNB Relation

    PNBRelation pnbRelation = newPNBRelation(MAX_TABLE_SIZE);

    // Populate Database PNB Relation
    insert_PNB( "59797", "G. Jones", "26 Dec 1986",pnbRelation);
    insert_PNB( "75196", "A. Moore", "28 Aug 1985",pnbRelation);
    insert_PNB( "87977", "U. Hughes", "13 Feb 1990",pnbRelation);
    insert_PNB( "20945", "Q. Morgan", "14 Feb 1998",pnbRelation);
    insert_PNB( "70513", "G. King", "13 Apr 1993",pnbRelation);
    insert_PNB( "51213", "T. Sullivan", "24 Jun 1995",pnbRelation);
    insert_PNB( "61367", "A. Moore", "18 Mar 2000",pnbRelation);
    insert_PNB( "55870", "D. Hernandez", "25 Jul 1997",pnbRelation);
    insert_PNB( "47087", "W. Stewart", "5 Jan 1994",pnbRelation);
    insert_PNB( "39468", "G. Jones", "25 Feb 1990", pnbRelation);

    // TPN Relation

    TPNRelation tpnRelation = newTPNRelation(MAX_TABLE_SIZE);

    insert_TPN("Americans", "87977", "11", tpnRelation);
    insert_TPN("Americans", "75196", "7", tpnRelation);
    insert_TPN("Americans", "61367", "99", tpnRelation);
    insert_TPN("Maple Leafs", "75196", "7", tpnRelation);
    insert_TPN("Maple Leafs", "20945", "24", tpnRelation);
    insert_TPN("Redwings", "70513", "10", tpnRelation);
    insert_TPN("Redwings", "20945", "10", tpnRelation);
    insert_TPN("Crunch", "51213", "1", tpnRelation);
    insert_TPN("Crunch", "51213", "9", tpnRelation);
    insert_TPN("Crunch", "55870", "13", tpnRelation);


    // TC Relation

    TCRelation tcRelation = newTCRelation(MAX_TABLE_SIZE);

    insert_TC("Americans", "Rochester", tcRelation);
    insert_TC("Maple Leafs", "Toronto", tcRelation);
    insert_TC("Redwings", "Detroit", tcRelation);
    insert_TC("Crunch", "Syracuse", tcRelation);


    // GHVD Relation

    GHVDRelation ghvdRelation = newGHVDRelation(MAX_TABLE_SIZE);

    insert_GHVD("1", "Americans", "Maple Leafs", "3 Jan 2023", ghvdRelation);
    insert_GHVD("2", "Crunch", "Redwings", "3 Jan 2023", ghvdRelation);
    insert_GHVD("3", "Americans", "Crunch", "6 Jan 2023", ghvdRelation);
    insert_GHVD("4", "Redwings", "Maple Leafs", "6 Jan 2023", ghvdRelation);
    insert_GHVD("5", "Redwings", "Americans", "8 Jan 2023", ghvdRelation);
    insert_GHVD("6", "Maple Leafs", "Crunch", "8 Jan 2023", ghvdRelation);
    insert_GHVD("7", "Maple Leafs", "Crunch", "9 Jan 2023", ghvdRelation);
    insert_GHVD("8", "Americans", "Redwings", "10 Jan 2023", ghvdRelation);
    insert_GHVD("9", "Maple Leafs", "Redwings", "10 Jan 2023", ghvdRelation);
    insert_GHVD("10", "Crunch", "Americans", "11 Jan 2023", ghvdRelation);
    insert_GHVD("11", "Crunch", "Redwings", "12 Jan 2023", ghvdRelation);


    GPGRelation gpgRelation = newGPGRelation(MAX_TABLE_SIZE);

    // Populate GPG Relation

    insert_GPG("2", "55870", "1", gpgRelation);
    insert_GPG("2", "70513", "2", gpgRelation);
    insert_GPG("3", "51213", "1", gpgRelation);
    insert_GPG("5", "20945", "4", gpgRelation);
    insert_GPG("6", "55870", "2", gpgRelation);
    insert_GPG("7", "75196", "1", gpgRelation);
    insert_GPG("8", "87977", "1", gpgRelation);
    insert_GPG("8", "75196", "2", gpgRelation);
    insert_GPG("9", "55870", "3", gpgRelation);
    insert_GPG("9", "61367", "2", gpgRelation);





    // Print all relations
    printHashTablePNB(pnbRelation->playerIDHashTable);
    printHashTableTPN(tpnRelation->teamHashTable);
    printHashTableTC(tcRelation->teamHashTable);
    printHashTableGHVD(ghvdRelation->gameIdHashTable);
    printHashTableGPG(gpgRelation->gameIdHashTable);

    freePNBRelation(pnbRelation);
    freeTPNRelation(tpnRelation);
    freeTCRelation(tcRelation);
    freeGHVDRelation(ghvdRelation);
    freeGPGRelation(gpgRelation);

*//*





*/
/*

// Test PNBRelation
PNBRelation pnbRelation = newPNBRelation(17);
insert_PNB("75196", "A. Moore", "28 Aug 1985", pnbRelation);
insert_PNB("59797", "G. Jones", "26 Dec 1986", pnbRelation);
insert_PNB("87977", "U. Hughes", "13 Feb 1990", pnbRelation);
insert_PNB("20945", "Q. Morgan", "14 Feb 1998", pnbRelation);
insert_PNB("70513", "G. King", "13 Apr 1993", pnbRelation);
insert_PNB("51213", "T. Sullivan", "24 Jun 1995", pnbRelation);
insert_PNB("61367", "A. Moore", "18 Mar 2000", pnbRelation);
insert_PNB("55870", "D. Hernandez", "25 Jul 1997", pnbRelation);
insert_PNB("47087", "W. Stewart", "5 Jan 1994", pnbRelation);
insert_PNB("39468", "G. Jones", "25 Feb 1990", pnbRelation);

// Test lookup_PNB for Inserted PNBs

printPNB(lookup_PNB("75196", "A. Moore", "28 Aug 1985", pnbRelation));
printPNB(lookup_PNB("59797", "G. Jones", "26 Dec 1986", pnbRelation));
printPNB(lookup_PNB("87977", "U. Hughes", "13 Feb 1990", pnbRelation));
printPNB(lookup_PNB("20945", "Q. Morgan", "14 Feb 1998", pnbRelation));
printPNB(lookup_PNB("70513", "G. King", "13 Apr 1993", pnbRelation));
printPNB(lookup_PNB("51213", "T. Sullivan", "24 Jun 1995", pnbRelation));
printPNB(lookup_PNB("61367", "A. Moore", "18 Mar 2000", pnbRelation));
printPNB(lookup_PNB("55870", "D. Hernandez", "25 Jul 1997", pnbRelation));
printPNB(lookup_PNB("47087", "W. Stewart", "5 Jan 1994", pnbRelation));
printPNB(lookup_PNB("39468", "G. Jones", "25 Feb 1990", pnbRelation));








// Free PNBRelation
freePNBRelation(pnbRelation);
*/