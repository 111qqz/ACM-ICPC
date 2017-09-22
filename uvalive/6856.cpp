/* ***********************************************
Author :111qqz
Created Time :2016年08月25日 星期四 23时35分28秒
File Name :code/uvalive/6856.cpp
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
const int N=1E6+7;
int k;
int n;
char s[N];
int sa[N],rk[N],t[N],t2[N],cnt[N];
int height[N];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[(a+l)%n]==r[(b+l)%n];}
 
void getSa(int n,int m)
{
    int *x = t,*y = t2;
    ms(cnt,0);
    for ( int i = 0 ; i < n ; i++) cnt[x[i]=s[i]]++;
    for ( int i = 1 ; i < m ; i++) cnt[i] += cnt[i-1];
    for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[i]]] = i ;
    for ( int k = 1 ; k <=  n;  k <<=1 )
    {
	int p = 0 ;

	for (  int i = 0 ; i < n ; i++)  y[p++] = sa[i]>=k?sa[i]-k:n+(sa[i]-k)%n;
	ms(cnt,0);
	for ( int i = 0 ; i < n ; i++) cnt[x[y[i]]]++;
	for ( int i = 0 ; i < m ; i++) cnt[i]+=cnt[i-1];
	for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[y[i]]]] = y[i];
	swap(x,y);
	p = 1;
	x[sa[0]] = 0;
	for ( int i = 1 ; i < n ; i++)
	    x[sa[i]] = cmp(y,sa[i-1],sa[i],k)?p-1:p++;
	if (p>=n) break;
	m = p;
    }
}

void getHeight( int n)
{
    int k = 0 ;
    for ( int i = 0 ; i < n ;i ++) rk[sa[i]] = i ;
    height[0] = 0 ;
    for ( int i = 0 ; i < n;  i++)
    {
    if (rk[i]==0) continue;
    if (k) k--;
    int j = sa[rk[i]-1];
    while (s[i+k]==s[j+k]) k++;
    height[rk[i]] = k ;
    }
}
 
int getSuffix( char s[])
{
    int len = strlen(s);
    int up = 0;
    for ( int i = 0 ; i < len ; i++)
    {
    int val = s[i];
    up = max(up,val);
    }
//    s[len++]='$';
    getSa(len,up+1);
    getHeight(len);
    return len;
}


bool check( int p)
{
    cout<<"p:"<<p<<endl;
    p = sa[p];
    int len = (n+k-1)/k;
    for ( int i = 0 ; i < len ; i++)
    {
	int  v = i;
	int t = i + n -1;
	for ( int j = 0 ; j < k ; j++)
	{
	    int vv = v;
	    if (vv>=n) vv-=n;
	    if (rk[p]<rk[vv]) v+=len-1;
	    else v+=len;
	    if (v>t) return true;
	}
    }
    return false;

}
void bin()
{
    int l = 0;
    int r = n-1;
    while (l<r)
    {
	int mid = (l+r)/2;
	if (check(mid)) r = mid;
	else l = mid+1;
    }
    int ans = sa[l];
    int len = (n+k-1)/k;
    for ( int i = 0 ; i < len ; i++)
    {
	int v = (ans+i)%n;
//	if (v>=n) v-=n;
//	cout<<"v: "<<v<<"  ";
	putchar(s[v]);
    }
    puts("");
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d",&n,&k))
	{
	    scanf("%s",s);
	    int len = getSuffix(s);
	    //for ( int i = 0 ; i < len ; i++) cout<<"sa[i]:"<<sa[i]<<endl;
	    bin();

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
