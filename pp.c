#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define LENGTH 10000
#define SIZE 100

typedef struct Node {
    char abc;
    char *key;
    int value;
    int p;
    struct Node *pre;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *now;
    Node *tail;
    int data_count;
} List;


int main() {
    int i, j;
    int count = 0;
    char char_temp[SIZE][LENGTH] = {{0}};
    char tok[LENGTH][SIZE] = {{0}};
    for (i = 0; i < LENGTH; i++) {
        fgets(char_temp[i], SIZE, stdin);
        count++;
        if (char_temp[i][0] == '0') {
            break;
        }
    }
    for (i = 0; i < count - 1; i++) {
        printf("%s", char_temp[i]);
    }

    int count2 = 0;
    const char space[2] = " ";
    char *token;
    token = strtok(char_temp[0], space);

    while (token != NULL) {
        tok[0][count2] = *token;
        printf("%d %s\n", count2++, token);
        token = strtok(NULL, space);
    }

    return 0;
}