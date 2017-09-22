/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 01时36分33秒
File Name :code/uva/10014.cpp
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
const int N=3E3+7;
int n;
double c[N];
double a,b;
string spa;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;        
	while (T--)
	{
	    scanf("%d",&n);
	    scanf("%lf %lf",&a,&b);

	//   cout<<"n:"<<n<<" a:"<<a<<" b:"<<b<<endl;
	    for ( int i = 1 ; i <= n ; i++) scanf("%lf",&c[i]);

	    double k = 0 ;
	    for ( int i = 1 ; i <= n ; i++) k+=(n-i+1)*c[i];

	    double  a1 = (n*a-2*k+b)/(n*1.0+1);   //写几组推下公式即可。

	    printf("%.2f\n",a1);
	    
	    if (T)
	    {
		puts(""); 
	    }

	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
