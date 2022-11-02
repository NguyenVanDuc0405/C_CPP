#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>check;
int x[10];
void Input(){
    cin >> n;
    for(int i = 1; i <= n+1; i++){
        check.push_back(1);
    }
}
void Solve(){
    for(int i = 1; i <= n; i++){
        cout << x[i] <<" ";
    }
    cout << endl;
}
void QuayLuiHoanVi(int i){
    for(int j = 1; j <=n ; j++){
        if(check[j] == 1){
            check[j] = 0;
            x[i] = j;
            if(i == n){
                Solve();
            }
            else{
                QuayLuiHoanVi(i+1);
            }
            check[j] = 1;
        }
    }
}
int main(){
    Input();
    QuayLuiHoanVi(1);
    return 0;
}	
