/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 20时37分44秒
File Name :code/bc/#70/1004.cpp
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

int lowbit( int x)
{
    return x&(-x);
}:
struct point
{
    int x,y,z;
    void input()
    {
	scanf("%d %d %d",&x,&y,&z);
    }

    bool operator < (point p)const
    {
	if (x<p.x) return true;
	if (x==p.x&&y<p.y) return true;
	if (x==p.x&&y==p.y&&z<p.z) return true;
	return false;
    }
}p[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
