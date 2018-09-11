// 链队列的基本操作（9个）
void InitQueue(LinkQueue &Q){
  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.front)
    exit(OVERFLOW);
  Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q){
  while (Q.front){
    Q.rear = Q.front->next;
    free(Q.front);
    Q.front = Q.rear;
  }
}

void ClearQueue(LinkQueue &Q){
  DestroyQueue(Q);
  InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q){
  if(Q.front->next == NULL)
    return TRUE;
  else
    return FALSE;
}

int QueueLength(LinkQueue Q){
  int i = 0;
  QueuePtr p = Q.front;
  while(Q.rear != p){
    i++;
    p = p->next;
  }
  return i;
}

Status GetHead(LinkQueue Q, QElemType &e){
  QueuePtr p;
  if(Q.front == Q.rear)
    return ERROR;
  p = Q.front->next;
  e = p->data;
  return OK;
}

void EnQueue(LinkQueue &Q, QElemType e){  //🌈 插入为队尾
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  if(!p)
    exit(OVERFLOW);
  p->data = e;
  p->next = NULL;
  Q.rear->next = p;
  Q.rear = p;
}

Status DeQueue(LinkQueue &Q, QElemType &e){ //🌈 删除为队头
  QueuePtr p;
  if(Q.front == Q.rear)
    return ERROR;
  p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if(Q.rear == p) //如果队列仅剩一个元素
    Q.rear = Q.front;
  free(p);
  return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType)){ //指针函数❤️
  QueuePtr p = Q.front->next;
  while(p){
    visit(p->data); //对p所指元素调用visit
    p = p->next;
  }
  printf("\n");
}
