#include <ctype.h>
#include <stdio.h>

#define MAXLEN 1000
#define BUFFSIZE 100

void printbuf(void);

int getch(void);

void ungetch(int c);

int getint(int *pn);

int main(void) {
    int number = 0;

    int ret = getint(&number);
    printf("get:%d, return val:%c\n", number, ret);

    printbuf();

    return 0;
}

// `bufp` is the index of the next free position in buf
int bufp = 0;
int buf[BUFFSIZE];

void printbuf(void) {
    if (bufp) {
        printf("Buffer: [ ");

        int i;
        for (i = bufp - 1; i >= 0; --i) {
            if (i) {
                printf("'%c', ", buf[i] != '\n' ? buf[i] : '.');
            } else {
                // i == 0, the last element, so no comma after it
                printf("'%c' ", buf[i] != '\n' ? buf[i] : '.');
            }
        }

        printf("]\n");
    }
}

int getch(void) {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

/**
 * getint: get next integer from input into *pn
 * @param pn: Pointer to an integer where the input integer will be stored.
 * @return: `EOF` if the input is at EOF, `0` if the next input is not a number, and the `a positive val(next input character)` otherwise.
 */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        if (!isdigit(c = getch())) {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn = *pn * sign;

    // `c` is the last character read from the input, and it's not a digit
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}
