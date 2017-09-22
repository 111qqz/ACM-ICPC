/* ***********************************************
Author :111qqz
Created Time :2016年11月20日 星期日 10时27分05秒
File Name :code/hdu/1880.cpp
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
char magic[N][25],fun[N][81];
int cnt;
int n;
map<int,int>mp1,mp2;
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0 ;
    while (*str) hash = hash*seed+(*str++);
    return (hash&0x7fffffff);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cnt = 1 ;
	while (~scanf("%s",magic[cnt]))
	{
	    if (strcmp(magic[cnt],"@END@")==0) break;
	    getchar();
	    gets(fun[cnt]);
	    cnt++;
	}
	cnt--;
	for ( int i = 1; i <= cnt ; i++)
	{
	    mp1[BKDRHash(magic[i])] = i ;
	    mp2[BKDRHash(fun[i])] =  i;
	}
	scanf("%d",&n);
	getchar();
	char tmp[85];
	while (n--)
	{   
	    gets(tmp);
	    if (tmp[0]=='[')
	    {
		
		if (!mp1[BKDRHash(tmp)])
		{
		    puts("what?");
		}
		else
		{
		    int id = mp1[BKDRHash(tmp)];
		    printf("%s",fun[id]);
		    printf("\n");
		}
	    }
	    else
	    {
		if (!mp2[BKDRHash(tmp)])
		{
		    puts("what?");
		}
		else
		{
		    int id = mp2[BKDRHash(tmp)];
		    int len = strlen(magic[id]);
		    for ( int i = 1 ; i <len -1 ; i++) printf("%c",magic[id][i]);
		    printf("\n");

		}
	    }
	    ms(tmp,0);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
