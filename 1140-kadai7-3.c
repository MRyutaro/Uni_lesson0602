#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell
{
  int data;
  struct cell *next;
} CELL;

CELL head;

void InsertCell(int x)
{
  CELL *p, *new;
  new = (CELL *)malloc(sizeof(CELL));
  new->data = x;
  for (p = &head; p->next != NULL; p = p->next)
  {
    if (new->data < (p->next)->data)
    {
      new->next = p->next;
      p->next = new;
      return;
    }
    else if (new->data == (p->next)->data)
      return;
  }
  new->next = NULL;
  p->next = new;

  return;
}

void DeleteCell(int x)
{
  CELL *p, *q;
  for (p = &head; p->next != NULL; p = p->next)
  {
    if ((p->next)->data == x)
    {
      q = p->next;
      p->next = q->next;
      free(q);
      return;
    }
  }
  fprintf(stderr, "そのような数字はありません。\n");
  return;
}

void DeletePositiveCell()
{
  CELL *p, *q;
  for (p = &head; p->next != NULL;)
  {
    if ((p->next)->data > 0)
    {
      q = p->next;
      p->next = q->next;
      free(q);
    }
    else
    {
      p = p->next;
    }
  }
}

void DeleteNegativeCell()
{
  CELL *p, *q;
  for (p = &head; p->next != NULL;)
  {
    if ((p->next)->data < 0)
    {
      q = p->next;
      p->next = q->next;
      free(q);
    }
    else
    {
      p = p->next;
    }
  }
}

void DeleteEvenCell()
{
  CELL *p, *q;
  for (p = &head; p->next != NULL;)
  {
    if (((p->next)->data % 2 == 0) && (p->next)->data != 0)
    {
      q = p->next;
      p->next = q->next;
      free(q);
    }
    else
    {
      p = p->next;
    }
  }
}

void PrintList()
{
  CELL *p;
  for (p = &head; p->next != NULL; p = p->next)
    printf("%d ", (p->next)->data);
  printf("\n");
}

int main(void)
{
  char list[] = {'i', 'd', 'p', 'n', 'e', 's', 'x'};
  char flag;
  while (1)
  {
    flag = 0;
    fprintf(stderr, "コマンドを入力してください(i, d, p, n, e, s, x)：");
    scanf(" %c", &flag);

    if (flag == list[0])
    {
      int x;
      printf("整数を入力してください: ");
      scanf("%d", &x);
      InsertCell(x);
    }
    else if (flag == list[1])
    {
      int x;
      printf("整数を入力してください: ");
      scanf("%d", &x);
      DeleteCell(x);
    }
    else if (flag == list[2])
    {
      DeletePositiveCell();
    }
    else if (flag == list[3])
    {
      DeleteNegativeCell();
    }
    else if (flag == list[4])
    {
      DeleteEvenCell();
    }
    else if (flag == list[5])
    {
      PrintList();
    }
    else if (flag == list[6])
    {
      fprintf(stderr, "終了します。");
      return 0;
    }
    else
    {
      fprintf(stderr, "コマンドが正しくありません。\n");
    }
  }
}