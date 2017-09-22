/*=============================================================================
#     FileName: multi-fillbox.c
#         Desc: multithread search and compute, let the big balloon in the front list
#       Author: d4smart
#        Email: d4smart@foxmail.com
#     HomePage: https://github.com/d4smart/box-filling
#      Version: 0.0.2
#   LastChange: 2016-05-31 9:33
=============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#define true 1
#define false 0

//存储气球的信息
typedef struct _Ball {
  double x;
  double y;
  double r;
} Ball;

//使用链表存储已经放入区间的球
typedef struct _listNode {
  struct _listNode * next;
  int isblock;	//是否为微小块
  Ball ball;
} listNode;

//向search传递参数的结构体
typedef struct _PM {
  float startx;
  float starty;
  float endx;
  float endy;
} PM;


void insert(Ball ball, int isblock);	//向链表中插入气球和点，半径大的在前
double distance(Ball b1, Ball b2);	//计算两个气球间的距离
double m_abs(double num);	//计算num的绝对值
int judge(Ball b);	//判断气球是否不与所有已放置的气球重叠
void freeBox();		//释放链表内存
void putBall();		//放置气球
void search(void *pm);	//在给定区间内搜索可以放置的最大的气球
void putBlock(double x, double y);	//向空间放入微小块


listNode *head = NULL, *tail = NULL;    //链表头指针
Ball maxBall;	        //用来存储最大的气球
double step = 1/128.0;	//搜索步长,浮点数表示1/128没有误差  //???
int num = 0;		//计数
double r2 = 0;		// ∑r^2
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	//互斥锁
int flag = true;	//记录第一个气球是否已经放置，未放为1


int main(int argc, char *argv[])
{
  int n, blocks, i;
  pthread_mutex_init(&mutex,NULL);	//互斥锁初始化

  printf("\n\nEnter the number of balls and blocks (to put blocks add number and position): ");
  while(scanf("%d%d", &n, &blocks) != EOF)
  {
    num = 0, r2 = 0;
    head = NULL, tail = NULL;

    //放置微小块
    for(i = 0; i < blocks; i ++)
    {
      double x, y;
      scanf("%lf%lf", &x, &y);
      putBlock(x, y);
    }

    printf("\nnum\t x\t  y\t  r\t sum(r^2)\n");

	//在区间内依次放入n个气球
    for(i = 0; i < n; i ++)
    {
      putBall();
    }

    freeBox();	//释放链表内存
    printf("\nsum of R^2:\t %lf\n", r2);        //输出计算结果
    flag = true;

    printf("\n\nEnter the number of balls and blocks (to put blocks add number and position): ");
  }

  printf("\n");
  return 0;
}

void putBlock(double x, double y)
{
  Ball ball = {x, y, 0};
  insert(ball, true);
}

void freeBox()
{
  printf("Ball.r: ");

  while(head)
  {
    listNode *tmp = head;
    head = tmp->next;
    printf("%lf ", tmp->ball.r);
    free(tmp);
  }
}

void insert(Ball ball, int isblock)
{
  listNode * node = (listNode *)malloc(sizeof(listNode));
  
  //放置点或第一个气球，head与tail均指向链表头
  if (isblock || flag) {
    node->isblock = isblock;
    node->ball = ball;
    node->next = head;
    head = node;
    tail = head;
    if ((!isblock) && flag) {
      flag = false;	//改变flag，标记第一个气球放置
    }
  }
  //放置其他气球，使head指向链表头，tail指向最后一个气球
  else {
    node->isblock = isblock;
    node->ball = ball;
    node->next = tail->next;
    tail->next = node;
    tail = node;
  }
}

void putBall()
{
  int i;
  pthread_t thread[4];
  PM *pm[4];
  for (i = 0; i < 4; i++) {
    pm[i] = (PM*)malloc(sizeof(PM));
  }
  Ball ball = {-1, -1, 0};
  maxBall = ball;
  pm[0]->startx=-1, pm[0]->starty=-1, pm[0]->endx=0, pm[0]->endy=0;
  pm[1]->startx=-1, pm[1]->starty=0, pm[1]->endx=0, pm[1]->endy=1;
  pm[2]->startx=0, pm[2]->starty=-1, pm[2]->endx=1, pm[2]->endy=0;
  pm[3]->startx=0, pm[3]->starty=0, pm[3]->endx=1, pm[3]->endy=1;

  //创建4个线程，搜索4个区域
  pthread_create (&thread[0], NULL, (void*)search, (void*)pm[0]);
  pthread_create (&thread[1], NULL, (void*)search, (void*)pm[1]);
  pthread_create (&thread[2], NULL, (void*)search, (void*)pm[2]);
  pthread_create (&thread[3], NULL, (void*)search, (void*)pm[3]);
  pthread_join (thread[0], NULL);
  pthread_join (thread[1], NULL);
  pthread_join (thread[2], NULL);
  pthread_join (thread[3], NULL);
  
  if(judge(maxBall)) {
    insert(maxBall, false);
    num++;
    r2 += maxBall.r * maxBall.r;
      printf("%d\t %.3lf\t %.3lf\t %.3lf\t %lf \n", num, maxBall.x, maxBall.y, maxBall.r, r2);
  }
}

void search(void *p)
{
  int i, j; 
  PM *pm = (PM*)p;
  Ball ball = {pm->startx, pm->starty, 0};

  //pthread_mutex_lock(&mutex);	//进入临界区
  for (i = 0; ball.x <= pm->endx; ++i) {
    ball.x += step;
    ball.y = -1;
    for (j = 0; ball.y <= pm->endy; ++j) {
      ball.y += step;
      ball.r = 0;
      double rstep = 0.1;
      while(rstep >= 0.00001)
      {
        if(ball.r > maxBall.r)
        {
	  pthread_mutex_lock(&mutex);	//进入临界区
          maxBall = ball;
	  pthread_mutex_unlock(&mutex);	//离开临界区
        }
        /*printf("%lf, %lf, %lf\n",ball.x, ball.y, ball.r);*/
        ball.r += rstep;
        if(!judge(ball))
        {
          ball.r -= rstep;
          rstep /= 10;
        }
      }
    }
  }
  //pthread_mutex_unlock(&mutex);	//离开临界区
}

int judge(Ball b)
{
  //是否超出区间
  if((m_abs(b.x) + b.r) > 1 || (m_abs(b.y) + b.r) > 1)
  {
    return false;
  }

  //检查是否与所有已经放置的气球都不重叠
  listNode *tmp = head;
  while(tmp)
  {
    Ball ball = tmp->ball;
    if(distance(b, ball) < b.r + ball.r )
    {
      return false;
    }
    tmp = tmp->next;
  }

  return true;
}

double m_abs(double num)
{
  if(num > 0)
    return num;
  return 0 - num;
}

double distance(Ball b1, Ball b2)
{
  double x1 = b1.x;
  double y1 = b1.y;
  double x2 = b2.x;
  double y2 = b2.y;
  return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}
