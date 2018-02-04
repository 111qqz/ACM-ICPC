#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1E5+10;
const double eps = 1e-8;
#define ms(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&(-x))
char buff[N];
int len = 0;
char ch;
void skip()
{
    while (ch=='\n'||ch==' '||ch=='\t') ch =getchar();
}
void TAG()
{
    len = 0;
    ch =getchar();
    while (ch!='>')
    {
	buff[len++] = ch;
	ch = getchar();
    }
    buff[len] = 0;
}
void STR()
{
    len = 0 ;
    while (ch!=' '&&ch!='\t'&&ch!='\n'&&ch!='<')
    {
	buff[len++] = ch;
	ch = getchar();
    }
    buff[len] = 0;
}

void pr( int len)
{
    for ( int i = 0 ; i < len ; i++) putchar(' ');
}
void solve()
{
    ch = ' ';
    int dep = 0;
    for ( ; ;)
    {
	skip();
	if (ch=='<')
	{
	    TAG();
	    if (buff[0]=='/')
	    {
		dep--;
		pr(dep);
	    }
	    else if (buff[len-1]=='/')
	    {
		pr(dep);
	    }
	    else 
	    {
		pr(dep);
		dep++;
	    }
	    printf("<%s>\n",buff);
	    if (strcmp(buff,"/html")==0) break;
	    ch = getchar();
	}
	else
	{
	    STR();
	    pr(dep);
	    printf("%s",buff);
	    //可能有多个字符串
	    skip();
	//    cout<<"buff:"<<buff<<endl;
	    while (ch!='<')
	    {
	//	cout<<"ch:"<<ch<<endl;
		STR();
		printf(" %s",buff);
		skip();
	    }
	    puts("");
	    //printf("\n");
	}

    }
}
int main(){
    	freopen("./in.txt","r",stdin);
//    	freopen("output","w",stdout);
    int cas = 0 ;
    int T;
    cin>>T;

   // cout<<"T:"<<T<<endl;
    while (T--)
    {
	printf("Case #%d:\n",++cas);
	solve();
    }
    return 0;
}
