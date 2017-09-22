/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 03时44分20秒
File Name :code/hdu/1841.cpp
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
const int N=1E6+7;
char a[N],b[N];
char tmp1[N],tmp2[N];

char * reverse(char *str)
{
    char *p,*q,temp;
    p = str,q = str;
    while (*p!='\0') p++;
    p--;
    while (q<p)
    {
	temp = *q;
	*q = *p;
	*p = temp;
	q++;
	p--;
    }
    return str;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(tmp1,0);
	    ms(tmp2,0);
	    scanf("%s",a);
	    scanf("%s",b);
	    int len1 = strlen(a);
	    int len2 = strlen(b);
	    int ans = len1+len2;

	    int cnt1 = 0 ;
	    int cnt2 = 0 ;
	    int mxl = 0 ;
	    for ( int i = 0 ; i < len1 && i < len2 ; i++)
	    {
		reverse(tmp2);
		tmp1[cnt1++]=a[i];
		tmp2[cnt2++]=b[len2-1-i];
		tmp1[cnt1]='\0';
		tmp2[cnt2]='\0';
		reverse(tmp2);
//		cout<<"tmp1:"<<tmp1<<" "<<tmp2<<endl;
		if (strcmp(tmp1,tmp2)==0)
		    mxl = i+1;
	    }

	    cnt1 = 0 ;
	    cnt2 = 0 ;
	    for ( int i = 0 ; i < len1 && i < len2 ; i++)
	    {
		reverse(tmp1);
		tmp1[cnt1++]=a[len1-1-i];
		tmp2[cnt2++]=b[i];
		tmp1[cnt1]='\0';
		tmp2[cnt2]='\0';
		reverse(tmp1);
//		cout<<"tmp1:"<<tmp1<<" tmp2:"<<tmp2<<endl;
		if (strcmp(tmp1,tmp2)==0)
		    mxl = max(mxl,i+1);
	    }

//	    cout<<"mxl:"<<mxl<<endl;
	    ans -=mxl;
	    printf("%d\n",ans);


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
