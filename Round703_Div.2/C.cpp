#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif
#include <iostream>

int ask(int start, int end) {
    if(start >= end) return -1;
    printf("? %d %d\n", start, end);
    fflush(stdout);
    int response;
    cin >> response;
    return response;
}

int main() {
    int n;
    scanf("%d", &n);
    int secondMax = ask(1, n);
    if(secondMax == 1 || ask(1, secondMax) != secondMax) {
        int left = secondMax, right = n;
        while(right - left > 1) {
            int middle = (left + right) / 2;
            if (ask(secondMax, middle) == secondMax) {
                right = middle;
            } else {
                left = middle;
            }
        }
        printf("! %d\n", right);
    } else {
        int left = 1, right = secondMax;
        while(right - left > 1) {
            int middle = (left + right) / 2;
            if (ask(middle, secondMax) == secondMax) {
                left = middle;
            } else {
                right = middle;
            }
        }
        printf("! %d\n", left);
    }
}