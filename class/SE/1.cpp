/* ***********************************************
Author :111qqz
Created Time :2016年05月23日 星期一 13时35分57秒
File Name :code/class/SE/1.cpp
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
const int quax[4]={1,-1,-1,1};
const int quay[4]={1,1,-1,-1};
const int N=20; 
struct circle
{
    double x,y;
    double r;
    circle(){}
    circle(double _x,double _y,double _r)
    {
	x=_x;
	y=_y;
	r=_r;
    }

    void out()
    {
	printf("(%10f,%10f)   r=%10f\n",x,y,r*r);
    }
    

}cir[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cir[1]=circle(0,0,1);
	double x,y,r;
	x=2.0*sqrt(2.0)-2.0;
	y=x;
	r =3.0-2*sqrt(2.0);
	for ( int i = 2 ; i <= 5 ; i++)
	{
	    cir[i]=circle(x*quax[i-2],y*quay[i-2],r);
	}

	for ( int i = 1 ; i <= 5 ; i++)
	{
	    cir[i].out();
	}

//	cout<<"12-8sqrt(2):"<<12.0-8.0*sqrt(2.0)<<endl;
	
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
