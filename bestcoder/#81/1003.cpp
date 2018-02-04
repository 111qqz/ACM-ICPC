/* ***********************************************
Author :111qqz
Created Time :2016年04月22日 星期五 19时51分12秒
File Name :code/bc/#81/1003.cpp
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
char st[N];
int k;
int len;
bool vis[35];
int num[35];
LL ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%s",st);
	    scanf("%d",&k);
	    len = strlen(st);
	    ms(vis,false);
	    ms(num,0);
	    int cnt = 0 ;
	    int head = 0 ;
	    int tail = -1;
	    ans = 0LL;
	    for ( int i = 0 ; i < len ; i++)
	    {

		int tmp = st[i]-'a'+1;
		num[tmp]++;
		if (!vis[tmp])
		{
		    cnt++;
		    vis[tmp] = true;
		}  
		if (cnt==k)
		{
		    tail = i;
		    break;

		}
	    }
	  //  cout<<"cnt:"<<cnt<<endl;
	    if (tail==-1)
	    {
		printf("0\n");
		continue;
	    }
	//    for ( int i = 1 ; i <= 26 ; i++) if (vis[i]) cout<<char(i+96)<<endl;
	    ans = ans + LL(len-tail);
	    ans = ans + LL(tail+1-k);
	    cout<<"ans:"<<ans<<endl;
	    for ( int i = tail+1 ; i < len ; i++)
	    {
		int tmp = st[head]-'a'+1;
		num[tmp]--;
	//	cout<<"tmp:"<<tmp<<endl;
		head++;
		if (num[tmp]==0)
		{
		    cnt--;
		    vis[tmp] = false;
		}

		tmp = st[i]-'a'+1;
	//	cout<<"tmp2:"<<tmp<<endl;
		num[tmp]++;
		if (!vis[tmp])
		{
		//    cout<<"cnt:::"<<cnt<<endl;
		    vis[tmp] = true;
		    cnt++;
		}
	//	cout<<"i:"<<i<<" cnt:"<<cnt<<endl;
		if (cnt==k)
		{
		    ans = ans + LL(len-i);
		}

	//	cout<<"ans:"<<ans<<endl;
	    }

	    //printf("%I")
	    cout<<ans<<endl;
	  //  printf("%I64d\n",ans);


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
