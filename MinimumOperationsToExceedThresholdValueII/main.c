#include <stdio.h>
#include <stdlib.h>

// Implement insertion on sorted array
// NOTE1: Nums is sorted in ascending order
// NOTE2: Nums first element is empty
void sortedInsert(long int* nums, int numsSize, long int new_num) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < new_num) {
            nums[i - 1] = nums[i];
        } else {
            nums[i - 1] = new_num;
            return;
        }
    }
    nums[numsSize - 1] = new_num;
}

// Implement quick sort
void quickSort(long int* nums, int numsSize) {
    if (numsSize <= 1) {
        return;
    }
    int left = 0;
    int right = numsSize - 1;
    if (left < right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        quickSort(nums, left);
        quickSort(nums + left + 1, numsSize - left - 1);
    } 
}

// Convert to long int
long int* convertToLong(int* nums, int numsSize) {
    long int* long_nums = (long int*)malloc(numsSize * sizeof(long int));
    for (int i = 0; i < numsSize; i++) {
        long_nums[i] = (long int)nums[i];
    }
    return long_nums;
}

int minOperations(int* nums, int numsSize, int k) {
    // Convert to long int
    long int* long_nums = convertToLong(nums, numsSize);
    // Initialize operations counter
    int operations = 0;
    // Sort the array
    quickSort(long_nums, numsSize);
    // Perform operations as long threadhold is not exceeded
    while (numsSize > 1 && long_nums[0] < k) {
        // Calculate the new value
        long int new_value = (long_nums[0] * 2) + long_nums[1];
        // Update the array size
        long_nums++;
        numsSize--;
        // Insert the new value in the array
        sortedInsert(long_nums, numsSize, new_value);
        // Increment the operations counter
        operations++;
    }
    // Return result
    return operations;
}

int main() {
    // Test case 1
    int nums1[] = {2,11,10,1,3};
    int numsSize1 = 5;
    int k1 = 10;
    int result1 = minOperations(nums1, numsSize1, k1);
    printf("Result 1: %d\n", result1);

    // Test case 2
    int nums2[] = {1,1,2,4,9};
    int numsSize2 = 5;
    int k2 = 20;
    int result2 = minOperations(nums2, numsSize2, k2);
    printf("Result 2: %d\n", result2);

    return 0;
}