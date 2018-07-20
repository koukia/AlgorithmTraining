#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"


void selection_sort(int *data, int len)
{
  int i,j,tmp,min;

  for(i=0;i<len-1;i++){
    min = i;

    for(j=i+1;j<len;j++){
      if (data[j] < data[min])
        min = j;
    }

    if (i != min){
      tmp = data[i];
      data[i] = data[min];
      data[min] = tmp;
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

  selection_sort(data, len);
  test_sort(data, len);
}


