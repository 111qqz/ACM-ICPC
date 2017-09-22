/* ***********************************************
Author :111qqz
Created Time :2016年02月26日 星期五 20时11分27秒
File Name :code/51nod/A.cpp
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

int n,k;
int cnt = 0 ;
int gcd(int a,int b)
{
    cnt++;
    cout<<"a:"<<a<<" b:"<<b<<endl;
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    

	cin>>n>>k;
	if (n%k==0)
	{
	    cout<<n/k<<endl;
	    return 0;
	}
	

	cnt = n / k;
	int r = n % k;
	if (k%2==1)
	{
	    cnt += k-n%k+1;
	}else if (r%2==0&&k%2==0)
	{
	    cnt += k-n%k;
	}
	else cnt = -1;

	cout<<cnt<<endl;



    return 0;
}
