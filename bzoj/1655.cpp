/* ***********************************************
Author :111qqz
Created Time :2016年04月14日 星期四 16时42分31秒
File Name :code/bzoj/1655.cpp
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
const int N=1E4+7;
const int MAXN =300;
int n,m;
int a[N][105],tmp[N][105];

void add(int x,int y)
{
    for ( int i = 1 ; i <= 100 ; i++)
	tmp[x][i]+=a[y][i];

    for ( int i = 1 ; i <= 100 ; i++)
    {
	tmp[x][i+1]+=tmp[x][i]/10;
	tmp[x][i]%=10;
    }

}

void tran( int x)
{
    for ( int i = 1 ; i <= 100 ; i++)
    {
	a[x][i] = tmp[x][i];
	tmp[x][i] =  0;
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	ms(a,0);
	m = min(m,n);
	for ( int i = 0 ; i <= n ; i++)
	{
	    a[i][1] = 1;
	    tmp[i][1] =  0 ;
	}

	for ( int i = 2 ; i <= m ; i++)
	{
	    for ( int j = 0 ;j <= n ; j++)
	    {
		for ( int k = 0 ; k+j<= n ; k+=i)
		{
		    for ( int z = 1 ; z <= 40 ; z++)
		    {
			tmp[k+j][z] += a[j][z];
		    }
		
		}
	    }
//	    cout<<"aaa"<<endl;

	    for ( int j = 0 ; j <= n ; j++)
	    {
		for ( int z = 1 ; z <= 40 ; z++)
		{
		    tmp[j][z+1]+=tmp[j][z]/10;
		    tmp[j][z]%=10;
		}
	    }
	    for ( int j = 0 ; j <= n ; j++)
	    {
		for ( int z = 1 ; z <= 40 ; z++)
		{
		    a[j][z] = tmp[j][z];
		    tmp[j][z]  = 0;
		}
	    }
	}

	int len = 100;
	while (a[n][len]==0) len--;
//	cout<<"len:"<<len<<endl;
	for ( int i = len  ;i >0 ; i--) printf("%d",a[n][i]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
