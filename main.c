#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 8300
#define LENGTH 100

typedef struct Node {
    char abc;
    char *key;
    int value;
    int disable;
    struct Node *pre;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *now;
    Node *tail;
    int data_count;
} List;

// 줄 개수 변수 선언
int nth;

int main() {
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // 문자열 변수 선언
    char text[LENGTH][SIZE] = {{0}};
    char dict[LENGTH][SIZE] = {{0}};
    char *tok[LENGTH][SIZE] = {{0}};
    int index[SIZE] = {0};
    int i, j;
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // 문자 입력
    for (i = 0; i < LENGTH; i++) {
        fgets(text[i], SIZE, stdin);
        if (text[i][0] == '0') {
            nth = i;
            break;
        }
    }
    // 첫문장 크기 변수 선언 및 확인
//    int length = strlen(text[0]);
//    printf("length = %d\n", length);
    // nth 확인
//    printf("nth = %d\n", nth);
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // count 선언
    int count[nth];
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // text -> dict 복사
    for (i = 0; i < nth; i++) {
        for (j = 0; j < SIZE; j++) {
            if (text[i][j] == '\n') {
                break;
            }
            dict[i][j] = text[i][j];
            // 복사 성공 테스트
//            printf("%c", dict[i][j]);
        }
//        printf("\n");
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // strtok 이용해 단어 단위로 분리
    const char space[2] = " ";
    char *token;
    for (i = 0; i < nth; i++) {
        count[i] = 0;
        token = strtok(dict[i], space);

        while (token != NULL) {
            tok[i][count[i]] = token;
//            printf("%d %s ", count[i], token);
            count[i]++;
            token = strtok(NULL, space);
        }
//        printf("\n");
    }
    // tok 테스트
//    for (i = 0; i < nth; i++) {
//        for (j = 0; j < count[i]; j++) {
//            printf("tok[%d][%d] = %s\n", i, j, tok[i][j]);
//        }
//    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // 첫번째 문자 저장 변수 선언(0번째 무시)
    char *command[nth - 1];
    // 명령(del, sub, sch) 판단
    for (i = 0; i < nth - 1; i++) {
        command[i] = tok[i + 1][0];
        // command 테스트
//        printf("command[%d] = %s\n", i, command[i]);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // Node 구현
    Node node[LENGTH];
    int eq, real = 0, end;
    for (i = 0; i < count[0]; i++) {
        eq = 1;
        for (j = 0; j < i; j++) {
            if (strcmp(tok[0][i], tok[0][j]) == 0) {
                eq = 0;
            }

        }
        if (eq == 0) {
            real--;
        } else {
            node[real].abc = tok[0][i][0];
            node[real].value = real;
            node[real].key = tok[0][i];
            if (real == 0) {
                node[real].pre = NULL;
            } else {
                node[real].pre = &node[real - 1];
            }
            if (i == count[0] - 1) {
                node[real].next = NULL;
            } else {
                node[real].next = &node[real + 1];
            }
//            printf("%d %s\n", real, node[real].key);
        }
        if (i == count[0] - 1) {
            end = real;
        } else {
            real++;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    int c;
    for (i = 0; i < nth - 1; i++) {
        if (strcmp(command[i], "sch") == 0) {
            c = 0;
            for (j = 0; j <= end; j++) {
                if ((tok[i + 1][1][0] == node[j].abc) && (node[j].disable != 1)) {
                    if(c==0) {
                        printf("%d", node[j].value);
                        c++;
                    } else {
                        printf(" %d", node[j].value);
                    }
                    if (strcmp(tok[i + 1][1], node[j].key) == 0 || j == end) {
                        break;
                    }
                }
            }
            printf("\n");
        } else if (strcmp(command[i], "sub") == 0) {
            int eq2 = 0;
            for (j = 0; j <= end; j++) {
                if ((strcmp(node[j].key, tok[i + 1][2]) == 0) && (node[j].disable != 1)) {
                    eq2 = 1;
                }
            }
            if (eq2 == 1) {
                for (j = 0; j <= end; j++) {
                    if ((strcmp(node[j].key, tok[i + 1][1]) == 0) && (node[j].disable != 1)) {
                        node[j].disable = 1;
                    }
                }
            }
//            if (eq2 != 1) {
            for (j = 0; j <= end; j++) {
                if ((strcmp(node[j].key, tok[i + 1][1]) == 0) && (node[j].disable != 1)) {
//                    if (j == 0) {
//                        node[j].disable = 1;
////                        node[j + 1].pre = NULL;
////                        node[end].next = &node[end + 1];
//                        node[end + 1].key = tok[i + 1][2];
////                        node[end + 1].pre = &node[end];
////                        node[end + 1].next = NULL;
//                        node[end + 1].abc = tok[i + 1][2][0];
//                        node[end + 1].value = node[j].value;
//                        end++;
//                    } else if (j == end) {
//                        node[j].disable = 1;
////                        node[j - 1].next = &node[end + 1];
//                        node[end + 1].key = tok[i + 1][2];
////                        node[end + 1].pre = &node[i - 1];
////                        node[end + 1].next = NULL;
//                        node[end + 1].abc = tok[i + 1][2][0];
//                        node[end + 1].value = node[j].value;
//                        end++;
//                    } else {
//                        node[j].disable = 1;
////                        node[i - 1].next = &node[i + 1];
////                        node[i + 1].pre = &node[i - 1];
//                        node[end + 1].key = tok[i + 1][2];
////                        node[end + 1].pre = &node[end];
////                        node[end + 1].next = NULL;
//                        node[end + 1].abc = tok[i + 1][2][0];
//                        node[end + 1].value = node[j].value;
//                        end++;
//                    }
                    node[j].disable = 1;
                    node[end + 1].key = tok[i + 1][2];
                    node[end + 1].abc = tok[i + 1][2][0];
                    node[end + 1].value = node[j].value;
                    end++;
                    break;
                }
            }
//            }
        } else if (strcmp(command[i], "del") == 0) {
            for (j = 0; j <= end; j++) {
                if ((strcmp(node[j].key, tok[i + 1][1]) == 0) && (node[j].disable != 1)) {
                    node[j].disable = 1;
//                    node[i - 1].next = &node[i + 1];
//                    node[i + 1].pre = &node[i - 1];
                }
            }
        }
//        for (j = 0; j <= end; j++) {
//            if (node[j].disable != 1) {
//                printf("%d %s\n", node[j].value, node[j].key);
//            }
//        }
    }
//    printf("end = %d\n", end);
//    printf("nth = %d\n", nth);

//    for (i = 0; i <= end; i++) {
//        if (node[i].disable != 1) {
//            printf("%d %s\n", node[i].value, node[i].key);
//        }
//    }

    return 0;
}
