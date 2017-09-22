/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 13时21分33秒
File Name :code/cf/problem/166A.cpp
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
const int N=55;
int n ,k;
struct node
{
    int p,t;
    bool operator==(node a)const
    {
	return a.p==p&&a.t==t;
    }
    bool operator<(node a)const
    {
	return p>a.p||(a.p==p&&t<a.t);
    }

    void input()
    {
	scanf("%d %d",&p,&t);
    }

    void ouput()
    {
	printf("%d %d\n",p,t);
    }
}q[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>k;

	q[0].p = -1;
	q[n+1].p = -1;
	for ( int i = 1 ; i <= n ; i++) q[i].input();

	sort(q+1,q+n+1);

//	for ( int i =  1 ;i <= n ; i++) q[i].ouput();

	int x = k,y = k;
	while (q[k]==q[x]) x--;
	while (q[k]==q[y]) y++;
	
//	cout<<"x:"<<x<<endl;
//	cout<<"y:"<<y<<endl;
	cout<<y-x-1<<endl;




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
