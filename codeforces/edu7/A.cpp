/* ***********************************************
Author :111qqz
Created Time :2016年02月10日 星期三 22时57分31秒
File Name :code/cf/edu7/A.cpp
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
LL n;
LL cal(LL x)
{
    return x*(x+1)/2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	double k = sqrt(2*n);
	LL p = LL (k);
//	cout<<"p:"<<p<<endl;
	LL d;
	LL q;
	for ( LL i = p ; i <=p+10 ; i++ )
	{
	    LL tmp = i*(i+1);
	    if (tmp>=2*n)
	    {
		d =  i;
		break;
	    }
	}
//	cout<<"d:"<<d<<endl;
	q = n-cal(d-1);
	cout<<q<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
