typedef int SElemType;
#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"

void conversion(){
  SqStack s;
  unsigned n;
  SElemType e;
  printf("将十进制整数n转换为十六进制数，请输入：n（≥0）=");
  scanf("%u", &n);
  InitStack(s);
  while(n){
    Push(s, n%16);
    n = n/ 16;
  }
  while(!StackEmpty(s)){
    Pop(s,e);
    if(e <= 9)
      printf("%d", e);
    else
      printf("%c", e + 55); //ASCII 码
  }
  printf("\n");
  DestroyStack(s);
}

int main(int argc, char const *argv[]) {
  conversion();
  return 0;
}
