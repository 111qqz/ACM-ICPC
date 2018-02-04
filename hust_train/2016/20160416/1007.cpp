/* ***********************************************
Author :111qqz
Created Time :2016年04月16日 星期六 14时15分50秒
File Name :code/hust/20160416/1007.cpp
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
const int N=1E5+7;
int n;
int l;
char st[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d",&l,&n))
	{
	    scanf("%s",st);
	    int cnt = 0 ;
	    for ( int i = 0 ; i < l-1 ; i++)
	    {
		if (st[i]=='.'&&st[i+1]=='.') cnt++;
	    }
	 //   cout<<"cnt:"<<cnt<<endl;
	    for ( int i = 0 ; i < n ; i++)
	    {
		int p;
		char ch;
		scanf("%d %c\n",&p,&ch);
		p--;
		if (st[p]==ch)
		{
		    printf("%d\n",cnt);
		    continue;
		}
		st[p]=ch;
		if (ch=='.')
		{
		    if (p==0)
		    {
			if (st[p+1]=='.')
			    cnt++;
		    }
		    else
		    {
			if (st[p+1]=='.') cnt++;
			if (st[p-1]=='.') cnt++;
		    }
		}
		else
		{
		    if (p==0)
		    {
			if (st[p+1]=='.')
			    cnt--;
		    }
		    else
		    {
			if (st[p+1]=='.') cnt--;
			if (st[p-1]=='.') cnt--;
		    }
		}
		printf("%d\n",cnt);
	    }
    
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
