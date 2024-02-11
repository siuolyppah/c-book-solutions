#include <stdio.h>

int strncmp_ptr(char *s, char *t, size_t n);

void human_readable_strncmp(char *s, char *t, size_t n) {
    int is_equal = strncmp_ptr(s, t, n);

    if (is_equal == 0) {
        printf("\"%s\" equal to \"%s\"\n", s, t);
    } else if (is_equal > 0) {
        printf("\"%s\" greater than \"%s\"\n", s, t);
    } else {
        printf("\"%s\" less than \"%s\"\n", s, t);
    }
}

int main(void) {
    human_readable_strncmp("abc", "abff", 2);
    human_readable_strncmp("abcdefg", "abcccc", 4);
    human_readable_strncmp("abcccc", "abcfff", 3);

    return 0;
}

// Return <0 if s<t, 0 if s==t, >0 if s>t *1
int strncmp_ptr(char *s1, char *s2, size_t n) {
    for (; n && *s1 == *s2; --n, ++s1, ++s2) {
        if (*s1 == '\0') {
            return 0;
        }
    }

    return n == 0 ? 0 : *s1 - *s2;
}