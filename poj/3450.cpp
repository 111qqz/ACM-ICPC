/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 02时10分53秒
File Name :code/poj/3450.cpp
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
const int N=4E3+7;
int nxt[205];
char dna[N][205];
int n;
char tmp[205];
char ans[205];
void getnxt( char *a)
{
    int  i = 0;
    int j = -1;
    int n = strlen(a);
    nxt[0] = -1;
    while (i<n)
	if (j==-1||a[i]==a[j]) nxt[++i]=++j;
	else j = nxt[j];
}
bool kmp(char *a,char *b)
{
    int m = strlen(a);
    int n = strlen(b);
    getnxt(a);
    int i = 0;
    int j = 0;
    while (i<n)
    {
	if (j==-1||a[j]==b[i]) i++,j++;
	else j = nxt[j];
	if (j==m) return true;
    }

    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    ms(ans,0);
//	    cout<<"ans:"<<strlen(ans)<<endl;
	    for ( int i = 1 ; i <= n ; i++) scanf("%s",dna[i]);
	    int len = strlen(dna[1]);
//	    cout<<"len:"<<len<<endl;

	    for ( int i = 0 ; i < len ; i++)
	    {
		int cnt = 0 ;
		for ( int j = i ; j < len ; j++)
		{
		    tmp[cnt++]=dna[1][j];
		    tmp[cnt]='\0';
	//	    cout<<"tmp:"<<tmp<<endl;

		    bool match = true;
		    for ( int k = 2; k <= n ; k++)
			if (!kmp(tmp,dna[k]))
			{
			    match = false;
			    break;
			}

		    if (match)
		    {
			if (strlen(tmp)>strlen(ans))
			    strcpy(ans,tmp);
			else if (strlen(tmp)==strlen(ans)&&strcmp(tmp,ans)<0)
			    strcpy(ans,tmp);
		    }
		}
	    }
	    if (strlen(ans)==0) puts("IDENTITY LOST");
	    else printf("%s\n",ans);

	}

#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
}
