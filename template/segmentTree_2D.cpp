/* ***********************************************
Author :111qqz
Created Time :2017年11月09日 星期四 21时13分45秒
File Name :segmentTree_2D.cpp
************************************************ */

#include <bits/stdc++.h>
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
void update_x(int rooty, int rootx, int L, int R, int x, int a) //tree[rooty][rootx]对应的矩阵x方向上范围是[L,R]
{ 
	tree[rooty][rootx] += a; 
	if( L == R ) 
		return; 
	int mid = (L + R )/2; 
	if( x <= mid ) 
		update_x(rooty,( rootx << 1) + 1, L ,mid, x, a);
	else 
		update_x(rooty,( rootx << 1) + 2, mid + 1,R, x, a);
}
void update_y(int rooty, int L, int R, int y, int x, int a) //tree[rooty][rootx]对应的矩阵y方向上范围是[L,R] 
{ 
	update_x( rooty,0, 1, S, x,a); 
	if( L == R) return; 
	int mid = (L + R )/2;
	if( y <= mid ) 
		update_y( ( rooty << 1) + 1, L, mid,y, x, a); 
	else
		update_y( ( rooty << 1) + 2, mid+1, R, y, x, a); 
}
int query_x(int rooty, int rootx, int L, int R, int x1, int x2) 
{ 
	if (L == x1 && R == x2)
		return tree[rooty][rootx]; 
	int mid = (L + R) / 2; 
	if (x2 <= mid)
		return query_x(rooty, (rootx << 1) + 1, L, mid, x1, x2); 
	else if (x1 > mid)
		return query_x(rooty, (rootx << 1) + 2, mid + 1, R, x1, x2); 
	else
		return query_x(rooty, (rootx << 1) + 1, L, mid, x1, mid) + query_x(rooty, (rootx << 1) + 2, mid + 1, R, mid + 1, x2); 
}
int query_y(int rooty, int L, int R, int y1, int y2, int x1, int x2)
{
	if (L == y1 && R == y2)
		return query_x(rooty, 0, 1, S, x1, x2);
	int mid = (L + R) / 2;
	if (y2 <= mid)
		return query_y((rooty << 1) + 1, L,
			mid, y1, y2, x1, x2);
	if (y1 > mid)
		return query_y((rooty << 1) + 2,
			mid + 1, R, y1, y2, x1, x2);
	else
		return query_y((rooty << 1) + 1, L,
			mid, y1, mid, x1, x2) +
		query_y((rooty << 1) + 2,
			mid + 1, R, mid + 1, y2, x1, x2);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
