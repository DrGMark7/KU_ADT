#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 150000
#define MAX_NAME_LEN 20

typedef struct hash {
    char name[MAX_NAME_LEN + 1];
} HashEntry;

typedef struct {
    HashEntry *table;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->table = (HashEntry *)calloc(size, sizeof(HashEntry));
    return hashTable;
}

unsigned int hashFunction(const char *str, int size) {
    unsigned int hashValue = 0;
    for (int i = 0; i < strlen(str); i++) {
        hashValue = hashValue * 31 + str[i];
    }
    return hashValue % size;
}

int findLocation(HashTable *hashTable, const char *name, int size) {
    unsigned int hashValue = hashFunction(name, size);
    for (int i = 0; i < size; i++) {
        unsigned int index = (hashValue + i * i) % size;
        if (strlen(hashTable->table[index].name) == 0) {
            return -1;
        }
        if (strcmp(hashTable->table[index].name, name) == 0) {
            return index;
        }
    }
    return -1;
}

void addLocation(HashTable *hashTable, const char *name, int size) {
    unsigned int hashValue = hashFunction(name, size);
    for (int i = 0; i < size; i++) {
        unsigned int index = (hashValue + i * i) % size;
        if (strlen(hashTable->table[index].name) == 0) {
            strcpy(hashTable->table[index].name, name);
            return;
        }
    }
}

void handleRegistration(HashTable *hashTable, const char *name, int size) {
    char newName[MAX_NAME_LEN + 1];
    int index = findLocation(hashTable, name, size);
    
    if (index == -1) {
        printf("OK\n");
        addLocation(hashTable, name, size);
    } else {
        int suffix = 1;
        char baseName[MAX_NAME_LEN + 1];
        int nameLength = strlen(name);
        int i = nameLength - 1;

        // Extract the base name without digits at the end
        while (i >= 0 && name[i] >= '0' && name[i] <= '9') {
            i--;
        }
        strncpy(baseName, name, i + 1);
        baseName[i + 1] = '\0';
        
        // Generate new name with increasing suffix
        while (1) {
            snprintf(newName, sizeof(newName), "%s%d", baseName, suffix);
            if (findLocation(hashTable, newName, size) == -1) {
                printf("Change to %s\n", newName);
                addLocation(hashTable, newName, size);
                break;
            }
            suffix++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    HashTable *hashTable = createHashTable(HASH_SIZE);
    
    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LEN + 1];
        scanf("%s", name);
        handleRegistration(hashTable, name, HASH_SIZE);
    }
    
    free(hashTable->table);
    free(hashTable);
    return 0;
}
