/* ***********************************************
Author :111qqz
Created Time :2016年04月08日 星期五 13时59分29秒
File Name :code/bzoj/1637.cpp
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
const int N=1E5+7;
const int C=50000;
int total;
int ans;
int sum1[N],sum2[N];
int n;
struct node
{
    int sex;
    int x;

    bool operator < (node b)const
    {
	return x<b.x;
    }
}a[N];

int solve()
{

    //三种情况，包含左端点
    int cur =  0;
    int res2=-1;
    for ( int i = 1 ;i <= n ; i++) 
    {
	cur += a[i].sex;
//	cout<<"cur:"<<cur<<endl;
	if (cur==0)
	    res2 = a[i].x-a[1].x;
    }
    int res3 = -1;
    cur = 0 ;
    for ( int i = n ;  i >= 1 ; i--)
    {
	cur +=a[i].sex;
	if (cur==0)
	    res3 = a[n].x - a[i].x;
    }


    ms(sum1,-1);
    cur = C ;
    for ( int i = 1 ;i <= n ; i++)
    {
	cur += a[i].sex;
	if (sum1[cur]==-1) sum1[cur] = i;
    }
    cur = C;
    ms(sum2,-1);
    for ( int i  = n ; i >= 1 ; i--)
    {
	cur += a[i].sex;
	if (sum2[cur]==-1) sum2[cur] = i;
    }

//    for ( int i = C + 1 ; i <= C + 3 ; i++) cout<<sum2[i]<<endl;

    int res= 0;
    cur = C;
    for ( int i = 1 ; i <= n-1 ; i++)
    {
	cur += a[i].sex;
	int Y = total - cur+C;
//	cout<<"i:"<<i<<" Y:"<<Y-C<<" sum2[Y]:"<<sum2[Y]<<endl;
	if (Y>=0&&sum2[Y]!=-1&&a[sum2[Y]-1].x-a[i+1].x>0) res = max(res,a[sum2[Y]-1].x-a[i+1].x);
//	cout<<"res:"<<res<<endl;
    }

  //  cout<<"res:"<<res<<endl;
    res = max(res,res2);
    res = max(res,res3);
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	total = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>a[i].sex>>a[i].x;
	    if (a[i].sex==0) a[i].sex--;
	    total += a[i].sex;
	}
	total += C;

	sort(a+1,a+n+1);

	cout<<solve()<<endl;

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
