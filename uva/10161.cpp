/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 03时34分14秒
File Name :code/uva/10161.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n)&&n)
	{
	  int  k = int(sqrt(n-0.5))+1;
	  int  p = k*k-k+1;
	  if (n>p)
	  {
	      if (k%2==1)
	      printf("%d %d\n",k-(n-p),k);
	      else printf("%d %d\n",k,k-(n-p));
	  }
	  else
	    {
		if (k%2==1)
		printf("%d %d\n",k,k-(p-n));
		else printf("%d %d\n",k-(p-n),k);
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
