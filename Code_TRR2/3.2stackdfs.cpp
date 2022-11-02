#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class graph{
    int n,A[MAX][MAX],chuaxet[MAX];
    public:
    void readdata();
    void init();
    void dfs(int u);
    void stackdfs(int u);
};
void graph::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   cin>>A[i][j];
    }
}
void graph::init(){
    for(int i=1;i<=n;i++)   chuaxet[i]=1;
}
void graph::stackdfs(int u){
    stack<int> nganxep;
    nganxep.push(u);
    cout<<u<<" ";
    chuaxet[u]=0;
    while(!nganxep.empty()){
        int s=nganxep.top();
        nganxep.pop();
        for(int t=1;t<=n;t++){
            if(A[s][t]==1&&chuaxet[t]==1){
                nganxep.push(s);
                nganxep.push(t);
                cout<<t<<" ";
                chuaxet[t]=0;
                break;
            }
        }
    }
}
int main(){
    graph g;
    g.readdata();
    g.init();
    g.stackdfs(1);
}
