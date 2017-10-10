/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 12时48分18秒
File Name :BB.cpp
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
const string error="Impossible";
int n,b,g;
string solve()
{
	string res ="";
	int GG = n-b;
	int BB = n-g;
	int BG = b+g-n;
	//printf("GG:%d BB:%d BG:%d\n",GG,BB,BG);
	bool flag[4];
	flag[1]=GG>=0&&BB>=0&&BG>=0;
	flag[2]=BG%2==0;
	flag[3]=b==0||g==0||BG>0;
	if (flag[1]&&flag[2]&&flag[3])
	{


	    for ( int i = 1 ; i <= BG/2 ; i++) res = res + "BG";
	    for ( int i = 1 ; i <= GG ; i++) res+='G';
	    for ( int i = 1 ; i <= BB ; i++) res+='B';
	    return res;
	}
	return error;
}
	

int main()
{
//	freopen("./in.txt","r",stdin);
	freopen("boysgirls.in","r",stdin);
	freopen("boysgirls.out","w",stdout);
	cin>>n>>b>>g;
	string ans = solve();
	cout<<ans<<endl;

    return 0;
}
