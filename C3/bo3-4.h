// 循环队列的基本操作

void InitQueue(SqQueue &Q){
  Q.base = (Qelemtype*)malloc(MAX_QSIZE*sizeof(QElemType));
  if(!Q.base)
    exit(OVERFLOW);
  Q.front = Q.rear = 0; //队列为空
}

void DestroyQueue(SqQueue &Q){
  if(Q.base)
    free(Q.base); //释放Q.base所指的存储空间
  Q.base = NULL;  //Q.base不指向任何单元
  Q.front = Q.rear = 0;
}

void ClearQueue(SqQueue &Q){  //清空队列
  Q.front = Q.rear = 0;
}

Status QueueEmpty(SqQueue Q){
  if(Q.front == Q.rear) //队列为空的标志
    return TRUE;
  else
    return FALSE;
}

int QueueLength(SqQueue Q){
  return(Q.rear - Q.front + MAX_QSIZE) %MAX_QSIZE;
}

Status GetHead(SqQueue Q, QElemType &e){
  if(Q.front == Q.rear)
    return ERROR;
  e = Q.base[Q.front];
  return OK;
}

Status EnQueue(SqQueue &Q, QElemType e){
  if((Q.rear+1)%MAX_QSIZE == Q.front) //队列已🈵️
    return ERROR;
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1)%MAX_QSIZE; //
  return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e){
  if(Q.front == Q.rear)
    return ERROR;
  e = Q.base[Q.front];
  Q.front = (Q.front + 1)%MAX_QSIZE; //
  return OK;
}

void QueueTraverse(SqQueue Q, void(*visit)(QElemType)){
  int i = Q.front;
  while(i != Q.rear){
    visit(Q.base[i]);
    i = (i + 1) % MAX_QSIZE;  //遍历
  }
  printf("\n");
}
