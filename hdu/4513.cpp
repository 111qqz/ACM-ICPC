/* ***********************************************
Author :111qqz
Created Time :2016年04月18日 星期一 20时32分45秒
File Name :code/hdu/4513.cpp
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
const int N=2E5+7;
int n;
int p[N];
int a[N];

int manacher( int *s)
{
    for ( int i = n ; i >= 0 ; i--)
    {
	s[i+i+2] = s[i];
	s[i+i+1] = 300;
    }
    s[0] = 400;s[2*n+3] =405;

  //  for ( int i = 1 ; i < 2*n+1 ; i++) cout<<"s[i]:"<<s[i]<<endl;
    int id = 0 ;
    int maxlen = 0 ;

    for ( int i = 2 ; i < 2*n +1 ; i++)
    {
	if (p[id]+id>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;

	while (s[i-p[i]]==s[i+p[i]])
	{
	    if (s[i-p[i]]==300)
	    {
		p[i]++;
	    }
	    else if (s[i-p[i]]<300)
	    {
		if (s[i-p[i]]>s[i-p[i]+2]) break;
		p[i]++;
	    }
	
//	    cout<<"aaaaaaaaaooooooo"<<endl;
	}
//	cout<<"p[i]:"<<p[i]<<endl;
	if (id+p[id]<i+p[i]) id = i ;

	if (maxlen<p[i]) maxlen = p[i];
    }
    
    return maxlen-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);
	    for ( int i =  0 ; i < n ; i++) scanf("%d",&a[i]);

	    int ans =manacher(a);
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
