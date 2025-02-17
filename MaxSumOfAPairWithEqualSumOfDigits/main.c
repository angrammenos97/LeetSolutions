#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int digi_sum;
    int i_num;
    int j_num;
    int ij_sum;
    bool valid;
} Pair_s;

typedef struct {
    Pair_s* pairs;
    int capacity;
    int elements;
} PairArray_s;

bool enlargePairsArray(PairArray_s* array) {
    if (array->capacity == 0) {
        array->capacity = 1;
        array->pairs = (Pair_s*)malloc(array->capacity * sizeof(Pair_s));
    } else {
        array->capacity *= 2;
        array->pairs = (Pair_s*)realloc(array->pairs, array->capacity * sizeof(Pair_s));
    }
    if (array->pairs == NULL) {
        return false;
    }
    return true;
}

bool createPair(PairArray_s* array, int digi_sum, int i_num) {
    if (array->elements == array->capacity) {
        if (!enlargePairsArray(array)) {
            return false;
        }
    }
    array->pairs[array->elements].digi_sum = digi_sum;
    array->pairs[array->elements].i_num = i_num;
    array->pairs[array->elements].j_num = 0;
    array->pairs[array->elements].ij_sum = array->pairs[array->elements].i_num 
                                            + array->pairs[array->elements].j_num;
    array->pairs[array->elements].valid = false;
    array->elements++;
    return true;
}

int findPair(PairArray_s* array, int digi_sum) {
    for (int i = 0; i < array->elements; i++) {
        if (array->pairs[i].digi_sum == digi_sum) {
            return i;
        }
    }
    return -1;
}

void updatePair(PairArray_s* array, int index, int num) {
    if (array->pairs[index].valid == false || array->pairs[index].i_num > array->pairs[index].j_num) {
        array->pairs[index].j_num = num;
    } else {
        array->pairs[index].i_num = num;
    }
    array->pairs[index].ij_sum = array->pairs[index].i_num + array->pairs[index].j_num;
    array->pairs[index].valid = true;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maximumSum(int* nums, int numsSize) {
    // Initialze
    PairArray_s array = {0};    // Array of pairs
    int maxsum = -1;            // Maximum sum of pairs
    // Iterate through the numbers
    for (int i = 0; i < numsSize; i++) {
        // Find the sum of digits of the current number
        int digi_sum = sumOfDigits(nums[i]);
        // Check if the sum of digits is already in the array
        int index = findPair(&array, digi_sum);
        if (index == -1) {
            createPair(&array, digi_sum, nums[i]);
        }
        // If the sum of digits is already in the array
        else {
            // Update the pair with the current number
            updatePair(&array, index, nums[i]);
            // Check if updated is greater
            if (array.pairs[index].ij_sum > maxsum) {
                maxsum = array.pairs[index].ij_sum;
            }
        }
    }
    // Return the maximum sum
    return maxsum;
}

int main() {
    // Test case 1
    int nums[] = {18,43,36,13,7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maximumSum(nums, numsSize);
    printf("%d\n", result);
    
    // Test case 2
    int nums2[] = {10,12,19,14};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = maximumSum(nums2, numsSize2);
    printf("%d\n", result2);
    return 0;
}