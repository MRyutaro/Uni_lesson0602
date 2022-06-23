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

switch (strsmp())
{
case /* constant-expression */:
  /* code */
  break;

default:
  break;
}
