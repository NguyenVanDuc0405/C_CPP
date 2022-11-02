#include<iostream>
#define MAX 100
#define INF 1000000
using namespace std;
class graph{
    int     n, s, a[MAX][MAX], d[MAX], truoc[MAX], chuaxet[MAX];
    public:
    void    readdata();
    int     gets(){ return s;   }
    void    dijkstra(int s);
};
void    graph::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j]==0)  a[i][j]=INF;
        }
}
void    graph::dijkstra(int s){
    //Khoi tao
    d[s]=0;     truoc[s]=s;
    for(int i=1; i<=n; i++) chuaxet[i]=1;
    chuaxet[s]=0;
    for(int v=1; v<=n; v++)
        if(v!=s){    d[v]=a[s][v];  truoc[v]=s;     }
    //Lap
    for(int k=1; k<=n-1; k++){
        //tim du=min{dz | z thuoc T hay chuaxet[z]=1}
        int du=INF, u;
        for(int z=1; z<=n; z++)
            if((chuaxet[z]==1)&&(du>d[z])){
                du=d[z];    u=z;
            }
        if(du!=INF){
            chuaxet[u]=0;
            //Cap nhat nhan tam thoi
            for(int v=1; v<=n; v++)
                if((chuaxet[v]==1)&&(a[u][v]!=INF)&&(d[v]>du+a[u][v])){
                    d[v]=du+a[u][v];    truoc[v]=u;
                }
        }
    }
    //In kq
    for(int t=1; t<=n; t++)
        if(d[t]==INF)   cout<<"K/c "<<s<<" -> "<<t<<" = INF;"<<endl;
        else{
            cout<<"K/c "<<s<<" -> "<<t<<" = "<<d[t]<<"; ";
            cout<<t<<" <- ";
            int u=truoc[t];
            while(u!=s){
                cout<<u<<" <- ";
                u=truoc[u];
            }
            cout<<s<<endl;
        }
}
int main(){
    graph g;    g.readdata();   g.dijkstra(g.gets());   //cout<<"\nOk";
}
