#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"


void merge(int* array, int begin, int end, int mid, int* work)
{
  int i,j,k;

  for (i=begin;i<=mid;++i){
    work[i] = array[i];
  }

  for (i=mid+1,j=end;i<=end;++i,--j){
    work[i] = array[j];
  }

  i = begin;
  j = end;
  for (k=begin;k<=end;++k){
    if (work[i] <= work[j]){
      array[k] = work[i];
      ++i;
    }else{
      array[k] = work[j];
      --j;
    }
  }
}

void merge_sort_rec(int *array, int begin, int end, int* work)
{
  int mid;

  if (begin >= end){
    return;
  }

  mid = (begin + end) / 2;
  merge_sort_rec(array, begin, mid, work);
  merge_sort_rec(array, mid+1, end, work);

  merge(array, begin, end, mid, work);
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

  int* work;
  work = malloc( sizeof(int) * len );
  merge_sort_rec(data, 0, len-1, work);
  free(work);
  test_sort(data, len);
}


