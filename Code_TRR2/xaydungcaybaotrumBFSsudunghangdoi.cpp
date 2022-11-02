#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
typedef struct{
    int dau, cuoi;
} edge;
class graph{
    int n, s, A[MAX][MAX], chuaxet[MAX], d;
    edge T[MAX];
    public:
    void readdata();
    void init(){ for(int i=1;i<=n;i++) chuaxet[i]=1; }
    void bfstree(int u);
    int gets() { return s; }
};
void graph::readdata(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}
void graph::bfstree(int u){
    queue<int> hangdoi;
    hangdoi.push(u);
    chuaxet[u]=0;
    d=0;
    while(!hangdoi.empty()){
        int ss=hangdoi.front();
        hangdoi.pop();
        for(int t=1;t<=n;t++){
            if(A[ss][t]==1 && chuaxet[t]==1){
                hangdoi.push(t);
                d++;
                if(ss>t){
					T[d].dau=t; 
					T[d].cuoi=ss;
				} else {
					T[d].dau=ss; 
					T[d].cuoi=t;
				}
                chuaxet[t]=0;
            }
        }
    }
    if(d<n-1){
		cout<<"No spanning tree"<<endl;
	} else {
		cout<<"Queue BFS tree"<<endl;
		for(int i=1;i<=d;i++){
			cout<<T[i].dau<<" "<<T[i].cuoi<<endl;
		}
	}
}
int main(){
    graph g;
    g.readdata();
    g.init();
    g.bfstree(g.gets());
}
