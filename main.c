#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 1000
#define LENGTH 100

int nth;

int main() {
    char text[LENGTH][SIZE] = {{0}};
    char dict[LENGTH][SIZE] = {{0}};
    char *tok[LENGTH][SIZE] = {{0}};
    int i, j;
    int index[SIZE] = {0};
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // 문자 입력
    for (i = 0; i < LENGTH; i++) {
        fgets(text[i], SIZE, stdin);
        if (text[i][0] == '0') {
            nth = i;
            break;
        }
    }
    printf("nth = %d\n", nth);

    int count[nth];

    for (i = 0; i < nth; i++) {
        for (j = 0; j < SIZE; j++) {
            if (text[i][j] == '\n') {
                break;
            }
            dict[i][j] = text[i][j];
//            printf("%c", dict[i][j]);
        }
//        printf("\n");
    }

    const char space[2] = " ";
    char *token;
    for (i = 0; i < nth; i++) {
        count[i] = 0;
        token = strtok(dict[i], space);

        while (token != NULL) {
            tok[i][count[i]] = token;
            printf("%d ", count[i]++);
            printf("%s\n", token);
            token = strtok(NULL, space);
        }
        for (j = 0; j < count[i]; i++) {
            printf("tok[%d][%d] = %s\n", i, j, tok[i][j]);
        }
    }

    return 0;
}