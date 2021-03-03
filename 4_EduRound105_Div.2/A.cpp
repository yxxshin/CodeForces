#include <cstdio>
using namespace std;
#ifdef __APPLE__
#include "dbg.h"
#else
#define dbg(...)
#endif

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        char a[52];
        scanf("%s", a);
        int lenA = 0, lenB = 0, lenC = 0;
        for(int i = 0; i < strlen(a); i++) {
            if(a[i] == 'A') lenA++;
            else if(a[i] == 'B') lenB++;
            else lenC++;
        }
        char MAX;
        if(max({lenA, lenB, lenC}) == lenA) MAX = 'A';
        else if(max({lenA, lenB, lenC}) == lenB) MAX = 'B';
        else MAX = 'C';

        dbg(MAX);

        bool isMAXOpen;
        if(a[0] == MAX) {
            isMAXOpen = true;
        } else {
            isMAXOpen = false;
        }

        dbg(isMAXOpen);
        bool flag = true;
        stack<int> s;
        for(int i = 0; i < strlen(a); i++) {
            dbg(i);

            if(a[i] == MAX && isMAXOpen) {
                dbg(1);
                s.push(1);
            } else if (a[i] != MAX && !isMAXOpen) {
                dbg(2);
                s.push(1);
            } else {
                if(s.empty()) {
                    flag = false;
                    break;
                }
                else {
                    dbg(3);
                    s.pop();
                }
            }
        }
        if(!s.empty()) flag = false;

        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}