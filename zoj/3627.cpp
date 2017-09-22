/*************************************************************************
	> File Name: code/zoj/3627.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月24日 星期六 17时00分25秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;

const int N=1E5+7;
LL sum[N],v[N];

int n,t,m,p;
LL cal( int l,int r)
{
    l = max(1,l);
    r = min(n,r);//边界处理
    return sum[r]-sum[l-1];
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&p)!=EOF)
   {
       sum[0] = 0;
       for ( int i = 1 ; i <= n ; i++)
     {
	 scanf("%lld",&v[i]);
	 sum[i] = sum[i-1] + v[i];
     }
       
       scanf("%d %d",&m,&t);    
       int now = m ;
       int l,r;
       l=r=p;
       while (now>=2 &&t>0)  //在到达距离m之前（m为偶数）或m-1之前（m为奇数）时,同时往两边走
	{
	    l--;
	    r++;
	    t--;
	    now = now - 2;

	}
       LL ans = cal(l,r);   //在往两边走的过程中已经用完时间
       LL res;
       int mr,ml;
       for ( int i = 1 ; i <= t ; i++)  //先往右边走，分配时间
	{
	    mr = r+i;
	    int  tmp = r-m-(t-2*i); //往右走i时间，再回来还需要i时间
				    //此时还剩t-2*i时间，可以让之前再r-m位置的向左走到tmp位置
	    ml = min(l,tmp);	    //即使tmp比l大，tmp~l的部分再之前往两边走的过程中已经取过了，所以作端点至少为l
				    //换言之，要的是分配i时间走右边的时候能走的最长的那个区间
	    res = cal(ml,mr);
	    ans = max(ans,res);
	   // cout<<"mr:"<<mr<<"tmp:"<<tmp<<" ml:"<<ml<<endl;
	}

       for ( int i = 1 ; i <= t ; i++) //先往左边走，分配时间，同理。
       {
	   ml = l-i;
	   int tmp = l+m+(t-2*i);
	   mr =max(r,tmp);
	   res = cal(ml,mr);
	   ans = max(ans,res);
       }
       printf("%lld\n",ans);
}
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
