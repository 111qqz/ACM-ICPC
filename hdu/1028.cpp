/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 21时53分43秒
File Name :code/hdu/1028.cpp
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
const int N=125;
int n;
int a[N],tmp[N]; //a[i]表示每两个表达式运算时候的前一个表达式的x^i的系数，以及最后的表达式的x^i的系数
		//tmp[i]是每次运算临时存储指数用
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))         //第i个表达式的样子为：(1+x^i,+x^(2*i),....) 表示有一个i,两个i......
	{
	    for ( int i = 0 ; i <= n ; i++)  //所以指数都非负，所以最多有n个表达式对答案有贡献。
	    {
		a[i] = 1;
		tmp[i] = 0 ;
	    }
//每次只考虑两个表达式的运算，把运算结果放在第一个表达式里。
	    for ( int i = 2 ; i <= n ; i++)  //i表示第i个表达式
	    {
		for ( int j = 0 ; j <= n ; j++) //j表示第一个表达式的第j个变量
		{
		    for ( int k = 0 ; k+j<= n ; k+=i) //k表示第i个表达式的指数，0,i,2*i,3*i...
		    {
			tmp[j+k] += a[j];
		    }
		}

		for ( int j = 0 ; j <= n ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0  ;
		}
	    }

	//    for ( int i = 0 ; i <= n ; i++) cout<<"i:"<<i<<" "<<a[i]<<endl;

	    printf("%d\n",a[n]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
