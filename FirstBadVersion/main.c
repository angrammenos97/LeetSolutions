#include <stdio.h>
#include <stdbool.h>

#define BAD_VERSION 4

bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    // binary_search_rightmost
    int L = 0;
    while (L < n) {
        int m = (n / 2) + (L / 2);
        if (isBadVersion(m))
            n = m;
        else
            L = m + 1;
    }
    return n;
}

int main() {
    printf("The first bad version is %d\n", firstBadVersion(5));
    return 0;
}