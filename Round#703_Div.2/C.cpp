#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif
#include <iostream>

void findMax(int start, int end) {
    if(end - start == 1) {
        printf("? %d %d\n", start, end);
        fflush(stdout);
        int response;
        cin >> response;
        if(response == start) {
            printf("! %d\n", end);
            fflush(stdout);
            exit(0);
        } else {
            printf("! %d\n", start);
            fflush(stdout);
            exit(0);
        }
    }

    else {
        // 두 번째로 큰 놈 전체에서 찾기
        printf("? %d %d\n", start, end);
        fflush(stdout);
        int secondMax;
        cin >> secondMax;

        // 두 번째 놈 포함해서 범위 돌리기
        if(secondMax < (start + end)/2) {
            // 뒤쪽으로 돌림
            printf("? %d %d\n", secondMax, end);
            fflush(stdout);
            int response;
            cin >> response;
            if(response == secondMax) {
                // 최댓값이 이 범위에 있음
                return findMax(secondMax+1, end);
            } else {
                // 이 범위에 없음
                return findMax(start, secondMax-1);
            }
        } else {
            // 앞쪽으로 돌림
            printf("? %d %d\n", start, secondMax);
            fflush(stdout);
            int response;
            cin >> response;
            if(response == secondMax) {
                // 최댓값이 이 범위에 있음
                return findMax(start, secondMax - 1);
            } else {
                // 이 범위에 없음
                return findMax(secondMax + 1, end);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    findMax(1, n);
}