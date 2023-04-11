
#include <time.h>
#include "Database.h"
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


    printf("\n----------Testing Insertion-------------\n");
    // (g) insert(⟨“Ice Pilots”, “Pensacola”⟩, Team-City)
    insertTC("Ice Pilots", "Pensacola", database);
    printf("TC Relation after Insertion:\n");
    printTCRelation(database);
    // (h) insert(⟨“Crunch”, “Syracuse”⟩, Team-City)
    insertTC("Crunch", "Syracuse", database);
    printf("TC Relation after Insertion:\n");
    printTCRelation(database);
    deleteTPN("Americans", "*", "*", database);


    // Test Delete GHWD

    printf("\n----------Testing Delete Function for GHVD Relation-------------\n");
    printf("\nDeleting GHVD Tuple with GameID: 4, HomeTeam: Redwings, AwayTeam: Maple Leafs, Date: 6 Jan 2023");
    deleteGHVD("4", "Redwings", "Maple Leafs", "6 Jan 2023", database);
    printf("\nDeleting GHVD Tuple with GameID: *, HomeTeam: Redwings, AwayTeam: Crunch, Date: *");
    deleteGHVD("*", "Redwings", "Crunch", "*", database);
    printf("\nDeleting GHVD Tuple with GameID: *, HomeTeam: Americans, AwayTeam: *, Date: *");
    deleteGHVD("*", "Americans", "*", "*", database);
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
    printf("\nSelected TPN Relation after select function:\n");
    printHashTableTPN(selectedTPNRelation->playerIDHashTable);

    // (b) Projection for TPN
    printf("\n----------(B) Testing Projection Function for TPN Relation: Parameter Player ID: 51213------------\n");
    ProjectionTPNRelation projectedTPNRelation = project_TPN("51213", database->tpnRelation);
    // Print the projected TPN Relation
    printf("\n-----------------Projected TPN Relation after projection function:--------------------------------\n");
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
