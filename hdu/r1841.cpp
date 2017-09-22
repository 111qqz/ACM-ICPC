/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 04时32分08秒
File Name :code/hdu/r1841.cpp
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
#include <deque>
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
const int N=1E6+7;
int n;
char a[N],b[N];
int nxt[N];
void getnxt(char *s)
{
    int i = 0;
    int j = -1;
    int n = strlen(s);
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i]=++j;
	else j = nxt[j];
}
int kmp(char *a,char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    getnxt(b);
    int i = 0 ;
    int j = 0;
    while (i<n&&j<m) //由于不一定哪个是模式串，所以要记得判边界j<m,因为这个而wa了一发
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
    }
 //   if (i==n) //这样才能保证文本串中匹配的是后缀
    return j;
    return 0;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%s",a);
	    scanf("%s",b);
	    int ans = kmp(a,b);
	    ans = max(ans,kmp(b,a));
	    ans = strlen(a)+strlen(b)-ans;
	    printf("%d\n",ans);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
