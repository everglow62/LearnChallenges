//栈的顺序存储结构
#define STACK_INIT_SIZE 10 //初始空间分配量
#define STACK_INCREMENT 2 //存储空间分配增量

struct SqStack{ //顺序栈
  SElemType *base;
  SElemType *top;
  int stacksize;  //已分配的存储空间，以元素为单位
};
