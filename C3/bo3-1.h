// 顺序栈（存储结构由c3-1.h定义）的基本操作
void InitStack(SqStack &S){
  //构造一个空栈 S
  S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
  if(!S.base)
    exit(OVERFLOW);
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S){
  //销毁栈 S, S 不再存在
  free(S.base); //释放栈空间
  S.top = S.base = NULL;
  S.stacksize = 0;
}

void ClearStack(SqStack &S){
  //将 S 设为空栈
  S.top = S.base; //栈顶指向栈底
}

Status StackEmpty(SqStack S){
  //判断栈 S 是否为🈳️
  if(S.top == S.base) //空栈条件
    return TRUE;
  else
    return FALSE;
}

int StackLength(SqStack S){
  return S.top - S.base; //栈 S 的长度
}

Status GetTop(SqStack S, SElemType &e){
  //若栈 S 不空，则返回栈顶元素
  if(S.top > S.base){
    e = *(S.top-1);
    return OK;
  }
  else
    return ERROR;
}

void Push(SqStack &S, SElemType e){
  //插入元素 e
  if(S.top - S.base == S.stacksize){  //栈满
    S.base = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREMENT)*
    sizeof(SElemType)); //追加空间
    if(!S.base)
      exit(OVERFLOW);
    S.top = S.base + S.stacksize;
    S.stacksize += STACK_INCREMENT;
  }
  *(S.top)++= e;  //e 入栈，成为新栈顶，同时栈顶指针上移
}

Status Pop(SqStack &S, SElemType &e){
  //若栈不空，删除栈顶元素，用e返回其值
  if(S.top == S.base)
    return ERROR;
  e = *--S.top; //⚠️，栈顶指针在栈顶元素之上
  return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType)) {
  //遍历
  SElemType *p = S.base;
  while(S.top > p)
    visit(*p++);
  printf("\n");
}
