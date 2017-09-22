/*************************************************************************
	> File Name: code/poj/2074.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月08日 星期日 10时26分28秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=1E4+6;
int n;

int dblcmp(double d)
{
    return d<-eps ?-1:d>eps;
}
struct node
{
    double x1,x2,y;
}obs[N],house,li;

struct point
{
    double x,y;
};

bool cmp (node a,node b )
{
    return a.x2<b.x2;
}

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%lf %lf %lf",&house.x1,&house.x2,&house.y)!=EOF)
    {
	if (dblcmp(house.x1)==0&&dblcmp(house.x2)==0&&dblcmp(house.y)==0) break;
	scanf("%lf %lf %lf",&li.x1,&li.x2,&li.y);
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++ ) scanf("%lf %lf %lf",&obs[i].x1,&obs[i].x2,&obs[i].y);

	sort(obs,obs+n,cmp);
	double sum = -1 ;
	
	point p1,p2;
	double k;
	bool beblocked = false;
        for ( int i = 0 ;i <n-1 ; i++)   //最后一个只算右端点就行      
	{
	    if (dblcmp(obs[i].y-house.y)>=0||dblcmp(obs[i].y-li.y)<=0) continue;
	    else beblocked = true;
	    if (dblcmp(obs[i].x2-obs[i+1].x1)<0)
	    {                                                                                                   
		if (dblcmp(obs[i].x2-house.x1)==0)
		{
		    p1.x=house.x1; 
		}
		else
		{
		    k = (house.y-obs[i].y)*1.0/(house.x1-obs[i].x2);
		    p1.x = house.x1-(house.y-li.y)/k;

		}
		if (dblcmp(obs[i+1].x1-house.x2)==0)
		{
		    p2.x=house.x2;
		}
		else
		{
		    k = (house.y-obs[i+1].y)*1.0/(house.x2-obs[i+1].x1);
		    p2.x = house.x2-(house.y-li.y)/k;
		}
		p1.x = max(p1.x,li.x1);  //边界维护
		p2.x = min(p2.x,li.x2);
//		cout<<"p1.x:"<<p1.x<<" p2.x"<<p2.x<<endl;
		if (dblcmp(p2.x-p1.x)>0)  //求连续的最大段。。。不是求和。。认真读题。
		{
		    sum = max(sum,p2.x-p1.x);
		    beblocked  = true;
//		    cout<<"sum:"<<sum<<endl;
		}                                             
	    }
	}
	//最后一个特殊处理：
	if (dblcmp(house.x1-obs[n-1].x2)==0)
	{
	    p1.x = house.x1;
	}
	else
	{
	    k = (house.y-obs[n-1].y)/(house.x1-obs[n-1].x2);
	    p1.x = house.x1-house.y/k;
//	    cout<<"k:"<<k<<endl;
	}
//	cout<<"p1.x:"<<p1.x<<" li.x2:"<<li.x2<<" minus:"<<li.x2-p1.x<<endl;
	if (dblcmp(house.y-obs[n-1].y)>0&&dblcmp(li.y-obs[n-1].y)<0)
	    sum = max(sum,li.x2-p1.x),beblocked = true;

	//第一个要要单独处理
	    
	if (dblcmp(house.x2-obs[0].x1)==0)
	{
	    p1.x=house.x2;
	}
	else
	{
	    k = (house.y-obs[0].y)/(house.x2-obs[0].x1);
	    p1.x = house.x2-house.y/k;
//	    cout<<"k:"<<k<<endl;
	}
	if (dblcmp(house.y-obs[0].y)>0&&dblcmp(li.y-obs[0].y)<0)
	    sum = max(sum,p1.x-li.x1),beblocked = true;
        
	if (!beblocked)
	{
	    sum = li.x2-li.x1;
	}
	if (dblcmp(sum)>0)
	{
	    printf("%.2f\n",sum);
	}
	else
	{
	    puts("No View");
	}
	    


    }
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
