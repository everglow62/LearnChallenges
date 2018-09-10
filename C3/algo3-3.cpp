typedef char SElemType;
#include "c1.h"
#include "c3-1.h" //顺序栈
#include "bo3-1.h"

FILE *fp;

void copy(SElemType c ) {
  //将字符C 送到 fp 所指文件中
  fputc(c, fp);
}

void LineEdit() {
  //利用字符栈s，从终端接收一行并送至调用过程的数据区
  SqStack s;
  char ch;
  InitStack(s);
  printf("请输入一个文本文件，^Z 结束输入：\n");
  ch = getchar(); //接收字符到 ch
  while(ch != EOF){   //当全文结束时，EOF为 ^z 即 control + d
    while (ch != EOF && ch != '\n'){  //当全文结束，且未到行末
      switch (ch){  //对 ch 分情况处理
        case '#': if(!StackEmpty(s))
                    Pop(s,ch); //栈非空时，弹出栈顶
                  break;
        case '@': ClearStack(s); //重制 s 为空栈
                  break;
        default : Push(s, ch);
      }
      ch = getchar();
    }
    StackTraverse(s, copy);
    fputc('\n', fp);
    ClearStack(s);
    if(ch != EOF)
      ch = getchar(); //从终端接收下一个字符
  }
  DestroyStack(s);
}

int main(){
  fp = fopen("ed.txt", "w");

  if(fp){ //文件建立成功
    LineEdit(); //行编辑
    fclose(fp); //关闭fp所指文件
  }
  else
    printf("建立文件失败！\n");
}
