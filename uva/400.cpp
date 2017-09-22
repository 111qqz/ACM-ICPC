/* ***********************************************
Author :111qqz
Created Time :2016年01月27日 星期三 20时55分50秒
File Name :code/uva/400.cpp
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
const int N=1E2+7;
int n;
string st[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d",&n)!=EOF)
	{
	    printf("------------------------------------------------------------\n");
	    int mx = -1;
	    for ( int i = 0 ; i < n ; i++)
	    {
		cin>>st[i];
		int len=st[i].length();
		mx = max(mx,len);
	    }
	    int col = 62/(mx+2);
	    int row = ceil(n*1.0/col);
	    sort(st,st+n);

	    for ( int i = 0 ; i < row; i ++)
	    {
		for ( int j = 0 ; j < col ; j++)
		{
		    int t = j*row+i;
		    if (t>=n) continue;
		    cout<<st[t];
		    int k = mx - st[t].length();
		    while (k--) printf(" ");
		    if (j!=col-1) printf("  ");
		}
		puts("");
	    }
	}




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
