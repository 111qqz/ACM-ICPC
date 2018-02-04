#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>

const int N=1E6+7;
using namespace std;

long long ans;
char str[N];

void solve()
{
    long long len=strlen(str);
    bool flag=false;
//   for(int i=0;i<len;i++)
  //      {
    //        if(str[i]!='c'&&str[i]!='f') {ans=-1;return;}
      //  }
    for(int i=0;i<len;i++)
        {
            if(str[i]=='c') {flag=true;break;}
        }
    if(flag==false) {ans=(len+1)/2;return;}

    int tmp1=0,tmp=0;
    long long cnt=0;
    for(int i=0;i<len;i++)
        {
            if(str[i]=='c') {break;}
            tmp1++;
        }
    for(int i=0;i<len;i++)
        {
            if(str[i]=='c')
            {
                cnt++;
                if(cnt!=1)
                  {
                      if(tmp<2) {ans=-1;return;}
                  }
                tmp=0;
            }
            else tmp++;
        }
    if(tmp+tmp1<2) {ans=-1;return;}
    ans=cnt;
    return;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   int i,j;
   int T;
   scanf("%d",&T);
   int Case=1;
    while(T--)
        {
            scanf("%s",str);
            solve();
	    printf("Case #%d: %lld\n",Case++,ans);
        }
    return 0;
}

