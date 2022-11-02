#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class graph{
    int n,A[MAX][MAX], chuaxet[MAX];
    public:
    void readdata();
    void reInit(){
        for(int i=1; i<=n; i++) chuaxet[i]=1;
    }
    void dfs(int u);
    bool strongly_connected();
};
void graph::readdata(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
        }
    }
}
void graph::dfs(int u){
    chuaxet[u]=0;
    for(int v=1; v<=n; v++){
        if(A[u][v]==1 && chuaxet[v]==1) dfs(v);
    }
}
bool graph::strongly_connected(){
    reInit();
    for(int u=1; u<=n; u++){
    	dfs(u);
    	for(int i=1;i<=n;i++){
    		if(chuaxet[i]==1)	return 0;
    	}
		reInit();
	}      
    return 1;
}
int main(){
    graph g;
    g.readdata();
    if(g.strongly_connected()){
    	cout<<"strongly connected";
	}	
    else{
    	cout<<"not strongly connected";
	}
	return 0;
    
}
