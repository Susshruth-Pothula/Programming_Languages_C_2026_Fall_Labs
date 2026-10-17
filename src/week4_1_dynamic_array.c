
/*
 * week4_1_dynamic_array.c
 * Author: Susshruth Chandhra Gnan Pothula
 * Student ID: 251ADB006
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  /* Allocate memory for n integers. */
  arr = malloc(n * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  /* Read the integers into the allocated array. */
  printf("Enter %d integers: ", n);

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
  }

  /* Calculate the sum and average. */
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  float average = (float)sum / n;

  printf("Sum = %d\n", sum);
  printf("Average = %.2f\n", average);

  /* Release the allocated memory. */
  free(arr);

  return 0;
}
