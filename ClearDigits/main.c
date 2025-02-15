#include <stdio.h>
#include <stdbool.h>

bool isNumber(char c) {
    if ((c >= '0') && (c <= '9')) {
        return true;
    }
    return false;
}

char* clearDigits(char* s) {
    char* curr_char = s;
    while (*curr_char != '\0') {
        if (isNumber(*curr_char) && (curr_char > s)) {
            for (char* c = curr_char - 2; c >= s; c--) {
                *(c+2) = *(c);
            }
            s += 2;
        }
        curr_char++;
    }
    return s;
}

int main() {
    printf("%s\n", clearDigits("abc"));
    char s[] = "cb34";
    printf("%s\n", clearDigits(s));
    return 0;
}