/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 03时00分35秒
File Name :code/uva/123.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <set>

using namespace std;

int main()
{
    set<string> ignore;
    multimap<string, string> r;
    string t;
    while (getline(cin, t) && t != "::")
        ignore.insert(t);
    while (getline(cin, t))
    {
        for (int i = 0; i < t.size(); i++)
            t[i] = tolower(t[i]);
        for (int i = 0; i < t.size(); i++)
        {
            if (!isalpha(t[i]))
                continue;
            string t2;
            int j = i;
            while (isalpha(t[j]))
            {
                t2 += t[j];
                j++;
            }
            if (!ignore.count(t2))
            {
                for (int k = 0; k < t2.size(); k++)
                    t2[k] = toupper(t2[k]);
                string t3 = t;
                t3.replace(i, t2.size(), t2);
                r.insert(make_pair(t2, t3));
            }
            i = j;
        }
    }
    for (map<string, string> :: iterator i = r.begin(); i != r.end(); i++)
        cout << i->second << endl;
    return 0;
}

