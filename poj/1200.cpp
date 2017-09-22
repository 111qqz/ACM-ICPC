/* ***********************************************
Author :111qqz
Created Time :2016年11月22日 星期二 19时43分10秒
File Name :code/poj/1200.cpp
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
int id[200];

int n,nc;
unsigned int BKDHash(char *str,char *end)
{
    unsigned int seed = nc;
    unsigned int hash = 0 ;
    while (str<end){
	hash = hash*seed+(*str++);
    }
    return (hash&0x7fffffff);
}
const int N = 2E7;
char st[N],tmp[N];
map<int,bool>mp;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(id,-1);
	scanf("%d %d",&n,&nc);
	scanf("%s",st);
	int len = strlen(st);
	for ( int i = 0 ; i < len-n+1 ; i++)
	{

	    int id = BKDHash(st+i,st+i+n);
//	    for ( int j = i ; j < i+n ; j++) printf("%c",st[j]);
//	    printf("\n");
	  //  cout<<"tmp:"<<tmp<<endl;
	    mp[id] = true;
	}
	    
/*	char *s = st;
	char *t =s + len;
	for ( ;  s<=t-n ; s++)
	{
	    int id = BKDHash(s,s+n);
	    mp[id] = true;
	}
	*/
	int siz  = mp.size();
	printf("%d\n",siz);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
