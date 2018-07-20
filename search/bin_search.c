#include <stdlib.h>
#include <stdio.h>

#define INPUT_SIZE 10
int input[INPUT_SIZE];

int binary_search(int key)
{
  int find_flg = 0;
  int search_left = 0;
  int search_right = INPUT_SIZE - 1;
  int pivot;

  while (search_left <= search_right) {
    pivot = (search_right + search_left) / 2;
    printf("pivot is %d\n", pivot);

    if (key == input[pivot]) {
      return pivot;
    }else if (key < input[pivot])
      search_right = pivot - 1;
    else
      search_left = pivot + 1;
  }
  return -1;
}

void test_bin_search(int target, int expect)
{
  int result = binary_search(target);
  if (result != -1)
    printf("input[%d] has %d\n", result, target);
  else
    printf("%d is not found\n", result);

  if (result == expect)
    printf("This case is passed.\n");
  else
    printf("This case is failed...\n");
}

int main(int argc, char const *argv[])
{
  int i;
  int result;
  for (i=0;i<INPUT_SIZE;i++) {
    input[i] = i;
    printf("%d[%d], ", input[i], i);
  }
  printf("\n");
  
  int target;
  
  //Test:bin_search()
  test_bin_search(0, 0);
  test_bin_search(3, 3);
  test_bin_search(9, 9);
  test_bin_search(10, -1);

  return 0;
}

