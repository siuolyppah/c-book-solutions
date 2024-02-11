#include <stdio.h>

void strcat_ptr(char *s, char *t);

int main(void) {
    char s[100] = "This is the first string";
    char t[] = ", this second string!";

    strcat_ptr(s, t);

    puts(s);

    return 0;
}

// concatenate t to end of s; s must be big enough
void strcat_ptr(char *s, char *t) {
    // stop when *s == '\0'
    while (*s != '\0') {
        ++s;
    }

    // copy t to the end of s
    while ((*s++ = *t++) != '\0');
}
