#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

stack<int> a;
stack<int> temp;
vector<int> b;
bool check[100002];
int n;

void func() {
    dbg(b);
    while(true) {
        int top = a.top();

        a.pop();
        temp.push(top);

        if(check[top]) {
            while(!temp.empty()) {
                int xx = temp.top();
                temp.pop();
                b.push_back(xx);
            }

            if(a.empty()) {
                return;
            } else {
                return func();
            }
        }  else {
            continue;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        b.clear();
        int max = 0;
        memset(check, false, sizeof(check));

        for(int i = 0; i < n; i++) {
            int input;
            scanf("%d", &input);
            a.push(input);
            if(input > max) {
                max = input;
                check[input] = true;
            }
        }

        func();

        for(int i = 0; i < n; i++) {
            printf("%d", b[i]);
            if(i != n-1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
}