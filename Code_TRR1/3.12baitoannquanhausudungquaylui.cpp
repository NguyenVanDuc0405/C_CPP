#include<bits/stdc++.h>

using namespace std;
int n;
int xuoi[20];
int nguoc[20];
int a[10];
int x[10];
void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = 1;
    }
    for(int i = 1; i <= 2* n; i++){
        xuoi[i] = 1;
        nguoc[i] = 1;
    }
}
void Out(){
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void Queen(int i){
    for(int j = 1; j <=n; j++){
        if(a[j] == 1 && xuoi[i-j+n] == 1 && nguoc[i+j-1] == 1){
            x[i] = j;
            a[j] = 0;
            xuoi[i-j+n] = 0;
            nguoc[i+j-1] = 0;
            if(i == n){
                Out();
            }
            else{
                Queen(i+1);
            }
            a[j] = 1;
            xuoi[i-j+n] = 1;
            nguoc[i+j-1] = 1;
        }
    }
}
int main(){
    Input();
    Queen(1);
    return 0;
}
