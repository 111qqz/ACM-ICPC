/*************************************************************************
	> File Name: code/2015summer/#5/AA.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 16时26分55秒
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
LL l,v1,v2,t,mxv,miv;
int main()
{
    cin>>l>>v1>>v2>>t;
    mxv=max(v1,v2);
    miv=min(v1,v2);
    double ans;
    ans = t*1.0/(l*1.0/mxv);
    LL ians = int(ans);
    LL beishu = -1;
    //if (mxv%miv==0)
  //  {
//	if ((mxv/miv)%2==0)
//	{
//	    beishu = mxv/miv;
//	}
//    }
    int k = -1;
    if (mxv!=miv&&l%(mxv-miv)==0)
    {
	k = l/(mxv -miv);
    }
    int i = 1;
 //   cout<<"k:"<<k<<endl;
    while (i*k<ians&&k!=-1)
    {
	ians--;
	i=i+2;
    }
    double dis;
//     cout<<"beishu:"<<beishu<<endl;
    dis = miv*(l*1.0/mxv)*ians;  //慢的车走的距离
    LL num=0; //慢的车走了几趟
 //    cout<<"dis:"<<dis<<endl;
 //   if (ians>=1&&beishu!=-1)
  //  {
//	ians = ians-(ians-1)/beishu;
  //  }
    while (dis>=l*1.0)
    {
	num++;
	dis = dis - l *1.0;
    }
    double rt; //走完整数后的剩余时间
    rt = t*1.0-ians*(l*1.0/mxv);
  //    cout<<"ians:"<<ians<<endl;
   //   cout<<"rt:"<<rt<<endl;
  //    cout<<"num:"<<num<<endl;
  //    cout<<"dis:"<<dis<<endl;
    bool org; //慢的车是否在初始端
    if (num%2==0)
    {
	org = true;
    }
    else
    {
	org = false;
    }
    if (ians%2==0)  //快车在初始端
    {
	if (org)
	{
//	    cout<<"111111111111"<<endl;
	    if (rt*mxv+dis*1.0+rt*miv>=l*1.0)
	    {
		ians++;
	    }
	}
	else
	{
	    if (dis==0)
	    {
		cout<<ians<<endl;
		return 0;
	    }
//	    cout<<"22222222222222"<<endl;
	    if (rt*mxv>=dis*1.0+rt*miv)
	    {
		ians++;
	    }
	}
    }
    else
    {
	if (org)
	{
	    if (dis==0)
	    {
 		cout<<ians<<endl;
		return 0;
	    }
//	    cout<<"333333333333"<<endl;
	    if (rt*mxv>=dis*1.0+rt*miv)
	    {
		ians++;
	    }
	}
	else
	{
//	    cout<<"44444444444444"<<endl;
	    if (rt*mxv+dis*1.0+rt*miv>=l*1.0)
	    {
		ians++;
	    }
	}
     }

    
    cout<<ians<<endl;
	return 0;
}
