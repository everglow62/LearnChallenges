//ջ��˳��洢�ṹ
#define STACK_INIT_SIZE 10 //��ʼ�ռ������
#define STACK_INCREMENT 2 //�洢�ռ��������

struct SqStack{ //˳��ջ
  SElemType *base;
  SElemType *top;
  int stacksize;  //�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
};
