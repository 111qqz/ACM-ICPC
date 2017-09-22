/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 03时57分01秒
File Name :code/uva/253.cpp
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
pair<char,char>a[10],b[10];
char st[30];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%s",st+1)!=EOF)
	{
	   // for ( int i = 0 ; i <= 12 ; i++) cout<<"i:"<<i<<" "<<st[i]<<endl;
	   //
	   for ( int i = 1 ; i <= 3 ;i++)
	    {
		if (st[i]>st[7-i]) swap(st[i],st[7-i]);
		a[i]=make_pair(st[i],st[7-i]);
	    }
	   for ( int i = 7 ; i <= 9 ; i++)
	    {
		 if (st[i]>st[19-i]) swap(st[i],st[19-i]);
		b[i-6]=make_pair(st[i],st[19-i]);
	    }

	   sort(a+1,a+4);
	   sort(b+1,b+4);

	   bool flag = true;
//	   for ( int i = 1 ; i <= 3 ; i++)
//	    {
//	    	cout<<"a:"<<a[i].fst<<" "<<a[i].sec<<endl;
//		cout<<"b:"<<b[i].fst<<" "<<b[i].sec<<endl;
//		
//	    }
	   for ( int i = 1 ; i <=3 ;  i++)
	    {
		if (a[i].fst!=b[i].fst||a[i].sec!=b[i].sec)
		{
		    flag = false;
		    break;
		}
	    }

	    
	    if (flag)
	    {
		puts("TRUE");
	    }
	    else
	    {
		puts("FALSE");
	    }
	}

	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
