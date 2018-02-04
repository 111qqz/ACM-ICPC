#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define test freopen("test.txt","r",stdin)  
#define maxn 20001
#define mod 1000000007
#define eps 1e-9
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//**************************************************************************************

vector<int> Q;
struct node
{
    int x,y;
};
struct point
{
    double x;
    int y;
};
bool cmp(point a,point b)
{
    return a.x<b.x;
}
double a[maxn];
vector<point> T;
int main()
{
    node tmp;
    tmp.x=0,tmp.y=0;
    int n=read();
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    int flag=1;
    
    for(int i=1;i<=n;i++)
    {
        if(fabs(a[i])>1&&a[i]>0)
        {
            Q.push_back(i);
            flag=0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            point kiss;
            kiss.x=a[i];
            kiss.y=i;
            T.push_back(kiss);
	    cout<<"   "<<kiss.x<<endl;
        }
    }
    if(T.size()!=0)
    {


	
        sort(T.begin(),T.end(),cmp);

    	
        for(int i=0;i<T.size()-1;i++)
        {
	   // cout<<T[i].x<<endl;
            if(T[i].x*T[i+1].x>1)
            {
                Q.push_back(T[i].y);
                Q.push_back(T[i+1].y);
                i++;
                flag = 0;
            }
        }
    }
    a[0]=0;
    if(flag)
    {
        int max1=0,max2=0;
        int max3=0;
        for(int i=n;i>=1;i--)
        {
            if(a[i]<0)
            {
                if(fabs(a[i])>=fabs(a[max1]))
                {
                    max2=max1;
                    max1=i;
                }
                else if(fabs(a[i])>=fabs(a[max2]))
                {
                    max2=i;
                }
            }
            else
            {
                if(fabs(a[i])>=fabs(a[max3]))
                {
                    max3=i;
                }
            }
        }
        
        if(max3==0)
        {
            if(max2==0)
                Q.push_back(max1);
            else
                Q.push_back(max1),Q.push_back(max2);
        }
        else
        {
            if(max2==0)
                Q.push_back(max3);
            else
            {
                double tmp1=a[max3],tmp2=a[max1]*a[max2];
                if(tmp1-tmp2>-eps)
                    Q.push_back(max3);
                else
                    Q.push_back(max1),Q.push_back(max2);
            }
        }

    }
    sort(Q.begin(),Q.end());
    cout<<Q.size()<<endl;
    for(int i=0;i<Q.size();i++)
        printf("%d ",Q[i]);
    printf("\n");
}
