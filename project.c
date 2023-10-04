#include<stdio.h>
#include<string.h>
#define MAX_KEYS 1000
struct KeyValue {
    char key[256];
    char value[256];
};

struct KeyValue database[MAX_KEYS];
int numKeys = 0;
void create(const char* key, const char* value) {
    if (numKeys < MAX_KEYS) {
        strcpy(database[numKeys].key, key);
        strcpy(database[numKeys].value, value);
        numKeys++;
        printf("created successfully.\n");
    }
    else {
        printf("Cannot create more pairs.\n");
    }
}
void read(const char* key) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Key: %s, Value: %s\n", database[i].key, database[i].value);
            return;
        }
    }
    printf("Key not found.\n");
}
void update(const char* key, const char* value) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(database[i].key, key) == 0) {
            strcpy(database[i].value, value);
            printf("updated successfully.\n");
            return;
        }
    }
    printf("Key not found.\n");
}
void delet(const char* key) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(database[i].key, key) == 0) {
            for (int j = i; j < numKeys - 1; j++) {
                strcpy(database[j].key, database[j + 1].key);
                strcpy(database[j].value, database[j + 1].value);
            }
            numKeys--;
            printf("Key-Value pair deleted successfully.\n");
            return;
        }
    }
    printf("Key not found. Cannot delete.\n");
}
int main() {
    char command[10];
    char key[256];
    char value[256];

    while (1) {
        printf("Enter command (create/read/update/delete/quit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);
            create(key, value);
        }
        else if (strcmp(command, "read") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            read(key);
        }
        else if (strcmp(command, "update") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter new value: ");
            scanf("%s", value);
            update(key, value);
        }
        else if (strcmp(command, "delete") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            delet(key);
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        }
        else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}
