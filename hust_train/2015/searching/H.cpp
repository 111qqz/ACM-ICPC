/*************************************************************************
	> File Name: code/2015summer/searching/H.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月27日 星期一 09时11分28秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E2+5;
int A,B,C;
int d[N][N];
bool flag;
struct node
{
    int d,opt,par,prea,preb;
}q[N][N];

void print(int x,int y)
{
 //    cout<<"x:"<<x<<"y:"<<y<<endl;
    if (q[x][y].prea!=-1&&q[x][y].preb!=-1)
    {
// 	  cout<<"who is 111qqz"<<endl;
	  print(q[x][y].prea,q[x][y].preb);
	  if (q[x][y].opt==1){
		printf("FILL(%d)\n",q[x][y].par);
	  }
	  if (q[x][y].opt==2)
	  {
		printf("DROP(%d)\n",q[x][y].par);
	  }
	  if (q[x][y].opt==3)
	  {
		printf("POUR(%d,%d)\n",q[x][y].par,3-q[x][y].par);
	  }
    }

}
void bfs()
{
    memset(q,-1,sizeof(q));
    queue<int>a;
    queue<int>b;
    a.push(0);
    b.push(0);
    q[0][0].d=0;
    while (!a.empty()&&!b.empty())
    {
	  int av = a.front();a.pop();
	  int bv = b.front();b.pop();
// 	  cout<<"av:"<<av<<"bv:"<<bv<<endl;
	  if (av==C||bv==C)
	  {
		flag = true;
		//cout<<"yeah~~~~~~~~~~~~~~~"<<endl;
		cout<<q[av][bv].d<<endl;
// 		cout<<"prea:"<<q[av][bv].prea<<"preb:"<<q[av][bv].preb<<endl;
		print(av,bv);
	  	return;
	  }
	  if (av<A&&q[A][bv].d==-1)
	  {
		q[A][bv].d=q[av][bv].d+1;
		q[A][bv].opt=1;
		q[A][bv].par=1;
		q[A][bv].prea=av;
		q[A][bv].preb=bv;
		a.push(A);
		b.push(bv);
	  }
	  if (av>0&&q[0][bv].d==-1)
	  {
		q[0][bv].d=q[av][bv].d+1;
		q[0][bv].opt=2;
		q[0][bv].par=1;
		q[0][bv].prea=av;
		q[0][bv].preb=bv;
		a.push(0);
		b.push(bv);

	  }
	  if (bv<B&&q[av][B].d==-1)
	  {
		q[av][B].d=q[av][bv].d+1;
		q[av][B].opt=1;
		q[av][B].par=2;
		q[av][B].prea = av;
		q[av][B].preb = bv;
		a.push(av);
		b.push(B);
		
	  }
	  if (bv>0&&q[av][0].d==-1)
	  {
		q[av][0].d=q[av][bv].d+1;
		q[av][0].opt=2;
		q[av][0].par=2;
		q[av][0].prea=av;
		q[av][0].preb=bv;
		a.push(av);
		b.push(0);
	  }

	  if (av+bv<=B&&q[0][av+bv].d==-1)
	  {
		q[0][av+bv].d=q[av][bv].d+1;
		q[0][av+bv].opt=3;
		q[0][av+bv].par=1;
		q[0][av+bv].prea=av;
		q[0][av+bv].preb=bv;
		a.push(0);
		b.push(av+bv);
	  }
	  if (av+bv>B&&q[av-(B-bv)][B].d==-1)   //把1往2里倒入的两种情况
	  {
	  
		int tmp = av-(B-bv);
		q[tmp][B].d=q[av][bv].d+1;
		q[tmp][B].opt=3;
		q[tmp][B].par=1;
		q[tmp][B].prea=av;
		q[tmp][B].preb=bv;
		a.push(tmp);
		b.push(B);
	  }

	  if (bv+av<=A&&q[av+bv][0].d==-1)
	  {
		q[av+bv][0].d=q[av][bv].d+1;
		q[av+bv][0].opt=3;
		q[av+bv][0].par=2;
		q[av+bv][0].prea=av;
		q[av+bv][0].preb=bv;
		a.push(av+bv);
		b.push(0);
	  }
	  if (bv+av>A&&q[A][bv-(A-av)].d==-1)
	  {
		int tmp = bv-(A-av);
		q[A][tmp].d=q[av][bv].d+1;
		q[A][tmp].opt=3;
		q[A][tmp].par=2;
		q[A][tmp].prea=av;
		q[A][tmp].preb=bv;
		a.push(A);
		b.push(tmp);
	  }
    }
}
int main()
{
    
    flag = false;
    cin>>A>>B>>C;
    bfs();
    if (!flag)
    {
	  cout<<"impossible"<<endl;
    }
    
    
	return 0;
}
