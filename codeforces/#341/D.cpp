/* ***********************************************
Author :111qqz
Created Time :2016年02月08日 星期一 03时38分46秒
File Name :code/cf/#341/D.cpp
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
double x,y,z;
string ans[20];

double cal( double a,double b,double c)
{
    return c*log(b)+log(log(a));
}
double cal2(double a,double b,double c)
{
    return log(b*c*log(a));
}


void pre()
{
    ans[1] = "x^y^z";
    ans[2] = "x^z^y";
    ans[5] = "y^x^z";
    ans[6] = "y^z^x";
    ans[9] = "z^x^y";
    ans[10]= "z^y^x";


    ans[3] ="(x^y)^z";
    ans[4] ="(x^z)^y";
    ans[7] ="(y^x)^z";
    ans[8] ="(y^z)^x";
    ans[11]="(z^x)^y";
    ans[12]="(z^y)^x";
}
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct node
{
    double val;
    int id;
    node()
    {
	val = -9999999;  //初始化是0不够小，虽然最大值一定大于0，但是比较的时候由于取了两次对数所以不一定大于0.
    }

    bool operator <(node b)const
    {
	int d = dblcmp(val-b.val);
	if (d>0) return true;
	if (d==0&&id<b.id) return true;
	return false;
    }

}a[20];



bool cmp(node a,node b)
{
    int d = dblcmp(a.val-b.val);
    if (d<0) return true;
    if (d==0&&a.id<b.id) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	cin>>x>>y>>z;
	pre();
	for ( int i = 1 ; i <= 12 ; i ++) a[i].id = i ;
	int cnt = 0 ;
	
	if (x>1)
	{
	    
	    a[1].val = cal(x,y,z);
	  //   cout<<"a[1].val:"<<a[1].val<<endl;
    
	    a[2].val = cal(x,z,y);
	    
	    a[3].val = cal2(x,y,z);
	  //  cout<<"a[3].val:"<<a[3].val<<endl;
	    
	    a[4].val = cal2(x,z,y);
	}
	if (y>1)
	{
	    a[5].val = cal(y,x,z);
	    a[6].val = cal(y,z,x);
	    a[7].val = cal2(y,x,z);
	    a[8].val = cal2(y,z,x);
	}
	if (z>1)
	{
	    a[9].val = cal(z,x,y);
	    a[10].val = cal(z,y,x);
	    a[11].val = cal2(z,x,y);
	    a[12].val = cal2(z,y,x);
	}

	if (x>1||y>1||z>1)
	{
	    sort(a+1,a+13);
	}
	else
	{
	    a[1].val = cal(1.0/x,y,z);
    
	    a[2].val = cal(1.0/x,z,y);
	    
	    a[3].val = cal2(1.0/x,y,z);
	    
	    a[4].val = cal2(1.0/x,z,y);
	    
	    a[5].val = cal(1.0/y,x,z);
	    a[6].val = cal(1.0/y,z,x);
	    a[7].val = cal2(1.0/y,x,z);
	    a[8].val = cal2(1.0/y,z,x);

	    a[9].val = cal(1.0/z,x,y);
	    a[10].val = cal(1.0/z,y,x);
	    a[11].val = cal2(1.0/z,x,y);
	    a[12].val = cal2(1.0/z,y,x);
	//    for ( int i = 1 ; i <=12 ; i++) cout<<a[i].val<<endl;
	    sort(a+1,a+13,cmp);
	    
	}

	cout<<ans[a[1].id]<<endl;
	
	

	


	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
