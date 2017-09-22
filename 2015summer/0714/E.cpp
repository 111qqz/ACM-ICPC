	  tmp = tmp*10+st[i]-'0';
	  dfs(i+1,sum+tmp);
	  if (x) dfs(i+1,sum-tmp);
    }
}
int main()
{
    while (scanf("%s",st)!=EOF)
    {
	  scanf("%lld",&n);
	   ans = 0;
	  len = strlen(st);
	  dfs(0,0);
	  cout<<ans<<endl;
    }
	return 0;
}
