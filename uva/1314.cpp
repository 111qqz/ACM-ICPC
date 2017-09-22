/* ***********************************************
Author :111qqz
Created Time :2016年08月12日 星期五 18时48分29秒
File Name :code/uva/1314.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
int n ;
char s[N];
int minRep(char *s)
{
    int n = strlen(s);
    int i = 0;
    int j = 1;
    int k = 0;
    while (i<n&&j<n&&k<n)
    {
	int t = s[(i+k)%n]-s[(j+k)%n];
	if (t==0) k++;
	else 
	{
	    if (t>0)
		i+=k+1;
	    else j+=k+1;
	    if (i==j) j++;
	    k = 0 ;
	}
    }
    return i<j?i:j;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%s",s);
	    printf("%d\n",minRep(s)+1);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
