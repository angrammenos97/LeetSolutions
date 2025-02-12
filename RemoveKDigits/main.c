#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    // Find new number length
    unsigned int num_len = strlen(num);
    unsigned int st_len = num_len - k;
    if (st_len == 0)   //case of remove all digits
      return "0";
  
    // Initialize stack (plus one for termination character)
    char* stack = (char*)calloc(num_len + 1, sizeof(char));
    unsigned int el_num = 0; //number of stack elements
  
    // Pass through all digits (and termination character)
    for (unsigned int i = 0; i < num_len + 1; i++) {
      for (signed int j = el_num - 1; (j >= 0 && k > 0); j--) {
      //   printf("Current: \"%s\"\n", stack);
        if (stack[j] > num[i]){
          el_num--; //pop stack
          k -= 1;
        }
      }
      stack[el_num++] = num[i]; //appent stack
    }
    
    // Remove leading zeros (2 for termination)
    while (*stack == '0' && el_num > 2) {
      //pop from the front
      stack += 1;
      el_num -= 1;
    }
  
    // Return results
    // printf("Result: \"%s\"\n", stack);
    return stack;
  }

int main() {
  // Test case 1
  char* num = "1432219";
  int k = 3;
  printf("Result: \"%s\"\n", removeKdigits(num, k));

  // Test case 2
  num = "10200";
  k = 1;
  printf("Result: \"%s\"\n", removeKdigits(num, k));

  // Test case 3
  num = "10";
  k = 2;
  printf("Result: \"%s\"\n", removeKdigits(num, k));

  return 0;
}