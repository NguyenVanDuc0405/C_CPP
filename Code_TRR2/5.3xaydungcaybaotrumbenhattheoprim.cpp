#include<iostream>
#define MAX 100
using namespace std;
typedef struct{
    int     dau, cuoi, c;
}Edge;
class   graph{
    int     n, s, C[MAX][MAX], T[MAX][MAX], ne, neT, dH, chuaxet[MAX];
    Edge    G[MAX], Tree[MAX];
    public:
    void    readdata();
    void    init(){ for(int i=1; i<=n; i++) chuaxet[i]=1;   }
    void    dfs_tree(int u){
                chuaxet[u]=0;
                for(int v=1; v<=n; v++)
                    if((T[u][v]==1)&&(chuaxet[v]==1))   dfs_tree(v);
            }
    int     gets(){ return s;   }
    void    sort();
    void    prim(int s);
};
void    graph::readdata(){
    cin>>n>>s;
    ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>C[i][j];
            if((C[i][j]!=0)&&(i<j)){
                ne++;   G[ne].dau=i;    G[ne].cuoi=j;   G[ne].c=C[i][j];
            }
        }
}
void    graph::sort(){  
    for(int i=ne; i>=1; i--)
        for(int j=1; j<i; j++)
            if(G[j+1].c<G[j].c){
                Edge tmp=G[j];  G[j]=G[j+1];    G[j+1]=tmp;
            }
}
void    graph::prim(int s){
    neT=0;  dH=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) T[i][j]=0;
    sort();
    for(int eT=1; eT<=n-1; eT++){
        //chon canh
        int found=0;
        for(int e=1; e<=ne; e++){
            init(); dfs_tree(s);
            if(chuaxet[G[e].dau]+chuaxet[G[e].cuoi]==1){
                found=1;
                neT++;
                Tree[neT].dau=G[e].dau; Tree[neT].cuoi=G[e].cuoi; Tree[neT].c=G[e].c;
                T[G[e].dau][G[e].cuoi]=T[G[e].cuoi][G[e].dau]=1;
                dH=dH+G[e].c;
                break;
            }
        }
        if(found==0)    break; 
    }
    if(neT!=n-1)    cout<<"No spanning tree"<<endl;
    else{
        cout<<"dH = "<<dH<<endl;
        for(int eT=1; eT<=n-1; eT++)    cout<<Tree[eT].dau<<" "<<Tree[eT].cuoi<<endl;
    }
}
int main(){
    graph   g;  g.readdata();   g.prim(g.gets());   
}
