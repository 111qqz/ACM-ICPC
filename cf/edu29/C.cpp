/* ***********************************************
Author :111qqz
Created Time :2017年09月24日 星期日 14时26分54秒
File Name :C.cpp
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
LL k;
int x,y;
int a[5][5],b[5][5];
map< pair<int,int>,bool >mp;
vector < pair<int,int> >seq; //记录游戏序列，肯定不会很长。
int nx( int x,int y)
{
    return a[x][y];
}
int ny ( int x,int y)
{
    return b[x][y];
}
LL s_ali( int x,int y)
{
    
    if (x==2&&y==1) return 1;
    if (x==3&&y==2) return 1;
    if (x==1&&y==3) return 1;
    return 0;
}
LL s_bob( int x,int y)
{
    if (y==2&&x==1) return 1;
    if (y==3&&x==2) return 1;
    if (y==1&&x==3) return 1;
    return 0;
}
void print( pair<LL,LL>score)
{
    
    printf("ali:%lld bob:%lld\n ",score.fst,score.sec);
}

/* 几种可能错误:
 * k的大小不足以出现循环节
 * 比分序列的时候为了找循环节开始的位置存了最后一个元素进去（第一次循环的开始），但是后面算的时候要去除
 * k的大小是LL,记得各种地方的LL
 */
pair<LL,LL> solve(int x,int y)
{

    pair< LL,LL >ret;
    ret.fst=ret.sec=0;
    seq.clear();
    mp.clear();
    seq.PB(MP(x,y));
    mp[MP(x,y)]=true;
    while (1)
    {
	int xx = nx(x,y);
	int yy = ny(x,y);
	seq.PB(MP(xx,yy));
	if (mp[MP(xx,yy)])
	{
	    break;
	}
	mp[MP(xx,yy)] = true;
	x = xx;
	y = yy;
    }


    int siz = seq.size();
 //   for ( int i = 0 ; i < siz ; i++) printf("(%d %d)\n",seq[i].fst,seq[i].sec);
    pair<int,int>tar = seq[siz-1];
    int st,en;
    st = -1;
    en = siz-1;
    for ( int i = 0 ; i < siz ; i++)
    {
	pair<int,int> u = seq[i];
	if (u.fst==tar.fst&&u.sec==tar.sec)
	{
	    st = i;
	    break;
	}
    }
    //printf("st:%d\n",st);
    seq.pop_back();
    siz = seq.size();
    LL ali_sum,bob_sum;
    ali_sum=bob_sum=0LL;
    //有一种可能是k比循环节的开始要小。
    if (k<st) //没有循环节
    {
	for ( int i = 0 ; i < k ; i++)
	{
	    int x = seq[i].fst;
	    int y = seq[i].sec;
	    ret.fst += s_ali(x,y);
	    ret.sec += s_bob(x,y);
	}
//	print(ret);
	return ret;
    }

    for ( int i = 0 ; i < st ; i++)
    {
	int x = seq[i].fst;
	int y = seq[i].sec;
	ali_sum+=s_ali(x,y);
	bob_sum+=s_bob(x,y);
    }
    k-=st; //剩下的是循环节部分.
    LL circle_len = siz-st;
    //printf("cir_len:%lld\n",circle_len);
    LL circle_ali=0;
    LL circle_bob=0; //一个循环节中的得分.
    for ( int i = st ; i < siz ; i++)
    {
	int x = seq[i].fst;
	int y = seq[i].sec;
	circle_ali+=1LL*s_ali(x,y);
	circle_bob+=1LL*s_bob(x,y);
    }
    LL num = k/circle_len;
    LL mod = k%circle_len;
    //printf("num:%lld  mod:%lld\n",num,mod);
    ret.fst = 1LL*ali_sum;
    ret.sec = 1LL* bob_sum;
    //print(ret);
    ret.fst += 1LL*num*circle_ali;
    ret.sec += 1LL*num*circle_bob;
   // print(ret);
    for ( int i = st ; i< st+mod ; i++)
    {
	int x = seq[i].fst;
	int y = seq[i].sec;
	ret.fst += 1LL*s_ali(x,y);
	ret.sec += 1LL*s_bob(x,y);
    }

    return ret;

    
}
	    
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>k>>x>>y;
	for ( int i = 1 ; i <= 3 ; i++)
	    for ( int j = 1 ; j <= 3 ; j++)
		scanf("%d",&a[i][j]);
	for ( int i = 1 ; i <= 3 ; i++)
	    for ( int j = 1 ; j <= 3 ; j++)
		scanf("%d",&b[i][j]);
	pair<LL,LL> ans = solve(x,y);
	printf("%lld %lld\n",ans.fst,ans.sec);



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
