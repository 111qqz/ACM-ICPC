/* ***********************************************
Author :111qqz
Created Time :2016年03月05日 星期六 16时28分35秒
File Name :code/hdu/4407.cpp
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
const int N=666; //sqrt(400000)
int prime[N];
bool np[N];
int fac_cnt;//质因子个数
int fac[N];
LL ans = 0 ;
map<int,int >mp;
int m;
int n;
void getprime()
{
    ms(prime,0x3f);
    int cnt  = 0;
    for ( int i = 2 ; i < N ; i++ )
    {
	if (!np[i])
	{
	    prime[++cnt] =  i;
	    for ( int j = 2*i ; j < N ; j+=i)
		np[j] = true;
	}
    }
    //check
  //  for ( int i = 1 ; i <= cnt ; i++) cout<<prime[i]<<endl;
}

void Div( int x)
{
    fac_cnt = 0 ;
    
    for ( int i = 1 ; prime[i]*prime[i]<= x ; i++)  
    {
	if (x%prime[i]!=0) continue;
	cout<<"i:"<<i<<" prime[i]:"<<prime[i]<<"x:"<<x<<endl;
	while (x%prime[i]==0) 
	{
	    cout<<"prime[i]:::::"<<prime[i]<<endl;
	    x/=prime[i];
	    cout<<"sadsadsad"<<endl;
	}
	fac[++fac_cnt] = prime[i];
	cout<<"sadsad"<<endl;
    }
    cout<<"x:"<<x<<endl;
    if (x!=1) //说明n是质数
	fac[++fac_cnt] = x ;

}

LL sum(int n)
{
    LL res = 0 ;
    res = 1LL*n*(n+1)/2;
    return res;
}

void dfs(int id,LL mul,int flag,int n)
{
    if (mul>n) return;
    if (id==fac_cnt)
    {
	LL cnt = n/mul;
	ans +=cnt*n*(cnt+1)*flag/2;
	return;
    }
    dfs(id+1,mul*fac[id],-flag,n);
    dfs(id+1,mul,flag,n);

}

int gcd ( int a,int b)
{
    if (a<b) gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	ios::sync_with_stdio(false);
	int T;
	getprime();
	cin>>T;
	while (T--)
	{
	    mp.clear();
	      scanf("%d%d",&n,&m);
	    while (m--)
	    {
		int opt ;
		cin>>opt;
		cout<<"opt:"<<opt<<endl;
		if (opt==1)
		{
		    int x,y,p;
		    scanf("%d %d %d",&x,&y,&p);
		    Div(p); //对p因数分解
		    dfs(0,1,-1,x-1);
		    dfs(0,1,1,y);
		    for (map<int,int>::iterator it =mp.begin() ;it!=mp.end() ;it++)
		    {
			int id = it->fst;
			int val = it->sec;
			if (id>y||id<x) continue;
			if (val==id) continue; //变了之后和没变一样
			if (gcd(val,id)==1)
			    ans+=val;
		    }
		    
		    printf("%lld\n",ans);
		}
		else
		{
		    int x,c;
		    scanf("%d %d",&x,&c);
		    mp[x]=c;
		}





		
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
