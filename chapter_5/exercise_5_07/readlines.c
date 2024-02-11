#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 // max # of lines to be sorted
#define MAXLEN 1000
#define MAXSTORE 10000 // max # of chars from all lines to be stored

char *line_ptr[MAXLINES]; // pointers to text lines

size_t get_line(char line[], size_t max_line_len);

int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines);

void writelines(char *line_ptr[], int nr_of_lines);

void swap(char *v[], int i, int j);

void quick_sort(char *line_ptr[], int left, int right);

int main() {
    int nr_of_lines;             // the line count read
    char stored_lines[MAXSTORE]; // place to store read lines

    if ((nr_of_lines = readlines(line_ptr, MAXLINES, stored_lines)) >= 0) {
        quick_sort(line_ptr, 0, nr_of_lines - 1);
        printf("-----\n");
        writelines(line_ptr, nr_of_lines);
        return 0;
    } else {
        printf("Error: input too big to sort.\n");
        return 1;
    }
}

int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines) {
    size_t read_line_cnt = 0;

    char *line = stored_lines;
    while (read_line_cnt < max_nr_of_lines) {
        size_t len = get_line(line, MAXLEN);

        if (len == 0) {
            break;
        } else {
            line_ptr[read_line_cnt++] = line;
            line += len;
        }
    }

    return read_line_cnt;
}

void writelines(char *line_ptr[], int nr_of_lines) {
    while (nr_of_lines-- > 0) {
        printf("%s\n", *line_ptr++);
    }
}

size_t get_line(char line[], size_t max_line_len) {
    int c;
    size_t i = 0;

    for (; i < max_line_len - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }


    line[i] = '\0';

    return i;
}

void quick_sort(char *v[], int left, int right) {
    int i;
    int last;

    // Do nothing if the array contains less than 2 elements
    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; ++i) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
