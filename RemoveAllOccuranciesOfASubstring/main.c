#include <stdio.h>
#include <string.h>

void myStrcat(char *dest, char *src) {
    char *ptr = dest;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
}

char* removeOccurrences(char* s, char* part) {
    // Return empty
    if (s == NULL || part == NULL || *s == '\0' || *part == '\0') {
        return NULL;
    }
    // Initialize variables
    int s_len = strlen(s);
    int part_len = strlen(part);
    // Find the first occurrence of the part
    char *found_ptr = strstr(s, part);
    // Loop through the string
    while (found_ptr != NULL) {
        *found_ptr = '\0';
        myStrcat(s, found_ptr + part_len);
        found_ptr = strstr(s, part);
    }
    // Return the resulted string
    return s;
}

int main() {
    // Test case 1
    char s[] = "daabcbaabcbc";
    char part[] = "abc";
    printf("%s\n", removeOccurrences(s, part));
    // Test case 2
    char s2[] = "axxxxyyyyb";
    char part2[] = "xy";
    printf("%s\n", removeOccurrences(s2, part2));
    return 0;
}