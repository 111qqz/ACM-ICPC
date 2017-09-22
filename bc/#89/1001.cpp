/* ***********************************************
Author :111qqz
Created Time :Sat 29 Oct 2016 06:58:00 PM CST
File Name :code/bc/#89/1001.cpp
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
const int N=1E5+7;
char st[N];
int len;
int y[N],r[N],x[N];
int Y,R,X;
vector<int>fac[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	for ( int i = 1; i <= 10000 ; i++)
	{
	    for ( int j = 1 ; j*j <= i ; j++)
	    {
		if (i%j==0) fac[i].push_back(j);
		if (j!=i/j) fac[i].push_back(i/j);
	    }
	    //sort(fac[i].begin(),fac[i].end());
	}
	//for ( int i = 0 ; i < fac[4].size();  i++) cout<<" i:"<<fac[4][i]<<endl;
//	getchar();
	while (T--)
	{
	    LL ans = 0 ;
	    scanf("%s",st);
	    len = strlen(st);
	    ms(y,0);
	    ms(r,0);
	    ms(x,0);
	    Y = 0 ;
	    R = 0 ;
	    X = 0 ;
//	    cout<<"st:"<<st<<endl;
	    for ( int i =  0 ; i < len ; i++)
	    {
		if (st[i]=='r') r[++R] =  i+1;
		if (st[i]=='y') y[++Y] =  i+1;
	    }

	    for ( int i = 1 ; i <= len ; i++)
	    {
		if (st[i-1]=='y')
		{
		    for ( int j = i+i ; j <= len ; j+=i)
		    {
			if (st[j-1]=='r')
			{
			    int k = j*j/i;
			    if (k>=1&&k<=len&&st[k-1]=='x') ans++;
			}
		    }
		}
	    }
	    for ( int j = 1 ; j <= len ; j++)
	    {
		if (st[j-1]=='r')
		{
		    for ( int i = j + j ; i <= len ; i+=j)
		    {
			if (st[i-1]=='y')
			{
			    int k = j*j/i;
			    if (k>=1&&k<=len&&st[k-1]=='x') ans++;
			}
		    }
		}
	    }

	//    for ( int i = 1 ; i <= R ; i++) cout<<"R:"<<r[i]<<endl;
	   /* 
	    for ( int i = 1 ; i <= R ; i++)
	    {
		int pos = r[i];
		int siz = fac[pos].size();
		for ( int j = 0 ; j < siz ; j++)
		{
		    int v =  fac[i][j];
		    if (st[v-1]=='y')
		    {
			int d = pos/v;
			if (pos*d>len) continue;
			if (pos*d<=len&&st[pos*d-1]=='x')  ans++;
		    }
		    if (st[v-1]=='x')
		    {
			int d = pos/v;
			if (pos*d>len) continue;
			if (pos*d<=len&&st[pos*d-1]=='y') ans++;
		    }
		}
	    }
	    */
    
	    /*
	    for ( int i = 1 ; i <= R ; i ++)
	    {
		int pos = r[i];
		//cout<<"pos:"<<pos<<endl;
		int siz = fac[pos].size();
		for (  int j = 0 ;j  < siz ; j++)
		{
		    int v = fac[pos][j];
		   // cout<<v<<" ?";
		    if (st[v-1]=='y')
		    {
			int d = pos/v;
			if (pos*d>len) continue;
			if (st[pos*d-1]=='x') ans++;
		    }
		    if (st[v-1]=='x')
		    {
			int d = pos/v;
			if (pos*d>len) continue;
			if (st[pos*d-1]=='y') ans++;
		    }
		    
		}
		for ( int j  = 0 ; j < siz;  j++)
		{
		    int v = fac[pos][j];
		    if (st[v-1]!='x') continue;
		    int d = pos/v;
		    if (pos*d>len) continue;
		    if (st[pos*d-1]=='y') ans++;
		}
	    } 
	    */
	    
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

