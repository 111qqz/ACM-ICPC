/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 18时52分30秒
File Name :code/bc/#70/1001.cpp
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
#include <assert.h>
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
int a,b,c;
int fa[N],fc[N];
int cnta,cntc;


bool solve()
{
  //  cout<<"cnta:"<<cnta<<endl;
  //  cout<<"cntc:"<<cntc<<endl;
    for ( int i = 1 ; i <=cnta ;i++)
    {
	for ( int j = 1 ; j <=cntc ; j++)
	{
	  //  cout<<"fa[j]:"<<fa[j]<<endl; 
	    int p,q,m,k;
//	    assert(fa[i]>0);
//	    assert(fc[j]>0);
	    p = fa[i];
	    q = a/fa[i];
	    m = fc[j];
	    k = c/fc[j];
//	    cout<<"p:"<<p<<" q:"<<q<<" m:"<<m<<" k:"<<k<<endl;
	    if (p*k+q*m==b||p*m+q*k==b)
	    {
		return true;
	    }
	    
	}
	

    }
    return false;
	    
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
	    cnta=0;
	    cntc=0;
	    ms(fa,0);
	    ms(fc,0);
	    scanf("%d %d %d",&a,&b,&c);
	    for ( int i = 1 ; i*i<=a ; i++)
	    {
		if (a%i==0)
		{
		    cnta++;
		    fa[cnta]=i;
		}
	    }
	    for ( int i = 1 ; i *i<=c ; i++)
	    {
		if (c%i==0)
		{
		    cntc++;
		    fc[cntc]=i;
		}
	    }
//	    for ( int i = 1 ; i <=cnta ; i++) cout<<fa[i]<<endl;
//	    cout<<"T:"<<T<<endl;
	    if (solve())
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
