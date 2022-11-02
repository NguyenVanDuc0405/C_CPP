#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class graph{
    int n,A[MAX][MAX],chuaxet[MAX];
    public:
        void readdata();
        void reInit(){
            for(int i = 1; i <= n; i++)
                chuaxet[i] = 1;
        }
        void dfs(int u){
            chuaxet[u] = 0;
            for(int v = 1; v <= n; v++)
                if(A[u][v] == 1 && chuaxet[v] == 1)
                    dfs(v);
        }
        int lienthong(){
            int dem = 0;
            for(int i = 1; i <= n; i++){
                if(chuaxet[i] == 1){
                    dem++;
                    dfs(i);
                }
            }
            return dem;
        }

        void canhcau();
};
void graph:: readdata(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A[i][j];
}
void graph::canhcau(){
    reInit();
    int lt = lienthong();
    for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			if(A[i][j]) {
                reInit();
				A[i][j] = 0;
				A[j][i] = 0;
				int temp = lienthong();
				if(temp > lt)
					cout << i << " " << j << endl;
				A[i][j] = 1;
				A[j][i] = 1;
			}
	cout << endl;
}
int main() {
    graph g;
    g.readdata();
    g.canhcau();
    return 0;
}
