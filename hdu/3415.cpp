/* ***********************************************
Author :111qqz
Created Time :2016年08月05日 星期五 18时02分36秒
File Name :code/hdu/3415.cpp
 ************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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
const int N=2E5+7;
int a[N],sum[N];
int n,k;
int on;
deque<int>dq;
inline bool read(int &num)
{
    char in;
    bool ISN = false;
    in=getchar();
    if (in==EOF) return false;
    while (in!='-'&&(in<'0'||in>'9')) in=getchar();
    if (in=='-') ISN = true,num=0;
    else num=in-'0';
    while (in=getchar(),in>='0'&&in<='9'){
	num*=10,num+=in-'0';
    }
    if (ISN) num=-num;
    return true;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif

    int T;
    //scanf("%d",&T);
    read(T);
    while (T--)
    {
	scanf("%d%d",&n,&k);
//	read(n);
//	read(k);
	on = n ;
	sum[0] = 0 ;
	for ( int i = 1 ; i <= n ; i++){
	    scanf("%d",&a[i]);
	   // read(a[i]);
	    a[i+n] = a[i];
	}
	n = n+k-1;
	for ( int i = 1 ; i <= n ; i++) sum[i] = sum[i-1] + a[i];
//	for ( int i = 1 ; i <= n ; i++) cout<<a[i]<<" "; cout<<endl;
//	for ( int i = 1 ; i <= n ; i++) cout<<sum[i]<<" "; cout<<endl;
	dq.clear();
	int ans = -inf;
	int l,r;
	//dq.push_back(0);  //作用并不是哨兵，因为区间[l,r]的和为sum[r]-sum[l-1]，我求前i(i<=k)个元素的前缀和的时候，答案为sum[i]-sum[0]
			    //因此有必要让0入队。
	for ( int i = 1 ; i <= n ; i++)  //枚举最后一个元素
	{
	    while (!dq.empty()&&dq.front()<i-k) dq.pop_front();  //由于前缀和的性质，最多保留k+1个元素而不是k个
	    while (!dq.empty()&&sum[dq.back()]>sum[i-1]) dq.pop_back();
	    dq.push_back(i-1);
	    if (sum[i]-sum[dq.front()]>ans)
	    {
		ans = sum[i] - sum[dq.front()];
		l = dq.front()+1;
		r = i ;
	    }
	}
	if (r>on) r%=on;
	printf("%d %d %d\n",ans,l,r);
    }

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
