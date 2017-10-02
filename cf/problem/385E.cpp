/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 10时37分58秒
File Name :385E.cpp
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
#define PB push_back
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
const int N=6;
LL n,dx,dy,sx,sy,t;
LL mod;
struct Mat
{
    LL mat[N][N];
    void clear()
    {
	ms(mat,0);
    }
    void pr()
    {
	for ( int i = 0 ; i < N ; i++)
	    for ( int j = 0 ; j < N; j++)
		printf("%lld%c",mat[i][j],j==N-1?'\n':' ');
    }
}M,M1;
Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < N ; i++)
	for ( int j = 0 ; j < N ; j++)
	    for ( int k = 0 ; k < N ;k++)
	    {
		a.mat[i][k]%=mod;
		b.mat[k][j]%=mod;
		c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j] %mod)%mod;
	    }
    return c;
}
Mat operator ^ (Mat a,LL b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < N ; i++) ret.mat[i][i] = 1;
    while (b>0)
    {
	if (b&1) ret = ret * a;
	b = b >> 1LL;
	a = a * a;
    }
    return ret;
}
pair<LL,LL> solve()
{
    if (t==0) return MP(sx,sy);
    if (n==1) return MP(1,1);
    M.clear();
    for ( int i = 0 ; i < N ; i++) M.mat[i][i] = 1;
    M.mat[0][1] = M.mat[0][2] = M.mat[0][3] = 1;
    M.mat[1][0] = M.mat[2][0] = M.mat[4][1] = M.mat[5][2] = 1;
    //puts("*******M***begin*******");
    //M.pr();
    //puts("*******M***end*********");
    M1.clear();
    dx = (dx + sx + sy)%mod;
    dy = (dy + sx + sy)%mod;
//    printf("sx:%lld sy:%lld  dx:%lld  dy:%lld\n",sx,sy,dx,dy);
    M1.mat[0][0] = (sx+dx)%n+(sy+dy)%n+1;
    M1.mat[1][0] = dx;
    M1.mat[2][0] = dy;
    M1.mat[3][0] = 1;
    M1.mat[4][0] = ((sx-1)%mod + mod)%mod;
    M1.mat[5][0] = ((sy-1)%mod + mod )%mod;

    //puts("*******M1 begin *************");
    //M1.pr();
    //puts("*******M1 end ***************");
    Mat ans;
    ans = (M^(t))*M1;
    //ans.pr();
    LL ret_x = (ans.mat[4][0] + 1)%mod;
    LL ret_y = (ans.mat[5][0] + 1)%mod;
    return MP(ret_x,ret_y);

}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>sx>>sy>>dx>>dy>>t;
	mod = n;
	auto ans = solve();
	cout<<ans.fst<<" "<<ans.sec<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
