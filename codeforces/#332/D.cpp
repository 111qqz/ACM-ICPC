/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 15时54分37秒
File Name :code/cf/#332/D.cpp
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
#define pi pair < LL ,LL >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
LL x;
LL cur;
const LL MAXN = 1442550;
set<pi>se;
LL cal( LL n,LL m)
{
    LL res = -n*n*n+3*n*n*m+3*n*m+n;
    return res;
}
int square = -1;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	for ( LL i = 1 ; ; i++)
//	{
//	    cur = cal(i,i);
//	  //  cout<<"i:"<<i<<" cur:"<<cur<<endl;
//	    if (cur>1E18)
//	    {
//		cout<<i<<endl;
//		break;
//	    }
//
//	}
	cin>>x;
	x = x*6;
	for ( LL i = 1 ; cal(i,i)<=x ; i++)
	{
	    LL tmp = (x-i+i*i*i)%(3*i*i+3*i);
	  //  cout<<"i:"<<i<<" tmp:"<<tmp<<endl;
	    if (tmp==0)
	    {
		se.insert(make_pair(i,(x-i+i*i*i)/(3*i*i+3*i)));
		if (i==(x-i+i*i*i)/(3*i*i+3*i)) square = 1;

	    }
	}
	if (square==1)
	cout<<se.size()*2-1<<endl;
	else cout<<se.size()*2<<endl;
	set<pi>::iterator it;
	for (it = se.begin(); it!=se.end() ;it++)
	{

	    cout<<(*it).fst<<" "<<(*it).sec<<endl;
	}
	set<pi>::reverse_iterator it2;   //反向遍历要用反向迭代器。。。右忘记了。。。。
	for ( it2 =se.rbegin() ;it2 !=se.rend() ; it2 ++)
	{
	    if (square==1)
	    {
		square = 2;
		continue;
	    }

	    
	    cout<<(*it2).sec<<" "<<(*it2).fst<<endl;
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
