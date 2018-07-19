#include <stdlib.h>
#include <stdio.h>

#define INPUT_SIZE 16
int input[INPUT_SIZE];

int binary_search(int key)
{
  int find_flg = 0;
  int search_left = 0;
  int search_right = INPUT_SIZE - 1;
  int pivot;

  while (search_left < search_right) {
    pivot = (search_right + search_left) / 2;
    if (key == input[pivot]) {
      return pivot;
    }
    if (pivot == search_right || pivot == search_left)
      break;
    if (key < input[pivot])
      search_right = pivot;
    else
      search_left = pivot;
  }
}


int main(int argc, char const *argv[])
{
  int i;
  int result;
  for (i=0;i<INPUT_SIZE;i++) {
    input[i] = i * 3;
  }
  
  result = binary_search(6);
  printf("input[%d] has %d\n", result, 6);
  return 0;
}
