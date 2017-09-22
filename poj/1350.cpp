/* ***********************************************
Author :111qqz
Created Time :2016年01月20日 星期三 12时51分41秒
File Name :code/poj/1350.cpp
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
int n;
int cnt;

int get_next( int x)
{
    int a,b,len;
    char st[10];
    sprintf(st,"%d",x);
    len = strlen(st);
//    if (len<4) return -1;
    if (st[0]==st[1]&&st[1]==st[2]&&st[2]==st[3]&&st[3]==st[0]) return -1;
    for ( int i = 0 ; i < len ; i++)
	for ( int j =  i+1 ;  j < len ; j++)
	    if (st[i]<st[j]) swap(st[i],st[j]);

    sscanf(st,"%d",&a);
//    cout<<st<<endl;

    for ( int i = 0 ;i < len/2 ;  i++) swap(st[i],st[len-1-i]);
  //  cout<<st<<endl;

    sscanf(st,"%d",&b);

    printf("%d-%d=%d\n",a,b,a-b);
    return a-b;
    

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF&&n!=-1)
	{
	    cnt =  0 ;
	    printf("N=%d:\n",n);
	    if (n<1000||n>9999) 
	    {
		puts("No!!");
		continue;
	    }
	    while (1)
	    {
		cnt++;
		n = get_next(n);
	//	cout<<"n:"<<n<<endl;
		if (n==-1)
		{
		    puts("No!!");
		    break;
		}
		if (n==0||n==6174)
		{
		    printf("Ok!! %d times\n",cnt);
		    break;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
