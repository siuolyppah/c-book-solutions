#include <stdio.h>
#include <string.h>


void itoa(char *s, int n);

int main(void) {
    int i = 1234;
    char s[100] = "";

    itoa(s, i);

    printf("itoa: %s\n", s);

    return 0;
}

void reverse(char *s) {
    char *e = s + (strlen(s) - 1);
    while (s < e) {
        char tmp = *s;
        *s++ = *e;
        *e-- = tmp;
    }
}

void itoa(char *s, int n) {
    char *bak = s;

    while (n) {
        *s++ = n % 10 + '0';
        n /= 10;
    }

    *s = '\0';

    reverse(bak);
}
