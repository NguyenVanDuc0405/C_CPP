#include<iostream>
#define MAX 100
using namespace std;
typedef struct{
    int dau, cuoi, c;
}Edge;
class   graph{
    int     n, C[MAX][MAX], T[MAX][MAX], chuaxet[MAX], dH, ne, neT;
    Edge    G[MAX], Tree[MAX];
    public:
    void    readdata();
    void    init(){ for(int i=1; i<=n; i++) chuaxet[i]=1;   }
    void    dfs_T(int u);   //Duyet tren cay theo chieu sau
    void    sort();
    void    kruskal();
};
void    graph::readdata(){
    cin>>n;
    ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>C[i][j];
            if((C[i][j]!=0)&&(i<j)){
                ne++;
                G[ne].dau=i;    G[ne].cuoi=j;   G[ne].c=C[i][j];
            }
        }
}
void    graph::dfs_T(int u){
    chuaxet[u]=0;
    for(int v=1; v<=n; v++)
        if((T[u][v]==1)&&(chuaxet[v]==1))   dfs_T(v);
}
void    graph::sort(){  //bubble sort
    for(int i=ne; i>=1; i--)
        for(int j=1; j<i; j++)
            if(G[j].c>G[j+1].c){
                Edge tmp=G[j+1];    G[j+1]=G[j];    G[j]=tmp;
            }
}
void    graph::kruskal(){
    //Khoi tao
    neT=0;  dH=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) T[i][j]=0;
    //Sap xep
    sort();
    //Lap
    for(int e=1; e<=ne; e++){
        //Kiem tra xem bo sung canh G[e] vao cay T co tao nen chu trinh hay khong
        init();
        dfs_T(G[e].dau);
        if(chuaxet[G[e].cuoi]==1){  //dau, cuoi thuoc 2 thanh phan lien thong khac nhau: OK
            neT++;  Tree[neT].dau=G[e].dau; Tree[neT].cuoi=G[e].cuoi;   Tree[neT].c=G[e].c;
            T[G[e].dau][G[e].cuoi]=T[G[e].cuoi][G[e].dau]=1;
            dH=dH+G[e].c;
        }
    }
    //In kq
    if(neT!=n-1)    cout<<"Do thi khong lien thong\n";
    else{
        cout<<"dH = "<<dH<<endl;
        for(int eT=1; eT<=neT; eT++)
            cout<<Tree[eT].dau<<" "<<Tree[eT].cuoi<<endl;
    }
}
int main(){ graph   g;  g.readdata();   g.kruskal();    //cout<<"\nOk";
}
