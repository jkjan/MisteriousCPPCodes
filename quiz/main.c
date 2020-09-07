#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#define MAX_SIZE 20

typedef struct query {
    uint index1, index2;
}indices;

char** words;
int read();
indices question(int k);
void answer(char* ans);
void mark(indices underBar, const char* ans, int i, int* score, int* count);

int main() {
    int score, count, wordNum;
    score = count = 0;

    if ((wordNum = read(words)) == 0) {
        printf("프로그램을 종료합니다.\n");
    }

    srand(time(NULL));

    printf("지금부터 영어단어 시험을 실시하겠습니다.\n\n");

    for (int i = 0; i < wordNum; i++) {
        char ans[2];
        indices underBar = question(i);
        answer(ans);
        mark(underBar, ans, i, &score, &count);
        printf("\n");
    }

    printf("문제5개중 %d개를 맞추셨습니다. 100점만점에 %d점입니다.", count, score);

    free(words);
    return 0;
}

int read() {
    FILE* fp = fopen("word.txt", "rt");

    if (fp == NULL) {
        printf("파일오픈 실패\n");
        return 0;
    }

    int i = 0;
    char buffer[MAX_SIZE];
    int wordNum = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        wordNum++;
    }

    fseek(fp, 0, SEEK_SET);
    rewind(fp);

    words = (char**)malloc(sizeof(char*) * wordNum);
    for (int j = 0; j < wordNum; j++) {
        words[j] = (char*)malloc(sizeof(char) * MAX_SIZE);
    }

    while (fgets(buffer, MAX_SIZE, fp) != NULL) {
        uint lastIndex = strlen(buffer) - 1;
        while (buffer[lastIndex] == 10 || buffer[lastIndex] == 13) {
            lastIndex--;
        }
        buffer[lastIndex+1] = (char) NULL;
        strcpy(words[i++], buffer);
    }

    fclose(fp);

    return wordNum;
}

indices question(int k) {
    char str[MAX_SIZE];
    unsigned int len = strlen(words[k]);
    unsigned int index1, index2;
    strcpy(str, words[k]);

    index1 = rand() % (len - 1);
    index2 = (rand() % (len - index1 - 1)) + index1 + 1;

    indices underBar = {index1, index2};
    str[index1] = '_';
    str[index2] = '_';
    printf("%d번 : %s \n", k+1, str);

    return underBar;
}

void answer(char* ans) {
    printf("정답 (띄어쓰기로 구분) : ");
    scanf(" %c %c", ans, ans+1);
}

void mark(indices underBar, const char* ans, int i, int* score, int* count) {
    if ((words[i][underBar.index1] == ans[0])
    && (words[i][underBar.index2] == ans[1]) ) {
        printf("정답입니다. 축하합니다. \n");
        *score += 20;
        (*count)++;
    }
    else
        printf("틀렸습니다. 정답은 %s입니다.\n", words[i]);
}