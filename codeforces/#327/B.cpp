/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 19时13分12秒
File Name :code/cf/#327/B.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
char st[N];

int n,m;
char x,y;
map<char,char>mp;


int main()
{
    freopen("code/in.txt","r",stdin);
    mp.clear();
    for ( int i = 0 ; i < 26 ; i++)
    {
	char tmp = char(i+97);
	mp[tmp] = tmp;
    }

    scanf("%d %d",&n,&m);
    scanf("%s",st);
    getchar();
    while (m--)
    {
	char x,y;
	scanf("%c %c",&x,&y);
	getchar();
	for ( int i = 0 ; i < 26 ; i ++)
	{
	    char tmp = char(i+97);
	    if (mp[tmp]==x) mp[tmp]=y;
	    else if (mp[tmp]==y) mp[tmp] = x;
	}
    }
    for ( int i = 0 ; i < n ;i++)
    {
	printf("%c",mp[st[i]]);
    }
    return 0;
}
