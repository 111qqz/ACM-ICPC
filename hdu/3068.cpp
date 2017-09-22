/* ***********************************************
Author :111qqz
Created Time :2016年04月18日 星期一 14时06分59秒
File Name :code/hdu/3068.cpp
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
const int N=2E6+999;
char st[N];
int p[2*N];  //p[i]为以第i个位置的字符为中心的回文串的半径长，默认为1.


int manachar( char *s)
{
    int len = strlen(s);
    int id = 0; //id表示之前位置的能延伸到最远位置的字符串的中心位置。
    int maxlen = 0 ;  //maxlen是为了更新答案而用。。。就是记录了一个最大值。。。
    int mx = 0 ;//mx为当前位置之前的回文串能延伸到的最远位置 即：max(p[j]+j) (j<i)
                //如果知道之前能延伸到最远位置的字符串的中心位置的下标为id，那么就是p[id]+id;
    for ( int i = len ; i >= 0 ; i--)  //插入'#'是为了将字符串长度奇偶性不同的统一考虑。
    {
	s[i+i+2] = s[i];
	s[i+i+1] = '#';
    }
    s[0]='*'; //s[0] ='*'以及用字符数组最后默认的s[len+len+2]='\0'是为了下面while 循环的时候不溢出。。
		//两边的字符一定要不一样。。用string的话记得两边都加字符。。。
    for ( int i = 2 ; i < 2*len+1 ; i++)
    {
	if (p[id]+id>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;
	while (s[i-p[i]]==s[i+p[i]]) p[i]++;
	if (id+p[id]<i+p[i]) id = i;
	if (maxlen<p[i]) maxlen = p[i];
    }
    return maxlen-1;  
    //这道题是问最长回文串的长度。。。如果是问回文串是什么的话。。。根据id和maxlen也可以构造出来。。。
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%s",st))
	{
	   int ans = manachar(st);
	   printf("%d\n",ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
