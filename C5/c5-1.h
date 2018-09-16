// 数组的顺序存储结构

#define MAX_ARRAY_DIM 8

struct Array {
  ElemType *base;
  int dim;  //数组的维数
  int *bounds;  //数组维界基址
  int *constants; //数组映像函数常量基址
};

/*
*base:

数组元素基址,以二维数组A为例,将数组(按行或者按列)拉成一个向量L所组成的线性结构的首地址.

*bounds:

数组维界地址,指向一个一维数组B,它存放了数组A各维度元素的数目.假设数组A是(3,4,5)大小的, 则数组B=[3,4,5]

*constants:

数组映像函数常量基址,指向一个数组C, 它存放了"数组A各个维度上的数字加一时, 元素在线性结构L上所移动的距离
*/
