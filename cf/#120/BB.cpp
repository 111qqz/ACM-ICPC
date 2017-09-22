/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 12时53分05秒
File Name :code/cf/#120/BB.cpp
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
int a,b,r1;
int c,d,r2;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a>>b>>r1;
	cin>>c>>d>>r2;
	double dis = sqrt((a-c)*(a-c)+(b-d)*(b-d));
	double r = r1+r2;
	if (dblcmp(r-dis)==0)
	{
	    puts("0.0000000000000000");
	    return 0;
	}

	if (dblcmp(r-dis)<0)
	{
	    double ans = (dis-r)*0.5;
	    printf("%.16f\n",ans);
	}
	if (dblcmp(r-dis)>0)
	{
	    if (dblcmp(dis-abs(r1-r2))>=0)
	    {
		puts("0.00000000000000");
	    }
	    if (dblcmp(dis-abs(r1-r2))<0)
	    {
		double ans = (abs(r1-r2)-dis)*0.5;
		printf("%.15f\n",ans);
	    }
	    
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
