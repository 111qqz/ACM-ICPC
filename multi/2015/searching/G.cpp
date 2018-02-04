/*************************************************************************
	> File Name: code/2015summer/searching/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月24日 星期五 23时14分42秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
map<string, int> mp;
int n;
string tar;
string trans(string s1, string s2) {
    string s12 = "";
    for(int i = 0; i < n; i++) {
        s12 += s2[i], s12 += s1[i];
    }
    return s12;
}

int bfs(string s1, string s2) 
{
    queue<string> que;
    string s12 = trans(s1, s2);
    mp[s12] = 1;
    que.push(s12);
    while(!que.empty()) {
        string front = que.front();
        que.pop();
        if(front == tar) return mp[front];
        s1 = front.substr(0, n);
        s2 = front.substr(n, n);
        s12 = trans(s1, s2);
        if(mp[s12] > 0) return -1;
        mp[s12] = mp[front] + 1;
        que.push(s12);
    }
    return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int T, cas = 1;
    string s1, s2;
    cin >> T;
    while(T--) {
        mp.clear();
        cin >> n;
        cin >> s1 >> s2 >> tar;
        int ans = bfs(s1, s2);
        cout << cas++ << ' ' << ans << endl;
    }
    return 0;
}
