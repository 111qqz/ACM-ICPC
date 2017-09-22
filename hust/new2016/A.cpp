/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 12时36分15秒
File Name :code/hust/new2016/A.cpp
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
double k;
double sum;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%lf",&k)!=EOF)
	{
	    LL cnt =  0;
	    sum =  0;
	    while (1)
	    {
		cnt++;
		sum += 1.0/cnt;
		cout<<"sum:"<<sum<<endl;
		if (dblcmp(sum-k)>0)
		{
		    cout<<cnt<<endl;
		    break;
		}
	    }
	
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
