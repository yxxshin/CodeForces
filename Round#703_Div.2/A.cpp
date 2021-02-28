#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

int main() {
   int t;
   scanf("%d", &t);
   while(t--) {
       int n;
       bool flag = false;
       long long sum = 0;
       scanf("%d", &n);
       long long h[102];
       for(int i = 0; i < n; i++) {
           scanf("%lld", &h[i]);
       }

       for(int i = 0; i < n-1; i++) {
           h[i+1] += h[i] - i;
           if(h[i+1] < i+1) {
               flag = true;
               break;
           }
       }

       if(flag) printf("NO\n");
       else printf("YES\n");
   }
}