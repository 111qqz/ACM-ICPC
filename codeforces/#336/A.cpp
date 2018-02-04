/* ***********************************************
Author :111qqz
Created Time :2015年12月24日 星期四 00时32分24秒
File Name :code/cf/#336/A.cpp
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
const int N=105;
int n;
int s;
struct node
{
    int f,t;

    bool operator <(node b)const
    {
	if (f>b.f) return true;
	if (f==b.f&&t>b.t) return true;
	return false;
    }
}q[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>s;
	for ( int i =  1 ; i<= n ;i++) cin>>q[i].f>>q[i].t;

	sort(q+1,q+n+1);
	int cur = s;
	int t = 0 ;
	q[0].f = -1;
//	for ( int i = 1 ; i <= n ; i++) cout<<q[i].f<<" "<<q[i].t<<endl;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (q[i].f==q[i-1].f) continue;
	    t+=cur-q[i].f;
	   // cout<<"t:"<<t<<" ";
	    cur = q[i].f;
	    if (t<q[i].t)
	    {
		t = q[i].t;
	    }
	  //  cout<<"t2:"<<t<<endl;
	}
	t+=q[n].f;
	cout<<t<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
