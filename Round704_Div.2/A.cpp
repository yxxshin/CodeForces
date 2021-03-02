#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

long long int p, a, b, c;

long long int func(long long int x) {
    auto temp = (long long int)(ceil((long double)p/x));
    dbg(temp);
    return (temp*x - p);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld", &p, &a, &b, &c);
        printf("%lld\n", min({func(a), func(b), func(c)}));
    }
}