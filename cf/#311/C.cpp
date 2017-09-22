/*************************************************************************
	> File Name: code/cf/#311/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月19日 星期三 20时09分26秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int MAX = 100005;
const int INF = 100000*200;

struct Leg
{
    int l;
    int d;
};

int n;
Leg leg[MAX];
int cnt[205]; //每种代价的桌腿个数
int total; //总代价

bool cmp(Leg l1, Leg l2)
{
    return l1.l < l2.l;
}

void input()
{
    total = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &leg[i].l);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &leg[i].d);
        total += leg[i].d;
    }
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    sort(leg, leg + n, cmp);
    int i = 0, num, temp, cost, ans = INF;
    while(i < n)
    {
        num = 0;
        cost = total;
        for(temp = i; leg[temp].l == leg[i].l; temp++)
        {
            num++;
            cost -= leg[temp].d;
        }
        num--;
        for(int j = 200; j >= 1 && num > 0; j--)
        {
            cost -= min(num, cnt[j])*j;
            num -= cnt[j];
        }
        ans = min(ans, cost);
        for(temp = i; leg[temp].l == leg[i].l; temp++)
            cnt[leg[temp].d]++;
        i = temp;
    }
    printf("%d\n", ans);
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        input();
        solve();
    }
    return 0;
}

