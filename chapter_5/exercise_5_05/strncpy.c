#include <stdio.h>
#include <malloc.h>
#include <string.h>

void strncpy_ptr(char *s, char *t, size_t n);

void test(char *s, char *t, size_t n) {
    // copy s from only readable section to malloced memory to allow update
    char *buf = (char *) malloc(sizeof(char) * 100);
    strcpy(buf, s);

    strncpy_ptr(buf, t, n);
    puts(buf);

    free(buf);
}

int main(void) {
    test("long_string", "short", 1);
    test("long_string", "short", 7);

    return 0;
}

void strncpy_ptr(char *s, char *t, size_t n) {
    for (; n > 0 && *t != '\0'; --n) {
        *s++ = *t++;
    }

    *s = '\0';
}
