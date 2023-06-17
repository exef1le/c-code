#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a security
typedef struct {
    char code[4];
    int id;
    int reliability;
} Security;

// Structure to represent the database
typedef struct {
    Security *securities;
    int count;
    int capacity;
} Database;

// Initialize the database
void initializeDatabase(Database *db) {
    db->securities = NULL;
    db->count = 0;
    db->capacity = 0;
}

// Check if a security exists in the database
int isSecurityExists(Database *db, char *code) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->securities[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

// Add a security to the database
void addSecurity(Database *db, char *code) {
    if (isSecurityExists(db, code) != -1) {
        printf("EXISTS %d %d\n", db->securities[isSecurityExists(db, code)].id, db->securities[isSecurityExists(db, code)].reliability);
    } else {
        if (db->count == db->capacity) {
            db->capacity = (db->capacity == 0) ? 1 : db->capacity * 2;
            db->securities = realloc(db->securities, db->capacity * sizeof(Security));
        }
        strcpy(db->securities[db->count].code, code);
        db->securities[db->count].id = db->count;
        db->securities[db->count].reliability = 0;
        printf("CREATED %d 0\n", db->count);
        db->count++;
    }
}

// Delete a security from the database
void deleteSecurity(Database *db, char *code) {
    int index = isSecurityExists(db, code);
    if (index != -1) {
        printf("OK %d %d\n", db->securities[index].id, db->securities[index].reliability);
        for (int i = index; i < db->count - 1; i++) {
            db->securities[i] = db->securities[i + 1];
        }
        db->count--;
    } else {
        printf("BAD REQUEST\n");
    }
}

// Increase the reliability of a security
void increaseReliability(Database *db, char *code, int reliability) {
    int index = isSecurityExists(db, code);
    if (index != -1) {
        db->securities[index].reliability += reliability;
        printf("OK %d %d\n", db->securities[index].id, db->securities[index].reliability);
    } else {
        printf("BAD REQUEST\n");
    }
}

// Find a security by its position
void findSecurity(Database *db, int n) {
    if (db->count == 0) {
        printf("EMPTY\n");
        return;
    }

    if (n >= db->count) {
        n = db->count - 1;
    }

    // Sort securities in descending order of reliability
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (db->securities[j].reliability < db->securities[j + 1].reliability) {
                Security temp = db->securities[j];
                db->securities[j] = db->securities[j + 1];
                db->securities[j + 1] = temp;
            }
        }
    }

    // Sort groups of securities with the same reliability by the time of addition
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = i + 1; j < db->count; j++) {
            if (db->securities[i].reliability == db->securities[j].reliability && db->securities[i].id > db->securities[j].id) {
                Security temp = db->securities[i];
                db->securities[i] = db->securities[j];
                db->securities[j] = temp;
            }
        }
    }

    printf("OK %s %d %d\n", db->securities[n].code, db->securities[n].id, db->securities[n].reliability);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Read the newline character after the number of queries

    Database db;
    initializeDatabase(&db);

    for (int i = 0; i < N; i++) {
        char query[20];
        fgets(query, sizeof(query), stdin);
        query[strlen(query) - 1] = '\0';  // Remove the newline character at the end of the query string

        char command[10];
        char code[4];
        int reliability;
        int n;

        sscanf(query, "%s", command);

        if (strcmp(command, "ISSUE") == 0) {
            sscanf(query, "%s %s", command, code);
            addSecurity(&db, code);
        } else if (strcmp(command, "DELETE") == 0) {
            sscanf(query, "%s %s", command, code);
            deleteSecurity(&db, code);
        } else if (strcmp(command, "RELIABILITY") == 0) {
            sscanf(query, "%s %s %d", command, code, &reliability);
            increaseReliability(&db, code, reliability);
        } else if (strcmp(command, "FIND") == 0) {
            sscanf(query, "%s %d", command, &n);
            findSecurity(&db, n);
        }
    }

    free(db.securities);  // Free the memory allocated for the database

    return 0;
}
                                //Check the code on an online compiler !!!