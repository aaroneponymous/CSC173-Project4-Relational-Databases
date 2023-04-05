#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Database.h"
#include "Hashtable.h"
#include "Query.h"
#include "RelationalAlgebra.h"

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

    // (d) lookup(<"*", "A. Moore", "28 Aug 1985">, PNB)
    printf("\n----------Testing Lookup Function for PNB Relation-------------\n");
    printf("Looking up PNB Tuple with PlayerID: *, Name: *, BirthDate: 28 Aug 1985\n\n");
    lookupPNB("*", "*", "28 Aug 1985", database);


    printf("\n----------Testing Insertion-------------\n");
    // (g) insert(⟨“Ice Pilots”, “Pensacola”⟩, Team-City)
    insertTC("Ice Pilots", "Pensacola", database);
    printf("TC Relation after Insertion:\n");
    printTCRelation(database);
    // (h) insert(⟨“Crunch”, “Syracuse”⟩, Team-City)
    insertTC("Crunch", "Syracuse", database);
    printf("TC Relation after Insertion:\n");
    printTCRelation(database);


    // Look Up (⟨∗, “Redwings”, “Crunch”, ∗⟩, GameId-HomeTeam-AwayTeam-Date) GHVD
    printf("\n----------Testing Lookup Function for GHVD-------------\n");
    printf("Looking up GHVD Tuple with GameID: *, HomeTeam: Redwings, AwayTeam: Crunch, Date: *\n\n");
    lookupGHVD("*", "*", "Redwings", "10 Jan 2023", database);


//        // Print Hash Table PNB->PlayerID
//        printf("\n----------Testing Print Function for PNB Relation-------------\n");
//        printHashTablePNB(database->pnbRelation->playerIDHashTable);



//        // Test Delete Repl
//        deletePNB("75196", "A. Moore", "28 Aug 1985", database);

//          // Test Delete TPN
//          deleteTPN("Americans", "*", "*", database);

//        printf("\n----------Testing Delete Function for PNB Relation-------------\n");
//        deletePNBREPL(database);

//        printf("\n----------Testing Delete Function for TPN Relation-------------\n");
//        deleteTPNREPL(database);

    destroyDatabase(database);



    printf("\n--------------------------------------------------------------\n");


}

void partB() {
    printf("\n--------------------------------------------------------Part B--------------------------------------------------------\n");
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

    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
}

void partC() {
    printf("\n--------------------------------------------------------Part C--------------------------------------------------------\n");
    Database database = createDatabase(MAX_TABLE_SIZE, "CSC173 RELATIONAL DATABASE");
    loadDatabase(database);

    // IMPLEMENT THE RELATIONAL ALGEBRA FUNCTIONS
    printf("\n----------Testing Relational Algebra Functions-------------\n");
    // (a) select for TPN
    printf("\n----------(A) Testing Select Function for TPN Relation: Parameter Player ID: 51213------------\n");
    TPNRelation selectedTPNRelation = select_TPN("87977", database->tpnRelation);
    // Print the selected TPN Relation
    printHashTableTPN(selectedTPNRelation->playerIDHashTable);

    // (b) Projection for TPN
    printf("\n----------(B) Testing Projection Function for TPN Relation: Parameter Player ID: 51213------------\n");
    ProjectionTPNRelation projectedTPNRelation = project_TPN("51213", database->tpnRelation);
    // Print the projected TPN Relation
    printProjectedTPN(projectedTPNRelation);
    freeProjectedTPNRelation(projectedTPNRelation);

    // (c) Join for GHVD|><|GPG - GHVDPG
    printf("\n----------(C) Testing Join Function for GHVD|><|GPG Relations------------\n");
    JoinGHVDPGRelation joinedGHVDPGRelation = join_GHVDPG(database->ghvdRelation, database->gpgRelation);
    // Print the joined GHVD|><|GPG Relation
    printJoinGHVDPGRelation(joinedGHVDPGRelation);


    // (d) All of the Above
    printf("\n----------(D) Testing All of the Above Functions for πPlayerId,Goals(σDate=“8 Jan 2023”(GHVD ▷◁ GPG))------------\n");
    AllofTheAboveRelation allofTheAboveRelation = relational_all_of_the_above("8 Jan 2023", joinedGHVDPGRelation);
    printAllofTheAboveRelation(allofTheAboveRelation);



    freeJoinGHVDPGRelation(joinedGHVDPGRelation);
    freeAllofTheAboveRelation(allofTheAboveRelation);
    destroyDatabase(database);

    printf("\n-------------------------------------------------------------\n");
}

int main() {
    clock_t start_time = clock();
    partA();
    partB();
    partC();
    clock_t end_time = clock();
    double time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds \n", time);
    return 0;

}
