/* ***********************************************
Author :111qqz
Created Time :2016年08月04日 星期四 21时21分23秒
File Name :code/ural/1126.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=15000;
int n,k;
int a[N];
int f[N];
deque<int>dq;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&k);
	n = 0 ;
	do
	{
	    scanf("%d",&a[++n]);
	    if (a[n]==-1)
	    {
		n--;
		break;
	    }
	}
	dq.clear();
	a[0] = inf; //单调队列的哨兵
	dq.push_back(0);
	int x;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( x = dq.front(); x<i-k+1&&x>0 ; x=dq.front()) dq.pop_front() ; //在队首删除过期元素.
	//x>0是防止队列为空。						    //以第i个数为末尾的k个数的开头是i-k+1,在这之前的元素都会过期。
	   
	    for ( x = dq.front(); a[x]<a[i] ; x = dq.front()) dq.pop_back(); //在队尾删除破坏单调性的元素，因为比a[i]早出现并且比a[i]小的
	}

			
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
