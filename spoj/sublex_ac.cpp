// spoj7528
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#define LL long long
#define inf 1<<30
#define Pi acos(-1.0)
#define free(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
using namespace std;
 
const int maxn=1000010;
char s[maxn],ans[maxn];
int n,K;
 
namespace SAM {
    int ch[maxn<<1][26],par[maxn<<1],len[maxn<<1],Dargen,last,sz;
    int b[maxn],id[maxn<<1],sum[maxn<<1];
    void Extend(int c) {
        int np=++sz,p=last;last=np;
        len[np]=len[p]+1;
        for (;p && !ch[p][c];p=par[p]) ch[p][c]=np;
        if (!p) par[np]=Dargen;
        else {
            int q=ch[p][c];
            if (len[p]+1==len[q]) par[np]=q;
            else {
                int nq=++sz;len[nq]=len[p]+1;
                memcpy(ch[nq],ch[q],sizeof(ch[nq]));
                par[nq]=par[q];
                par[np]=par[q]=nq;
                for (;p && ch[p][c]==q;p=par[p]) ch[p][c]=nq;
            }
        }
    }
    void build() {
        Dargen=last=sz=1;
        for (int i=1;i<=n;i++) Extend(s[i]-'a');
    }
    void pre() {   //貌似这个东西是精髓?一个O(n)的基数排序之后根据parent树的性质对Right集合的大小和一些其它奇奇怪怪的东西进行O(n)的预处理
        for (int i=1;i<=sz;i++) b[len[i]]++;
        for (int i=1;i<=n;i++) b[i]+=b[i-1];
        for (int i=1;i<=sz;i++) id[b[len[i]]--]=i;
        for (int i=sz,S=0;i>=1;i--,S=0) {   //sum记录当前节点不同子串个数
            for (int j=0;j<26;j++) S+=sum[ch[id[i]][j]];
            sum[id[i]]=S+1;
        }
    }
    void query(int K) {
        int now=Dargen,tot=0;
        while (K) {
            for (int i=0;i<26;i++) if (ch[now][i]) {
                    if (sum[ch[now][i]]>=K) {
                        ans[++tot]='a'+i,K--,now=ch[now][i];
                        break;
                    }
                    else K-=sum[ch[now][i]];
                }
        }
        ans[++tot]='\0';
    }
}
using namespace SAM;
 
int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    build();
    pre();
    int q;scanf("%d",&q);
    while (q--) {
        scanf("%d",&K);
        query(K);
        puts(ans+1);
    }
    return 0;
}
