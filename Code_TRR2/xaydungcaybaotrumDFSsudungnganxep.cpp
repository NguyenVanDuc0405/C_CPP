#include<iostream>
#include<stack>
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
    void dfstree(int u);
    int gets() { return s; }
};
void graph::readdata(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}
void graph::dfstree(int u){
    stack <int> st;
	st.push(u);
	chuaxet[u]=0;
	d=0;
	while(!st.empty()){
		int s=st.top();
		st.pop();
		for(int v=1; v<=n; v++){
			if(A[s][v] == 1 && chuaxet[v]==1){
				d++;
				if(s>v){
					T[d].dau=v; 
					T[d].cuoi=s;
				} else {
					T[d].dau=s; 
					T[d].cuoi=v;
				}
				chuaxet[v]=0;
				st.push(s);
				st.push(v);
				break;
			}
		}
	}
	if(d<n-1){
		cout<<"No spanning tree"<<endl;
	} else {
		cout<<"Stack DFS tree"<<endl;
		for(int i=1;i<=d;i++){
			cout<<T[i].dau<<" "<<T[i].cuoi<<endl;
		}
	}
}
int main(){
    graph g;
    g.readdata();
    g.init();
    g.dfstree(g.gets());
}
