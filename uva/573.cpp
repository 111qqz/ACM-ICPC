/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 19时29分21秒
File Name :code/uva/573.cpp
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
int h,u,d,f;

int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d %d %d %d",&h,&u,&d,&f)!=EOF)
	{
	    if (h==0) break;

	    double curh = 0 ;
	    double hpd =  u;
	    for ( int i = 1 ; ; i++)
	    {
		curh+=hpd;
	//	cout<<"curh:"<<curh<<" hpd:"<<hpd<<endl;
		if (dblcmp(curh-h)>0)
		{
		    printf("success on day %d\n",i);
		    break;
		}
		
		curh-=d;
		if (dblcmp(curh)<0)
		{
		    printf("failure on day %d\n",i);
		    break;
		}
		hpd -=f*1.0/100*u;
		if (dblcmp(hpd)<0) hpd = 0 ;
	    }
	    //cout<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
