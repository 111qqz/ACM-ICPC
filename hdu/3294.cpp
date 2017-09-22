/* ***********************************************
Author :111qqz
Created Time :2016年04月18日 星期一 19时40分06秒
File Name :code/hdu/3294.cpp
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
const int N=4E5+7;
char st[N],st2[N];
int p[N];
char ch;

void manacher(char *s)
{
    int len = strlen(s);

    for ( int i = len ;  i>= 0 ; i--)
    {
	s[i*2+2] = s[i];
	s[i*2+1] = '#';
    }

    int id = 0 ;
    int maxlen = 0 ;
    int center = 0 ;
    s[0]='%';
    for ( int i = 2 ; i < 2*len+1 ; i++)
    {
	if (id+p[id]>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;

	while (s[p[i]+i]==s[i-p[i]]) p[i]++;

	if (id+p[id]<i+p[i]) id = i;
	if (p[i]>maxlen)
	{
	    maxlen = p[i];
	    center = i;
	}
    }
    int ans = (maxlen-1);
   // cout<<"ans:"<<ans<<" center:"<<center<<endl;
    if (ans<2)
    {
	puts("No solution!");
    }
    else
    {
	int left = center/2-1-ans/2+(ans%2==0);
	int right = center/2-1+ans/2;
	printf("%d %d\n",left,right);
	for ( int  i = left ; i <= right ; i++) printf("%c",st2[i]);
	printf("\n");
    }
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    
	while (scanf("%c %s\n",&ch,st)!=EOF)
	{
	    int k = ch-'a';
	    int len = strlen(st);
	    for ( int i = 0 ; i < len ; i++)
	    {
		int tmp = (st[i]-'a'-k+26)%26;
		st[i] = char(tmp+'a');
		st2[i] = st[i];
	    }
	//    cout<<"st:"<<st<<endl;
	    manacher(st);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
