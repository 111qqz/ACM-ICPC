/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 15时10分01秒
File Name :code/cf/#333/B.cpp
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
const int N=1E5+7;
int n ;
int a[N];

void ruler()
{
    int head = 1;
    int tail = 1;
    int ans = -1;
    multiset<int>se;
    while (tail<=n)
    {
	se.insert(a[tail]);
//	cout<<"tail:"<<tail<<" a[tail]:"<<a[tail]<<" "<<endl;
//	cout<<"min:"<<*se.begin()<<" max:"<<*se.end()<<endl;
	if (abs(*se.begin()-*se.rbegin())>1)
	{
	    se.erase(se.find(a[head]));//这样写是删除multiset中的一个元素，写成se.erase(a[head])会删除掉所有的。
					//删掉一个就可以。虽然删掉一个不一定使得满足最大值和最小值差的绝对值小于等于1
					//但是之前插入一个，现在删除一个，区间长度没有变，就是不会对当前答案有影响。
	    head++;
	}
	ans = max(ans,int(se.size()));

//	cout<<"size:"<<int(se.size())<<"head:"<<head<<" tail:"<<tail<<endl;
	tail++;

    }
   cout<<ans<<endl;
    multiset<int>::iterator it;

//    for ( it =se.begin() ;it !=se.end() ;it++)
 //   {
//	cout<<*it<<endl;
//    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 1 ; i<= n ; i++) scanf("%d",&a[i]);

//	for ( int i = 1 ; i <= n ; i++) printf("%d %d\n",i,a[i]);
	ruler();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
