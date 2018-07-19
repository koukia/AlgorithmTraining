#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  typedef struct node {
    struct node *next;
    int data;
  }NODE;

  int x;
  NODE *head = NULL, *p;
  while (1)
  {
    printf("data = ");
    scanf("%d", &x);
    if(x == -1)
      break;
    p = malloc(sizeof(NODE));//本来は戻り値チェックが必要
    p->next = head;
    p->data = x;
    head = p;

  }

  p = head;
  while (p)
  {
    printf("%d\n", p->data);
    p = p->next;
  }
  return 1;
}