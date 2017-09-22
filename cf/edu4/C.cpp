/* ***********************************************
Author :111qqz
Created Time :2015年12月25日 星期五 22时58分50秒
File Name :code/cf/edu4/C.cpp
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
int len;
char st[N];
int cost = 0 ;

char a[N];
int n ;


int which(char ch)
{
    if (ch=='<'||ch=='{'||ch=='('||ch=='[') return 1;
    return 2;
}
int kin(char ch)
{
    if (ch=='{'||ch=='}') return 1;
    if (ch=='['||ch==']') return 2;
    if (ch=='<'||ch=='>') return 3;
    if (ch=='('||ch==')') return 4;
}
bool ok(char x,char y)
{
    int res = 0 ;
    if(x=='<'||x=='{'||x=='['||x=='(') res++;
    if (y=='>'||y=='}'||y==']'||y==')') res++;
    if (res==2)
    {
	if (kin(x)!=kin(y)) cost++;
//	cout<<"x:"<<x<<" y:"<<y<<endl;
	return true;
    }
    return false;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>st;
	len = strlen(st);
	int head = -1;
	int ans = 0 ;
	
	for ( int i = 0 ; i < len ; i++)
	{
	    if (head==-1)
	    {
		head++;
		a[head] = st[i];
		if (which(st[i])==2)
		{
		    puts("Impossible");
		    return 0;
		}
    	 
		continue;
	    }
		if (ok(a[head],st[i]))
		{
		    head--;
		}
		else
		{
		    head++;
		    a[head] = st[i];
		}
	    
//	    cout<<"head:"<<head<<endl;
	}
//	cout<<"head:"<<head<<endl;
	if (head!=-1)
	{
	    puts("Impossible");
	}
	else
	{
	    cout<<cost<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
