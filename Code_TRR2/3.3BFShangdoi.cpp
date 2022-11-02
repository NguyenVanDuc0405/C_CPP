#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class graph{
    int n;
    int A[MAX][MAX];
    public:
    bool chuaxet[MAX];
    void readdata();
    void set();
    void QueueBFS(int u);
};
void graph::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
        }
    }
}
void graph::set(){
    for(int i=1;i<=n;i++)   chuaxet[i]=true;
}
void graph::QueueBFS(int u){
    //khoitao
    queue<int> hangdoi;
    chuaxet[u]=false;
    hangdoi.push(u);
    //lap
    while(!hangdoi.empty()){
        int s=hangdoi.front();
        hangdoi.pop();
        cout<<s<<" ";
        for(int i=1;i<=n;i++){
            if(A[s][i]==1&&chuaxet[i]==true){
                chuaxet[i]=false;
                hangdoi.push(i);
            }
        }
    }
}
int main(){
    graph g;
    g.readdata();
    g.set();
    g.QueueBFS(1);
    return 0;
    
}
