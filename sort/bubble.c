#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"


void bubble_sort(int *data, int len)
{
  int i,j,tmp;

  for (i=0;i<len-1;i++){
    for (j=i+1;j<len;j++){
      if (data[i] > data[j]){
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int len = 10;
  int data[len];
  int i;

  srand(time(NULL));

  for (i=0;i<len;i++){
    data[i] = rand() % 100 + 1;
    printf("%d[%d] ", data[i], i);
  }
  printf("\n");

  bubble_sort(data, len);
  test_bubble_sort(data, len);
}

