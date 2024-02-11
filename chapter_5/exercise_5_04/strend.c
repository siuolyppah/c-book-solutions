#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(void) {
    char *s = "This si a simple string";
    char *t1 = "string";
    char *t2 = "balabala string";

    if (strend(s, t1)) {
        puts("string t1 occurs at the end of string s.");
    } else {
        puts("string t1 doesn't occur at the end of string s.");
    }

    if (strend(s, t2)) {
        puts("string t2 occurs at the end of string s.");
    } else {
        puts("string t2 doesn't occur at the end of string s.");
    }

    return 0;
}

/**
 * strend: return 1 if string t occurs at the end of string s, and zero otherwise.
 */
int strend(char *s, char *t) {
    // move the pointers to the end of the strings
    size_t s_length = strlen(s);
    size_t t_length = strlen(t);
    s += s_length;
    t += t_length;

    // compare the strings from the end
    while (t_length && (*s-- == *t--))
        --t_length;

    if (t_length)
        return 0;

    return 1;
}
