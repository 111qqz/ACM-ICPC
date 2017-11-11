#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int N=200233;

struct SAM
{
    int next[N][26],fa[N],len[N];
    int pool,u,id[N],b[N];
    int mn[N],mx[N];

    inline void init()
    {
        pool=u=1;
        memset(next,0,sizeof(next));
        memset(len,0,sizeof(len));
        memset(mn,127,sizeof(mn));
        memset(fa,0,sizeof(fa));
        memset(id,0,sizeof(id));
    }

    inline void add(int v)
    {
        int now=++pool;
        len[now]=len[u]+1;
        while(!next[u][v] && u)
            next[u][v]=now,u=fa[u];

        if(!u)
            fa[now]=1;
        else
        {
            int q=next[u][v];
            if(len[q]==len[u]+1)
                fa[now]=q;
            else
            {
                int newq=++pool;
                len[newq]=len[u]+1;
                fa[newq]=fa[q];
                memcpy(next[newq],next[q],sizeof(next[q]));

                fa[q]=fa[now]=newq;

                while(next[u][v]==q)
                    next[u][v]=newq,u=fa[u];
            }
        }
        u=now;
    }

    inline void topsort(int lenn)
    {
        for(int i=1;i<=pool;i++)
            ++b[len[i]];
        for(int i=1;i<=lenn;i++)
            b[i]+=b[i-1];
        for(int i=1;i<=pool;i++)
            id[b[len[i]]--]=i;
    }

    inline void run(char *s)
    {
        int now=1;
        int tmp=0;
        int lenn=strlen(s+1);

        memset(mx,0,sizeof(mx));
        for(int i=1;i<=lenn;i++)
        {
            while(!next[now][s[i]-'a'] && now)
                now=fa[now],tmp=len[now];
            if(!now)
                now=1,tmp=0;
            else
                tmp++,now=next[now][s[i]-'a'];

            mx[now]=max(mx[now],tmp);
        }

        for(int i=pool;i>=1;i--)
        {
            int v=id[i];
            mn[v]=min(mn[v],mx[v]);
            if(mx[v] && fa[v])
                mx[fa[v]]=len[fa[v]];
        }
    }

    inline int calc()
    {
        int ans=0;
        for(int i=1;i<=pool;i++)
            ans=max(ans,mn[i]);
        return ans;
    }
}koishi;

int main()
{
    freopen("./in.txt","r",stdin);
    koishi.init();

    char s[N];
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
        koishi.add(s[i]-'a');
    koishi.topsort(strlen(s+1));

    while(scanf("%s",s+1)!=EOF)
        koishi.run(s);

    printf("%d\n",koishi.calc());

    return 0;
}
//spoj还我青春！！！
