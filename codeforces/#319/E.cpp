/*************************************************************************
	> File Name: code/cf/#319/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月18日 星期五 20时55分10秒
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
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int n;
int id[N],x[N],y[N];

bool cmp(int a,int b) //id[a] 和id[b]的大小比较定义
{
    if (x[a]<x[b]) return true;
    if (x[a]>x[b]) return  false;
    if (x[a]%2==1) return y[a]<y[b];
    else  return y[a]>y[b];                   //sort的cmp函数原来还可以这么写，长见识了．
    
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++)
    {
	scanf("%d %d",&x[i],&y[i]);
	x[i] /=1000;
	y[i] /=1000;
	id[i] = i;
    }
    sort(id,id+n,cmp);
    for ( int i = 0 ; i < n ; i++)
    {
	printf("%d ",id[i]+1);
    }
    

  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
