/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 12时12分39秒
File Name :A.cpp
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
#define PB push_back
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
int cnt[105]={};
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    cin>>x;
	    cnt[x]++;
	}
	int x=-1,y=-1;
	int num = 0;
	bool die = false;
	for ( int i = 1 ; i <= 100 ; i++)
	{
	    if (cnt[i]>0)
	    {
		num++;
	    }
	    if (num==1&&x==-1) x = i;
	    if (num==2&&y==-1) y = i;
	    if (num>2)
	    {
		die = true;
		break;
	    }
	}
	if (die||cnt[x]!=cnt[y]) 
	{
	    puts("NO");
	}
	else
	{
	    puts("YES");
	    printf("%d %d\n",x,y);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
