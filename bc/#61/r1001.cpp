/*************************************************************************
	> File Name: code/bc/#61/r1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月31日 星期六 19时16分46秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E3+7;
int n;
struct Q
{
    int val;
    int id;
}q[N];

bool cmp(Q a,Q b)
{
    return a.val<b.val;
}

int flag [N];
int posi[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d",&n)!=EOF)
    {
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&q[i].val);
	    q[i].id = i ;

	}
	sort(q+1,q+n+1,cmp);
	
	int k = n;
	bool ok = false;
	for ( int i = 1 ; i <= n-2; i++)
	{
	    if (ok) break;
	    for ( int j = i +1 ; j <= n-1 ; j++)
	    {
		while (j<k&&q[i].val+q[j].val<q[k].val) k--;
		if (q[i].val+q[j].val==q[k].val&&j<k)
		{
	//	    cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
	//	    cout<<"q[i]:"<<q[i].val<<" q[j]:"<<q[j].val<<" q[k]:"<<q[k].val<<endl;
		    ok = true;
		    break;
		}

	    }
	}
	if (ok)
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
