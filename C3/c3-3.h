//循环队列
#define MAX_QSIZE 5 //最大队列长度 6

struct SqQueue{
  QElemType *base; //初始化的动态分配存储空间
  int front;
  int rear;
};
