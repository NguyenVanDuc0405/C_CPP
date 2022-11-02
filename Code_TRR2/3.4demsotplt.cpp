#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class graph{
    int n,A[MAX][MAX], chuaxet[MAX];
    public:
    void readdata();
    void init();
    void bfs(int u);
    void duyet();
};
void graph::readdata(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
        }
    }
}
void graph::init(){
    for(int i=1; i<=n; i++) chuaxet[i]=1;
}
void graph::bfs(int u){
    queue<int> hangdoi;
    hangdoi.push(u);
    chuaxet[u]=0;
    while(!hangdoi.empty()){
        int s=hangdoi.front();
        hangdoi.pop();
        for(int i=1; i<=n; i++){
            if(A[s][i]==1 && chuaxet[i]==1){
                hangdoi.push(i);
                chuaxet[i]=0;
            }
        }
    }
}
void graph::duyet(){
    int soTPLT=0;
    for(int i=1; i<=n; i++){
        if(chuaxet[i]){
            soTPLT++;
            bfs(i);
        }
    }
    cout<<soTPLT;
}
int main(){
    graph g;
    g.readdata();
    g.init();
    g.duyet();
    return 0;
}
