// 稀疏矩阵
#define MAX_SIZE 100

struct Triple{
  int i, j; //行下标，列下标
  ElemType e; //非零元素值
};

struct TSMatrix{
  Triple data[MAX_SIZE + 1];  //非零元三元组表，data[0]未用
  int mu, nu, tu; //行数，列数，非零元个数
}
