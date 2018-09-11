//单链队列，链式存储结构
typedef struct QNode{
  QElemType data;
  QNode *next;
} *QueuePtr;

struct LinkQueue{
  QueuePtr front, rear;
}
