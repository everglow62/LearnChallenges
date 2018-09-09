// 检验 bo3-1.h

#include "c1.h"
typedef int SElemType;
#include "c3-1.h"
#include "bo3-1.h"
#define ElemType SElemType
#include "func2-2.h"

int main(int argc, char const *argv[]) {
  int j;
  SqStack s;
  SElemType e;

  InitStack(s);
  for(j = 1; j <= 12; j++)
    Push(s, j);
  printf("栈中元素依次为");
  StackTraverse(s, print);
  Pop(s, e);
  printf("弹出栈顶元素 e = %d\n", e);
  printf("栈空否？ %d （1:空 0:否）", StackEmpty(s) );
  GetTop(s, e);
  printf("栈顶元素 e= %d, 栈的长度为%d\n", e, StackLength(s) );
  ClearStack(s);
  printf("清空栈后，栈空否？%d (1:空 0:否)\n", StackEmpty(s));
  DestroyStack(s);
  printf("销毁栈后，s.top = %u, s.base = %u, s.stacksize=%d\n", s.top,s.base,
          s.stacksize);

  return 0;
}
