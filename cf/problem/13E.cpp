/* ***********************************************
Author :111qqz
Created Time :2016年02月20日 星期六 23时48分28秒
File Name :code/cf/problem/13E.cpp
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
int n,m;
int cnt[N];//cnt[i]表示第i个洞的球跳出所在块所需要的步数
int end[N]; //end[i]表示第i个洞的球跳出序列之前所经历的最后一个洞的序号
int jmp[N]; //jmp[i]表示第i个洞的球跳出所在的块到下一个块的洞的序号。
int a[N];
int siz = 313; //sqrt(1E5)
 int pos[N];

void go ( int x)
{
    int ans = 0 ;
    int e;
    while (1)
    {
	if (x>n)
	{
	    //cout<<e<<" "<<ans<<endl;
	    printf("%d %d\n",e,ans);
	    break;
	}
	ans +=cnt[x];
	e = end[x];
	x = jmp[x];
    }
  //  cout<<"x:"<<x<<" cnt[x] :"<<cnt[x]<<endl;
    
   // cout<<e<<" "<<ans<<endl;
}
void update( int i,int j)
{
    if (j>n)//跳出所有洞
    {
	cnt[i] = 1;
	end[i] = i;
	jmp[i] = n+1;//只要是一个大于n的数表示跳出就可以了
    }
    else
    {
	if (pos[i]==pos[j]) //在同一块
	{
	    cnt[i]=cnt[j]+1;
	    end[i]=end[j];
	    jmp[i]=jmp[j];
	}
	else
	{
	    cnt[i] = 1;
	    end[i]=end[j];
	    jmp[i] = j;
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    pos[i] = (i-1)/siz;
	}
	for ( int i = n ; i >= 1 ; i--) update(i,i+a[i]);

	while (m--)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==0)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		a[x]=y;
		update(x,x+a[x]);
		int pos = (x-1)/siz*siz;//pos表示x所在的块首下标

		for ( int i = x-1 ; i >= pos; i--) update(i,i+a[i]);
	    }
	    else
	    {
		int x;
		scanf("%d",&x);
		go(x);
	    }
	}

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
