/* ***********************************************
Author :111qqz
Created Time :2015年12月08日 星期二 16时39分56秒
File Name :code/cf/problem/600C.cpp
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
const int N=2E5+7;
char st[N];
int len;
int cnt[30];
int odd[30];
int k;
int mappd[30];
char ans[N];

void solve()
{
//  cout<<"k:"<<k<<endl;
    if (k==0)
    {
	for ( int i = 0 ; i < 26 ; i++)
	{
	    for ( int j = 0 ; j < cnt[i]/2 ; j++)
		printf("%c",char(i+'a'));
	}
	for ( int i = 25 ; i >= 0 ; i--)
	    for ( int j = 0 ; j < cnt[i]/2 ;  j++)
		printf("%c",char(i+'a'));
	return ;
    }
    if (k%2==0)
    {
	for ( int i = 1 ; i <= k/2 ; i++)
	{
	    cnt[odd[i]]++;
	    cnt[odd[i+k/2]]--;
	}
	int num =  0;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    for ( int j = 0 ; j < cnt[i]/2; j++)
		printf("%c",char(i+'a'));
	}
	for ( int i = 25 ; i >=0 ; i--)
	{
	    for ( int j = 0 ; j < cnt[i]/2  ; j++)
		printf("%c",char(i+'a'));
	}
	printf("\n");
	
    }
    if (k%2==1)
    {
//	cout<<"what the fuck?"<<endl;
	for ( int i = 1 ; i <= k/2 ; i++)
	{
	    cnt[odd[i]]++;
	    cnt[odd[i+k/2+1]]--;
	}
	int the_lonely_one = odd[k/2+1]; 
	int num = 0 ;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    if (i==the_lonely_one ) cnt[i]--;
	    for ( int j = 0 ; j < cnt[i]/2 ; j++)
		printf("%c",char(i+'a'));
	}
//	puts("AAA??");
	printf("%c",char(the_lonely_one+'a'));
	for ( int i = 25 ; i >= 0 ; i--)
	{
	    for ( int j = 0 ; j < cnt[i]/2 ; j++)
		printf("%c",char(i+'a'));
	}
    }

}

int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%s",st);
	len = strlen(st);
	ms(cnt,0);
	ms(odd,0);
	for ( int i = 0 ; i   <  len ; i ++)
	{
	    cnt[st[i]-'a']++;
	}
	 k = 0;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    if (cnt[i]%2==1)
	    {
		k++;
		odd[k] = i;
	    }
	}
	solve();
	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
