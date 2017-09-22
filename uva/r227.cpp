#include<stdio.h>
#include<string.h>
const int LEN=5;
const int MAX=100;
const int y[]={0,0,1,-1};
const int x[]={-1,1,0,0};
char map[LEN][LEN];
int tra[110];
bool legal(int pos){
    return 0<=pos&&pos<LEN;
}
void Pmap(){
    for(int cow=0;cow<LEN;cow++){
        printf("%c",map[cow][0]);
        for(int col=1;col<LEN;col++)
            printf(" %c",map[cow][col]);
        printf("\n");
    }
}
int main(){
    tra['A']=0;
    tra['B']=1;
    tra['R']=2;
    tra['L']=3;

    bool first=true;
    int Case=0;
    //freopen("in.txt","r",stdin);
    //freopen("out","w",stdout);
    int bx,by;
    while(gets(map[0])){
        if(map[0][0]=='Z')break;
        for(int col=1;col<LEN;col++)
            gets(map[col]);
        for(int i=0;i<LEN;i++)
            for(int j=0;j<LEN;j++)
                if(map[i][j]==' '){
                    bx=i;by=j;
                }
        bool ok=true;
        char c;
        while(scanf(" %c",&c),c!='0'){
            if(!ok)continue;
            int nx=bx+x[tra[c]],ny=by+y[tra[c]];
            if(!legal(nx)||!legal(ny)){
                ok=false;
                continue;
            }
            map[bx][by]=map[nx][ny];
            map[nx][ny]=' ';
            bx=nx;by=ny;
        }
        getchar();
        if(first)
            first=false;
        else
            printf("\n");
        printf("Puzzle #%d:\n",++Case);
        if(ok)
            Pmap();
        else
            printf("This puzzle has no final configuration.\n");
    }
    return 0;
}
