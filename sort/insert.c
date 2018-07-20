#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"


void insert_sort(int *data, int len)
{
  int i,j,tmp,min;

  for(i=1;i<len;i++){
    min = data[i];

    for(j=i;j>0 && min < data[j-1];j--)
      data[j] = data[j - 1];
    
    data[j] = min;
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

  insert_sort(data, len);
  test_sort(data, len);
}


