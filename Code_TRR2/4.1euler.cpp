#include<iostream>
#include<stack>
#define MAX 100
using namespace std;
class graph{
    int     n, s, A[MAX][MAX];
    public:
    void    readdata();
    int     gets(){ return s;   };
    void    euler(int u);
};
void    graph::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin>>A[i][j];
}
void    graph::euler(int u){
    stack<int>  stack, ce;
    stack.push(u);
    while(!stack.empty()){
        int s=stack.top(), isolated=1;
        for(int t=1; t<=n; t++)
            if(A[s][t]==1){
                isolated=0;
                stack.push(t);
                A[s][t]=A[t][s]=0;
                break;
            }
        if(isolated==1){
            ce.push(s);
            stack.pop();
        }
    }
    while(!ce.empty()){
        cout<<ce.top()<<" ";  ce.pop();
    }
}
int main(){ graph   g;  g.readdata();   g.euler(g.gets());  
}
