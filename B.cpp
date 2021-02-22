#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<long long> x;
        vector<long long> y;
        for(int i = 0; i < n; i++) {
            long long a, b;
            scanf("%lld %lld", &a, &b);
            x.push_back(a);
            y.push_back(b);
        }
        if(n%2 == 1) {
            printf("1\n");
            continue;
        }
        dbg(x);
        dbg(y);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long a = x[n/2] - x[n/2 - 1] + 1;
        long long b = y[n/2] - y[n/2 - 1] + 1;
        printf("%lld\n", a*b);
    }
}