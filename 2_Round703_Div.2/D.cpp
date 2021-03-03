#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

#include <cstring>
#include <algorithm>
#define MAX_N 200000

int n, k;
int arr[MAX_N+5];

bool check_X(int x) {
    // check if x is possible for answer
    int brr[MAX_N+5], preSum[MAX_N+5], minSum[MAX_N+5];
    memset(brr, 0, sizeof(brr));
    memset(preSum, 0, sizeof(preSum));
    memset(minSum, 0, sizeof(minSum));

    if(arr[1] < x) brr[1] = -1;
    else brr[1] = 1;

    preSum[1] = brr[1];
    minSum[1] = min(preSum[1], minSum[0]);

    for(int i = 2; i <= n; i++) {
        // set values of preSum and minSum
        if(arr[i] < x) brr[i] = -1;
        else brr[i] = 1;
        preSum[i] = preSum[i-1] + brr[i];
        minSum[i] = min(minSum[i-1], preSum[i]);

        if(i >= k && preSum[i] > minSum[i-k])
            return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // binary search
    int l = 1;
    int r = n;
    int m, ans = arr[1];
    while(l <= r) {
        m = (l+r)/2;
        if(check_X(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}