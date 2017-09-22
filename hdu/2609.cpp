/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 02时44分21秒
File Name :code/hdu/2609.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=1E4+7;
int n;
char s[N][105];
set<string>se;
int minRep(char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = 1 ;
    int k = 0 ;
    while (i<n&&j<n&&k<n)
    {
	int t  = s[(i+k)%n] - s[(j+k)%n];
	if (t==0) k++;
	else 
	{
	    if (t>0)
		i+=k+1;
	    else j+=k+1;
	    if (i==j) j++;
	    k = 0 ;
	}
    }
    return i<j?i:j;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(s,0);
	    se.clear();
	  //  cout<<"n:"<<n<<endl;
	    char tmp[105];
	    for ( int i = 0 ; i < n;  i++)
	    {
		scanf("%s",tmp);
//		cout<<"tmp:"<<tmp<<endl;
		int k = minRep(tmp);
//		cout<<"k:"<<k<<endl;
		int cnt = 1;
		int len = strlen(tmp);
		for ( int j = k ; cnt <= len ; j++,cnt++)
		    s[i][cnt-1] = tmp[j%len];

		se.insert(string(s[i]));
	    }
//	for ( int i = 0 ; i < n;  i++) cout<<"s[i]:"<<s[i]<<endl;
//
	    int ans = se.size();
	    printf("%d\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
