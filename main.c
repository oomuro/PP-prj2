#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 1000
#define LENGTH 100

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
            printf("%d %s\n", count[i]++, token);
            token = strtok(NULL, space);
        }
    }
    // tok 테스트
//    for (i = 0; i < nth; i++) {
//        for (j = 0; j < count[i]; j++) {
//            printf("tok[%d][%d] = %s\n", i, j, tok[i][j]);
//        }
//    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // 첫번째 문자 저장 변수 선언(0번째 무시)
    char *command[nth];
    // 명령(del, sub, sch) 판단
    for (i = 0; i < nth; i++) {
        command[i] = tok[i][0];
        // command 테스트
        printf("command[%d] = %s\n", i, command[i]);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////


    return 0;
}