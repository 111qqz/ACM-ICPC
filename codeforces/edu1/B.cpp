/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 14时24分56秒
File Name :code/cf/edu/B.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E4+7;

char st[N];
int len;
int m;
int l,r,k;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%s",st);
	scanf("%d",&m);
	while (m--)
	{
	    scanf("%d %d %d",&l,&r,&k);
	    l--;
	    r--; //强行让下标从0开始。。。处理起来方便
	    int len = r-l+1;
	    k = k % len;
	    char tmp[N];

	    for ( int i = l ; i <= r ; i++)
	    {
		int offset = (i-l+len-k)%len;
		tmp[i] = st[offset+l];
	    }
	    for ( int i = l; i <= r ; i++) st[i] = tmp[i];

//	    printf("%s\n",st);
	}
	printf("%s\n",st);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
