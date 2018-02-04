/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 00时36分47秒
File Name :code/cf/#334/C.cpp
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
const int N=1E5+7;
char a[N];
int n;

char tow(char ch)
{
    if (ch=='0') return '1';
    if (ch=='1') return '0';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	scanf("%d",&n);
	scanf("%s",a);
	int cnt =  0;
	for ( int i = 0  ; i < n-1 ; i++) 
	    if (a[i]==a[i+1])
		cnt++;

    if (cnt>=2) cnt = 2;
    
    char tar = a[0];
	tar = tow(tar);
	int ans = 1;
	for ( int i = 1 ; i < n ; i++ )
	{
//	    printf("%d %c\n",i,tar);
	    if (a[i]==tar)
	    {
		ans++;
		tar = tow(tar);
	    }
	}
	
	printf("%d\n",ans+cnt);
    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
