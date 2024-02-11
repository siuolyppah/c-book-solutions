#include <stdio.h>
#include <string.h>

void strncat_ptr(char *s, char *t, size_t n);

int main(void) {
    char s[100] = "This is the first string";
    char *t = ", this second string!";
    size_t nr_chars = 5;

    strncat_ptr(s, t, nr_chars);

    puts(s);

    return 0;
}


/**
 * concatenate t to end of s; s must be big enough
 * @param s: Pointer to the destination string. This string should be large enough to contain the concatenated result.
 * @param t: Pointer to the source string. This string will be appended to the end of string 's'.
 * @param n: The number of characters from 't' to be appended to 's'.
 */
void strncat_ptr(char *s, char *t, size_t n) {
    // move s to the end of the string
    s += strlen(s);

    // copy t to the end of s
    while (n-- && (*s++ = *t++) != '\0');

    *s = '\0';
}
