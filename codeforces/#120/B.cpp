/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 12时24分37秒
File Name :code/cf/#120/B.cpp
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
int a,b,c;
int d,e,f;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a>>b>>c;
	cin>>d>>e>>f;
	int dis = (a-d)*(a-d)+(b-e)*(b-e);
	double ans;
//	cout<<"dis:"<<dis<<endl;
	if (dis>c*c+2*c*f+f*f)
	{
	    ans = sqrt(dis)-c*1.0-f*1.0;
	    ans = ans /2.0;
	    printf("%.10f\n",ans);
	}
	else if (dis==c*c+2*c*f+f*f)
	{
	    puts("0.0000000000000");
	}
	else
	{
	    ans = c*1.0+f*1.0-sqrt(dis);
	    ans = ans / 2.0;
	    printf("%.10f/n",ans);
	}


	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
