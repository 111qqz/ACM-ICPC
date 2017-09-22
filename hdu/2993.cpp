/* ***********************************************
Author :111qqz
Created Time :Mon 26 Sep 2016 02:35:01 AM CST
File Name :code/hdu/2993.cpp
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
LL sum[N];
int n,k;
int q[N];
namespace IO {
    const int MT = 10 * 1024 * 1024;  /// 10MB 请注意输入数据的大小！！！
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;
    /// 要记得把这一行添加到main函数第一行！！！
    void begin() {
        IO_PTR = 0;
        IO_SZ = fread (IO_BUF, 1, MT, stdin);
    }
    template<typename T>
    inline bool scan_d (T & t) {
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' && (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
            IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        bool sgn = false;
        if (IO_BUF[IO_PTR] == '-') sgn = true, IO_PTR ++;
        for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9'; IO_PTR ++)
            t = t * 10 + IO_BUF[IO_PTR] - '0';
        if (sgn) t = -t;
        return true;
    }
    inline bool scan_s (char s[]) {
        while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n') ) IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        int len = 0;
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
            s[len ++] = IO_BUF[IO_PTR], IO_PTR ++;
        s[len] = '\0';
        return true;
    }
};
void read( int  &r)
{
    char c;
    while (c = getchar() ,c<'0'|| c>'9');
    r = c-'0';
    while (c = getchar (),c>='0'&& c<='9') r = r*10 + c - '0';
}
LL Up(int j,int k)
{
    return sum[j]-sum[k];
}
LL Down( int j,int k)
{
    return 1LL*(j-k);
}
double Dp(int i,int j)
{
    return (sum[i]-sum[j])*1.0/(i-j);
}
using namespace IO;
int main()
{
	
	IO::begin();
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d%d",&n,&k)!=EOF)
	{
	    sum[0] = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
	//	IO::scan_d(x);
		cin>>x;
		cout<<"x:"<<x<<endl;
		sum[i] = sum[i-1] + x;
	    }
	    int head,tail;
	    head = tail = 0 ;
	   // q[tail++] = 0 ;
	    double ans = 0 ;
	    for ( int i = k ; i <= n ; i++)
	    {

		while (head+1<tail&&Up(i-k,q[tail-1])*Down(q[tail-1],q[tail-2])<=Up(q[tail-1],q[tail-2])*Down(i-k,q[tail-1])) tail--;
		q[tail++] = i-k;
		while (head+1<tail&&Up(i,q[head])*Down(q[head],q[head+1])<=Up(q[head],q[head+1])*Down(i,q[head])) head++;
		ans = max(ans,Dp(i,q[head]));

	    }
	    printf("%.2f\n",ans);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
