/* ***********************************************
Author :111qqz
Created Time :Sat 29 Oct 2016 03:07:32 PM CST
File Name :code/ccpc2016/hangzhou/1006.cpp
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
const int N=25;
char st[N];
int len;
LL a[N][N];
LL cal( int x,int y,int z)
{
    LL res = 0 ;
    res = a[y+1][z]*a[z+1][z+1]/a[z+2][len-1];
    res = -res + a[0][x] +a[x+1][y];
//    cout<<"x: "<<x<<" y:"<<y<<"  z:"<<z<<" res:"<<res<<endl;
    return res;

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
	    ms(a,0);
	    scanf("%s",st);
	    len = strlen(st);
	    for ( int i = 0 ; i < len ; i++)
	    {
		LL val = st[i]-'0';
		a[i][i] = val;
		for ( int j = i+1 ; j < len ; j++)
		{
		    LL tmp = st[j]-'0';
		    val = val*10 + tmp;
		    a[i][j] = val;
		}
	    }

/*	    for ( int i = 0 ; i < len ; i++)
	    {
		for ( int j = i ; j < len ; j++)
		    printf("%lld ",a[i][j]);
		printf("\n");
	    }
	    */
	    LL ans = 0 ;
	    for ( int i = 0 ; i < len-4 ; i++)
	    {
		for ( int j = i+1 ; j < len-3 ; j++)
		{
		    for ( int k = j+1; k < len-2 ; k++)
		    {
			ans = max(ans,cal(i,j,k));
		    }
		}
	    }
	    ms(st,0);
	    printf("Case #%d: %lld\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
