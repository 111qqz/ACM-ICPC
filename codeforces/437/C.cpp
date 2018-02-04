/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 19时19分50秒
File Name :C.cpp
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
const int N=1E5+7;
int n;
LL s;
struct node
{
    LL s,a,b;
    void input()
    {
	cin>>s>>a>>b;
    }
    bool operator < (node rhs)
    {
	return a-b<rhs.a-rhs.b;
    }

}p[N];

bool cmp(node X,node Y)
{
    return X.b-X.a < Y.b-Y.a;
}
vector <node>A;
vector <node>B;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>s;
	for ( int i = 1 ; i <= n ; i++) p[i].input();

	for ( int i = 1 ; i <= n ; i++)
	{
	    if (p[i].a>p[i].b) A.PB(p[i]);
	    else B.PB(p[i]);
	}
	

	LL sumA = 0 ;
	LL numA = 0 ;
	LL rA = 0 ;
	for ( int i = 0 ; i < int(A.size()) ;  i++)
	{
	    sumA += A[i].s;
	}
	numA = sumA/s;
	rA = sumA%s;
	int cntA = 0 ;
	LL totA = 0 ;
	LL ans = 0 ;
	sort(A.begin(),A.end());

	for ( int i = 0 ; i  < int(A.size()) ; i++)
	{   
	    totA += A[i].s;
	    if (totA>=rA)


	
	

	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
