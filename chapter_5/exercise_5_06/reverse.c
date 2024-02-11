#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main(void) {
    char s[100] = "abcde";

    reverse(s);
    puts(s);

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
