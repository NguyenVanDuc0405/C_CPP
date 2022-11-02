#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class graph{
    int n, s, A[MAX][MAX];
    public:
    void readdata() {
        cin >> n >> s;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) cin >> A[i][j];
        }
    }
    int gets() {
        return s;
    }
    
    void euler(int u) {
        stack<int> hangdoi;
        vector<int> a;
        hangdoi.push(u);
        while(hangdoi.size()) {
            int v = hangdoi.top();
            int sz = 1;
            for(int i = 1; i <= n; i++) {
                if(A[v][i]) {
                    A[v][i] = A[i][v] = 0;
                    sz = 0;
                    hangdoi.push(i);
                    break;
                }
            }
            if(sz) {
                hangdoi.pop();
                a.push_back(v);
            }
    	}
        if(a.size()) {
            reverse(a.begin(), a.end());
            for(auto x : a) cout << x <<"";
        }
    }
    
    int check() {
        int demle = 0;
        for (int i = 1; i <= n; i++) {
            int dem = 0;
            for (int j = 1; j <= n; j++) {
                if (A[i][j]) dem++;
            }
            if (dem & 1) demle++;
        }
        if (demle == 0) return 1;
        else if (demle == 2) return 1;
        else return 0;
    }    
};

int main() {
    graph g;
    g.readdata();
    if(!g.check()) {
        cout << "no Euler cycle";
    }
    else {
        g.euler(g.gets());
    }
    
    return 0;
}
