/*************************************************************************
	> File Name: code/2015summer/#6/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月31日 星期五 12时32分45秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
int x[10],y[10],z[10];
int bx,by,bz,r;
int x1,x2,y1,y2,z1,z2;
int vx[20],vy[20],vz[20];
double dis(int x1,int x2,int y1,int y2,int z1,int z2)
{
    LL res;
    res = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
  //  cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<z1<<" "<<z2<<" res:"<<res<<endl;

    return sqrt(res);
}
bool ok2 () //在里面判断边重合，在外面判断点重合
{
	
    if (dis(bx,x1,by,by,bz,bz)<=r&&by>=y1&&by<=y2&&bz>=z1&&bz<=z2)
	return false;
    if (dis(bx,x2,by,by,bz,bz)<=r&&by>=y1&&by<=y2&&bz>=z1&&bz<=z2)
	return false;
    if (dis(bx,bx,y1,by,bz,bz)<=r&&bx>=x1&&bx<=x2&&bz>=z1&&bz<=z2)
	return false;
    if (dis(bx,bx,y2,by,bz,bz)<=r&&bx>=x1&&bx<=x2&&bz>=z1&&bz<=z2)
	return false;
    if (dis(bx,bx,by,by,z1,bz)<=r&&bx>=x1&&bx<=x2&&by>=y1&&by<=y2)
	return false;
    if (dis(bx,bx,by,by,z2,bz)<=r&&bx>=x1&&bx<=x2&&by>=y1&&by<=y2)
	return false;
    for ( int i = 0 ; i  < 8 ; i++ )
    {
	
	if (dis(bx,x[i],by,y[i],bz,z[i])<=r)
	    return false;
    }
    return true;
}
bool ok()
{

 //   if (bx-r>x1&&bx+r<x2&&by-r>y1&&by+r<y2&&bz-r>z1&&bz+r<z2)
 //   {
//	return true;
  //  }
   // if ((bx-r>x2||bx+r<x1)||(by-r>y2||by+r<y1)||(bz-r>z2||bz+r<z1))
    if (x1>=bx-r&&x1<=bx+r&&by>=y1&&by<=y2&&bz>=z1&&bz<=z2) return false;
    if (y1>=by-r&&y1<=by+r&&bx>=x1&&bx<=x2&&bz>=z1&&bz<=z2) return false;
    if (z1>=bz-r&&z1<=bz+r&&bx>=x1&&bx<=x2&&by>=y1&&by<=y2) return false;   //面穿球了.
    if (x2>=bx-r&&x2<=bx+r&&by>=y1&&by<=y2&&bz>=z1&&bz<=z2) return false;
    if (y2>=by-r&&y2<=by+r&&bx>=x1&&bx<=x2&&bz>=z1&&bz<=z2) return false;
    if (z2>=bz-r&&z2<=bz+r&&bx>=x1&&bx<=x2&&by>=y1&&by<=y2) return false;   //面穿球了.
   // {
//	flag1 = true;
  //  }
  //  if (!flag1)
  //  {
//	cout<<"wadawdasf"<<endl;
  //  }
    
    for ( int i = 0;  i < 8 ; i++ )
	{
	if (dis(bx,x[i],by,y[i],bz,z[i])<=r)
	{
	 //   cout<<dis(2,1,2,1,2,1)<<endl;
//	    cout<<"fuffffffffffffff"<<endl;
//	    cout<<bx<<" "<<x[i]<<" "<<by<<" "<<y[i]<<" "<<bz<<" "<<z[i]<<endl;
	    return false;
	}

    }
    for ( int i = 1 ; i <= 4 ; i++ )
    {
	if (dis(bx,vx[i],by,vy[i],bz,bz)<=r&&bz>=z1&bz<=z2)
	    return false;
    }
    for ( int i = 5 ; i <= 8 ; i++ )
    {
	if (dis(bx,vx[i],by,by,bz,vz[i])<=r&&by>=y1&&by<=y2)
	    return false;
    }
    for ( int i = 9 ; i <= 12 ; i++ )
    {
	if (dis(bx,bx,by,vy[i],bz,vz[i])<=r&&bx>=x1&&bx<=x2)
	    return false;
    }
    
    return true;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	bool edge;
	bool vv;
	for ( int i = 0 ; i < 8 ; i++)
	{
	    scanf("%d %d %d",&x[i],&y[i],&z[i]);
	}
	x1 = x[0];
	y1 = y[0];
	z1 = z[0];
	for ( int i = 1; i < 8 ; i++ )
	{
	    if (x[i]!=x1)
	    {
		x2 = x[i];
	    }
	    if (y[i]!=y1)
	    {
		y2 = y[i];
	    }
	    if (z[i]!=z1)
	    {
		z2 = z[i];
	    }
	}
	if (x1>x2) swap(x1,x2);
	if (y1>y2) swap(y1,y2);
	if (z1>z2) swap(z1,z2);
	vx[1]=x1;vy[1]=y1;
	vx[2]=x1;vy[2]=y2;
	vx[3]=x2;vy[3]=y1;
	vx[4]=x2;vy[4]=y2;
	vx[5]=x1;vz[5]=z1;
	vx[6]=x1;vz[6]=z2;
	vx[7]=x2;vz[7]=z1;
	vx[8]=x2;vz[8]=z2;
	vy[9]=y1;vz[9]=z1;
	vy[10]=y1;vz[10]=z2;
	vy[11]=y2;vz[11]=z1;
	vy[12]=y2;;vz[12]=z2;

	scanf("%d %d %d %d",&bx,&by,&bz,&r);
//	cout<<"x1:"<<x1<<" x2:"<<x2<<" y1:"<<y1<<" y2:"<<y2<<" z1:"<<z1<<" z2:"<<z2<<endl;
	
	    if (ok())
	    {
		cout<<"No"<<endl;
	    }
	    else
	    {
		cout<<"Yes"<<endl;
	    }
    }
  
	return 0;
}
