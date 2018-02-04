/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 16时28分28秒
File Name :code/cf/problem/14C.cpp
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
int a,b,c,d;
int l[10];
int cnt;



struct point 
{
    int x,y;
    
    bool operator <(point p)const
    {
	if (x<p.x) return true;
	if (x==p.x&&y<p.y) return true;
	return false;
    }
    bool ok (point p)
    {
	if (x!=p.x&&y!=p.y) return false; //不平行
	if (x==p.x&&y==p.y) return false; //退化成一点
	if (x==p.x) cnt++;
	return true;
    }

    bool operator ==(point p)const
    {
	return x==p.x&&y==p.y;
    }
    bool operator !=(point p)const
    {
	if (x!=p.x||y!=p.y) return true;
	return false;
    }
}p[10];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	bool ok=true;
	cnt =  0 ;
	for ( int i = 0 ; i < 4 ; i++)
	{
	    cin>>p[i].x>>p[i].y>>p[i+4].x>>p[i+4].y;
	    if (!p[i].ok(p[i+4]))
	    {
		ok = false;
	    }
	}
	if (!ok||cnt!=2)
	{
	    puts("NO");

	}
	else
	{
	    sort(p,p+8);
	    if (p[0]==p[1]&&p[2]==p[3]&&p[4]==p[5]&&p[6]==p[7]&&p[0]!=p[2]&&p[2]!=p[4]&&p[4]!=p[6]) //两两重合后保证四个点
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
