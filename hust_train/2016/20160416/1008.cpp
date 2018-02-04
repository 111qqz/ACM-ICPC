/* ***********************************************
Author :111qqz
Created Time :2016年04月16日 星期六 15时11分45秒
File Name :code/hust/20160416/1008.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define INF 0x3F3F3F3F
using namespace std;

const int SIZE = 1005;
int dist[SIZE];
int G[SIZE][SIZE];
bool vis[SIZE];

struct HeapElement {
    int key, value;    
};
void swap(HeapElement &ha, HeapElement &hb) {
    int key = ha.key;
    int value = ha.value;
    ha.key = hb.key;
    ha.value = hb.value;
    hb.key = key;
    hb.value = value;
};
// 使用邻接表储存图，线性表储存堆 
struct MinHeap {
    HeapElement heap[SIZE];
    int n;    // 顶点数    
        
    void makeheap() {
        for (int i = n/2; i > 0; -- i)
            siftDown(i);
    };
    void siftUp(int index) {
        int k = index;
        while (k > 1) {
            if (heap[k].value < heap[k/2].value) {
                swap(heap[k],heap[k/2]);    
            } else {
                break;    
            }
            k /= 2;    
        }
    };
    void siftDown(int index) {
        int k = index;
        while (k*2 <= n) {
            k *= 2;
            if (k < n && heap[k].value > heap[k+1].value) {
                ++ k;    
            }
            if (heap[k].value < heap[k/2].value) {
                swap(heap[k],heap[k/2]);
            } else {
                break;    
            }    
        }
    };
    void insert(HeapElement element) {
        heap[++n] = element;
        siftUp(n);    
    };
    void decrease(int index) {
        int x = heap[index].value;
        int y = heap[n].value;
        n -= 1;
        
        // 若删除节点位于最末位置，则删除成功，无需其他操作。 
        if (index == n+1) 
            return;
        
        heap[index] = heap[n+1];
        if (y >= x) {
            siftDown(index);    
        } else {
            siftUp(index);    
        }
    };
    int decreaseMin() {
        int x = heap[1].key;
        decrease(1);
        return x;
    };
}H;

void dijkstra(int src, int n) {
    int i, j, w;
    bool flag;
    
    for (i = 1; i <= n; ++ i) {
        if (G[i][src] != INF) {
            dist[i] = G[src][i];
            HeapElement h = {i, dist[i]};
            H.insert(h);    
        } else {
            dist[i] = INF;    
        }    
    }
    
    memset(vis, false, sizeof(vis));
    vis[src] = true;
    dist[src] = 0;
    

    
    for (i = 1; i < n; ++ i) {

        int node = H.decreaseMin();
        vis[node] = true;

        for (w = 1; w <= n; ++ w) {
            flag = false;
            if (!vis[w] && G[node][w] != INF) {
                if (dist[node] < dist[w] - G[node][w]) {
                    dist[w] = dist[node] + G[node][w];
                        
                } 
                for (j = 1; j <= H.n; ++ j) {
                        if (H.heap[j].key == w) {
                            H.heap[j].value = dist[w];
                            flag = true;
                            break;    
                        }    
                    }    
                
                if (!flag) {
                    HeapElement h = {w, dist[w]};
                    H.insert(h);
                } else {
                    H.siftUp(j);
                }
            }
        }    
    }
};

void init(int n) {
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            G[i][j] = INF;
    H.n = 0;
};

int main()
{
    int N, M, a, b, c;
    int C,D,K;
    
    freopen("code/in.txt","r",stdin); 
    while (scanf("%d%d%d%d%d",&N,&M,&C,&D,&K)!=EOF) {
        init(N);
        
        for (int i = 0; i < M; ++ i) {
            scanf("%d%d%d",&a,&b,&c);
            if (G[a][b] > c) {
                G[a][b] = c;
            }
        }
        
        dijkstra(C, N);
	for ( int i = 1 ; i <= N ; i++) cout<<"i:"<<i<<" dist[i]:"<<dist[i]<<endl;
        if (dist[D]>K)
	{
	    puts("Sorry");
	}
	else 
        printf("%d\n",dist[D]);    
    }
}
