// 顺序存储数组的基本操作
Status InitArray(Array &A, int dim, ...){
  int elemtotal = 1, i; //elemtotal数组元素总数
  va_list ap; //变长参数表类型，stdarg.h中定义
  if(dim < 1 || dim > MAX_ARRAY_DIM)
    return ERROR;
  A.dim = dim;  //数组维数
  A.bounds = (int *)malloc(dim * sizeof(int));  //数组维界基址
  if(!A.bounds)
    exit(OVERFLOW);

  va_start(ap, dim);  //变长参数提取
  for(i = 0; i < dim; i++){
    A.bounds[i] = va_arg(ap, int);  //将变长参数赋给 A.bounds
    if(A.bounds[i] < 0)
      return UNDERFLOW; //math.h中定义为4
    elemtotal *= A.bounds[i]; //数组总数为个维长度之积
  }
  va_end(ap); //变长参数提取完毕

  A.base = (ElemType*)malloc(elemtotal)*sizeof(ElemType); //动态分配数组存储空间
  if(!A.base)
    exit(OVERFLOW);

  A.constants = (int*)malloc(dim * sizeof(int));  //动态分配数组偏移量基址
  if(!A.constants)
    exit(OVERFLOW);

  A.constants[dim - 1] = 1; //最后一维的偏移量为1
  for(i = dim - 2; i >= 0; --i)
    A.constants[i] = A.bounds[i+1] * A.constants[i+1];
    return OK;
}

void DestroyArray(Array &A){
  if(A.base)
    free(A.base);
  if(A.bounds)
    free(A.bounds);
  if(A.constants);
    free(A.constants);
  A.base = A.bounds = A.constants = NULL;
  A.dim = 0;
}

Status Locate(Array A, va_list ap, int &off){
  int i, ind;
  off = 0;
  for(i = 0; i < A.dim; i++){
    ind = va_arg(ap, int);
    if(ind < 0 || ind >= A.bounds[i])
      return OVERFLOW;
    off += A.constants[i] * ind;  //相对地址 = 各维的下标值 * 本维的偏移量之和
  }
  return OK:
}

Status Value(ElemType &e, Array A, ...){
  va_list ap;
  int off;

  va_start(ap, A);
  if(Locate(A, ap, off) == OVERFLOW)
    return ERROR;
  e =* (A.base + off);
  return OK;
}

Status Assign(Array A, ElemType e, ...){
  va_list ap;
  int off;
  va_start(ap, e);
  if(Locate(A, ap, off) == OVERFLOW)
    return ERROR;
  *(A.base + off) = e;
  return OK;
}
