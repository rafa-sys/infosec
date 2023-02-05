#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

void print_trace (void) {
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    printf ("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        printf ("%s\n", strings[i]);

    free (strings);
}

void handler (int sig) {
    print_trace ();
    exit (1);
}

void buggy_function (void) {
    int *p = NULL;
    *p = 0;
}

int main (void) {
    signal (SIGSEGV, handler);
    buggy_function ();
    return 0;
}
