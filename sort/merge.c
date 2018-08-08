#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"


void merge(int* array, int begin, int end, int mid, int* tmp)
{
  int size,i_array,i_tmp,i_hind;

  //配列arrayの前半部を配列tmpにコピー
  for (i_array = begin, i_tmp = 0;i_array <= mid; i_array++, i_tmp++){
    tmp[i_tmp] = array[i_array];
  }
  
  size = mid - begin + 1;
  i_tmp = 0;
  i_hind = mid + 1;
  i_array = begin;

  //配列tmpと配列arrayの後半部をマージ
  while(i_tmp < size && i_hind <= end){
    if (tmp[i_tmp] < array[i_hind]){
      array[i_array] = tmp[i_tmp];
      i_tmp++;
    }else{
      array[i_array] = array[i_hind];
      i_hind++;
    }
    i_array++;
  }
  //前半部(tmp)が残った場合はarrayに結合
  while(i_tmp < size){
    array[i_array] = tmp[i_tmp];
    i_array++;
    i_tmp++;
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

int merge_sort(int *array,int len)
{
  int* work;
  int work_size = (len-1) / 2;
  work = malloc( sizeof(int) * work_size);
  
  merge_sort_rec(array, 0, len-1, work);
  free(work);
}

int main(int argc, char const *argv[])
{
  int len = 10;
  int array[len];
  int i;

  srand(time(NULL));

  for (i=0;i<len;i++){
    array[i] = rand() % 100 + 1;
    printf("%d[%d] ", array[i], i);
  }
  printf("\n");
 
  merge_sort(array, len);
  test_sort(array, len);
}


