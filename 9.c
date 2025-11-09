#include <stdio.h>
#include <stdbool.h>

#define SIZE 7

int table[SIZE];
int empty_marker = -1;

int hash_of(int key) {
    return key % SIZE;
}

void init_table() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = empty_marker;
    }
}

void insert(int key) {
    int idx = hash_of(key);
    int start = idx;
    while (table[idx] != empty_marker) {
        idx = (idx + 1) % SIZE;
        if (idx == start) {
            printf("Table is full, cannot insert %d\n", key);
            return;
        }
    }
    table[idx] = key;
    printf("Inserted %d at slot %d\n", key, idx);
}

void print_table() {
    printf("\nSlot | Value\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == empty_marker) {
            printf("%4d | (empty)\n", i);
        } else {
            printf("%4d | %d\n", i, table[i]);
        }
    }
}

int main() {
    init_table();

    // change the keys here if you want
    int keys[] = {1,2,3,4,5,6};
    int nkeys = sizeof(keys) / sizeof(keys[0]);

    printf("Begin inserting keys...\n");
    for (int i = 0; i < nkeys; i++) {
        insert(keys[i]);
    }

    print_table();
    return 0;
}
