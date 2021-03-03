#include <cstdio>
#include <cstring>

char changeLow(char x) {
    if(x == 'a') return 'b';
    else return 'a';
}

char changeHigh(char x) {
    if(x == 'z') return 'y';
    else return 'z';
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        char s[52];
        scanf("%s", s);
        for(int i = 0; i < strlen(s); i++) {
            if(i%2 == 0) s[i] = changeLow(s[i]);
            else s[i] = changeHigh(s[i]);
        }
        printf("%s\n", s);
    }
}