#include<iostream>
#define MAX 100
#define INF 1000000
using namespace std;
class graph{
    int     n, s, a[MAX][MAX], truoc[MAX], d[MAX];
    public:
    void    readdata();
    int     gets(){ return s;   }
    void    bellmanford(int s);
};
void    graph::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j]==0)  a[i][j]=INF;
        }
}
void    graph::bellmanford(int s){
    //Khoi tao
    for(int v=1; v<=n; v++){
        d[v]=a[s][v];   truoc[v]=s;
    }
    d[s]=0;
    //Lap
    for(int k=1; k<=n-2; k++)
        for(int v=1; v<=n; v++)
            if(v!=s)
                for(int u=1; u<=n; u++)
                    if((d[u]!=INF)&&(a[u][v]!=INF)&&(d[v]>d[u]+a[u][v])){
                        d[v]=d[u]+a[u][v];  truoc[v]=u;
                    }
    //In ket qua
    for(int t=1; t<=n; t++)
        if(d[t]==INF)   cout<<"K/c "<<s<<" -> "<<t<<" = INF;"<<endl;
        else{
            cout<<"K/c "<<s<<" -> "<<t<<" = "<<d[t]<<"; ";
            cout<<t<<" <- ";
            int u=truoc[t];
            while(u!=s){
                cout<<u<<" <- ";    u=truoc[u];
            }
            cout<<s<<endl;
        }
}
int main(){
    graph   g;  g.readdata();   g.bellmanford(g.gets());    //cout<<"\nOk";
}
