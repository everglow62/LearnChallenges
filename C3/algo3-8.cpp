#include "c1.h"
int c = 0;//全局变量，搬动次数

void move(char x, int n, char z){
  //第n个圆盘，从塔座x，搬到塔座z
  printf("第%i步：将%i号盘从%c移到%c \n", ++c, n, x, z);

}

void hanoi(int n, char x, char y, char z){
  //塔座x 上，自上而下圆盘编号为1-> n
  //搬到塔座z 上，塔座y为辅助
  if(n == 1){
    move(x, 1, z); //只有一个盘子，不再递归
  }
  else{
    hanoi(n-1, x, z, y); //n-1 个盘子移到 b

    move(x, n, z); //第 n 个移到 c
    hanoi(n-1, y, x, z); //剩下 n-1 个从 b 移到 c
  }
}

int main(){
  int n;
  printf("3个塔座为a、b、c，圆盘最初在a座，借助b座移到c座。请输入圆盘数：");
  scanf("%d", &n);
  hanoi(n, 'a', 'b', 'c');
}
