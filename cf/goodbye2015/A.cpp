
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
int x;
char st[25],nouse[33];
int main()
{
	
	scanf("%d %s %s",&x,nouse,st);
	if (st[0]=='w')
	{
	    if (x==6||x==5)
	    {
		cout<<53<<endl;
	    }
	    else
	    {
		cout<<52<<endl;
	    }

	}
	else
	{
	    if (x<=29)
	    {
		puts("12");
	    }
	    else if (x<=30)
	    {
		puts("11");
	    }
	    else
	    {
		puts("7");
	    }
	}

    return 0;
}
