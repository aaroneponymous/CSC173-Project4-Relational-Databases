#include "HashTable.h"
#include "GHVDRelation.h"

#include <string.h>
#include <stdbool.h>



// Look Up Function

Bucket lookup_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation) {

    // gameID Asterisk
    bool gameIDAsterisk = strcmp(gameId, "*") == 0;
    // homeTeam Asterisk
    bool homeTeamAsterisk = strcmp(homeTeam, "*") == 0;
    // visitorTeam Asterisk
    bool visitorTeamAsterisk = strcmp(visitorTeam, "*") == 0;
    // date Asterisk
    bool dateAsterisk = strcmp(date, "*") == 0;

    // Parameters: gameid, hometeam, visitorteam, date passed to the lookup_GHVD function
    // Can be of varous combinations of asterisks and values
    // They can either take "*" or a value

    // List of all possible combinations of parameters
    // 2^n = 16

    // 1. gameid = *, hometeam = *, visitorteam = *, date = *
    if (gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {
        return getAllBuckets(ghvdRelation->gameIdHashTable);
    }

        // 2. gameid = *, hometeam = *, visitorteam = *, date = value
    else if (gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {
        return lookUpBucket(ghvdRelation->dateHashTable, ghvdRelation->capacity, date);
    }

        // 3. gameid = *, hometeam = *, visitorteam = value, date = *
    else if (gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {
        return lookUpBucket(ghvdRelation->visitorTeamHashTable, ghvdRelation->capacity, visitorTeam);
    }

        // 4. gameid = *, hometeam = *, visitorteam = value, date = value
    else if (gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->visitorTeamHashTable, ghvdRelation->capacity, visitorTeam);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 5. gameid = *, hometeam = value, visitorteam = *, date = *
    else if (gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {
        return lookUpBucket(ghvdRelation->homeTeamHashTable, ghvdRelation->capacity, homeTeam);
    }

        // 6. gameid = *, hometeam = value, visitorteam = *, date = value
    else if (gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->homeTeamHashTable, ghvdRelation->capacity, homeTeam);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 7. gameid = *, hometeam = value, visitorteam = value, date = *
    else if (gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->visitorTeamHashTable, ghvdRelation->capacity, visitorTeam);
        Bucket returnBucket = malloc(sizeof(struct Bucket));
        Bucket properBucketHead = returnBucket;
        Bucket temp;
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->HomeTeam, homeTeam) == 0) {
                temp = malloc(sizeof(struct Bucket));
                temp->relationTuple = bucket->relationTuple;
                temp->next = NULL;
                returnBucket->next = temp;
                returnBucket = returnBucket->next;
            }
            bucket = bucket->next;
        }
        return properBucketHead->next;
    }

        // 8. gameid = *, hometeam = value, visitorteam = value, date = value
    else if (gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->homeTeamHashTable, ghvdRelation->capacity, homeTeam);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 9. gameid = value, hometeam = *, visitorteam = *, date = *
    else if (!gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {
        return lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
    }

        // 10. gameid = value, hometeam = *, visitorteam = *, date = value
    else if (!gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 11. gameid = value, hometeam = *, visitorteam = value, date = *
    else if (!gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 12. gameid = value, hometeam = *, visitorteam = value, date = value
    else if (!gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 13. gameid = value, hometeam = value, visitorteam = *, date = *
    else if (!gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->HomeTeam, homeTeam) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 14. gameid = value, hometeam = value, visitorteam = *, date = value
    else if (!gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 15. gameid = value, hometeam = value, visitorteam = value, date = *
    else if (!gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->VisitorTeam, visitorTeam) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

        // 16. gameid = value, hometeam = value, visitorteam = value, date = value
    else if (!gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {
        Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
        while (bucket != NULL) {
            GHVD ghvd = (GHVD) bucket->relationTuple;
            if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                return bucket;
            }
            bucket = bucket->next;
        }
        return NULL;
    }

    return NULL;

}