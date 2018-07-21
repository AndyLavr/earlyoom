// SPDX-License-Identifier: MIT

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Print message to stderr and exit with "code".
// Example: fatal(6, "could not compile regexp '%s'\n", regex_str);
void fatal(int code, char* fmt, ...)
{
    char* red = "";
    char* reset = "";
    if (isatty(fileno(stderr))) {
        red = "\033[31m";
        reset = "\033[0m";
    }
    char fmt2[100];
    snprintf(fmt2, sizeof(fmt2), "%sfatal: %s%s", red, fmt, reset);
    va_list args;
    va_start(args, fmt); // yes fmt, NOT fmt2!
    vfprintf(stderr, fmt2, args);
    va_end(args);
    exit(code);
}

// Print a yellow warning message to stderr.
void warn(char* fmt, ...)
{
    char* yellow = "";
    char* reset = "";
    if (isatty(fileno(stderr))) {
        yellow = "\033[33m";
        reset = "\033[0m";
    }
    char fmt2[100];
    snprintf(fmt2, sizeof(fmt2), "%s%s%s", yellow, fmt, reset);
    va_list args;
    va_start(args, fmt); // yes fmt, NOT fmt2!
    vfprintf(stderr, fmt2, args);
    va_end(args);
}
