/* ***********************************************
Author :111qqz
Created Time :2016年01月29日 星期五 17时46分13秒
File Name :code/uva/10719.cpp
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
const int N=1E4+7;
int k;
int n;
int a[N];
int p[N];
int ans[N];

void in(string x)
{
    x = x+" ";
    int p = x.find(' ');
    while (p!=-1)
    {
	string sval = x.substr(0,p);
	int val;
//	cout<<"sval:"<<sval<<endl;
	sscanf(sval.c_str(),"%d",&val);
	n++;
//	cout<<"val:"<<val<<endl;
	a[n]=val;
	x.erase(0,p+1);
	p = x.find(' ');
    }

    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d",&k)!=EOF)
	{
	    ms(ans,0);
	    getchar();
	    n = 0 ;
	    string st;
	    getline(cin,st);
	    in(st); 
	    //check input
	    //for ( int i = 1 ; i <= n ; i++) cout<<a[i]<<endl;
	    for ( int i = 0 ; i <= n ; i++)
	    {
		p[i]=a[n-i];
	    }
	    n--;
	//    for ( int i = n  ;  i >= 0 ; i--) cout<<p[i]<<endl;

	    for ( int i = n ; i >=1 ; i--)
	    {
		ans[i-1]+=p[i];
		p[i-1]+=k*ans[i-1];
	    }

	    printf("q(x): ");
	    for ( int i = n-1 ; i >0  ;i--)
	    {
		printf("%d ",ans[i]);
	    }
	    printf("%d\n",ans[0]);
	    printf("r = %d\n",p[0]);
	    puts("");

	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
