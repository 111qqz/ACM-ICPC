/* ***********************************************
Author :111qqz
Created Time :2016年11月20日 星期日 11时13分29秒
File Name :code/poj/2503.cpp
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
char eng[N][12],fori[N][12];
char str[N];
map<int,int>mp;
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 113;
    unsigned int hash = 0 ;
    while (*str) hash = hash*seed+(*str++);
    return (hash&0x7fffffff);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    int cnt = 1 ;
    while (gets(str))
    {
	if (strlen(str)==0) break;
	sscanf(str,"%s %s",eng[cnt],fori[cnt]);
	cnt++;
    }
    cnt--;
 //   for ( int i = 1; i <= cnt ;i++) printf("%s %s\n",eng[i],fori[i]);
    for ( int i = 1; i <= cnt ; i++) mp[BKDRHash(fori[i])] = i ;
    while(scanf("%s",str)!=EOF)
    {
	if (!mp[BKDRHash(str)]) puts("eh");
	else puts(eng[mp[BKDRHash(str)]]);
    }
    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
