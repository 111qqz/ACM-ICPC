/* ***********************************************
Author :111qqz
Created Time :2016年04月08日 星期五 22时53分36秒
File Name :code/cf/edu11/A.cpp
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
const int N=1E3+7;

int n;
int a[N];
int b[N];
bool judge ( int x)
{
    for ( int i = 2 ; i* i <= x ; i++)
    {
	if (x%i==0) return false;
    }
    return true;

}

int gcd (int a,int b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int p;
//	for ( int i = 1E9 ; ; i++ )
//	    if (judge(i))
//	    {
//		p =  i;
//		break;
//	    }
//	cout<<p<<endl;
        p = 1E9+7;	
	cin>>n;
	for ( int i = 1;i <= n ; i++) cin>>a[i];
	
	int cnt = 0 ;
	int num = 0 ;
	b[++cnt] = a[1];
	for ( int i = 2 ; i <=n ; i++)
	{
	    if (gcd(a[i-1],a[i])==1)
	    {
		b[++cnt] = a[i];
	    }else
	    {
		num++;
		b[++cnt] = p;
		b[++cnt] = a[i];
	    }
	}

	cout<<num<<endl;
	for ( int i = 1 ; i <= cnt ; i++) cout<<b[i]<<" ";
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
