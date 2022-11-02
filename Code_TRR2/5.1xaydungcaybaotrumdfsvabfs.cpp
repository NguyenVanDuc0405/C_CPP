#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class graph{
    int n, s, A[MAX][MAX], chuaxet[MAX];
    public:
    void readdata();
    void init(){ for(int i=1;i<=n;i++) chuaxet[i]=1; }
    void stackdfs(int u);
    void queuebfs(int u);
    int gets(){
    	return s;
	}
    
};
void graph::readdata(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
}
void graph::stackdfs(int u){
    stack<int> nganxep;
    chuaxet[u]=0;
    nganxep.push(u);
    while(!nganxep.empty()){
        int s=nganxep.top();
        nganxep.pop();
        for(int t=1;t<=n;t++){
            if(A[s][t]==1&&chuaxet[t]==1){
                nganxep.push(s);
                nganxep.push(t);
                chuaxet[t]=0;
                if(s<t)	cout<<s<<" "<<t<<endl;
                else	cout<<t<<" "<<s<<endl;
                break;
            }
        }
    }
}
void graph::queuebfs(int u){
    queue<int> hangdoi;
    chuaxet[u]=0;
    hangdoi.push(u);
    while(!hangdoi.empty()){
        int s=hangdoi.front();
        hangdoi.pop();
        for(int i=1;i<=n;i++){
            if(A[s][i]==1&&chuaxet[i]==1){
                chuaxet[i]=0;
                hangdoi.push(i);
                if(s<i)	cout<<s<<" "<<i<<endl;
                else	cout<<i<<" "<<s<<endl;
            }
        }
    }
}
int main(){
    graph g;
    g.readdata();
    cout<<"DFS tree"<<endl;	g.init();	g.stackdfs(g.gets());
    cout<<"BFS tree"<<endl;	g.init();	g.queuebfs(g.gets());
	
}
