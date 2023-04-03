#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#include "DataBase.h"
#include "HashTable.h"
#include "Query.h"

void qNameNumber(char* name, char* team, Database database) {
    printf("----------Querying PNB Relation for Name: %s and Team: %s---------\n", name, team);

    Bucket pnbBucket = lookup_PNB("*", name, "*", database->pnbRelation);

    //if there exists a bucket containing that name
    if(pnbBucket) {
        // use database lookup function just to print the players found with that given name
        // printf("\n\nTuples Found with Player Name: %s\n\n", name);
        // lookupPNB("*", name, "*", database);

        //use each name found and the team to lookup the jersey number in the tpn relation
        while(pnbBucket) {
            //look into tpn for each bucket in the list of buckets at that index
            PNB pnb = (PNB)pnbBucket->relationTuple;
            char* playerID = pnb->PlayerId;
            // printf("\n\nTPN Tuple(s) Found with PlayerID: %s and Team: %s\n\n", playerID, team);
            Bucket tpnBucket = lookup_TPN(team, playerID, "*", database->tpnRelation);

            //if there exists a bucket containing that name and team
            if(tpnBucket) {
                //use database lookup function just to print the players found with that given name and team
                // lookupTPN(team, playerID, "*", database);

                while(tpnBucket) {
                    TPN tpn = (TPN) tpnBucket->relationTuple;
                    char *number = tpn->Number;
                    //if name AND team AND number are found, print the player's jersey number
                    if(strcmp(pnb->Name, name) == 0 && strcmp(tpn->Team, team) == 0) {
                        printf("\nPlayer \"%s\" found with Jersey Number: %s\n", name, number);
                    }
                    tpnBucket = tpnBucket->next;
                }
            } else {
                printf("No Records Found\n");
            }
            pnbBucket = pnbBucket->next;
        }
    } else {
        printf("No Records Found\n");
    }
}

void qNameGoals(char *name, char* date, Database database) {
    printf("----------Querying PNB Relation for Name: %s and Date: %s---------\n", name, date);

    bool playerFound = false;

    // 1. First Look Up Name in PNB Relation
    Bucket pnbBucket = lookup_PNB("*", name, "*", database->pnbRelation);


    // 2. Return the Bucket Containing the Tuple with the Name
    // 3. While (Bucket) "Meaning the Tuples with the same Name in the Buckets List Exist"
    while (pnbBucket) {
        // 4. Look Up the PlayerID in the Bucket for each Tuple in the Bucket List in the PNB Relation and save it in a Local Variable
        PNB pnb = (PNB)pnbBucket->relationTuple;
        char* playerID = pnb->PlayerId;

        // 5. Within the While loop, Look Up the Bucket with the PlayerID in the TNP Relation
        Bucket tpnBucket = lookup_TPN("*", playerID, "*", database->tpnRelation);

        // 6. While (Bucket) "Meaning the Tuples with the same PlayerID in the Buckets List Exist"
        while (tpnBucket) {
            // 7. Look Up the Team Name in the Bucket for each Tuple in the Bucket List in the TNP Relation and save it in a Local Variable
            TPN tpn = (TPN)tpnBucket->relationTuple;
            char* teamName = tpn->Team;

            // 8. Within the While loop, Look Up the Bucket with the Team Name in the GHVD Relation
            Bucket ghvdBucket = lookup_GHVD("*", "*", "*", date, database->ghvdRelation);

            // 9. While (Bucket) "Meaning the Tuples with the same Team Name in the Buckets List Exist"
            while (ghvdBucket) {
                // 10. Look Up the Goals in GPG when GHVD bucket->relationTuple->Date == date && GHVD bucket->relationTuple->Name == name
                GHVD ghvd = (GHVD)ghvdBucket->relationTuple;
                char* homeTeam = ghvd->HomeTeam;
                char* visitorTeam = ghvd->VisitorTeam;
                char* dateFound = ghvd->Date;

                // 11. If a matching Tuple Found print the goals from the GPG Relation
                if (strcmp(dateFound, date) == 0 && ((strcmp(homeTeam, teamName) == 0) ^ (strcmp(visitorTeam, teamName) == 0))) {

                    char* gameID = ghvd->GameId;

                    // 12. Look Up the Goals in GPG when GHVD bucket->relationTuple->Date == date && GHVD bucket->relationTuple->Name == name
                    Bucket gpgBucket = lookup_GPG(gameID, playerID, "*", database->gpgRelation);

                    // 13. While (Bucket) "Meaning the Tuples with the same Team Name in the Buckets List Exist"
                    while (gpgBucket) {
                        GPG gpg = (GPG)gpgBucket->relationTuple;
                        char* goals = gpg->Goals;
                        if (strcmp(gameID, gpg->GameId) == 0 && strcmp(playerID, gpg->PlayerId) == 0) {
                            printf("\nPlayer \"%s\" (ID: %s) with Team: \"%s\" scored Goals: %s\n", name, playerID,
                                   teamName, goals);
                            playerFound = true;
                        }
                        gpgBucket = gpgBucket->next;
                    }

                }

                ghvdBucket = ghvdBucket->next;
            }
            tpnBucket = tpnBucket->next;
        }
        pnbBucket = pnbBucket->next;
    }

    if (!playerFound) {
        printf("No Records Found\n");
    }
}