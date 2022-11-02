#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class graph{
    int n,A[MAX][MAX],chuaxet[MAX],s,t,truoc[MAX];
    public:
    void readdata();
    void init(){
        for(int i=1;i<=n;i++){
            chuaxet[i]=1;
            truoc[i]=0;
        }
    }
    void stackdfs(int u);
    void queuebfs(int u);
    void pathst();
    int gets(){
        return s;
    }
    int truoct(){
        return truoc[t];
    }
};
void graph::readdata(){
    cin>>n>>s>>t;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
        }
    }
}
void graph::stackdfs(int u){
    stack<int> nganxep;
    nganxep.push(u);
    chuaxet[u]=0;
    while(!nganxep.empty()){
        int s=nganxep.top();
        nganxep.pop();
        for(int t=1; t<=n; t++){
            if(A[s][t]==1 && chuaxet[t]==1){
                nganxep.push(s);
                nganxep.push(t);
                chuaxet[t]=0;
                truoc[t]=s;
                break;
            }
        }
    }
}
void graph::queuebfs(int u){
    queue<int> hangdoi;
    hangdoi.push(u);
    chuaxet[u]=0;
    while(!hangdoi.empty()){
        int s=hangdoi.front();
        hangdoi.pop();
        for(int t=1; t<=n; t++){
            if(A[s][t]==1 && chuaxet[t]==1){
                hangdoi.push(t);
                chuaxet[t]=0;
                truoc[t]=s;
            }
        }
    }
}
void graph::pathst(){
    if(truoc[t]==0){
        cout<<"no path";
    } 
    else{
        cout<<t<<" ";
        int u=truoc[t];
        while(u!=s){
            cout<<u<<" ";
            u=truoc[u];
        }
        cout<<s<<"\n";
    }
}
int main(){
    graph g;
    g.readdata();
    g.init();
    g.stackdfs(g.gets());
    if(g.truoct()!=0){
        cout<<"DFS path: ";
        g.pathst();
        g.init();
        g.queuebfs(g.gets());
        cout<<"BFS path: ";
        g.pathst();
    }else{
        cout<<"no path\n";
    }
}
