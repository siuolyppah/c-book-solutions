#include <stdio.h>

int my_atoi(const char *s);

int main(void) {
    int i;
    char *s = "12s3a";

    i = my_atoi(s);

    printf("atoi: %d", i);

    return 0;
}

int my_atoi(const char *s) {
    int i = 0;

    while (*s > '0' && *s < '9') {
        i = i * 10 + *s - '0';
        ++s;
    }

    return i;
}
