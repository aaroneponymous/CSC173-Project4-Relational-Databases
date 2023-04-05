#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Database.h"
#include "HashTable.h"
#include "GHVDRelation.h"
#include "Query.h"
#define CharSize 25




// Loading the Database

Database createDatabase(int capacity, char *name) {
    Database newDatabase = malloc(sizeof(struct Database));
    strcpy(newDatabase->Name, name);
    newDatabase->capacity = capacity;
    newDatabase->pnbRelation = newPNBRelation(capacity);
    newDatabase->pnbRelation->entries = 0;
    newDatabase->tpnRelation = newTPNRelation(capacity);
    newDatabase->tpnRelation->entries = 0;
    newDatabase->tcRelation = newTCRelation(capacity);
    newDatabase->tcRelation->entries = 0;
    newDatabase->ghvdRelation = newGHVDRelation(capacity);
    newDatabase->ghvdRelation->entries = 0;
    newDatabase->gpgRelation = newGPGRelation(capacity);
    newDatabase->gpgRelation->entries = 0;
    return newDatabase;
}

void loadDatabase(Database database) {

    printf("\n\nSetting Up and Initializing Database: \" %s \" ... \n \n", database->Name);


    // PNB Relation
    // Populate Database PNB Relation and Print The Truth Value of the Insertion
    printf("PNB TUPLES:\n \n");
    insertPNB("75196", "A. Moore", "28 Aug 1985", database);
    insertPNB("59797", "G. Jones", "26 Dec 1986", database);
    insertPNB("87977", "U. Hughes", "13 Feb 1990", database);
    insertPNB("20945", "Q. Morgan", "14 Feb 1998", database);
    insertPNB("70513", "G. King", "13 Apr 1993", database);
    insertPNB("51213", "T. Sullivan", "24 Jun 1995", database);
    insertPNB("61367", "A. Moore", "18 Mar 2000", database);
    insertPNB("55870", "D. Hernandez", "25 Jul 1997", database);
    insertPNB("47087", "W. Stewart", "5 Jan 1994", database);
    insertPNB("39468", "G. Jones", "25 Feb 1990", database);


    // Duplicate Test

    insertPNB("75196", "A Candy", "20 Aug 2015", database);


    // TPN Relation

    // Populate Database TPN Relation
    printf("TPN TUPLES:\n \n");

    insertTPN("Americans", "87977", "11", database);
    insertTPN("Americans", "75196", "7", database);
    insertTPN("Americans", "61367", "99", database);
    insertTPN("Maple Leafs", "75196", "7", database);
    insertTPN("Maple Leafs", "20945", "24", database);
    insertTPN("Redwings", "70513", "10", database);
    insertTPN("Redwings", "20945", "10", database);
    insertTPN("Crunch", "51213", "1", database);
    insertTPN("Crunch", "51213", "9", database);
    insertTPN("Crunch", "55870", "13", database);



    // TC Relation

    // Populate Database TC Relation
    printf("TC TUPLES:\n \n");
    insertTC("Americans", "Rochester", database);
    insertTC("Maple Leafs", "Toronto", database);
    insertTC("Redwings", "Detroit", database);
    insertTC("Crunch", "Syracuse", database);


    // GHVD Relation
    // Populate Database GHVD Relation
    printf("GHVD TUPLES:\n \n");
    insertGHVD("1", "Americans", "Maple Leafs", "3 Jan 2023", database);
    insertGHVD("2", "Crunch", "Redwings", "3 Jan 2023", database);
    insertGHVD("3", "Americans", "Crunch", "6 Jan 2023", database);
    insertGHVD("4", "Redwings", "Maple Leafs", "6 Jan 2023", database);
    insertGHVD("5", "Redwings", "Americans", "8 Jan 2023", database);
    insertGHVD("6", "Maple Leafs", "Crunch", "8 Jan 2023", database);
    insertGHVD("7", "Maple Leafs", "Crunch", "9 Jan 2023", database);
    insertGHVD("8", "Americans", "Redwings", "10 Jan 2023", database);
    insertGHVD("9", "Crunch", "Americans", "12 Jan 2023", database);
    insertGHVD("10", "Redwings", "Maple Leafs", "12 Jan 2023", database);

    // GPG Relation
    // Populate Database GPG Relation
    printf("GPG TUPLES:\n \n");
    insertGPG( "2", "55870", "1", database);
    insertGPG( "2", "70513", "2", database);
    insertGPG( "3", "51213", "1", database);
    insertGPG("5", "20945", "4", database);
    insertGPG("6", "55870", "2", database);
    insertGPG( "7", "75196", "1", database);
    insertGPG( "8", "87977", "1", database);
    insertGPG("8", "75196", "2", database);
    insertGPG("9", "55870", "3", database);
    insertGPG("9", "61367", "2", database);

}

// Insert Functions
bool insertPNB(char *playerID, char *name, char *birthDate, Database database) {
    // Call insertPNBRelation function from pnbRelation.c
    // printf("Inserting PNB Tuple: \nPlayerID: %s \nName: %s \nBirthDate: %s \n", playerID, name, birthDate);
    return insert_PNB(playerID, name, birthDate, database->pnbRelation);

}
bool insertTPN(char *team, char *playerID, char *number, Database database) {
    // Call insertTPNRelation function from tpnRelation.c
    return insert_TPN(team, playerID, number, database->tpnRelation);
}
bool insertTC(char *team, char *city, Database database) {
    // Call insertTCRelation function from tcRelation.c
    return insert_TC(team, city, database->tcRelation);
}
bool insertGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date, Database database) {
    // Call insertGHVDRelation function from ghvdRelation.c
    return insert_GHVD(gameID, homeTeam, visitorTeam, date, database->ghvdRelation);
}
bool insertGPG(char *gameID, char *playerID, char *goals, Database database) {
    // Call insertGPGRelation function from gpgRelation.c
    return insert_GPG(gameID, playerID, goals, database->gpgRelation);
}

// Look Up Functions
void lookupPNB(char *playerID, char *name, char *birthDate, Database database) {
    // Call lookupPNBRelation function from pnbRelation.c
    Bucket lookupPNBBucket = lookup_PNB(playerID, name, birthDate, database->pnbRelation);

    // If both name and birthDate are not * then do something
    if (strcmp(name, "*") != 0 && strcmp(birthDate, "*") != 0) {

        if (lookupPNBBucket) {
            printf("\nResults Found:\n");
        }

        while (lookupPNBBucket->next) {
            // Check: If the name and birthDate match the name and birthDate in the bucket
            PNB pnbFirst = (PNB)lookupPNBBucket->relationTuple;

            printf("\nPlayerID: %s, \nName: %s, \nBirthDate: %s \n", pnbFirst->PlayerId, pnbFirst->Name, pnbFirst->BirthDate);

            PNB pnbSecond = (PNB)lookupPNBBucket->next->relationTuple;


            if (strcmp(pnbFirst->Name, pnbSecond->Name) == 0 && strcmp(pnbFirst->BirthDate, pnbSecond->BirthDate) == 0) {
                lookupPNBBucket = lookupPNBBucket->next;
            }
            else {
                break;
            }
        }
    }


    else if (lookupPNBBucket) {
        printf("\nResults Found:\n");
        while (lookupPNBBucket) {
            // Check: If the name matches the name in the bucket
            PNB pnb = (PNB)lookupPNBBucket->relationTuple;
            printf("\nPlayerID: %s, \nName: %s, \nBirthDate: %s \n", pnb->PlayerId, pnb->Name, pnb->BirthDate);
            lookupPNBBucket = lookupPNBBucket->next;
        }
    }

    else {
        printf("\nNo Records Found\n");
    }

}
void lookupTPN(char *team, char *playerID, char *number, Database database) {
    // Call lookupTPNRelation function from tpnRelation.c
    Bucket lookupTPNBucket = lookup_TPN(team, playerID, number, database->tpnRelation);


    if (lookupTPNBucket) {
        while (lookupTPNBucket) {
            // Check: If the playerID matches the playerID in the bucket
            TPN tpn = (TPN)lookupTPNBucket->relationTuple;
            printf("Team: %s\nPlayerID: %s\nNumber: %s \n", tpn->Team, tpn->PlayerId, tpn->Number);
            lookupTPNBucket = lookupTPNBucket->next;
        }
    }

    else {
        printf("\nNo Records Found\n");
    }
}
void lookupTC(char *team, char *city, Database database) {
    // Call lookupTCRelation function from tcRelation.c
    Bucket lookupTCBucket = lookup_TC(team, city, database->tcRelation);
    if(lookupTCBucket) {
        while (lookupTCBucket) {
            // Check: If the team matches the team in the bucket
            TC tc = (TC)lookupTCBucket->relationTuple;
            printf("Team: %s, City: %s \n", tc->Team, tc->City);
            lookupTCBucket = lookupTCBucket->next;
        }
    }

    else {
        printf("\nNo Records Found\n");
    }
}
void lookupGHVD(char *gameID, char *homeTeam, char *visitorTeam, char *date, Database database) {
    // Call lookupGHVDRelation function from ghvdRelation.c
    Bucket lookupGHVDBucket = lookup_GHVD(gameID, homeTeam, visitorTeam, date, database->ghvdRelation);
    if (lookupGHVDBucket) {
        while (lookupGHVDBucket) {
            // Check: If the gameID matches the gameID in the bucket
            GHVD ghvd = (GHVD)lookupGHVDBucket->relationTuple;
            printf("GameID: %s, HomeTeam: %s, VisitorTeam: %s, Date: %s \n", ghvd->GameId, ghvd->HomeTeam, ghvd->VisitorTeam, ghvd->Date);
            lookupGHVDBucket = lookupGHVDBucket->next;
        }
    }

    else {
        printf("\nNo Records Found\n");
    }

}
void lookupGPG(char *gameID, char *playerID, char *goals, Database database) {
    // Call lookupGPGRelation function from gpgRelation.c
    lookup_GPG(gameID, playerID, goals, database->gpgRelation);
}

// Delete Functions
void deletePNB(char *playerID, char *name, char *birthDate, Database database) {
    // Call delete_PNB from PNB relation file
    delete_PNB(playerID, name, birthDate, database->pnbRelation);
    printPNBRelation(database);
}
void deletePNBREPL(Database database) {

    printf("Enter Player ID, Name and BirthDate to Delete:\n");
    printf("To Stop the REPL, Enter \"y\" when prompted and anything else to continue\n");

    while(true) {

        char quitInput[CharSize];
        printf("\nEnter \"y\" to stop the REPL: ");
        fgets(quitInput, sizeof(quitInput), stdin);
        quitInput[strcspn(quitInput, "\n")] = '\0';

        if (strcmp(quitInput, "y") == 0) {
            printf("Exiting Query Name to Number REPL\n");
            break;
        }

        else {

            char playerID[CharSize];
            printf("Enter a Player ID:");
            fgets(playerID, sizeof(playerID), stdin);
            playerID[strcspn(playerID, "\n")] = '\0';


            char name[CharSize];
            printf("Enter a Name:");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            char birthDate[CharSize];
            printf("Enter a BirthDate:");
            fgets(birthDate, sizeof(birthDate), stdin);
            birthDate[strcspn(birthDate, "\n")] = '\0';

            if (delete_PNB(playerID, name, birthDate, database->pnbRelation)) {
                printf("Deleted Successfully\n");
                printHashTablePNB(database->pnbRelation->playerIDHashTable);
                printHashTablePNB(database->pnbRelation->nameHashTable);
                printHashTablePNB(database->pnbRelation->birthDateHashTable);
            }

            else {
                printf("Delete Failed\n");
            }

        }

    }

}

void deleteTPN(char *team, char *playerID, char *number, Database database) {
    // Call delete_TPN from TPN relation file
    delete_TPN(team, playerID, number, database->tpnRelation);
    printTPNRelation(database);
}
void deleteTPNREPL(Database database) {

    printf("Enter Team, Player ID and Number to Delete:\n");
    printf("To Stop the REPL, Enter \"y\" when prompted and anything else to continue\n");

    while(true) {

        char quitInput[CharSize];
        printf("\nEnter \"y\" to stop the REPL: ");
        fgets(quitInput, sizeof(quitInput), stdin);
        quitInput[strcspn(quitInput, "\n")] = '\0';

        if (strcmp(quitInput, "y") == 0) {
            printf("Exiting Query Name to Number REPL\n");
            break;
        }

        else {

            char team[CharSize];
            printf("Enter a Team:");
            fgets(team, sizeof(team), stdin);
            team[strcspn(team, "\n")] = '\0';

            char playerID[CharSize];
            printf("Enter a Player ID:");
            fgets(playerID, sizeof(playerID), stdin);
            playerID[strcspn(playerID, "\n")] = '\0';

            char number[CharSize];
            printf("Enter a Number:");
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = '\0';

            deleteTPN(team, playerID, number, database);

        }
    }
}



void printPNBRelation(Database database) {
    // Call printHashTablePNB function from HashTable
    printHashTablePNB(database->pnbRelation->playerIDHashTable);
}

void printTPNRelation(Database database) {
    // Call printHashTableTPN function from HashTable
    printHashTableTPN(database->tpnRelation->teamHashTable);
}

void printTCRelation(Database database) {
    // Call printTCRelation function from HashTable.c
    printHashTableTC(database->tcRelation->teamHashTable);
}





// PrintAll Functions
void printAll(Database database) {
    // HashTables
    HashTable pnbRelation = database->pnbRelation->playerIDHashTable;
    HashTable tpnRelation = database->tpnRelation->teamHashTable;
    HashTable tcRelation = database->tcRelation->teamHashTable;
    HashTable ghvdRelation = database->ghvdRelation->gameIdHashTable;
    HashTable gpgRelation = database->gpgRelation->gameIdHashTable;

    // Print All
    printf("\nPNB Relation:\n");
    printf("PNB Entries: %d \n", database->pnbRelation->entries);
    printHashTablePNB(pnbRelation);
    printf("\nTPN Relation:\n");
    printf("TPN Entries: %d \n", database->tpnRelation->entries);
    printHashTableTPN(tpnRelation);
    printf("\nTC Relation:\n");
    printf("TC Entries: %d \n", database->tcRelation->entries);
    printHashTableTC(tcRelation);
    printf("\nGHVD Relation:\n");
    printf("GHVD Entries: %d \n", database->ghvdRelation->entries);
    printHashTableGHVD(ghvdRelation);
    printf("\nGPG Relation:\n");
    printf("GPG Entries: %d \n", database->gpgRelation->entries);
    printHashTableGPG(gpgRelation);

}
void destroyDatabase(Database database) {
    freePNBRelation(database->pnbRelation);
    freeTPNRelation(database->tpnRelation);
    freeTCRelation(database->tcRelation);
    freeGHVDRelation(database->ghvdRelation);
    freeGPGRelation(database->gpgRelation);
    free(database);
}
void qNameNumberREPL(Database database) {

    printf("Enter a Name and Team to Query the PNB Relation for a Player's Jersey Number\n");
    printf("To Stop the REPL, Enter \"y\" when prompted and anything else to continue\n");

    while(true) {

        char quitInput[CharSize];
        printf("\nEnter \"y\" to stop the REPL: ");
        fgets(quitInput, sizeof(quitInput), stdin);
        quitInput[strcspn(quitInput, "\n")] = '\0';

        if (strcmp(quitInput, "y") == 0) {
            printf("Exiting Query Name to Number REPL\n");
            break;
        }

        else {

            char name[CharSize];
            printf("Enter a Name:");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            char team[CharSize];
            printf("Enter a Team:");
            fgets(team, sizeof(team), stdin);
            team[strcspn(team, "\n")] = '\0';

            qNameNumber(name, team, database);


        }

    }

}
void qNameGoalsREPL(Database database) {

    printf("Enter a Name and Date to Query the PNB Relation for a Player's Goals Scored\n");
    printf("To Stop the REPL, Enter \"y\" when prompted and anything else to continue\n");

        while(true) {

            char quitInput[CharSize];
            printf("\nEnter \"y\" to stop the REPL: ");
            fgets(quitInput, sizeof(quitInput), stdin);
            quitInput[strcspn(quitInput, "\n")] = '\0';

            if (strcmp(quitInput, "y") == 0) {
                printf("Exiting Query Name to Goals REPL\n");
                break;
            } else {

                char name[CharSize];
                printf("Enter a Name:");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                char date[CharSize];
                printf("Enter a Date:");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0';

                qNameGoals(name, date, database);
            }
        }
}

