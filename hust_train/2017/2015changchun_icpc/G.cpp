/* ***********************************************
Author :111qqz
Created Time :2017年10月14日 星期六 14时33分39秒
File Name :G.cpp
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
const int N=1E2+7;
struct point
{
    int x,y;
    void input()
    {
	scanf("%d %d",&x,&y);
    }
    bool operator < ( point b)
    {
	if (x==b.x) return y<b.y;
	return x<b.x;
    }
    void pr()
    {
	printf("%d %d\n",x,y);
    }
}p[N];
map< pair<int,int> ,bool>mp;
int n;



int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    //cout<<"n:"<<n<<endl;
	    mp.clear();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		p[i].input();
		mp[MP(p[i].x,p[i].y)] = true;
	    }
	    int X,Y;
	    if (n!=4)
	    {
		puts("NO");
		continue;
	    }
	    sort(p+1,p+4+1);
	    bool ok = false;
	    for ( int i = 1 ; i <= 4 ; i++)
		for ( int j = i+1 ; j <= 4 ; j++)
	    {

		X = p[j].x-p[i].x;
		Y = p[j].y-p[i].y;
		bool flag[5];
		ms(flag,false);
	    if (mp[MP(p[i].x+Y,p[i].y-X)]) flag[1] = true;
	    if (mp[MP(p[j].x+Y,p[j].y-X)]) flag[2] = true;
	    if (mp[MP(p[i].x-Y,p[i].y+X)]) flag[3] = true;
	    if (mp[MP(p[j].x-Y,p[j].y+X)]) flag[4] = true;
	    if (flag[1]&&flag[2]) ok = true;
	    else if (flag[3]&&flag[4]) ok = true;
	    }// for ( int i = 1 ; i <= n ; i++) p[i].pr();
	     if (ok) puts("YES");
	     else puts("NO");
	}	   


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
