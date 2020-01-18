#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin>>n;
    int x = n.back()-'0';

    if (x%2)
    {
        puts("-1");
    }
    else
    {
        puts("1");
    }
    return 0;
    
} // namespace std;

