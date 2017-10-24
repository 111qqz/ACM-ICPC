/* ***********************************************
Author :111qqz
Created Time :2017年10月24日 星期二 18时02分41秒
File Name :E.cpp
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
#define PB push_back
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
int n,m,q;

struct Rec
{
    int left,top;
};
void prset( multiset<int>se)
{
    for ( auto it =se.begin () ; it !=se.end() ; it++)
	printf("%d ",*it);
    puts("");
}
multiset<int>X,Y; //维护左边界的横坐标和上坐标的纵坐标
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>m>>q;
	int r1,r2,c1,c2;
	X.insert(0);
	X.insert(n+1);
	Y.insert(0);
	Y.insert(m+1);
	int opt;
	while (q--)
	{
	    scanf("%d%d%d%d%d",&opt,&r1,&r2,&c1,&c2);
	    if (opt==1)
	    {
		X.insert(r1);
		Y.insert(c2);
	    }else if (opt==2)
	    {
		auto it = X.find(r1);
		X.erase(it);
		auto it2 = Y.find(c2);
		Y.erase(it2);
	    }else
	    {
		auto itx = X.lower_bound(r1);
		auto ity = Y.lower_bound(r2);
		auto itx2 = X.lower_bound(c1);
		auto ity2 = Y.lower_bound(c2);
		cout<<"X Y:"<<endl;
		cout<<*itx<<" "<<*itx2<<endl;
		cout<<*ity<<" "<<*ity2<<endl;
		if (itx==itx2&&ity==ity2)
		{
		    puts("Yes");
		}
		else
		{
		    puts("No");
		}
	    }
	    prset(X);
//	    prset(Y);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
