/* ***********************************************
Author :111qqz
Created Time :2017年11月03日 星期五 18时20分42秒
File Name :2774_SAM.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
#define fst first
#define sec second
#define lnxt l,m,rt<<1
#define rnxt m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=3E5;
struct SAM
{
    struct node
    {
        node *nxt[26],*fa;int len;
        node(int M) {len=M;fa=0;memset(nxt,0,sizeof(nxt));}
    };
    typedef node* P_node;
    P_node ro,lst;
    SAM() {ro=new node(0);lst=ro;}
    void Insert(char ch)
    {
        int ID=ch-'a';P_node p=lst,np=new node(lst->len+1);
        while (p&&!p->nxt[ID]) p->nxt[ID]=np,p=p->fa;
        if (!p) np->fa=ro; else
        {
            P_node q=p->nxt[ID];
            if (p->len+1==q->len) np->fa=q; else
            {
                P_node nq=new node(p->len+1);
                memcpy(nq->nxt,q->nxt,sizeof(q->nxt));
                nq->fa=q->fa;q->fa=nq;np->fa=nq;
                while (p&&p->nxt[ID]==q) p->nxt[ID]=nq,p=p->fa;
            }
        }
        lst=np;
    }
    void make_SAM(char *s) {for (int i=0; s[i]!='\0';i++) Insert(s[i]);}
    int LCS(char *s) //求此后缀自动机对应字符串与s的LCS
    {
        int ans=0,len=0;P_node p=ro;
        for (int i=0;s[i]!='\0';i++)
        {
            int ID=s[i]-'a';
            if (p->nxt[ID]) p=p->nxt[ID],len++; else
            {
                while (p&&!p->nxt[ID]) p=p->fa;
                if (!p) p=ro,len=0; else len=p->len+1,p=p->nxt[ID];
            }
            ans=max(ans,len); //从所有len中刷出最优解
        }
        return ans;
    }
};
SAM sam;
char A[N],B[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	scanf("%s %s",A,B);
//	cout<<A<<endl;
//	cout<<B<<endl;
	sam.make_SAM(A);
	int ans = sam.LCS(B);
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
