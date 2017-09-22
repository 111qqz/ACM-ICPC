/* ***********************************************
Author :111qqz
Created Time :2016年02月24日 星期三 13时36分09秒
File Name :code/bzoj/1604.cpp
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
const LL linf =1E17;
const int N=1E5+7;
int n;
int father[N];
struct point
{
    LL x,y;
    int id; //合并的时候需要用到原来的序号
    point (){}
    point (LL _x,LL _y,int _id):x(_x),y(_y),id(_id){};

    bool operator<(point b)const
    {
	return y<b.y;
    }
}p[N];
LL c;

multiset<point>se;  //因为变换坐标后可能有相同的蒂娜所以要用multiset...?
multiset<point>::iterator it,it2;

queue<point>q;


int cnt[N];
int total;
bool cmp(point a,point b)
{
    return a.x<b.x;
}
void init()
{
    ms(cnt,0);
    ms(father,0);
    for ( int i = 1 ; i <N ; i++) father[i] =  i;

    total = n ;
}

int root( int x)
{
    if (x==father[x]) return x;
    else return father[x]=root(father[x]);
}

void merge(int x,int y)
{
    int rx=root(x);
    int ry=root(y);
    if (rx!=ry) father[rx]=ry,total--;
}

LL labs(LL x)
{
    if (x>0) return x;
    else return -x;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);

	cin>>n>>c;
	init();
	for ( int i = 1 ; i <= n ; i++)
	{
	    LL x,y;
	    cin>>x>>y;
	    p[i]=point(x+y,x-y,i);
	}

	sort(p+1,p+n+1,cmp);
     
	se.insert((point){0,linf,0});
	se.insert((point){0,-linf,0});
	se.insert(p[1]);
	int head = 1;

	for ( int i = 2 ; i <= n ; i++)
	{
	    while (p[i].x-p[head].x>c)
	    {
		se.erase(se.find(p[head]));  //注意multiset删除元素的时候的写法...写erase(p[head])的话会把所有相同的都删了
		head++;
//		cout<<"head:"<<head<<endl;
	    }
//	    cout<<"sad"<<endl;
	    

	    it = se.lower_bound(p[i]);
	    it2 = it;
	    it2--;
	    if (labs(it->y-p[i].y)<=c) merge(it->id,p[i].id);
	    if (labs(it2->y-p[i].y)<=c) merge(it2->id,p[i].id);

	    se.insert(p[i]);
	}


	for ( int i = 1 ;i <= n ; i++) 
	    cnt[root(i)]++;

	int mx = -1;
	for ( int i = 1 ; i <= n ; i++)
	    mx = max(mx,cnt[i]);

	cout<<total<<" "<<mx<<endl;





  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
