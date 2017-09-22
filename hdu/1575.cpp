/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 10时28分33秒
File Name :code/hdu/1575.cpp
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
const int N=12;
const int MOD = 9973;
struct Mat
{
    int mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
}A;
int n,k;

Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < n ; j++)
	    for (int k = 0 ; k < n ; k++)
		c.mat[i][j] =(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;

    return c;

}
Mat operator ^ (Mat a,int b)
{
    Mat c;
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < n ; j++ )
	    c.mat[i][j]=(i==j);
    while (b)
    {
	if (b&1) c = c * a;
	b = b>>1;
	a = a * a;
    }
    return c;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d %d",&n,&k);
	    A.clear();
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < n; j ++)
		    scanf("%d",&A.mat[i][j]);

	  //  for ( int i = 0 ; i < n ; i++)
//		for ( int j = 0 ; j < n ;j++) cout<<A.mat[i][j]<<" "<<endl;
	    Mat res;
	    res.clear();
	    res = A^k;

	    int ans = 0 ;
	    for ( int i = 0 ;  i < n ;i++) ans = (ans +res.mat[i][i])%MOD;

	    printf("%d\n",ans);

	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
