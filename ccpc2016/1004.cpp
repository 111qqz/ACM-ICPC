/* ***********************************************
Author :111qqz
Created Time :2016年08月14日 星期日 12时46分56秒
File Name :code/ccpc2016/1004.cpp
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
const int N=11;
int n;
int a[N];
int total;
bool bian[N];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    printf("Case #%d: ",++cas);
	    scanf("%d",&n);
	    ms(bian,false);
	    total = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d",&a[i]);
		total +=a[i];
	    }
	    if (n==1)
	    {
		if (a[1]>1)
		puts("1");
		else puts("0");
		continue;
	    }
	    sort(a+1,a+n+1,cmp);
	    int R = total/2;
	    int cur = 0 ;
	    int i = 1;
	    int j = 2;
	    while (cur<R&&i<=n&&j<=n)
	    {
//		int x = a[i];
//		int y = a[j];
		if (a[i]==a[j])
		{
		    cur +=a[i]+a[j];
		    a[i] = 0;
		    a[j] = 0;
		    i = j+1;
		    j = i+1;
		}
		else  if (!bian[i])
		{
		    cur +=a[j]+a[j]+1;
		    a[i]-=(a[j]+1);
		    a[j] = 0;
		    j++;
		    if (a[i]<a[j]) swap(a[i],a[j]);
		    else bian[i] = true;
		}
		else
		{
		    cur +=a[j]+a[j];
		    a[i]-=a[j];
		    a[j] = 0;
		    j++;
		    if (a[i]<a[j]) swap(a[i],a[j]);
		}
//		cout<<"cur:"<<cur<<endl;
	    }
	    cur = min(cur,R);
	    printf("%d\n",cur);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
