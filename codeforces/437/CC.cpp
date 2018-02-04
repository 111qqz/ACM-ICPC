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
	int siz_A = A.size(); 
	LL numA,numB; //吃的整张的两种披萨数目
	LL sumA = 0 ;
	LL sumB = 0;
	LL ans = 0 ;
	sort(A.begin(),A.end()); //从大到小排序，用最大的先填充
	for ( int i = 0 ; i < siz_A ; i++)
	{
	    sumA += A[i].s;
	}
	numA = sumA / s;
	sumA %=s; //不能吃整张的剩余

	sort(B.begin(),B.end(),cmp);
	int siz_B = B.size();
	for (  int i = 0 ; i < siz_B ; i++)
	{
	    sumB += B[i].s;
	}
	numB = sumB / s;
	sumB %= s;
	if (sumA + sumB >s)
	{
	    for ( int i = 0 ; i < siz_A; i++)
	    {
		ans = ans + 1LL*A[i].s*A[i].a;
	    }
	    for ( int i = 0 ; i < siz_B ; i++)
	    {
		ans = ans + 1LL * B[i].s * B[i].a;
	    }
	    cout<<ans<<endl;
	    return 0;
	}
	//都吃A
	//
	LL curA = 0,curB = 0 ;
	LL tmpA = 0 ;
	int AID = 0;
	for ( int i = 0 ; i < siz_A ; i++)
	{
	    tmpA += A[i].s;
	    if (tmpA>=sumA)
	    {
		AID = i;
		break;
	    }
	}
	tmpA = 0 ;
	for ( int i = 0 ; i <= AID ; i ++)
	{
	    if (i<AID)
	    {
		tmpA += A[i].s;
		curA = curA + 1LL*A[i].s * A[i].a;
	    }
	    else
	    {
		curA = curA + (sumA-tmpA)*A[i].a;
	    }
	}

	LL tmpB = 0 ;
 	LL BID = 0 ;
	for ( int i = 0 ; i < siz_B ; i++)
	{
	    tmpB += B[i].s;
	    if (tmpB>=sumB)
	    {
		BID = i;
	    }
	}
	tmpB = 0 ;
	for ( int i = 0 ; i <= BID ; i++)
	{
	    if (i < BID)
	    {
		tmpB += B[i].s;
		curA = curA + 1LL*B[i].s*B[i].a;
	    }
	    else
	    {
		curA = curA + (sumB-tmpB) *B[i].a;
	    }
	}

	//都吃B
	   //ID可以共用
	tmpA = 0 ;
	for ( int i = 0 ; i <= AID ; i++)
	{
	    if (i<AID)
	    {
		tmpA += A[i].s;
		curB = curB + A[i].s*A[i].b;
	    }
	    else
	    {
		curB = curB + (sumA-tmpA)*A[i].b;
	    }
	}
	tmpB = 0 ;
	//cout<<"curBBB:"<<curB<<endl;
	for ( int i = 0 ; i <= BID ; i++)
	{
	    if (i<BID)
	    {
		tmpB += B[i].s;
		curB = curB + B[i].s * B[i].b;
	    }
	    else
	    {
		curB = curB + (sumB-tmpB) * B[i].b;
	    }
	}
	//cout<<"curA:"<<curA<<" curB:"<<curB<<endl;
	//cout<<"AID:"<<AID<<" BID:"<<BID<<endl;
	LL mx = max(curA,curB);
	for ( int i = AID+1 ; i < siz_A ;  i++)
	    ans = ans + A[i].s * A[i].a;
	ans = ans + (A[AID].s-(sumA-tmpA)) * A[AID].a;
	//cout<<"after A ans:"<<ans<<endl;
	for ( int i = BID+1 ; i < siz_B ; i++)
	    ans = ans + B[i].s * B[i].b;
	ans = ans + (B[BID].s-(sumB-tmpB))*B[BID].b;

	ans += mx;
	cout<<ans<<endl;

	
	

	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
