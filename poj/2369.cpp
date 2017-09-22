/*************************************************************************
	> File Name: code/poj/2369.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月15日 星期六 20时22分44秒
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
const int N = 3E6+7;
const LL MOD = 3221225473;

int a[N];

int Scan()
{
	int res = 0, ch, flag = 0;

	if((ch = getchar()) == '-')				//判断正负
		flag = 1;

	else if(ch >= '0' && ch <= '9')			//得到完整的数
		res = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';

	return flag ? -res : res;
};

int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int n;
    int T;
    T = Scan();
    while(T--)
    {
	scanf("%d",&n);
        for(int i=1;i<=n;i++)
            a[i] = Scan();
        LL ans = 1;
        for(int i=1;i<=n;i++)
        {
            int tmp = a[i];
            int num = 1;
            while(tmp != i)
            {
                tmp = a[tmp];
                num++;
            }
            ans = lcm(ans,num)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

