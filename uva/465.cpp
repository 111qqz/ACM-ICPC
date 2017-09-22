/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 13时17分22秒
File Name :code/uva/465.cpp
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
const int MAXL =1E4+7;
const int modo = 10;
struct bigint
{
    int len;
    int ar[MAXL];

    void out()
    {
	if (len==0) printf("0");
	while (len>=2&&ar[len-1]==0) len--;

	for ( int i = len - 1 ; i >= 0 ; i--)
	    printf("%d",ar[i]);
	printf("\n");
    }
};


void plusx(bigint  &a,bigint b)
{
    int u,v,w;
    u=v=0;
    while (u<b.len||v)
    {
	w =a.ar[u] +b.ar[u]+v;
	a.ar[u] = w%modo;
	v = w/modo;
	++u;
    }
    if (a.len<u) a.len = u ;  
}


void times(bigint a,bigint b,bigint &c)
{
    int i,j;
    ms(c.ar,0);
    for ( i = 0 ; i < a.len ; i++)
	for ( j = 0 ; j < b.len ; j++)
	    c.ar[i+j]+=(a.ar[i]*b.ar[j]);
    i=j=0;
    while (i<=a.len+b.len-2||j)
    {
	j+=c.ar[i];
	c.ar[i]=j%modo;
	j = j /modo;
	++i;
    }
    c.len=i;
}

int bigger(bigint a,bigint b)
{
    if (a.len>b.len) return 1;
    else if (a.len<b.len) return -1;
    else 
	for ( int i = a.len-1 ; i >= 0 ; i--)
	    if (a.ar[i]>b.ar[i]) return 1;
		else if (a.ar[i]<b.ar[i]) return -1;
    return 0;

}

string noleadzero(string x)
{
    //int len = x.length();
    while (x[0]=='0'&&x.length()>1) x.erase(0,1);

    return x;

}
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (getline(cin,st))   //字符串可能有前导0.。。不说清楚真是一点意思都没有
	{
	    cout<<st<<endl;
	    int len = st.length();
	    int opt = 1;
	    int p = st.find('+');
	    if (p==-1) 
	    {
		p = st.find('*');
		opt = 2;
	    }

	    string vx = st.substr(0,p-1);
	    vx = noleadzero(vx);
	    bigint x;
	    x.len = vx.length();
	    for ( int i = x.len-1 ; i >= 0 ; i-- )
		x.ar[x.len-i-1] = vx[i]-'0';

	    string vy = st.substr(p+1);
	    vy = noleadzero(vy);
	    bigint y;
	    y.len =vy.length();
	    for ( int i = y.len -1  ; i>=0 ; i--)
	    x.ar[y.len-i-1] = vy[i]-'0';

	    bigint INF;
	    string sINF = "2147483647";
	    INF.len = sINF.length();
	    for ( int i = INF.len-1 ; i>= 0 ; i--)
		INF.ar[INF.len-i-1] = sINF[i]-'0';

	    bigint ans;
	    if (bigger(x,INF)==1)
	    {
		puts("first number too big");
	    }
	    if (bigger(y,INF)==1)
	    {
		puts("second number too big");
	    }

	    if (opt==1)
	    {
		plusx(x,y);
		if (bigger(x,INF)==1)
		    puts("result too big");
	    }
	    else
	    {
		times(x,y,ans);
		if (bigger(ans,INF)==1)
		{
		    puts("result too big");
		}
	    }

	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
