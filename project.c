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
        strcpy_s(database[numKeys].key, key);
        strcpy_s(database[numKeys].value, value);
        numKeys++;
        printf("Key-Value pair created successfully.\n");
    }
    else {
        printf("Database is full. Cannot create more pairs.\n");
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
            strcpy_s(database[i].value, value);
            printf("Key-Value pair updated successfully.\n");
            return;
        }
    }
    printf("Key not found. Cannot update.\n");
}
void delet(const char* key) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(database[i].key, key) == 0) {
            for (int j = i; j < numKeys - 1; j++) {
                strcpy_s(database[j].key, database[j + 1].key);
                strcpy_s(database[j].value, database[j + 1].value);
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
        scanf_s("%255s", &command, sizeof(command));

        if (strcmp(command, "create") == 0) {
            printf("Enter key: ");
            scanf_s("%255s", &key, sizeof(key));
            printf("Enter value: ");
            scanf_s("%255s", &value, sizeof(value));
            create(key, value);
        }
        else if (strcmp(command, "read") == 0) {
            printf("Enter key: ");
            scanf_s("%255s", &key, sizeof(key));
            read(key);
        }
        else if (strcmp(command, "update") == 0) {
            printf("Enter key: ");
            scanf_s("%255s", &key, sizeof(key));
            printf("Enter new value: ");
            scanf_s("%255s", &value, sizeof(value));
            update(key, value);
        }
        else if (strcmp(command, "delete") == 0) {
            printf("Enter key: ");
            scanf_s("%255s", &key, sizeof(key));
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
