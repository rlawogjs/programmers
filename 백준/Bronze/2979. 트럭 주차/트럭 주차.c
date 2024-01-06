#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int time[101] = {0}; // 시간대별 주차된 트럭의 수를 저장하는 배열
    for (int i = 0; i < 3; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        for (int j = start; j < end; j++) {
            time[j]++;
        }
    }

    int totalCost = 0;
    for (int i = 1; i <= 100; i++) {
        if (time[i] == 1) {
            totalCost += A;
        } else if (time[i] == 2) {
            totalCost += 2 * B;
        } else if (time[i] == 3) {
            totalCost += 3 * C;
        }
    }

    printf("%d\n", totalCost);
    return 0;
}
