#include <stdio.h>

int strindex(char *s, char *t);

int main(void) {
    char s[] = "hello, world";
    char t[] = "lo";

    printf("%d", strindex(s, t));

    return 0;
}

// find t in s
int strindex(char *s, char *t) {
    char *ss;
    char *tt;
    int pos = 0;

    while (*s != '\0') {
        if (*s == *t) {
            ss = s;
            tt = t;

            while (*ss++ == *tt++) {
                if (*tt == '\0')
                    return pos;
            }
        }
        pos++;
        s++;
    }

    return -1;
}
