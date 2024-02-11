#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number; // 숫자
    int count;  // 등장 횟수
    int firstIndex; // 처음 등장한 인덱스
} NumCount;

int compare(const void *a, const void *b) {
    NumCount *numA = (NumCount *)a;
    NumCount *numB = (NumCount *)b;
    // 빈도에 따라 내림차순 정렬
    if (numA->count != numB->count) {
        return numB->count - numA->count;
    }
    // 빈도가 같으면 먼저 등장한 순서대로 정렬
    return numA->firstIndex - numB->firstIndex;
}

int main() {
    int N, C, i, j, found;
    scanf("%d %d", &N, &C);
    NumCount counts[1000] = {0};
    int input;
    int uniqueNumbers = 0;

    for (i = 0; i < N; i++) {
        scanf("%d", &input);
        found = 0;
        for (j = 0; j < uniqueNumbers; j++) {
            if (counts[j].number == input) {
                counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            counts[uniqueNumbers].number = input;
            counts[uniqueNumbers].count = 1;
            counts[uniqueNumbers].firstIndex = i;
            uniqueNumbers++;
        }
    }

    qsort(counts, uniqueNumbers, sizeof(NumCount), compare);

    for (i = 0; i < uniqueNumbers; i++) {
        for (j = 0; j < counts[i].count; j++) {
            printf("%d ", counts[i].number);
        }
    }

    return 0;
}
