#include <stdio.h>
#include <stdlib.h>


void test_bubble_sort(int *data, int len)
{
  int i,j;
  int is_passed;

  is_passed = 1;
  for (i=0;i<len-1;i++)
    if (data[i] > data[i+1])
      is_passed = 0;
 
  if (is_passed)
    printf("Test is passed.\n");
  else
    printf("Test is failed...\n");
  
  for (i=0;i<len;i++){
    printf("%d[%d] ", data[i], i);
  }
  printf("\n");
}

