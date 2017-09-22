/* ***********************************************
Author :111qqz
Created Time :2016年03月15日 星期二 18时04分46秒
File Name :code/hdu/2089.cpp
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
int n,m;
int dp[30][2];
int digit[30];

int dfs (int pos,bool preis6,bool limit)  //pos表示从低到高的第几位，是从高位往低位递归的（也就是从左到又）
					  // preis6 表示上一个数字是否为6，
					  // limit表示该位置是否有限制。
{
//    cout<<pos<<" "<<preis6<<" "<<limit<<" "<<endl;
    if (pos==0) return 1; //到该位置表明找到了一个解.

    int res = 0 ;
    if (!limit&&dp[pos][preis6]!=-1) return dp[pos][preis6];  //如果不是limit位置，表示结果是通用的，而之前又算过的话，就可以直接调用这个结果。
    int mx = limit?digit[pos]:9; //mx第pos位置能取到的最大的数字..如果不是limit,则可以0..9任意取。
//    cout<<"mx:"<<mx<<endl;
    
    for ( int i = 0 ; i <= mx;  i++)
    {
	if (i==4||(i==2&&preis6)) continue;
	res += dfs(pos-1,i==6,limit&&i==mx); 
	//(limit&&i==mx)中limit的含义是。。如果当前一位不是limit位（即0..9可以随便取的位置）
	//，那么之后的位置也一定不是limit位置。
	//而i==mx部分的意思是，在当前位置的数字小于当前位置的数字能取的最大值（mx）之前，
	//后面位的数字随便取也不会超过上界。
    }
    
    if (!limit) dp[pos][preis6]=res;  //记忆化. 非limit位的结果才通用，不然没必要存。

    return res;

}
int solve ( int n)
{
    ms(digit,0);  //将数按照每一位存到digit数组中
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % 10;
	n/=10;
    }

    return dfs(len,false,true);

}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    
	    ms(dp,-1);
	    int ans = solve (m)-solve(n-1);

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
