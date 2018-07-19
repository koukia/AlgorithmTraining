#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int a[], int left, int right)
{
  int mid;
  int pivot;
  int idxL;
  int idxR;
  int tmp;

  if (left < right) {
    mid = left + (right - left) / 2;

    if (a[left] < a[mid]) {
      if (a[right] < a[left])
        pivot = a[left];
      else if (a[mid] < a[right])
        pivot = a[mid];
      else
        pivot = a[right];
    }else{
      if (a[right] > a[left])
        pivot = a[left];
      else if (a[mid] > a[right])
        pivot = a[mid];
      else
        pivot = a[right];
    }

    idxL = left;
    idxR = right;
    while(-1) {
      while (a[idxL] < pivot)
        idxL++;
      while (pivot < a[idxR])
        idxR--;
      if (idxL >= idxR)
        break;
      tmp = a[idxL];
      a[idxL] = a[idxR];
      a[idxR] = tmp;
      idxL++;
      idxR++;
    }
    quick_sort(a, left, idxL - 1);
    quick_sort(a, idxR + 1, right);
  }
}

int main(int argc, char const *argv[])
{
  int data[10000];
  int n;
  int start, end;
  int counter;
  int i;

  printf("Data num = ");
  scanf("%d", &n);

  start = clock();
  for (counter = 1;counter <= 10000;counter++) {
    srand((unsigned int)time(NULL));
    for (i = 0;i < n; i++) {
      data[i] = rand();
    }

    quick_sort(data, 0, n - 1);
  }

  end = clock();

  printf("Process time = %f[sec]\n", (end - start) / (double)CLOCKS_PER_SEC);

  return 0;
}
