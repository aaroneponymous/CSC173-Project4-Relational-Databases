#include "HashTable.h"
#include "GHVDRelation.h"

#include <string.h>
#include <stdbool.h>


// Delete Function

bool delete_GHVD(char* gameId, char* homeTeam, char* visitorTeam, char* date, struct GHVDRelation *ghvdRelation) {

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
        // Delete all the tuples from all the hashtables
        deleteAllBuckets(ghvdRelation->gameIdHashTable);
        deleteAllBuckets(ghvdRelation->visitorTeamHashTable);
        deleteAllBuckets(ghvdRelation->homeTeamHashTable);
        freeAllTuples(ghvdRelation->dateHashTable);

        return true;
    }

    Bucket ghvdBuck = lookup_GHVD(gameId, homeTeam, visitorTeam, date, ghvdRelation);

    if (ghvdBuck) {

        // 2. gameid = *, hometeam = *, visitorteam = *, date = value
        if (gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->Date, date) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                }

                return true;
            }


        }

            // 3. gameid = *, hometeam = *, visitorteam = value, date = *
        else if (gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->VisitorTeam, visitorTeam) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                }

                return true;
            }


        }

            // 4. gameid = *, hometeam = *, visitorteam = value, date = value
        else if (gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->VisitorTeam, visitorTeam) == 0 && strcmp(deleteTuple->Date, date) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                }

                return true;
            }
        }

            // 5. gameid = *, hometeam = value, visitorteam = *, date = *
        else if (gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->HomeTeam, homeTeam) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                    if (ghvdBuck) {
                        deleteTuple = (GHVD) ghvdBuck->relationTuple;
                    }

                }

                return true;
            }

        }

            // 6. gameid = *, hometeam = value, visitorteam = *, date = value
        else if (gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->HomeTeam, homeTeam) == 0 && strcmp(deleteTuple->Date, date) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                    if (ghvdBuck) {
                        deleteTuple = (GHVD) ghvdBuck->relationTuple;
                    }

                }

                return true;
            }
        }

            // 7. gameid = *, hometeam = value, visitorteam = value, date = *
        else if (gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->HomeTeam, homeTeam) == 0 && strcmp(deleteTuple->VisitorTeam, visitorTeam) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                    if (ghvdBuck) {
                        deleteTuple = (GHVD) ghvdBuck->relationTuple;
                    }
                }

                return true;
            }

        }

            // 8. gameid = *, hometeam = value, visitorteam = value, date = value
        else if (gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->HomeTeam, homeTeam) == 0 && strcmp(deleteTuple->VisitorTeam, visitorTeam) == 0 && strcmp(deleteTuple->Date, date) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                    if (ghvdBuck) {
                        deleteTuple = (GHVD) ghvdBuck->relationTuple;
                    }

                }

                return true;
            }

        }

            // 8. gameid = *, hometeam = value, visitorteam = value, date = value
        else if (gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            GHVD deleteTuple = (GHVD) ghvdBuck->relationTuple;

            if (deleteTuple) {

                while (ghvdBuck) {

                    ghvdBuck = ghvdBuck->next;

                    if (strcmp(deleteTuple->HomeTeam, homeTeam) == 0 && strcmp(deleteTuple->VisitorTeam, visitorTeam) == 0 && strcmp(deleteTuple->Date, date) == 0) {
                        deleteBucket(ghvdRelation->gameIdHashTable, deleteTuple->GameId, deleteTuple);
                        deleteBucket(ghvdRelation->homeTeamHashTable, deleteTuple->HomeTeam, deleteTuple);
                        deleteBucket(ghvdRelation->visitorTeamHashTable, deleteTuple->VisitorTeam, deleteTuple);
                        deleteBucketandTuple(ghvdRelation->dateHashTable, deleteTuple->Date, deleteTuple);
                        ghvdRelation->entries--;
                    }

                    if (ghvdBuck) {
                        deleteTuple = (GHVD) ghvdBuck->relationTuple;
                    }

                }

                return true;
            }

        }

            // 9. gameid = value, hometeam = *, visitorteam = *, date = *
        else if (!gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                ghvdRelation->entries--;
                bucket = bucket->next;
            }
            return true;


        }

            // 10. gameid = value, hometeam = *, visitorteam = *, date = value
        else if (!gameIDAsterisk && homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {
            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

            // 11. gameid = value, hometeam = *, visitorteam = value, date = *
        else if (!gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;

        }

            // 12. gameid = value, hometeam = *, visitorteam = value, date = value
        else if (!gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;

        }

            // 12. gameid = value, hometeam = *, visitorteam = value, date = value
        else if (!gameIDAsterisk && homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

            // 13. gameid = value, hometeam = value, visitorteam = *, date = *
        else if (!gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->HomeTeam, homeTeam) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;

        }

            // 14. gameid = value, hometeam = value, visitorteam = *, date = value
        else if (!gameIDAsterisk && !homeTeamAsterisk && visitorTeamAsterisk && !dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

            // 15. gameid = value, hometeam = value, visitorteam = value, date = *
        else if (!gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->VisitorTeam, visitorTeam) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

            // 16. gameid = value, hometeam = value, visitorteam = value, date = value
        else if (!gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

            // 16. gameid = value, hometeam = value, visitorteam = value, date = value
        else if (!gameIDAsterisk && !homeTeamAsterisk && !visitorTeamAsterisk && !dateAsterisk) {

            Bucket bucket = lookUpBucket(ghvdRelation->gameIdHashTable, ghvdRelation->capacity, gameId);
            while (bucket != NULL) {
                GHVD ghvd = (GHVD) bucket->relationTuple;
                if (strcmp(ghvd->HomeTeam, homeTeam) == 0 && strcmp(ghvd->VisitorTeam, visitorTeam) == 0 && strcmp(ghvd->Date, date) == 0) {
                    deleteBucket(ghvdRelation->gameIdHashTable, ghvd->GameId, ghvd);
                    deleteBucket(ghvdRelation->homeTeamHashTable, ghvd->HomeTeam, ghvd);
                    deleteBucket(ghvdRelation->visitorTeamHashTable, ghvd->VisitorTeam, ghvd);
                    deleteBucketandTuple(ghvdRelation->dateHashTable, ghvd->Date, ghvd);
                    ghvdRelation->entries--;
                }
                bucket = bucket->next;
            }
            return true;
        }

    }



    return NULL;

}