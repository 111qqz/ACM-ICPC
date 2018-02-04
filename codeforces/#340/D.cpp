/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 16时52分27秒
File Name :code/cf/#340/D.cpp
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

struct point 
{
    int x,y;

    void in()
    {
	cin>>x>>y;
    }

    bool operator<(point p)const
    {
	if (x<p.x) return true;
	if (x==p.x&&y<p.y) return true;
	return false;
    }
}p[10];


int solve()
{
    if (p[1].x==p[2].x&&p[2].x==p[3].x) return 1;
    if (p[1].y==p[2].y&&p[2].y==p[3].y) return 1;

  /*  if (p[1].x==p[2].x&&p[2].y==p[3].y) return 2;
    if (p[1].y==p[2].y&&p[2].x==p[3].x) return 2;
    if (p[2].x==p[1].x&&p[1].y==p[3].y) return 2;
    if (p[2].y==p[1].y&&p[1].x==p[3].x) return 2;
    if (p[1].x==p[3].x&&p[3].y==p[2].y) return 2;
    if (p[1].y==p[3].y&&p[3].x==p[2].x) return 2;  */

    if (p[1].x==p[2].x&&(p[3].y<=p[1].y||p[3].y>=p[2].y)) return 2;
    if (p[1].x==p[3].x&&(p[2].y<=p[1].y||p[2].y>=p[3].y)) return 2;
    if (p[2].x==p[3].x&&(p[1].y<=p[2].y||p[1].y>=p[3].y)) return 2;

    if (p[1].y==p[2].y&&(p[3].x<=p[1].x||p[3].x>=p[2].x)) return 2;
    if (p[1].y==p[3].y&&(p[2].x<=p[1].x||p[2].x>=p[3].x)) return 2;
    if (p[2].y==p[3].y&&(p[1].x<=p[2].x||p[1].x>=p[3].x)) return 2;

    return 3;
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	for ( int i = 1 ;i <= 3 ; i++) p[i].in();
	sort(p+1,p+4);
	cout<<solve()<<endl;

	string a="Thisisatest";
	string tmp = substr(a,6,2);
	cout<<tmp<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
